// Borrow.cpp: Cpp file for the implementation of the class Borrow
// Created by pam on 10/06/18.
//

#include "Borrow.h"

Borrow::Borrow(Subscriber *subscriber, Book *book, unsigned int returnDate) :
		subscriber_{subscriber}, book_{book}, returnDate_{returnDate} {}


// Copy ctor
// param[in]:
// param[out]:
Borrow::Borrow(const Borrow &borrow) : subscriber_{borrow.getSubscriber()}, book_{borrow.getBook()}, returnDate_{borrow.getReturnDate()} {}

// Move ctor
// param[in]:
// param[out]:
Borrow::Borrow(Borrow &&borrow) noexcept : subscriber_{nullptr}, book_{nullptr}, returnDate_{0} {
	subscriber_ = {borrow.getSubscriber()};
	book_ = {borrow.getBook()};
	returnDate_ = {borrow.getReturnDate()};

	borrow.setSubscriber(nullptr);
	borrow.setBook(nullptr);
	borrow.setReturnDate(0);
}


// Copy assignment operator
// param[in]:
// param[out]:
Borrow& Borrow::operator=(const Borrow& borrow)
{
	if(this != &borrow){
		subscriber_ = {borrow.getSubscriber()};
		book_ = {borrow.getBook()};
		returnDate_ = {borrow.getReturnDate()};
	}
	return *this;
}

// Move assignment operator
// param[in]:
// param[out]:
Borrow& Borrow::operator=(Borrow&& borrow) noexcept
{
	subscriber_ = {nullptr};
	book_ = {nullptr};
	returnDate_ = {0};

	if(this != &borrow){
		subscriber_ = {borrow.getSubscriber()};
		book_ = {borrow.getBook()};
		returnDate_ = {borrow.getReturnDate()};
	}
	return *this;
}

// Dtor
// param[in]:
// param[out]:
Borrow::~Borrow() {

}

// method
// param[in]:
// param[out]:
Subscriber *Borrow::getSubscriber() const {
	return subscriber_;
}

// method
// param[in]:
// param[out]:
void Borrow::setSubscriber(Subscriber *subscriber) {
	subscriber_ = {subscriber};
}

// method getBook() const
// param[in]: void
// param[out]: book_ (const std::shared_ptr<Book>& )
Book *Borrow::getBook() const {
	return book_;
}

// method setBook(const std::shared_ptr<Book>& book)
// param[in]: book (const std::shared_ptr<Book>& )
// param[out]: void
void Borrow::setBook(Book *book) {
	book_ = {book};
}

// method getRetunDate()
// param[in]: void
// param[out]: returnDate_ (unsigned int)
unsigned int Borrow::getReturnDate() const {
	return returnDate_;
}

// method setReturnDate(unsigned int returnDate)
// param[in]: returnDate
// param[out]: void
void Borrow::setReturnDate(unsigned int returnDate) {
	returnDate_ = {returnDate};
}

// method print()const
// param[in]: void
// param[out]: void
void Borrow::print() const {
	std::cout << "Subscriber #" << getSubscriber()->getId() << ". Book " << getBook()->getQuote() << ". Return date " << getReturnDate() << ".\n";
}

// method reprt() const
// param[in]: void
// param[out]: void
void Borrow::repr() const {
	std::cout << "Borrow(subscriber_ptr, book_ptr, return_date)\n";
}

// method str() const
// param[in]: void
// param[out]: void
void Borrow::str() const {
	std::cout << " Subscriber #subscriber_id. Book book_quote. Return date return_date\n";
}











