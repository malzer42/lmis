/**
   Library.cpp: Cpp file for the implementation of the class Library.
   Author(s): Pierre Abraham Mulamba.
   Date of creation (modification): 2018/06/10 (2018/06/12).
   Description: The class Library is an aggregation of three classes: Subscriber, Book, and Borrow.
   Usage: To create an instance of a Library.
   Compilation: Makefile provided.
   Run:
   */

#include "Library.h"

// Ctor to create and initialize a class Library
// params[in]: void
// param[out]: void
Library::Library() : subscribers_{nullptr}, nSubscribers_{0}, books_{nullptr}, nBooks_{0},
		     borrows_{nullptr}, nBorrows_{0}
{
  subscribers_ = {new Subscriber* [MAX_SUB]};
  books_ = {new Book* [MAX_BOOK]};
  borrows_ = {new Borrow* [MAX_BORROW]};

  for (unsigned int i = 0; i < MAX_SUB; i++) {
    subscribers_[i] = {nullptr};
  }

  for (unsigned int j = 0; j < MAX_BOOK; j++) {
    books_[j] = {nullptr};
  }
  
  for (unsigned int k = 0; k < MAX_BORROW; k++) {
    borrows_[k] = {nullptr};
  }
}

// Copy ctor
// param[in]: library (const Library&)
// param[out] void
Library::Library(const Library &library) : subscribers_{library.subscribers_}, nSubscribers_{library.nSubscribers_},
					   books_{library.books_}, nBooks_{library.nBooks_},
					   borrows_{library.borrows_}, nBorrows_{library.nBorrows_}
{

}

// Move ctor
// params[in]: library (Library&&)
// param[out]: void
Library::Library(Library &&library)noexcept : subscribers_{nullptr}, nSubscribers_{0},
					      books_{nullptr}, nBooks_{0},
					      borrows_{nullptr}, nBorrows_{0}
{
  subscribers_ = {library.subscribers_};
  nSubscribers_ = {library.nSubscribers_};
  books_ = {library.books_};
  nBooks_ = {library.nBooks_};
  borrows_ = {library.borrows_};
  nBorrows_ = {library.nBorrows_};
  library.subscribers_ = {nullptr};
  library.nSubscribers_ = {0};
  library.books_ = {nullptr};
  library.nBooks_ = {0};
  library.borrows_ = {nullptr};
  library.nBorrows_ = {0};
}

// Copy assignment operator
// param[in]: library (const Library&)
// param[out]: *this (Library&)
Library &Library::operator=(const Library &library)
{
  if (this != &library) {
    subscribers_ = {library.subscribers_};
    nSubscribers_ = {library.nSubscribers_};
    books_ = {library.books_};
    nBooks_ = {library.nBooks_};
    borrows_ = {library.borrows_};
    nBooks_ = {library.nBorrows_};
  }
  return *this;
}

// Move assignment operator
// param[in]: library (Library&&)
// param[out]: void
Library &Library::operator=(Library &&library) noexcept
{
  subscribers_ = {nullptr};
  nSubscribers_ = {0};
  books_ = {nullptr};
  nBooks_ = {0};
  borrows_ = {nullptr};
  nBorrows_ = {0};
  
  if (this != &library) {
    subscribers_ = {library.subscribers_};
    nSubscribers_ = {library.nSubscribers_};
    books_ = {library.books_};
    nBooks_ = {library.nBooks_};
    borrows_ = {library.borrows_};
    nBooks_ = {library.nBorrows_};
    
    library.subscribers_ = {nullptr};
    library.nSubscribers_ = {0};
    library.books_ = {nullptr};
    library.nBooks_ = {0};
    library.borrows_ = {nullptr};
    library.nBorrows_ = {0};
  }
  return *this;
}




// Dtor to cleanup the heap
// params[in]: void
// param[out]: void
Library::~Library()
{
  
  for (unsigned int i = 0; i < MAX_SUB; i++) {
    if(subscribers_[i] != nullptr){
      subscribers_[i] = {nullptr};
    }
  }

  delete[] subscribers_;
  subscribers_ = {nullptr};
  
  for (unsigned int j = 0; j < MAX_BOOK; j++) {
    if(books_[j] != nullptr){
      books_[j] = {nullptr};
    }
  }
  
  delete[] books_;
  books_ = {nullptr};
  
  for (unsigned int k = 0; k < MAX_BORROW; k++) {
    if(borrows_[k] != nullptr){
      borrows_[k] = {nullptr};
    }
  }

  delete[] borrows_;
  borrows_ = {nullptr};
}

