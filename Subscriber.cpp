// Subscriber.cpp: Implementation of the class Subscriber
// Created by pam on 08/06/18.


#include <iostream>
#include "Subscriber.h"

// Ctor
Subscriber::Subscriber(const std::string &id, const std::string &firstName, const std::string &lastName, unsigned short age) :
		id_(id), firstName_(firstName), lastName_(lastName), age_(age){

	const unsigned short min_age = 6;
	const unsigned short max_age = 100;
	if(age < min_age || max_age < age) throw Subscriber::BadSubscriber();

}

// Copy ctor
Subscriber::Subscriber(const Subscriber &subscriber) : id_(subscriber.getId()),
                                                       firstName_(subscriber.getFirstName()),
                                                       lastName_(subscriber.getLastName()),
                                                       age_(subscriber.getAge()){}

// Move ctor
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
Subscriber& Subscriber::operator=(Subscriber&& subscriber) noexcept
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

// Dtor
Subscriber::~Subscriber(){}


// Accessors or Getters
const std::string &Subscriber::getId() const {
	return id_;
}

const std::string &Subscriber::getFirstName() const {
	return firstName_;
}

const std::string &Subscriber::getLastName() const {
	return lastName_;
}

unsigned short Subscriber::getAge() const {
	return age_;
}

// Mutators or Setters
void Subscriber::setId(const std::string &id) {
	id_ = id;
}

void Subscriber::setFirstName(const std::string &firstName) {
	firstName_ = firstName;
}

void Subscriber::setLastName(const std::string &lastName) {
	lastName_ = lastName;
}

void Subscriber::setAge(unsigned short age) {
	age_ = age;
}

// Printing method
void Subscriber::print()const {
	std::cout << getFirstName() << " , " << getLastName()<<". " << getAge() << " y.o. #" << getId()<<'\n';
}

// Printing method for developer to know how to display information of the class Subscriber
void Subscriber::str()const {
	std::cout << "firstName, lastName. age  y.o. #id\n";
}

// Printing method for developer to know how to instantiate an object of the class Subscriber
void Subscriber::repr() const {
	std::cout << "Subscriber(id, firstName, lastName, age)\n";

}



