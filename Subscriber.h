/**
   Subscriber.h: Header for the definition of the class Subscriber.
   Author(s): Pierre Abraham Mulamba.
   Date of creation (modification): 2018/06/10 (2018/06/12).
   Description: The class Subscriber is a concrete class that defines
   a Subscriber interface and representation.
   Usage: To create an instance of a Subscriber.
   Compilation: Makefile provided.
   Run: Included as header file
*/

#ifndef LMIS_SUBSCRIBER_H
#define LMIS_SUBSCRIBER_H

#include <iostream>
#include <string>
#include <exception>

class Subscriber {
 public:
  // Ctor
  Subscriber(const std::string& id = {""}, const std::string& fname = {""}, const std::string& lname = {""}, unsigned int age = {0}, const std::string& sin={""} );
  Subscriber(const Subscriber& subscriber);  // Copy ctor
  Subscriber(Subscriber&& subscriber)noexcept; // Move ctor
  Subscriber& operator=(const Subscriber& subscriber); //! Copy assignment operator
  Subscriber& operator=(Subscriber&& subscriber)noexcept;// noexcept; //! Move assignment operator

  // Exception
  class BadSubscriber : public std::exception {
  public:
    const std::string exceptionMsg = {"BadSubscriberError: Unable to create an instance of the class Subscriber\n"};
  };
  // Dtor
  virtual ~Subscriber() = default;
  
  // Accessors or Getters
  const std::string& getId() const;
  const std::string& getFname() const;
  const std::string& getLname() const;
  unsigned int getAge() const;
  const std::string& getSin()const;

  // Mutators or Setters
  void setId(const std::string& id);
  void setFname(const std::string& fname);
  void setLname(const std::string& lname);
  void setAge(unsigned int age);
  void setSin(const std::string& sin);

  // Printing method
  void print()const ; // The actual printing method
  void printIdCard()const;
  void str()const; // For developer to know how the information of an instance of the class Subscriber will be displayed on the screen
  void repr()const; // For developer to know how to create an instance of the class Subscriber

 private:
  std::string id_; // e.g. "1839456"
  std::string fname_; // e.g. "John"
  std::string lname_; // e.g. "Doe"
  unsigned int age_; // e.g. 39
  std::string sin_;
};
#endif //LMIS_SUBSCRIBER_H
