// Subscriber.cpp: Cpp file for the implementation of the class Subscriber.
// Author(s): Pierre Abraham Mulamba.
// Date of creation (modification): 2018/06/10 (2018/06/100.
// Description: The class Subscriber is a concrete class that instantiates Subscriber objects.
// Usage: To create an instance of a Subscriber
// Compilation: Makefile provided.
// Run:

#include "Subscriber.h"

// Ctor
// params[in]: id(string), firstName(string), lastName(string), Age(unsigned short)
// param[out]: void
Subscriber::Subscriber(const std::string &id, const std::string &firstName, const std::string &lastName, unsigned int age) :
		id_(id), firstName_(firstName), lastName_(lastName), age_(age){

	const unsigned int min_age = 6;
	const unsigned int max_age = 100;
	if(age < min_age || max_age < age) throw Subscriber::BadSubscriber();

}

// Copy ctor
// param[in]: subscriber(Subscriber)
// param[out]: void
Subscriber::Subscriber(const Subscriber &subscriber) : id_(subscriber.getId()),
                                                       firstName_(subscriber.getFirstName()),
                                                       lastName_(subscriber.getLastName()),
                                                       age_(subscriber.getAge()){}

// Move ctor
// param[in]: subscriber(Subscriber&&)
// param[out]: void
Subscriber::Subscriber(Subscriber &&subscriber)noexcept : id_(""), firstName_(""), lastName_(""), age_(0)
{
	id_ = subscriber.getId();
	firstName_ = subscriber.getFirstName();
	lastName_ = subscriber.getLastName();
	age_ = subscriber.getAge();

	subscriber.setId("");
	subscriber.setFirstName("");
	subscriber.setLastName("");
	subscriber.setAge(0);
}

//! Copy assignment operator
// param[in]: subscriber(const Subscriber&)
// param[out]: *this(Subscriber&)
Subscriber& Subscriber::operator=(const Subscriber& subscriber)
{
	if(this != &subscriber)
	{
		id_ = subscriber.getId();
		firstName_ = subscriber.getFirstName();
		lastName_ = subscriber.getLastName();
		age_ = subscriber.getAge();
	}
	return *this;
}

// Move assignment
// param[in]: subscriber(Subscriber&&)
// param[out]: *this(Subscriber&)
Subscriber &Subscriber::operator=(Subscriber &&subscriber)noexcept
{
	id_ = "";
	firstName_ = "";
	lastName_ = "";
	age_ = 0;

	if (this != &subscriber)
	{
		id_ = subscriber.getId();
		firstName_ = subscriber.getFirstName();
		lastName_ = subscriber.getLastName();
		age_ = subscriber.getAge();

		subscriber.setId("");
		subscriber.setFirstName("");
		subscriber.setLastName("");
		subscriber.setAge(0);
	}
	return *this;
}


// Accessors or Getters

// method getId()const
// param[in]: void
// param[out]: id_ (const string)
const std::string &Subscriber::getId() const {
	return id_;
}

// method getFirstName()const
// param[in]: void
// param[out]: firstName_ (const string)
const std::string &Subscriber::getFirstName() const {
	return firstName_;
}

// method getLastName()const
// param[in]: void
// param[out]: lastName_ (const string)
const std::string &Subscriber::getLastName() const {
	return lastName_;
}

// method getId()const
// param[in]: void
// param[out]: age_ (unsigned short)
unsigned int Subscriber::getAge() const {
	return age_;
}

// Mutators or Setters

// method setId(const string& id)
// param[in]: id (string)
// param[out]: void
void Subscriber::setId(const std::string &id) {
	id_ = id;
}

// method setFirstName(const string& firstName)
// param[in]: firstName (string)
// param[out]: void
void Subscriber::setFirstName(const std::string &firstName) {
	firstName_ = firstName;
}

// method setLastName(const string& lastName)
// param[in]: lastName (string)
// param[out]: void
void Subscriber::setLastName(const std::string &lastName) {
	lastName_ = lastName;
}

// method setAge(unsigned short age)
// param[in]: age (unsigned short)
// param[out]: void
void Subscriber::setAge(unsigned int age) {
	age_ = age;
}

// method print()const
// param[in]: void
// param[out]: void
void Subscriber::print() const {
	std::cout << getFirstName() << " , " << getLastName()<<". " << getAge() << " y.o. #" << getId()<<'\n';
}

// Printing method for developer to know how to display information of the class Subscriber
// method str()const
// param[in]: void
// param[out]: void
void Subscriber::str() const {
	std::cout << "firstName, lastName. age  y.o. #id\n";
}

// Printing method for developer to know how to instantiate an object of the class Subscriber
// method repr()const
// param[in]: void
// param[out]: void
void Subscriber::repr() const {
	std::cout << "Subscriber(id, firstName, lastName, age)\n";

}



