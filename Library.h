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
#include <memory>
#include <regex>
#include "Subscriber.h"
#include "Book.h"
#include "Borrow.h"


class Library {
public:
	const unsigned short MAX_SUB = 100; // Maximum number of Subscribers
	const unsigned short MAX_BOOK = 1000; // Maximum number of Books
	const unsigned short MAX_BORROW = 200; // Maximum number of Borrows

	Library(); // Ctor
	// TODO: Copy ctor --> Library(const Library& library)
	// TODO: Move ctor --> Library(Library&& library) noexcept
	// TODO: Copy assignment --> Library& operator=(const Library& library)
	// TODO: Move assignment --> Library& operator=(Library&& library) noexcept
	class BadLibrary{
	public:
		const std::string exceptionMsg = "BadLibraryError: Unable to process item in the library\n";
	};
	virtual ~Library(); // Dtor

	void addSubscriber(Subscriber& subscriber);
	void removeSubscriber(const std::string& id);
	// TODO: void sortSubscriber()const;
	// TODO: void swapSubscriber(Subscriber& sub1, Subscriber& sub2)const;

	void addBook(Book& book);
	void removeBook(const std::string& quote);

	// TODO: void sortBook()const;
	// TODO: void swapBook(Book& book1, Book& book2)const;
	// TODO: void searchTitle(const std::string& value);
	// TODO: void searchQuote(const std::string& book_quote);
	// TODO: bool borrowBook(const std::string& subscriber_id, const std::string& book_quote, unsigned short returnDate);
	// TODO: bool returnBook(const std::string& subscriber_id, const std::string& book_quote);
	// TODO: void infoSubscriber(const std::string& subscriber_id);
	void print()const;

	//void addBook(Book book);

private:
	Subscriber** subscribers_; // Dynamic allocation in ctor of the class Library for pointers of Subscribers
	unsigned short nSubscribers_; // number of Subscriber instances
	Book** books_; // Dynamic allocation in ctor of the class Library for pointers of Books
	unsigned short nBooks_; // number of Book instances
	Borrow** borrows_; // Dynamic allocation in ctor of the class Library for pointers of Borrows
	unsigned short nBorrows_; // number of Borrow instances
};


#endif //LMIS_LIBRARY_H
