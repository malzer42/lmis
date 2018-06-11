// Book.h: Header file for the definition of the class Book
// Created by pam on 08/06/18.


#ifndef LMIS_BOOK_H
#define LMIS_BOOK_H

#include <string>

class Book {
public:
	Book(const std::string &quote = "", const std::string &title = "", unsigned short year = 0,
			unsigned short minReaderAge = 0, unsigned short nPossess = 0); // Ctor
	Book(const Book& book); // Copy ctor
	Book(Book&& book) noexcept ; // Move ctor
	Book& operator=(const Book& book); // Copy assignment
	Book& operator=(Book&& book) noexcept ;// Move assignment

	class BadBook{
	public:
		const std::string exceptionMsg = "BadBookError: Unable to create an instance of the class Book\n";
	};

	// Dtor
	virtual ~Book();

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

private:
	std::string quote_;
	std::string title_;
	unsigned short year_;
	unsigned short minReaderAge_;
	unsigned short nPossess_;
	unsigned short nAvailables_;
};


#endif //LMIS_BOOK_H