// method to add an instance of a Subscriber to a library
// param[in]: subscriber (Subscriber)
// param[out]: void
void Library::addSubscriber(Subscriber& subscriber)
{
  std::cout << "Adding: #" << subscriber.getId() << ".\n";
  bool isPresent = {true};
  if(nSubscribers_ == 0){
    subscribers_[nSubscribers_++] = {&subscriber};
    std::cout << "Subscriber: #" << subscriber.getId() << " added successfully!\n";
  }
  else{
    isPresent = {false};
    // Loop to check an existing subscriber in the system
    std::regex e(subscriber.getId());
    for (unsigned int i = {0}; i < nSubscribers_; ++i) { // Loop through the list of subscribers to check if the subscriber is or not in the list.
      if (std::regex_match(subscribers_[i]->getId(), e)) {
	std::cout << "!!! Subscriber: #" << subscriber.getId() << " failed!!!\n";
	std::cout << subscriber.getFname() << ", " << subscriber.getLname()<<". Already exit in the Library!!!\n";
	isPresent = {true};
	break;
      }
    }
  }
  
  // Add a subscriber if he does not exist in the system
  if ((!isPresent) && (nSubscribers_ < MAX_SUB)) {
    subscribers_[nSubscribers_++] = {&subscriber};
    std::cout << "Subscriber: #" << subscriber.getId() << " added successfully!\n";
  }
}


// method to remove an instance of a Subscriber to a Library based on the id of a subscriber
// param[in]: id (string)
// param[out]: void
void Library::removeSubscriber(const std::string &subscriber_id)
{
  std::cout << "\nRemoving the Subscriber: " << subscriber_id << ".\n";
  if (nSubscribers_ <= 0 || MAX_SUB < nSubscribers_) {
    std::logic_error description("Range_Error-- Could Not Remove the Subscriber");
    throw;
  } else {
    std::regex e(subscriber_id);
    for (unsigned int i = 0; i < nSubscribers_; i++) {
      if (std::regex_match(subscribers_[i]->getId(), e)) {
	for (unsigned int j = i; j < nSubscribers_; j++) {
	  subscribers_[j] = {subscribers_[j + 1]};
	}
	//std::swap(subscribers_[i], subscribers_[nSubscribers_ - 1]);
	subscribers_[nSubscribers_ - 1] = {nullptr};
	nSubscribers_--;
	continue;
      }
    }
  }
}

// method to add an instance of a Book to the library
// param[in]: book (Book)
// param[out]: void
void Library::addBook(std::unique_ptr<Book>& book)
{
 
  std::cout << "Adding the book: " << book->getQuote() << ".\n";
  bool isPresent = {true};
  if(nBooks_ == 0){
    books_[nBooks_++] = {&*book};
    std::cout << "Book: " << book->getQuote() << " added successfully!\n";
  }
  else{
    std::regex e(book->getQuote());   
    isPresent = {false};
    // Loop to check an existing book in the system
    for (unsigned int i = 0; i < nBooks_; ++i) {
      if (std::regex_match(books_[i]->getQuote(), e)) {
	std::cout << "!!! Book: " << book->getQuote() << " failed!!!\n";
	std::cout << book->getQuote() << ", " << book->getTitle()<<". Already exit in the Library!!!\n";
	isPresent = {true};
	break;
      }
    }
  }

  // Add an instance of a book if it does not exist in the system
  if ((!isPresent) && (nBooks_ < MAX_BOOK)) {
    books_[nBooks_++] = {&*book};
    std::cout << "Book: " << book->getQuote() << " added successfully!\n";
  }
}

// method to remove an instance of a Book from the library based on the quote
// param[in]: quote (string)
// parm[out]: void
void Library::removeBook(const std::string &book_quote)
{
  std::cout << "Removing the Book :" << book_quote << "\n\n";
  if (nBooks_ <= 0 || MAX_BOOK < nBooks_) {
    std::logic_error description("Range_Error-- Could Not Remove the Book");
    throw;
  } else {
    std::regex e(book_quote);
    for (unsigned int i = 0; i < nBooks_; i++) { // seek and destroy
      if (std::regex_match(books_[i]->getQuote(), e)) {
	for (unsigned int j = i; j < nBooks_; j++) {
	  books_[j] = {books_[j + 1]};
	}
	//std::swap(books_[i], books_[nBooks_ - 1]);
	books_[nBooks_ - 1] = {nullptr};
	nBooks_--;
	continue;
      }
    }
  }
}

