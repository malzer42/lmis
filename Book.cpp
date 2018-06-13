// Book.cpp: Cpp file for the implementation of the class Book.
// Author(s): Pierre Abraham Mulamba.
// Date of creation (modification): 2018/06/10 (2018/06/12).
// Description: The class Book is a concrete class that instantiates Book objects.
// Usage: To create an instance of a Book.
// Compilation: Makefile provided.
// Run:

#include "Book.h"


// Ctor
// params[in]: quote(string), title(string), year(unsigned short), minReaderAge(unsigned short), nPosses(unsigned short)
// param[out]: void
Book::Book(const std::string &quote, const std::string &title, unsigned short year, unsigned short minReaderAge, unsigned short nPossess) :
		quote_(quote), title_(title), year_(year), minReaderAge_(minReaderAge), nPossess_(nPossess) {


	if(minReaderAge_ < 0 ) throw Book::BadBook();
	nAvailables_ = 1000;

}

// Copy ctor
// param[in]: book(Book)
// param[out]: void
Book::Book(const Book& book) : quote_(book.getQuote()), title_(book.getTitle()), year_(book.getYear()),
                               minReaderAge_(book.getMinReaderAge()), nPossess_(book.getNPossess()),
                               nAvailables_(book.getNAvailables()){}
// Move ctor
// param[in]: book(Book)
// param[out]: void
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
// param[in]: book(Book)
// param[out]: *this(Book)
Book &Book::operator=(const Book &book) {
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
// param[in]: book(Book)
// param[out]: *this(Book)
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

// Dtor
// param[in]: void
// param[out]: void
//Book::~Book() {
//
//}

// Accessors and Mutators

// method getQuote()const
// param[in]: void
// param[out]: quote_ (const string)
const std::string &Book::getQuote() const {
	return quote_;
}


// method setQuote(quote)
// param[in]: qoute(const string)
// param[out]: void
void Book::setQuote(const std::string &quote) {
	quote_ = quote;
}

// method getTitle()const
// param[in]: void
// param[out]: title_ (const string)
const std::string &Book::getTitle() const {
	return title_;
}

// method setTitle(title)
// param[in]: title(const string)
// param[out]: void
void Book::setTitle(const std::string &title) {
	title_ = title;
}

// method getYear()const
// param[in]: void
// param[out]: year_ (unsigned short)
unsigned short Book::getYear() const {
	return year_;
}

// method setYear(year)
// param[in]: year(unsigned short)
// param[out]: void
void Book::setYear(unsigned short year) {
	year_ = year;
}

// method getMinReadearAge()const
// param[in]: void
// param[out]: minReaderAge_ (unsigned short)
unsigned short Book::getMinReaderAge() const {
	return minReaderAge_;
}

// method setMinReaderAge(minReaderAge)
// param[in]: minReaderAge(unsigned short)
// param[out]: void
void Book::setMinReaderAge(unsigned short minReaderAge) {
	minReaderAge_ = minReaderAge;
}

// method getNPossess()const
// param[in]: void
// param[out]: nPossess_ (unsigned short)
unsigned short Book::getNPossess() const {
	return nPossess_;
}

// method setNPossess(nPossess)
// param[in]: nPossess(unsigned short)
// param[out]: void
void Book::setNPossess(unsigned short nPossess) {
	nPossess_ = nPossess;
}

// method getNAvailables()const
// param[in]: void
// param[out]: nAvailables_ (unsigned short)
unsigned short Book::getNAvailables() const {
	return nAvailables_;
}

// method setNAvailables(nAvailables)
// param[in]: nAvailables(unsigned short)
// param[out]: void
void Book::setNAvailables(unsigned short nAvailables) {
	nAvailables_ = nAvailables;
}

// method print()const
// param[in]: void
// param[out]: void
void Book::print() const {
	std::cout << getQuote() <<". " << getTitle() <<". " << getYear()<<". " << getMinReaderAge() << " y.o. and more.\n";
}

// method repr()const
// param[in]: void
// param[out]: void
void Book::repr() const {
	std::cout << "Book(quote, title, year, minReaderAge, nPossess, nAvailable)\n";
}

// method str() const
// param[in]: void
// param[out]: void
void Book::str() const {
	std::cout << "quote. title. year. minReaderAge y.o. or more.\n";
}