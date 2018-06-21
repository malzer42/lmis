// Borrow.h: Header for the definition of the class Borrow.
// Author(s): Pierre Abraham Mulamba.
// Date of creation (modification): 2018/06/10 (2018/06/12).
// Description: The class Borrow is an aggregation of two classes --Subscriber and Book. It defines a Borrow interface and representation
// Usage: To create an instance of a Borrow.
// Compilation: Makefile provided.
// Run: Include as a header file


#ifndef LMIS_BORROW_H
#define LMIS_BORROW_H


#include <memory>
#include "Subscriber.h"
#include "Book.h"

class Borrow {
public: // Interface

	Borrow(const std::shared_ptr<Subscriber> &subscriber = {nullptr}, const std::shared_ptr<Book> &book = {nullptr}, unsigned int returnDate = {0});
	Borrow(const Borrow& borrow); // Copy ctor
	Borrow(Borrow&& borrow) noexcept ; // Move ctor
	Borrow& operator=(const Borrow& borrow); // Copy assignment
	Borrow& operator=(Borrow&& borrow) noexcept; // Move assignment


	//~Borrow();

	// Accessors and Mutators
	const std::shared_ptr<Subscriber> &getSubscriber() const;
	void setSubscriber(const std::shared_ptr<Subscriber> &subscriber);
	const std::shared_ptr<Book> &getBook() const;
	void setBook(const std::shared_ptr<Book> &book);
	unsigned int getReturnDate() const;
	void setReturnDate(unsigned int returnDate);
	void print() const;
	void repr() const;
	void str() const;

private: // Representation
	std::shared_ptr<Subscriber> subscriber_; // e.g std::shared_ptr<Subscriber> subscriber_ = std::make_shared<Subscriber>("102013", "Pierre", "Mulamba", 94)
	std::shared_ptr<Book> book_; // e.g. std::shared_ptr<Book> book_ = std::make_shared<Book>("QA203", "The Big C++", 2011, 8, 3)
	unsigned int returnDate_; // e.g. 20180612
};


#endif //LMIS_BORROW_H
