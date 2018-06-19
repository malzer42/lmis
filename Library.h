// Library.h: Header for the definition of the class Library.
// Author(s): Pierre Abraham Mulamba.
// Date of creation (modification): 2018/06/10 (2018/06/12).
// Description: The class Library is an aggregation of three classes: Subscriber, Book, and Borrow.
// Usage: To create an instance of a Library.
// Compilation: Makefile provided.
// Run: Included as header file


#ifndef LMIS_LIBRARY_H
#define LMIS_LIBRARY_H

#include <iostream>
#include <stdexcept>
#include <exception>
//#include <utility> // std::swap in C++11, <algorithm> in C++98
#include <memory> // std::shared_ptr, std::make_shared<Type>
#include <regex> // std::regex, std::regex_match, std::regex_search, std::regex_replace
#include "Subscriber.h"
#include "Book.h"
#include "Borrow.h"


class Library {
public:
	const unsigned int MAX_SUB = 100; // Maximum number of Subscribers
	const unsigned int MAX_BOOK = 1000; // Maximum number of Books
	const unsigned int MAX_BORROW = 200; // Maximum number of Borrows

	Library(); // Ctor
	// TODO: Copy ctor --> Library(const Library& library)
	// TODO: Move ctor --> Library(Library&& library) noexcept
	// TODO: Copy assignment --> Library& operator=(const Library& library)
	// TODO: Move assignment --> Library& operator=(Library&& library) noexcept
	class BadLibrary : public std::exception {
	public:
		const std::string exceptionMsg = "BadLibraryError: Unable to process item in the library\n";
	};
	virtual ~Library(); // Dtor

	// Processing subscribers in the library
	void addSubscriber(Subscriber& subscriber);
	void removeSubscriber(const std::string& id);
	void sortSubscriber(unsigned int option);
	void swapSubscriber(Subscriber &sub1, Subscriber &sub2);

	// Processing books in the library
	void addBook(Book& book);
	void removeBook(const std::string& quote);
	void sortBook(unsigned int option);
	void swapBook(Book &book1, Book &book2);

	// Searching, borrowing, returning, displaying methods
	void searchTitle(const std::string &str);
	void searchQuote(const std::string &book_quote);
	bool borrowBook(const std::string &subscriber_id, const std::string &book_quote, unsigned int returnDate);
	bool returnBook(const std::string &subscriber_id, const std::string &book_quote);
	void infoSubscriber(const std::string &subscriber_id) const;

	void print()const;

private:
	Subscriber** subscribers_; // Dynamic allocation in ctor of the class Library for pointers of Subscribers
	unsigned int nSubscribers_; // number of Subscriber instances
	Book** books_; // Dynamic allocation in ctor of the class Library for pointers of Books
	unsigned int nBooks_; // number of Book instances
	Borrow** borrows_; // Dynamic allocation in ctor of the class Library for pointers of Borrows
	unsigned int nBorrows_; // number of Borrow instances
};


#endif //LMIS_LIBRARY_H