// method searchTitle(const string)
// param[in]: pattern (const string&)
// param[out]: void
void Library::searchTitle(const std::string &str_title)
{
  std::cout << "\nSearching by title...: " << str_title << '\n';
  if (nBooks_ <= 0 || MAX_BOOK < nBooks_) {
    std::logic_error description("Range_Error-- Could Not run the searchTitle");
    throw;
  }
  else {
    std::regex pattern(str_title);
    bool isFound = {false};
    for (unsigned int i = 0; i < nBooks_; i++) {
      if (std::regex_search(books_[i]->getTitle(), pattern)) {
	isFound = {true};
	books_[i]->print();
      }
    }
    
    if (!isFound) {
      std::cout << "\n!!! Could not find a book with Title:  " << str_title << " !!!\n";
    }
  }
}

// method searchQuote(const string)
// param[in]: book_quote (const string)
// param[out]: void
void Library::searchQuote(const std::string &book_quote)
{
  std::cout << "Searching by quote...: " << book_quote << '\n';
  if (nBooks_ <= 0 || MAX_BOOK < nBooks_) {
    std::logic_error description("Range_Error-- Could Not run the searchQuote");
    throw;
  }
  else {
    std::regex pattern(book_quote);
    bool isFound = {false};
    for (unsigned int i = 0; i < nBooks_; ++i) {
      if (std::regex_search(books_[i]->getQuote(), pattern)) {
	isFound = {true};
	books_[i]->print();
      }
    }
    if (!isFound) {
      std::cout << "!!! Could not find a book with Quote: " << book_quote << "!!!\n";
    }
  }
}


