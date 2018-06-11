//
// Created by pam on 08/06/18.
//

#include <iostream>
#include "Book.h"

Book::Book(const std::string &quote, const std::string &title, unsigned short year, unsigned short minReaderAge, unsigned short nPossess) :
		quote_(quote), title_(title), year_(year), minReaderAge_(minReaderAge), nPossess_(nPossess) {


	if(minReaderAge_ < 0 ) throw Book::BadBook();
	nAvailables_ = 1000;

}

// Copy ctor
Book::Book(const Book& book) : quote_(book.getQuote()), title_(book.getTitle()), year_(book.getYear()),
                               minReaderAge_(book.getMinReaderAge()), nPossess_(book.getNPossess()),
                               nAvailables_(book.getNAvailables()){}
// Move ctor
Book::Book(Book&& book) noexcept : quote_(""), title_(""), year_(0), minReaderAge_(0), nPossess_(0), nAvailables_(0)
{
	quote_ = book.getQuote();
	title_ = book.getTitle();
	year_ = book.getYear();
	minReaderAge_ = book.getMinReaderAge();
	nPossess_ = book.getNPossess();
	nAvailables_ = book.getNAvailables();

	book.setQuote("");
	book.setTitle("");
	book.setYear(0);
	book.setMinReaderAge(0);
	book.setNPossess(0);
	book.setNAvailables(0);

}

// Copy assignment
Book& Book::operator=(const Book& book) {
	if(this != &book){
		quote_ = book.getQuote();
		title_ = book.getTitle();
		year_ = book.getYear();
		minReaderAge_ = book.getMinReaderAge();
		nPossess_ = book.getNPossess();
		nAvailables_ = book.getNAvailables();
	}

	return *this;

}

// Move assignment
Book& Book::operator=(Book&& book) noexcept
{
	quote_ = "";
	title_ = "";
	year_ = 0;
	minReaderAge_ = 0;
	nPossess_ = 0;
	nAvailables_ = 0;

	if(this != & book){
		quote_ = book.getQuote();
		title_ = book.getTitle();
		year_ = book.getYear();
		minReaderAge_ = book.getMinReaderAge();
		nPossess_ = book.getNPossess();
		nAvailables_ = book.getNAvailables();

		book.setQuote("");
		book.setTitle("");
		book.setYear(0);
		book.setMinReaderAge(0);
		book.setNPossess(0);
		book.setNAvailables(0);
	}
	return *this;
}


Book::~Book() {

}

// Accessors and Mutators
const std::string &Book::getQuote() const {
	return quote_;
}

void Book::setQuote(const std::string &quote) {
	quote_ = quote;
}

const std::string &Book::getTitle() const {
	return title_;
}

void Book::setTitle(const std::string &title) {
	title_ = title;
}

unsigned short Book::getYear() const {
	return year_;
}

void Book::setYear(unsigned short year) {
	year_ = year;
}

unsigned short Book::getMinReaderAge() const {
	return minReaderAge_;
}

void Book::setMinReaderAge(unsigned short minReaderAge) {
	minReaderAge_ = minReaderAge;
}

unsigned short Book::getNPossess() const {
	return nPossess_;
}

void Book::setNPossess(unsigned short nPossess) {
	nPossess_ = nPossess;
}

unsigned short Book::getNAvailables() const {
	return nAvailables_;
}

void Book::setNAvailables(unsigned short nAvailables) {
	nAvailables_ = nAvailables;
}

void Book::print()const{
	std::cout << getQuote() <<". " << getTitle() <<". " << getYear()<<". " << getMinReaderAge() << " y.o. and more.\n";
}

void Book::repr() const {
	std::cout << "Book(quote, title, year, minReaderAge, nPossess, nAvailable)\n";
}

void Book::str() const {
	std::cout << "quote. title. year. minReaderAge y.o. or more.\n";
}