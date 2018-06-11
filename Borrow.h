// Borrow.h: Header for the definition of the class Borrow
// Created by pam on 10/06/18.
//

#ifndef LMIS_BORROW_H
#define LMIS_BORROW_H


#include <memory>
#include "Subscriber.h"
#include "Book.h"

class Borrow {
public:
	Borrow(const std::shared_ptr<Subscriber>& subscriber, const std::shared_ptr<Book>& book, unsigned short returnDate);
	Borrow(const Borrow& borrow); // Copy ctor
	Borrow(Borrow&& borrow) noexcept ; // Move ctor
	Borrow& operator=(const Borrow& borrow); // Copy assignment
	Borrow& operator=(Borrow&& borrow) noexcept; // Move assignment


	virtual ~Borrow();

	// Accessors and Mutators
	const std::shared_ptr<Subscriber> &getSubscriber() const;
	void setSubscriber(const std::shared_ptr<Subscriber> &subscriber);
	const std::shared_ptr<Book> &getBook() const;
	void setBook(const std::shared_ptr<Book> &book);
	unsigned short getReturnDate() const;
	void setReturnDate(unsigned short returnDate);

private:
	std::shared_ptr<Subscriber> subscriber_;
	std::shared_ptr<Book> book_;
	unsigned short returnDate_;
};


#endif //LMIS_BORROW_H
