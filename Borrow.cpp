// Borrow.cpp: Cpp file for the implementation of the class Borrow
// Created by pam on 10/06/18.
//

#include "Borrow.h"


Borrow::Borrow(const std::shared_ptr<Subscriber> &subscriber, const std::shared_ptr<Book> &book, unsigned short returnDate) :
		subscriber_(subscriber), book_(book), returnDate_(returnDate) {}


// Copy ctor
Borrow::Borrow(const Borrow& borrow) : subscriber_(borrow.getSubscriber()), book_(borrow.getBook()), returnDate_(borrow.getReturnDate()) {}

// Move ctor
Borrow::Borrow(Borrow&& borrow) noexcept : subscriber_(nullptr), book_(nullptr), returnDate_(0)
{
	subscriber_ = borrow.getSubscriber();
	book_ = borrow.getBook();
	returnDate_ = borrow.getReturnDate();

	borrow.setSubscriber(nullptr);
	borrow.setBook(nullptr);
	borrow.setReturnDate(0);
}


// Copy assignment
Borrow& Borrow::operator=(const Borrow& borrow)
{
	if(this != &borrow){
		subscriber_ = borrow.getSubscriber();
		book_ = borrow.getBook();
		returnDate_ = borrow.getReturnDate();
	}
	return *this;
}

// Move assignment
Borrow& Borrow::operator=(Borrow&& borrow) noexcept
{
	subscriber_ = nullptr;
	book_ = nullptr;
	returnDate_ = 0;

	if(this != &borrow){
		subscriber_ = borrow.getSubscriber();
		book_ = borrow.getBook();
		returnDate_ = borrow.getReturnDate();
	}
	return *this;
}

Borrow::~Borrow() {

}

const std::shared_ptr<Subscriber> &Borrow::getSubscriber() const {
	return subscriber_;
}

void Borrow::setSubscriber(const std::shared_ptr<Subscriber> &subscriber) {
	subscriber_ = subscriber;
}

const std::shared_ptr<Book> &Borrow::getBook() const {
	return book_;
}

void Borrow::setBook(const std::shared_ptr<Book> &book) {
	book_ = book;
}

unsigned short Borrow::getReturnDate() const {
	return returnDate_;
}

void Borrow::setReturnDate(unsigned short returnDate) {
	returnDate_ = returnDate;
}


