/**
   main.cpp: Cpp file Controller for the lmis project.
   Author(s): Pierre Abraham Mulamba.
   Date of creation (modification): 2018/06/10 (2018/06/10).
   Description: Integration testing of four classes -- Subscriber, Book, Borrow, and Library.
   Usage: Controller/Driver.
   Compilation: Makefile provided.
   Run: ./lmis
*/

#include "Main.h"

int main(int argc, char *argv[])
{
  try {
    //system("clear");
    const std::string version = {"20180625 LTS"};
    const std::string program = {argv[0]};
    std::string program1(program, 2, program.size());
    Title title(program1, version);
    
    std::cout << "\nLIBRARY MANAGEMENT INVENTORY SYSTEM.\n"
	         << "-----INTEGRATION TEST PROGRAM.-------\n";
    auto begin = clock();
    Library library; // creation of an instance of a Library
    
    Subscriber sub1 = Subscriber("1839456", "John", "Doe", 23, "12345");
    Subscriber sub2 = Subscriber("1630236", "Nicolas", "Gagnon", 8, "67891");
    Subscriber sub3 = Subscriber("1268348", "Martin", "Tremblay", 18, "10112");
    
    // Adding Subscribers instances to the library
    library.addSubscriber(sub1);
    sub1.printIdCard();
    
    library.addSubscriber(sub2);
    sub2.printIdCard();
    
    library.addSubscriber(sub3);
    sub3.printIdCard();
    
    // Creation of Books instances
    std::shared_ptr<Book> book = std::make_shared<Book>("HB514", "Bjh D++", 2010, 9, 4); // ("GA403", "Big C++", 2009, 8, 3);
    std::shared_ptr<Book> book1 = std::make_shared<Book>("GA403", "Big C++", 2009, 8, 3); // ("GA403", "Big C++", 2009, 8, 3)
    std::shared_ptr<Book> book2 = std::make_shared<Book>("QA203", "Calcul a plusieurs variables partie 1", 2011, 3, 2);
    std::shared_ptr<Book> book3 = std::make_shared<Book>("QA204", "Calcul a plusieurs variables partie 2", 2011, 3, 2);
    std::shared_ptr<Book> book4 = std::make_shared<Book>("AC409", "Le chateau d'Ortrante", 1764, 16, 1);
    std::shared_ptr<Book> book5 = std::make_shared<Book>("BD302", "Harry Potter et le prisionier d'Azkaban", 1999, 3, 1);
    std::shared_ptr<Book> book6 = std::make_shared<Book> ("CE413", "Ibssz Qpuufs et le prisionier c'balbcbo", 2000, 4, 2);
    
    std::cout << "\n";
    // Adding Books instances to the library
    library.addBook(book);
    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);
    library.addBook(book4);
    library.addBook(book5);
    library.addBook(book6);
    

    // Sorting the library items
    //unsigned short subscriber_sort_option = {2}; // sorting options 1. sort by id, 2. sort by first name, 3. sort by last name, 4. sort by age
    //library.sortSubscriber(subscriber_sort_option);
    //library.print();

    library.print();

    /*******************************************************************/
    /*                      BEGINNING OF TESTS                         */
    /* Les modifications restantes sont a la fin de la fonction main.  */
    /*******************************************************************/
    // Search by title
    library.searchTitle("Calcul");
    
    std::cout << '\n';
    // Search by quote
    library.searchQuote("AC409");
    library.searchQuote("BD302");
    library.searchQuote("QA204");
    library.searchQuote("QA203");
    library.searchQuote("AC209");

    std::cout << '\n';
    
    // Testing the Borrowing
    // should fail because Nicolas is too young
    if (library.borrowBook({"1630236"}, {"AC409"}, {"160204"})) {
      std::cout << "AC409 borrowed by 1630236\n";
    } else {
      std::cout << "!!!Borrowing failed!!!\n";
    }
    
    // should work
    if (library.borrowBook({"1630236"}, {"BD302"}, {"160204"})) {
      std::cout << "BD302 borrowed by 1630236\n";
    } else {
      std::cout << "!!!Borrowing failed!!!\n";
    }
    
    // Should not work because the book is not available anymore
    if (library.borrowBook({"1839456"}, {"BD302"}, {"160204"})) {
      std::cout << "BD302 borrowed by 1839456\n";
    } else {
      std::cout << "!!!Borrowing failed!!!\n";
    }
    
    // Shoud not work because the subscriber has the book
    if (library.borrowBook({"1630236"}, {"BD302"}, {"160204"})) {
      std::cout << "BD302 borrowed by 1630236\n";
    } else {
      std::cout << "!!!Borrowing failed!!!\n";
    }
    
    // Should work
    if (library.borrowBook("1630236", "QA204", {"160204"})) {
      std::cout << "QA204 borrowed by 1630236\n";
    } else {
      std::cout << "!!!Borrowing failed!!!\n";
    }
    
    // Should not work because the subscriber has reached the limit of books to borrow
    if (library.borrowBook("1630236", "QA203", {"160204"})) {
      std::cout << "QA203 borrowed by 1630236\n";
    } else {
      std::cout << "!!!Borrowing failed!!!\n";
    }
    
    // Info of a subscriber before returning a book
    std::cout << "\nINFO OF A SUBSCRIBER BEFORE RETURNING A BOOK.\n";
    library.infoSubscriber("1630236");
    
    std::cout << "\nTESTS ON BOOKS RETURN.\n";
    
    // should work
    if (library.returnBook("1630236", "QA204")) {
      std::cout << "QA204 return by 1630236\n";
    } else {
      std::cout << "!!!Returning of BD302 by 1630236 Failed!!!\n";
    }
    
    // Should not work because the subscriber never borrowed a book
    if (library.returnBook("1839456", "QA203")) {
      std::cout << "QA203 return by 1839456\n";
    } else {
      std::cout << "!!!Returning failed!!!\n";
    }
    
    // Info of a Subscriber after returning a book
    std::cout << "\nINFOR OF A SUBSCRIBER AFTER RETURNING A BOOK.\n";
    library.infoSubscriber("1630236");
    //library.print();
    /*******************************/
    /*       END OF TESTS          */
    /*******************************/
    
    // Free dynamically allocated memory (the heap) if necessary
    
    std::cout << "\nEND OF TESTS\n";
    std::cout << "PROGRAM ENDED SUCCESSFULLY!\n\n";
    
    auto end = clock();
    auto elapsed_seconds = double(end - begin) / CLOCKS_PER_SEC;
    std::cout << "elapsed: " << elapsed_seconds << '\n';
    
    // Free resoucres
       
    return 0;
  }
  catch (Subscriber::BadSubscriber &e) {
    std::cerr << e.exceptionMsg << '\n';
  }
  catch (Book::BadBook &e) {
    std::cerr << e.exceptionMsg << '\n';
  }
  catch (Library::BadLibrary &e) {
    std::cerr << e.exceptionMsg << '\n';
  }
  catch (std::logic_error &e) {
    std::cout << e.what() << '\n';
  }
  catch (...) {
    std::cerr << "Unknown Exception thrown\n";
  }
}
