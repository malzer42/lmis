// Library.cpp: Cpp file for the implementation of the class Library.
// Author(s): Pierre Abraham Mulamba.
// Date of creation (modification): 2018/06/10 (2018/06/12).
// Description: The class Library is an aggregation of three classes: Subscriber, Book, and Borrow.
// Usage: To create an instance of a Library.
// Compilation: Makefile provided.
// Run:

#include "Library.h"

// Ctor to create and initialize a class Library
// params[in]: void
// param[out]: void
Library::Library() : subscribers_(nullptr), nSubscribers_(0),  books_(nullptr), nBooks_(0), borrows_(nullptr), nBorrows_(0)
{
	subscribers_ = new Subscriber*[MAX_SUB];
	books_ = new Book*[MAX_BOOK];
	borrows_ = new Borrow*[MAX_BORROW];

	for (int i = 0; i < MAX_SUB; i++) {
		subscribers_[i] = nullptr;
	}

	for (int j = 0; j < MAX_BOOK; j++) {
		books_[j] = nullptr;
	}

	for (int k = 0; k < MAX_BORROW; k++) {
		borrows_[k] = nullptr;
	}
}

// TODO: Copy ctor implementation
// TODO: Move ctor implementation
// TODO: Copy assignment implementation
// TODO: Move assignment implementation

// Dtor to cleanup the heap
// params[in]: void
// param[out]: void
Library::~Library() {

	for (int i = 0; i < MAX_SUB; i++) {
		if(subscribers_[i] != nullptr){
			subscribers_[i] = nullptr;
		}

	}

	delete[] subscribers_;
	subscribers_ = nullptr;

	for (int j = 0; j < MAX_BOOK; j++) {
		if(books_[j] != nullptr){
			books_[j] = nullptr;
		}
	}

	delete[] books_;
	books_ = nullptr;

	for (int k = 0; k < MAX_BORROW; k++) {
		if(borrows_[k] != nullptr){
			borrows_[k] = nullptr;
		}
	}

	delete[] borrows_;
	borrows_ = nullptr;
}

// method to add an instance of a Subscriber to a library
// param[in]: subscriber (Subscriber)
// param[out]: void
void Library::addSubscriber(Subscriber& subscriber)
{
	std::regex pattern(subscriber.getId());
	bool isPresent = true;
	if(nSubscribers_ == 0){
		subscribers_[nSubscribers_++] = &subscriber;
		std::cout << "Subscriber: #" << subscriber.getId() << " added successfully!\n";
	}
	else{
		isPresent = false;
		// Loop to check an existing subscriber in the system
		for (int i = 0; i < nSubscribers_; ++i) {
			if (regex_match(subscribers_[i]->getId(), pattern)) {
				std::cout << "!!! Subscriber: #" << subscriber.getId() << " failed!!!\n";
				std::cout << subscriber.getFirstName() << ", " << subscriber.getLastName()<<". Already exit in the Library!!!\n";
				isPresent = true;
				break;
			}
		}
	}

	// Add a subscriber if he does not exist in the system
	if ((!isPresent) && (nSubscribers_ < MAX_SUB)) {
		subscribers_[nSubscribers_++] = &subscriber;
		std::cout << "Subscriber: #" << subscriber.getId() << " added successfully!\n";
	}
}


// method to remove an instance of a Subscriber to a Library based on the id of a subscriber
// param[in]: id (string)
// param[out]: void
void Library::removeSubscriber(const std::string &id) {
	std::regex pattern(id);
	for (int i = 0; i < nSubscribers_; i++) {
		if (regex_match(subscribers_[i]->getId(), pattern)) {
			for (int j = i; j < nSubscribers_ ; j++) {
				subscribers_[j] = subscribers_[j+1];
			}
			subscribers_[nSubscribers_ -1] = nullptr;
			nSubscribers_--;
			continue;
		}
	}
}

// method to add an instance of a Book to the library
// param[in]: book (Book)
// param[out]: void
void Library::addBook(Book &book) {
	std::regex pattern(book.getQuote());
	bool isPresent = true;
	if(nBooks_ == 0){
		books_[nBooks_++] = &book;
		std::cout << "Book: " << book.getQuote() << " added successfully!\n";
	}
	else{
		isPresent = false;
		// Loop to check an existing book in the system
		for (int i = 0; i < nBooks_; ++i) {
			if (regex_match(books_[i]->getQuote(), pattern)) {
				std::cout << "!!! Book: " << book.getQuote() << " failed!!!\n";
				std::cout << book.getQuote() << ", " << book.getTitle()<<". Already exit in the Library!!!\n";
				isPresent = true;
				break;
			}
		}
	}

	// Add an instance of a book if it does not exist in the system
	if ((!isPresent) && (nBooks_ < MAX_BOOK)) {
		books_[nBooks_++] = &book;
		std::cout << "Book: " << book.getQuote() << " added successfully!\n";
	}
}

// method to remove an instance of a Book from the library based on the quote
// param[in]: quote (string)
// parm[out]: void
void Library::removeBook(const std::string &quote) {
	std::regex pattern(quote);
	for (int i = 0; i < nBooks_; i++) {
		if (regex_match(books_[i]->getQuote(), pattern)) {
			for (int j = i; j < nBooks_; j++) {
				books_[j] = books_[j + 1];
			}
			books_[nBooks_ - 1] = nullptr;
			nBooks_--;
			continue;
		}
	}

}

// method to print out instances of Subscriber, Book, and Borrow contained in the library
// param[in]: void
// param[out]: void
void Library::print() const {

	std::cout << "\nPrinting Subscribers\n";
	if(0 < nSubscribers_ && nSubscribers_ < MAX_SUB){
		for (int i = 0; i <nSubscribers_ ; ++i) {
			std::cout << i << " : ";
			subscribers_[i]->print();
		}
	}
	else{
		std::cout << "\nThe library does not have a subscriber\n";
		throw Library::BadLibrary();
	}


	std::cout << "\nPrinting Books\n";
	if(0 < nBooks_ && nBooks_ < MAX_BOOK){
		for (int j = 0; j < nBooks_ ; ++j) {
			std::cout << j << " : ";
			books_[j]->print();
		}
	}
	else{
		std::cout << "\nThe library does not have a book\n";
		throw Library::BadLibrary();
	}

	// TODO: adding the printing of Borrows
}



