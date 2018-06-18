// Book.h: Header for the definition of the class Book.
// Author(s): Pierre Abraham Mulamba.
// Date of creation (modification): 2018/06/10 (2018/06/12).
// Description: The class Book is a concrete class that defines a book interface and representation.
// Usage: To create an instance of a Book.
// Compilation: Makefile provided.
// Run: Include as a header file

#ifndef LMIS_BOOK_H
#define LMIS_BOOK_H

#include <iostream>
#include <string>
#include <exception>

class Book {
public: // Interface

	Book(const std::string &quote = "", const std::string &title = "", unsigned int year = 0,
	     unsigned int minReaderAge = 0, unsigned int nPossess = 0); // Ctor
	Book(const Book& book); // Copy ctor
	Book(Book&& book) noexcept ; // Move ctor
	Book& operator=(const Book& book); // Copy assignment
	Book& operator=(Book&& book) noexcept ;// Move assignment

	// Exception
	class BadBook : public std::exception {
	public:
		const std::string exceptionMsg = "BadBookError: Unable to create an instance of the class Book\n";
	};

	// Dtor
	virtual ~Book() = default;

	// Accessors or Getters and Mutators or Setters
	const std::string &getQuote() const;
	void setQuote(const std::string &quote);
	const std::string &getTitle() const;
	void setTitle(const std::string &title);

	unsigned int getYear() const;

	void setYear(unsigned int year);

	unsigned int getMinReaderAge() const;

	void setMinReaderAge(unsigned int minReaderAge);

	unsigned int getNPossess() const;

	void setNPossess(unsigned int nPossess);

	unsigned int getNAvailables() const;

	void setNAvailables(unsigned int nAvailables);

	// Printing methods
	void print()const;
	void repr()const;
	void str()const;

private: // Representation
	std::string quote_; // e.g. "GA203"
	std::string title_; // e.g. "The C++ Programming Language"
	unsigned int year_; // e.g 2011
	unsigned int minReaderAge_; // e.g. 8
	unsigned int nPossess_; // 2
	unsigned int nAvailables_; // 200
};


#endif //LMIS_BOOK_H
