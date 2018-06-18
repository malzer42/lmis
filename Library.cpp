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
		for (int i = 0; i < nSubscribers_; ++i) { // Loop through the list of subscribers to check if the subscriber is or not in the list to avoid duplication of data
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
	if (nSubscribers_ <= 0 || MAX_SUB < nSubscribers_) {
		std::logic_error description("Range_Error-- Could Not Remove the Subscriber");
		throw;
	} else {
		std::regex pattern(id);
		for (int i = 0; i < nSubscribers_; i++) {
			if (regex_match(subscribers_[i]->getId(), pattern)) {
				for (int j = i; j < nSubscribers_; j++) {
					subscribers_[j] = subscribers_[j + 1];
				}
				subscribers_[nSubscribers_ - 1] = nullptr;
				nSubscribers_--;
				continue;
			}
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
	if (nBooks_ <= 0 || MAX_BOOK < nBooks_) {
		std::logic_error description("Range_Error-- Could Not Remove the Book");
		throw;
	} else {
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
}

// method searchTitle(const string)
// param[in]: pattern (const string&)
// param[out]: void
void Library::searchTitle(const std::string &str) {
	if (nBooks_ <= 0 || MAX_BOOK < nBooks_) {
		std::logic_error description("Range_Error-- Could Not run the searchTitle");
		throw;
	} else {
		bool isFound = false;
		std::regex pattern(str);
		for (int i = 0; i < nBooks_; i++) {
			if (regex_search(books_[i]->getTitle(), pattern)) {
				isFound = true;
				books_[i]->print();
			}
		}

		if (!isFound) {
			std::cout << "\n!!! Could not find a book with Title:  " << str << " !!!\n";
		}

	}
}

// method searchQuote(const string)
// param[in]: book_quote (const string)
// param[out]: void
void Library::searchQuote(const std::string &book_quote) {
	if (nBooks_ <= 0 || MAX_BOOK < nBooks_) {
		std::logic_error description("Range_Error-- Could Not run the searchQuote");
		throw;
	} else {
		bool isFound = false;
		std::regex pattern(book_quote);
		for (int i = 0; i < nBooks_; ++i) {
			if (regex_search(books_[i]->getQuote(), pattern)) {
				isFound = true;
				books_[i]->print();
			}
		}
		if (!isFound) {
			std::cout << "\n!!! Could not find a book with Quote: " << book_quote << "!!!\n";
		}

	}
}


// method sortSubscriber(unsigned int option)
// param[in]: option (unsigned int)
// param[out]: void
void Library::sortSubscriber(unsigned int option) {
	if (nSubscribers_ <= 0 || MAX_SUB < nSubscribers_) {
		std::logic_error description("Range_Error-- Could Not run the sortSubscriber");
		throw;
	} else {
		auto pass = 1;
		switch (option) {
			case 1: // sort by id_
				while (pass < nSubscribers_) {
					for (int i = 0; i < nSubscribers_ - 1; i++) {
						if (subscribers_[i]->getId() > subscribers_[i + 1]->getId()) {
							Library::swapSubscriber(*subscribers_[i], *subscribers_[i + 1]);
						}
					}
					pass++;
				}
				break;
			case 2: // sort by firstName_
				while (pass < nSubscribers_) {
					for (int i = 0; i < nSubscribers_ - 1; i++) {
						if (subscribers_[i]->getFirstName() > subscribers_[i + 1]->getFirstName()) {
							Library::swapSubscriber(*subscribers_[i], *subscribers_[i + 1]);
						}
					}
					pass++;
				}
				break;
			case 3: // sort by lastName_
				while (pass < nSubscribers_) {
					for (int i = 0; i < nSubscribers_ - 1; i++) {
						if (subscribers_[i]->getLastName() > subscribers_[i + 1]->getLastName()) {
							Library::swapSubscriber(*subscribers_[i], *subscribers_[i + 1]);
						}
					}
					pass++;
				}
				break;
			case 4: // sort by age_
				while (pass < nSubscribers_) {
					for (int i = 0; i < nSubscribers_ - 1; i++) {
						if (subscribers_[i]->getAge() > subscribers_[i + 1]->getAge()) {
							Library::swapSubscriber(*subscribers_[i], *subscribers_[i + 1]);
						}
					}
					pass++;
				}
				break;
			default:
				while (pass < nSubscribers_) {
					for (int i = 0; i < nSubscribers_ - 1; i++) {
						if (subscribers_[i]->getId() > subscribers_[i + 1]->getId()) {
							Library::swapSubscriber(*subscribers_[i], *subscribers_[i + 1]);
						}
					}
					pass++;
				}
		}
	}
}

// method swapSubscriber(Subscriber& sub1, Subscriber& sub2)
// params[in]: sub1 (Subscriber&)m sub2 (Subscriber&)
// param[out]: void
void Library::swapSubscriber(Subscriber &sub1, Subscriber &sub2) {
	std::swap(sub1, sub2);
}

void Library::sortBook(unsigned int option) {
	if (nBooks_ <= 0 || MAX_BOOK < nBooks_) {
		std::logic_error description("Range_Error-- Could Not run the sortSubscriber");
		throw;
	} else {
		auto pass = 1;
		switch (option) {
			case 1: // sort by quote_
				while (pass < nBooks_) {
					for (int i = 0; i < nBooks_ - 1; i++) {
						if (books_[i]->getQuote() > books_[i + 1]->getQuote()) {
							Library::swapBook(*books_[i], *books_[i + 1]);
						}
					}
					pass++;
				}
				break;
			case 2: // sort by title_
				while (pass < nBooks_) {
					for (int i = 0; i < nBooks_ - 1; i++) {
						if (books_[i]->getTitle() > books_[i + 1]->getTitle()) {
							Library::swapBook(*books_[i], *books_[i + 1]);
						}
					}
					pass++;
				}
				break;
			case 3: // sort by year_
				while (pass < nBooks_) {
					for (int i = 0; i < nBooks_ - 1; i++) {
						if (books_[i]->getYear() > books_[i + 1]->getYear()) {
							Library::swapBook(*books_[i], *books_[i + 1]);
						}
					}
					pass++;
				}
				break;
			case 4: // sort by minReaderAge_
				while (pass < nBooks_) {
					for (int i = 0; i < nBooks_ - 1; i++) {
						if (books_[i]->getMinReaderAge() > books_[i + 1]->getMinReaderAge()) {
							Library::swapBook(*books_[i], *books_[i + 1]);
						}
					}
					pass++;
				}
				break;
			default:
				while (pass < nBooks_) {
					for (int i = 0; i < nBooks_ - 1; i++) {
						if (books_[i]->getQuote() > books_[i + 1]->getQuote()) {
							Library::swapBook(*books_[i], *books_[i + 1]);
						}
					}
					pass++;
				}
		}
	}
}

// method swapBook(Book& book1, Book& book2)
// params[in]: book1 (Book&), book2 (Book&)
// param[out]: void
void Library::swapBook(Book &book1, Book &book2) {
	std::swap(book1, book2);
}


// method borrowBook(sting& subscriber_id, string book_quote, unsigned int returnDate)
// params[in]: subscriber_id (string), book_quote(string), returnDate (unsigned int)
// param[out]: isBorrow (bool)
bool Library::borrowBook(const std::string &subscriber_id, const std::string &book_quote, unsigned int return_date) {
	// checking to be done before borrowing a book
	// 1. the book is available
	// 2. subscriber_age >= book_minimalReaderAge
	// 3. subscriber has not borrowed the book
	// 4. subscriber does not exceed the limit of borrowing
	//std::regex patternSub(subscriber_id);
	//std::regex patternBook(book_quote);


	// 1. Checking that the book is available
	bool isAvailable = false;
	int indexBook = 0;
	for (int j = 0; j < nBooks_; j++) {
		if (books_[j]->getQuote() == book_quote && books_[j]->getNAvailables() > 0) {
			indexBook = j; // index found
			isAvailable = true; // book is available
			break;
		}
	}

	// 2. Checking the subscriber_age >= book_minimalReaderAge --searching the index of a subscriber based of the subscriber id in the list subscribers_
	bool isOlder = false;
	int indexSub = 0;
	for (int i = 0; i < nSubscribers_; i++) {
		if (subscribers_[i]->getId() == subscriber_id && subscribers_[i]->getAge() >= books_[indexBook]->getMinReaderAge()) {
			indexSub = i; // index found
			isOlder = true;
			break;
		}
	}

	// 3. Checking that the subscriber has the book
	bool hasBook = false;
	for (int k = 0; k < nBorrows_; k++) {
		if (borrows_[k]->getSubscriber()->getId() == subscriber_id && borrows_[k]->getBook()->getQuote() == book_quote) {
			hasBook = true; // the subscriber has a book
			break;
		}
	}

	// 4. Checking that the subscriber does not exceed the limit of two books to borrow
	const unsigned int N_MAX_BORROW = 2;
	unsigned int counter = 0;
	bool hasExceedLimit = false;
	for (int j = 0; j < nBorrows_; j++) {
		if (borrows_[j]->getSubscriber()->getId() == subscriber_id) {
			counter += 1;
			if (counter > N_MAX_BORROW) {
				hasExceedLimit = true;
				break;
			}
		}
	}

	// 5. Initiate the borrowing process
	std::shared_ptr<Subscriber> sub = nullptr;
	std::shared_ptr<Book> book = nullptr;
	std::shared_ptr<Borrow> borrow = nullptr;
	bool isBorrow = false;
	if (isAvailable && isOlder && !hasBook && !hasExceedLimit) { // condition for allowing a subscriber to borrow a book
		// creating a pointer that point to a subscriber by retrieving the subscriber data from the list subscribers_
		sub = std::make_shared<Subscriber>(subscribers_[indexSub]->getId(),
		                                   subscribers_[indexSub]->getFirstName(),
		                                   subscribers_[indexSub]->getLastName(),
		                                   subscribers_[indexSub]->getAge());

		// creating a pointer that points to a book by retrieving the book data from the list books_
		book = std::make_shared<Book>(books_[indexBook]->getQuote(),
		                              books_[indexBook]->getTitle(),
		                              books_[indexBook]->getYear(), books_[indexBook]->getMinReaderAge(), 1);
		// creating a pointer that points to a Borrow
		borrow = std::make_shared<Borrow>(sub, book, return_date);
		borrows_[nBorrows_++] = &*borrow; // add a borrow to the list borrows_
		books_[indexBook]->setNAvailables(books_[indexBook]->getNAvailables() - 1); // decreasing the number of books available by one
		isBorrow = true; // confirm that the book is borrowed
	}

	return isBorrow;
}

// method returnBook(const string& subscriber_id, const string& book_quote)
// params[in]: subscriber_id (const string&), book_quote (const string&)
// param[out]: isReturned (bool)
bool Library::returnBook(const std::string &subscriber_id, const std::string &book_quote) {
	bool isReturned = false;
	std::regex patternSub(subscriber_id);
	std::regex patternBook(book_quote);

	for (int i = 0; i < nBorrows_; ++i) {
		if (regex_match(borrows_[i]->getSubscriber()->getId(), patternSub) && regex_match(borrows_[i]->getBook()->getQuote(), patternBook)) {
			//delete borrows_[i];
			borrows_[i] = nullptr;
			isReturned = true;
			nBorrows_--;
			break;
		}
	}

	for (int j = 0; j < nBooks_; ++j) {
		if (regex_match(books_[j]->getQuote(), patternBook) && isReturned) {
			books_[j]->setNAvailables(books_[j]->getNAvailables() + 1);
		}
	}

	return isReturned;
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

	std::cout << "\nPrinting Borrows\n";
	if (0 < nBorrows_ && nBorrows_ < MAX_BORROW) {
		for (int i = 0; i < nBorrows_; ++i) {
			std::cout << i << " : ";
			borrows_[i]->print();
		}
	} else {
		std::cout << "\nThe Library does not have a borrow\n";
		//throw Library::BadLibrary();

	}
}

void Library::infoSubscriber(const std::string &subscriber_id) const {
	std::cout << "\nInformation on a Subscriber: \n";
	std::regex pattern(subscriber_id);
	for (int i = 0; i < nSubscribers_; ++i) {
		if (regex_match(subscribers_[i]->getId(), pattern)) {
			subscribers_[i]->print();
			break;
		}
	}

	for (int j = 0; j < nBorrows_; ++j) {
		if (regex_match(borrows_[j]->getSubscriber()->getId(), pattern)) {
			borrows_[j]->print();
		}
	}

}








