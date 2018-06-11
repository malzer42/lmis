// Subscriber.h: Header file for the definition of class Subscriber
// Created by pam on 08/06/18.
// Usage: To be included in the implementation file Subscriber.cpp of the class Subscriber

#ifndef LMIS_SUBSCRIBER_H
#define LMIS_SUBSCRIBER_H


#include <string>

class Subscriber {
public:
	// Ctor
	Subscriber(const std::string &id="", const std::string &firstName="", const std::string &lastName="", unsigned short age=0);
	Subscriber(const Subscriber& subscriber);  // Copy ctor
	Subscriber(Subscriber&& subscriber) noexcept ; // Move ctor

	Subscriber& operator=(const Subscriber& subscriber); //! Copy assignment operator
	Subscriber& operator=(Subscriber&& subscriber ) noexcept; //! Move assignment operator

	class BadSubscriber{
	public:
		const std::string exceptionMsg = "BadSubscriberError: Unable to create an instance of the class Subscriber\n";

	};
	// Dtor
	virtual ~Subscriber();

	// Accessors or Getters
	const std::string &getId() const;
	const std::string &getFirstName() const;
	const std::string &getLastName() const;
	unsigned short getAge() const;

	// Mutators Setters
	void setId(const std::string &id);
	void setFirstName(const std::string &firstName);
	void setLastName(const std::string &lastName);
	void setAge(unsigned short age);

	// Printing method
	void print()const ; // The actual printing method
	void str()const; // For developer to know how the information of an instance of the class Subscriber will be displayed on the screen
	void repr()const; // For developer to know how to create an instance of the class Subscriber

private:
	std::string id_;
	std::string firstName_;
	std::string lastName_;
	unsigned short age_;
};


#endif //LMIS_SUBSCRIBER_H
