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

class Book {
public: // Interface

	Book(const std::string &quote = "", const std::string &title = "", unsigned short year = 0,
			unsigned short minReaderAge = 0, unsigned short nPossess = 0); // Ctor
	Book(const Book& book); // Copy ctor
	Book(Book&& book) noexcept ; // Move ctor
	Book& operator=(const Book& book); // Copy assignment
	Book& operator=(Book&& book) noexcept ;// Move assignment

	// Exception
	class BadBook{
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
	unsigned short getYear() const;
	void setYear(unsigned short year);
	unsigned short getMinReaderAge() const;
	void setMinReaderAge(unsigned short minReaderAge);
	unsigned short getNPossess() const;
	void setNPossess(unsigned short nPossess);
	unsigned short getNAvailables() const;
	void setNAvailables(unsigned short nAvailables);

	// Printing methods
	void print()const;
	void repr()const;
	void str()const;

private: // Representation
	std::string quote_; // e.g. "GA203"
	std::string title_; // e.g. "The C++ Programming Language"
	unsigned short year_; // e.g 2011
	unsigned short minReaderAge_; // e.g. 8
	unsigned short nPossess_; // 2
	unsigned short nAvailables_; // 200
};


#endif //LMIS_BOOK_H