// method sortSubscriber(unsigned int option)
// param[in]: option (unsigned int)
// param[out]: void
void Library::sortSubscriber(unsigned int option)
{
  if (nSubscribers_ <= 0 || MAX_SUB < nSubscribers_) {
    std::logic_error description("Range_Error-- Could Not run the sortSubscriber");
    throw;
  }
  else {
    unsigned int pass = 1;
    switch (option) {
    case 1: // sort by id_
      std::cout << "\nSorting the Subscribers by Id.\n";
      while (pass < nSubscribers_) {
	for (unsigned int i = 0; i < nSubscribers_ - 1; i++) {
	  if (subscribers_[i]->getId() > subscribers_[i + 1]->getId()) {
	    Library::swapSubscriber(*subscribers_[i], *subscribers_[i + 1]);
	  }
	}
	pass++;
      }
      break;
    case 2: // sort by firstName_
      std::cout << "\nSorting the Subscribers by First Name.\n";
      while (pass < nSubscribers_) {
	for (unsigned int i = 0; i < nSubscribers_ - 1; i++) {
	  if (subscribers_[i]->getFname() > subscribers_[i + 1]->getFname()) {
	    Library::swapSubscriber(*subscribers_[i], *subscribers_[i + 1]);
	  }
	}
	pass++;
      }
      break;
    case 3: // sort by lastName_
      std::cout << "\nSorting the Subscribers by Last Name.\n";
      while (pass < nSubscribers_) {
	for (unsigned int i = 0; i < nSubscribers_ - 1; i++) {
	  if (subscribers_[i]->getLname() > subscribers_[i + 1]->getLname()) {
	    Library::swapSubscriber(*subscribers_[i], *subscribers_[i + 1]);
	  }
	}
	pass++;
      }
      break;
    case 4: // sort by age_
      std::cout << "\nSorting the Subscribers by Age.\n";
      while (pass < nSubscribers_) {
	for (unsigned int i = 0; i < nSubscribers_ - 1; i++) {
	  if (subscribers_[i]->getAge() > subscribers_[i + 1]->getAge()) {
	    Library::swapSubscriber(*subscribers_[i], *subscribers_[i + 1]);
	  }
	}
	pass++;
      }
      break;
    default:
      std::cout << "\nSorting the Subscribers by Id.\n";
      while (pass < nSubscribers_) {
	for (unsigned int i = 0; i < nSubscribers_ - 1; i++) {
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
  Subscriber tmp = std::move(sub1);
  sub1 = std::move(sub2);
  sub2 = std::move(tmp);
  //std::swap(sub1, sub2);
}

void Library::sortBook(unsigned int option) {
  if (nBooks_ <= 0 || MAX_BOOK < nBooks_) {
    std::logic_error description("Range_Error-- Could Not run the sortSubscriber");
    throw;
  }
  else {
    unsigned int pass = 1;
    switch (option) {
    case 1: // sort by quote_
      while (pass < nBooks_) {
	for (unsigned int i = 0; i < nBooks_ - 1; i++) {
	  if (books_[i]->getQuote() > books_[i + 1]->getQuote()) {
	    Library::swapBook(*books_[i], *books_[i + 1]);
	  }
	}
	pass++;
      }
      break;
    case 2: // sort by title_
      while (pass < nBooks_) {
	for (unsigned int i = 0; i < nBooks_ - 1; i++) {
	  if (books_[i]->getTitle() > books_[i + 1]->getTitle()) {
	    Library::swapBook(*books_[i], *books_[i + 1]);
	  }
	}
	pass++;
      }
      break;
    case 3: // sort by year_
      while (pass < nBooks_) {
	for (unsigned int i = 0; i < nBooks_ - 1; i++) {
	  if (books_[i]->getYear() > books_[i + 1]->getYear()) {
	    Library::swapBook(*books_[i], *books_[i + 1]);
	  }
	}
	pass++;
      }
      break;
    case 4: // sort by minReaderAge_
      while (pass < nBooks_) {
	for (unsigned int i = 0; i < nBooks_ - 1; i++) {
	  if (books_[i]->getMinReaderAge() > books_[i + 1]->getMinReaderAge()) {
	    Library::swapBook(*books_[i], *books_[i + 1]);
	  }
	}
	pass++;
      }
      break;
    default:
      while (pass < nBooks_) {
	for (unsigned int i = 0; i < nBooks_ - 1; i++) {
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
void Library::swapBook(Book &book1, Book &book2)
{
  Book tmp = std::move(book1);
  book1 = std::move(book2);
  book2 = std::move(book1);
  //std::swap(book1, book2);
}


// method borrowBook(sting& subscriber_id, string book_quote, unsigned int returnDate)
// params[in]: subscriber_id (string), book_quote(string), returnDate (unsigned int)
// param[out]: isBorrow (bool)
bool Library::borrowBook(const std::string& subscriber_id, const std::string& book_quote, const std::string& return_date)
{
  std::cout << "Borrowing of the Book: " << book_quote << " By #" << subscriber_id << ".\n";
  // checking to be done before borrowing a book
  // 1. the book is available
  // 2. subscriber_age >= book_minimalReaderAge
  // 3. subscriber has not borrowed the book
  // 4. subscriber does not exceed the limit of borrowing
  //std::regex patternSub(subscriber_id);
  //std::regex patternBook(book_quote);
  
  
  // 1. Checking that the book is available
  bool isAvailable = {false};
  unsigned int indexBook = {0};
  for (unsigned int i = 0; i < nBooks_; i++) {
    if (books_[i]->getQuote() == book_quote && books_[i]->getNAvailables() > 0) {
      indexBook = {i}; // index found
      isAvailable = {true}; // book is available
      break;
    }
  }

  // 2. Checking the subscriber_age >= book_minimalReaderAge --searching the index of a subscriber based of the subscriber id in the list subscribers_
  bool isOlder = {false};
  unsigned int indexSub = {0};
  for (unsigned int i = 0; i < nSubscribers_; i++) {
    if (subscribers_[i]->getId() == subscriber_id && subscribers_[i]->getAge() >= books_[indexBook]->getMinReaderAge()) {
      indexSub = {i}; // index found
      isOlder = {true};
      break;
    }
  }
  
  // 3. Checking that the subscriber has the book
  bool hasBook = {false};
  for (unsigned int i = 0; i < nBorrows_; i++) {
    if (borrows_[i]->getSubscriber()->getId() == subscriber_id && borrows_[i]->getBook()->getQuote() == book_quote) {
      hasBook = {true}; // the subscriber has a book
      break;
    }
  }
  
  // 4. Checking that the subscriber does not exceed the limit of two books to borrow
  const unsigned int N_MAX_BORROW = {2};
  unsigned int counter = {0};
  bool hasExceedLimit = {false};
  for (unsigned int i = 0; i < nBorrows_; i++) {
    if (borrows_[i]->getSubscriber()->getId() == subscriber_id) {
      counter += 1;
      if (counter >= N_MAX_BORROW) {
	hasExceedLimit = {true};
	break;
      }
    }
  }

  // 5. Initiate the borrowing process
  bool isBorrow = {false};
  if (isAvailable && isOlder && !hasBook && !hasExceedLimit) { // condition for allowing a subscriber to borrow a book
    std::shared_ptr<Borrow> borrow = std::make_shared<Borrow>(subscribers_[indexSub], books_[indexBook], return_date); // add a borrow to the list borrows_
    borrows_[nBorrows_++] = {&*borrow};// {new Borrow(subscribers_[indexSub], books_[indexBook], return_date)}; // add a borrow to the list borrows_

    books_[indexBook]->setNAvailables(books_[indexBook]->getNAvailables() - 1); // decreasing the number of books available by one
    
    isBorrow = {true}; // confirm that the book is borrowed
  }
  
  //delete borrow;
  return isBorrow;
} // There is memory leak because we do not free the resource allocated to create a new Borrow

// method returnBook(const string& subscriber_id, const string& book_quote)
// params[in]: subscriber_id (const string&), book_quote (const string&)
// param[out]: isReturned (bool)
bool Library::returnBook(const std::string &subscriber_id, const std::string &book_quote)
{
  std::cout << "Returning of the Book: " << book_quote << " By #" << subscriber_id << ".\n";
  bool isReturned = {false};
  for (unsigned int i = 0; i < nBorrows_; i++) {
    if (borrows_[i]->getSubscriber()->getId() == subscriber_id && borrows_[i]->getBook()->getQuote() == book_quote) {
      for (unsigned int j = i; j < nBorrows_; j++) {
	borrows_[j] = borrows_[j + 1];
      }
      //std::swap(borrows_[i], borrows_[nBorrows_ - 1]);
      borrows_[nBorrows_ - 1] = {nullptr};
      nBorrows_--;
      isReturned = {true};
      break;
    }
  }

  for (unsigned int i = 0; i < nBooks_; i++) {
    if (books_[i]->getQuote() == book_quote && isReturned) {
      books_[i]->setNAvailables(books_[i]->getNAvailables() + 1);
    }
  }
  return isReturned;
}

// method swapBorrow(Borrow& borrow1, Borrow& borrow2)
// params[in]: borrow1 (Borrow&), borrow2 (Borrow&)
// param[out] void
void Library::swapBorrow(Borrow &borrow1, Borrow &borrow2)
{
  Borrow tmp = std::move(borrow1);
  borrow1 = std::move(borrow2);
  borrow2 = std::move(tmp);
}


// method infoSubscriber(const string subscriber_id)const
// param[in]: subscriber_id (const string&)const
// param[out]: void
void Library::infoSubscriber(const std::string &subscriber_id) const
{
  //std::cout << "\nInformation on a Subscriber: #" << subscriber_id <<".\n";
  for (unsigned int i = 0; i < nBorrows_; i++) {
    if (borrows_[i]->getSubscriber()->getId() == subscriber_id) {
      borrows_[i]->getSubscriber()->print();
      break;
    }
  }

  for (unsigned int i = 0; i < nBorrows_; i++) {
    if (borrows_[i]->getSubscriber()->getId() == subscriber_id) {
      borrows_[i]->print();
    }
  }
}

// method to print out instances of Subscriber, Book, and Borrow contained in the library
// param[in]: void
// param[out]: void
void Library::print() const
{
  std::cout << "\nPrinting Subscribers\n";
  if(0 < nSubscribers_ && nSubscribers_ < MAX_SUB){
    for (unsigned int i = 0; i < nSubscribers_; i++) {
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
    for (unsigned int i = 0; i < nBooks_; i++) {
      std::cout << i << " : ";
      books_[i]->print();
    }
  }
  else{
    std::cout << "\nThe library does not have a book\n";
    throw Library::BadLibrary();
  }

  std::cout << "\nPrinting Borrows\n";
  if (0 < nBorrows_ && nBorrows_ < MAX_BORROW) {
    for (unsigned int i = 0; i < nBorrows_; i++) {
      std::cout << i << " : ";
      borrows_[i]->print();
    }
  }
  else {
    std::cout << "The Library does not have a borrow\n";
  }
}
