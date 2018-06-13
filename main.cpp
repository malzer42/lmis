// main.cpp: Cpp file Controller for the lmis project.
// Author(s): Pierre Abraham Mulamba.
// Date of creation (modification): 2018/06/10 (2018/06/100.
// Description: Integration testing of four classes -- Subscriber, Book, Borrow, and Library.
// Usage: Controller/Driver.
// Compilation: Makefile provided.
// Run: ./lmis


#include <iostream>
#include <chrono>
#include <memory>
#include "Subscriber.h"
#include "Book.h"
#include "Library.h"

int main(int argc, char *argv[]) {
	try {

		auto begin = clock();

		std::cout << "\nCREATION ET AFFICHAGE DES ABONNES\n";
		std::cout << "\nDEVELOPER INFORMATION\n";
		Subscriber sub = Subscriber("102013", "Pierre", "Mulamba", 94);
		sub.repr();
		sub.str();
		sub.print();

		std::cout << "\nSUBSCRIBER OBJECTS INFO\n";
		Subscriber sub1 = Subscriber("1839456", "John", "Doe", 23);
		Subscriber sub2 = Subscriber("1630236", "Nicolas", "Gagnon", 8);
		Subscriber sub3 = Subscriber("1268348", "Martin", "Tremblay", 18);
		Subscriber sub4 = sub1;
		Subscriber sub5 = Subscriber(sub2);
		Subscriber sub6(sub3);
		decltype(sub1) sub7 = sub;

		sub1.print();
		sub2.print();
		sub3.print();
		sub4.print();
		sub5.print();
		sub6.print();
		sub7.print();

		//Subscriber sub0 = Subscriber();
		//sub0.print();
		std::cout << "\nCREATION ET AFFICHAGE DES LIVRES\n";
		std::cout << "\nDEVELOPER INFORMATION\n";
		Book book = Book("PA052", "My Strategy", 1969, 5, 10);
		book.repr();
		book.str();
		book.print();

		std::cout << "\nBOOK OBJECTS INFO\n";
		std::shared_ptr<Book> book1 = std::make_shared<Book>("GA403", "Big C++", 2009, 8, 3);
		std::shared_ptr<Book> book2 = std::make_shared<Book>("QA203", "Calcul a plusieurs variables partie 1", 2011, 3, 2);
		std::shared_ptr<Book> book3 = std::make_shared<Book>("QA204", "Calcul a plusieurs variables partie 2", 2011, 3, 2);
		std::shared_ptr<Book> book4 = std::make_shared<Book>("AC209", "Le Chateau d'ortrante", 1764, 16, 1);
		std::shared_ptr<Book> book5 = std::make_shared<Book>("BD302", "Harry Potter et le prisonier d'Azkaban", 1999, 3, 1);
		//decltype(book1) book6 = book2;

		book1->print();
		book2->print();
		book3->print();
		book4->print();
		book5->print();
		//book6->print();

		std::cout << "\nPROCESSING SUBSCRIBERS AND BOOKS IN THE LIBRARY\n\n";
		Library library;
		library.addSubscriber(sub1);
		library.addSubscriber(sub2);
		library.addSubscriber(sub3);
		library.addSubscriber(sub4);
		library.addSubscriber(sub5);
		library.addSubscriber(sub6);
		library.addSubscriber(sub7);

		std::cout << "\n\n";

		library.addBook(*book1);
		library.addBook(*book2);
		library.addBook(*book3);
		library.addBook(*book4);
		library.addBook(*book5);
		library.addBook(*book1);
		//library.addBook(*book6);

		library.print();

		std::cout << "\nREMOVING A SUBSCRIBER IN THE LIBRARY BASED ON THE ID:\n\n";

		std::string idSubscriber = "1630236";
		std::cout << '#' << idSubscriber << "\n\n";
		library.removeSubscriber(idSubscriber);

		std::cout << "\nREMOVING A BOOK IN THE LIBRARY BASED ON THE QUOTE:\n\n";
		const std::string quoteBook = "QA203";
		std::cout << quoteBook << "\n\n";
		library.removeBook(quoteBook);


		library.print();


		std::cout << "\nProgram Ended Successfully!\n\n";

		auto end = clock();
		auto elapsed_seconds = double(end - begin) / CLOCKS_PER_SEC;
		std::cout << "elapsed: " << elapsed_seconds << '\n';

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
	catch (...) {
		std::cerr << "Unknown Exception thrown\n";
	}
}