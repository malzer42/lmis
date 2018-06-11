// Library.h: Header file for the definition of the class Library
// Created by pam on 10/06/18.
//

#ifndef LMIS_LIBRARY_H
#define LMIS_LIBRARY_H


#include <memory>
#include "Subscriber.h"
#include "Book.h"
#include "Borrow.h"


class Library {
public:
	const unsigned short MAX_SUB = 100;
	const unsigned short MAX_BOOK = 1000;
	const unsigned short MAX_BORROW = 200;

	Library();

	virtual ~Library();

	void addSubscriber(Subscriber subscriber);
	void removeSubscriber(const std::string& id);

	//void addBook(Book book);

private:
	Subscriber** subscribers_;
	unsigned short nSubscribers_;
	Book** books_;
	unsigned short nBooks_;
	Borrow** borrows_;
	unsigned short nBorrows_;
};


#endif //LMIS_LIBRARY_H
