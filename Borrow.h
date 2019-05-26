/**
   Borrow.h: Header for the definition of the class Borrow.
   Author(s): Pierre Abraham Mulamba.
   Date of creation (modification): 2018/06/10 (2018/06/12).
   Description: The class Borrow is an aggregation of two classes --Subscriber and Book. It defines a Borrow interface and representation
   Usage: To create an instance of a Borrow.
   Compilation: Makefile provided.
   Run: Include as a header file
  
 */
#ifndef LMIS_BORROW_H
#define LMIS_BORROW_H


#include <memory>
#include <string>
#include "Subscriber.h"
#include "Book.h"

class Borrow {
 public: // Interface
  
  Borrow(Subscriber * = {nullptr}, Book *book = {nullptr}, const std::string& returnDate = {""});
  Borrow(const Borrow& borrow); // Copy ctor
  Borrow(Borrow&& borrow) noexcept ; // Move ctor
  Borrow& operator=(const Borrow& borrow); // Copy assignment
  Borrow& operator=(Borrow&& borrow) noexcept; // Move assignment
  ~Borrow();

  // Accessors and Mutators
  Subscriber *getSubscriber() const;
  void setSubscriber(Subscriber *subscriber);
  Book *getBook() const;
  void setBook(Book *book);
  const std::string& getReturnDate() const;
  void setReturnDate(const std::string& returnDate);
  void print() const;
  void repr() const;
  void str() const;

 private: // Representation
  Subscriber* subscriber_; // e.g std::shared_ptr<Subscriber> subscriber_ = std::make_shared<Subscriber>("102013", "Pierre", "Mulamba", 94)
  Book* book_;
  std::string returnDate_; // e.g. 20180612
};


#endif //LMIS_BORROW_H
