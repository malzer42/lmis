/**
   Subscriber.cpp: Cpp file for the implementation of the class Subscriber.
   Author(s): Pierre Abraham Mulamba.
   Date of creation (modification): 2018/06/10 (2018/06/10).
   Description: The class Subscriber is a concrete class that instantiates Subscriber objects.
   Usage: To create an instance of a Subscriber
   Compilation: Makefile provided.
   Run:
*/

#include "Subscriber.h"

// Ctor
// params[in]: id(string), fname(string), lname(string), Age(unsigned short)
// param[out]: void
Subscriber::Subscriber(const std::string& id, const std::string& fname, const std::string& lname, unsigned int age, const std::string& sin) :
  id_{id}, fname_{fname}, lname_{lname}, age_{age}, sin_{sin}
{

  const unsigned int min_age = {6};
  const unsigned int max_age = {100};
  if(age < min_age || max_age < age) throw Subscriber::BadSubscriber();
}

// Copy ctor
// param[in]: subscriber(Subscriber)
// param[out]: void
Subscriber::Subscriber(const Subscriber& subscriber) : id_{subscriber.getId()}, fname_{subscriber.getFname()},
						       lname_{subscriber.getLname()}, age_{subscriber.getAge()},
						       sin_{subscriber.getSin()}
{

}

// Move ctor
// param[in]: subscriber(Subscriber&&)
// param[out]: void
Subscriber::Subscriber(Subscriber&& subscriber)noexcept : id_{""}, fname_{""}, lname_{""}, age_{0}, sin_{""}
{
  id_ = {subscriber.getId()};
  fname_ = {subscriber.getFname()};
  lname_ = {subscriber.getLname()};
  age_ = {subscriber.getAge()};
  sin_ = {subscriber.getSin()};
  
  // Release resources
  subscriber.setId("");
  subscriber.setFname("");
  subscriber.setLname("");
  subscriber.setAge(0);
  subscriber.setSin("");  
}

//! Copy assignment operator
// param[in]: subscriber(const Subscriber&)
// param[out]: *this(Subscriber&)
Subscriber& Subscriber::operator=(const Subscriber& subscriber)
{
  if(this != &subscriber){
    id_ = {subscriber.getId()};
    fname_ = {subscriber.getFname()};
    lname_ = {subscriber.getLname()};
    age_ = {subscriber.getAge()};
    sin_ = {subscriber.getSin()};
  }
  return *this;
}

// Move assignment
// param[in]: subscriber(Subscriber&&)
// param[out]: *this(Subscriber&)
Subscriber& Subscriber::operator=(Subscriber&& subscriber)noexcept
{
  id_ = {""};
  fname_ = {""};
  lname_ = {""};
  age_ = {0};
  sin_ = {""};
        
  if (this != &subscriber){
    id_ = {subscriber.getId()};
    fname_ = {subscriber.getFname()};
    lname_ = {subscriber.getLname()};
    age_ = {subscriber.getAge()};
    sin_ = {subscriber.getSin()};
    
    subscriber.setId("");
    subscriber.setFname("");
    subscriber.setLname("");
    subscriber.setAge(0);
    subscriber.setSin("");  
  }
  return *this;
}


// ACCESSORS OR GETTERS
// method getId()const
// param[in]: void
// param[out]: id_ (const std::string)
const std::string &Subscriber::getId() const {
  return id_;
}

// method getSin(void)const
// param[in]: void
// param[out]: sin_(const std::string)
const std::string& Subscriber::getSin()const
{
  return sin_;
}

// method setSin(const std::string& sin)
// param[in]: sin(const std::string&)
// param[out]: void
void Subscriber::setSin(const std::string& sin)
{
  sin_ = {sin};
}

// method getFirstName()const
// param[in]: void
// param[out]: firstName_ (const string)
const std::string& Subscriber::getFname() const {
  return fname_;
}

// method getLname()const
// param[in]: void
// param[out]: lname_ (const string)
const std::string &Subscriber::getLname() const {
  return lname_;
}

// method getId()const
// param[in]: void
// param[out]: age_ (unsigned short)
unsigned int Subscriber::getAge() const {
  return age_;
}

// MUTATORS OR SETTERS
// method setId(const string& id)
// param[in]: id (string)
// param[out]: void
void Subscriber::setId(const std::string& id) {
  id_ = {id};
}

// method setFname(const string& fname)
// param[in]: fname (string)
// param[out]: void
void Subscriber::setFname(const std::string& fname) {
  fname_ = {fname};
}

// method setLname(const string& lname)
// param[in]: lname (string)
// param[out]: void
void Subscriber::setLname(const std::string& lname) {
  lname_ = {lname};
}

// method setAge(unsigned short age)
// param[in]: age (unsigned short)
// param[out]: void
void Subscriber::setAge(unsigned int age) {
  age_ = {age};
}

// method print()const
// param[in]: void
// param[out]: void
void Subscriber::print() const {
  std::cout << getFname() << " , " << getLname()<<". " << getAge() << " y.o. #" << getId()<<'\n';
}

// Printing method for developer to know how to instantiate an object of the class Subscriber
// method repr()const
// param[in]: void
// param[out]: void
void Subscriber::repr() const {
  std::cout << "Subscriber(subscriber_id, subscriber_fname, subscriber_lname, subscriber_age, subscriber_sin)\n";
}

// Printing method for developer to know how to display information of the class Subscriber
// method str()const
// param[in]: void
// param[out]: void
void Subscriber::str() const {
  std::cout << "fname, lname. age  y.o. #id\n";
}

void Subscriber::printIdCard()const
{
  std::cout << "\nLibrany Management Inventory System\n"
	    <<"ID #: " << getId()
	    <<"\nLast name: " << getLname()
	    <<"\nFirst name: " << getFname()
	    <<'\n';
}
