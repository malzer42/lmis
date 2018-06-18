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
		//Subscriber sub = Subscriber("102013", "Pierre", "Mulamba", 94);
		//sub.repr();
		//sub.str();
		//sub.print();

		std::cout << "\nSUBSCRIBER OBJECTS INFO\n";
		Subscriber sub1 = Subscriber("1839456", "John", "Doe", 23);
		Subscriber sub2 = Subscriber("1630236", "Nicolas", "Gagnon", 8);
		Subscriber sub3 = Subscriber("1268348", "Martin", "Tremblay", 18);
		//Subscriber sub4 = sub1;
		//Subscriber sub5 = Subscriber(sub2);
		//Subscriber sub6(sub3);
		//decltype(sub1) sub7 = sub;

		sub1.print();
		sub2.print();
		sub3.print();
		//sub4.print();
		//sub5.print();
		//sub6.print();
		//sub7.print();

		//Subscriber sub0 = Subscriber();
		//sub0.print();
		std::cout << "\nCREATION ET AFFICHAGE DES LIVRES\n";
		std::cout << "\nDEVELOPER INFORMATION\n";
		//Book book = Book("PA052", "My Strategy", 1969, 5, 10);
		//book.repr();
		//book.str();
		//book.print();

		std::cout << "\nBOOK OBJECTS INFO\n";
		std::shared_ptr<Book> book1 = std::make_shared<Book>("GA403", "Big C++", 2009, 8, 3);
		std::shared_ptr<Book> book2 = std::make_shared<Book>("QA203", "Calcul a plusieurs variables partie 1", 2011, 3, 2);
		std::shared_ptr<Book> book3 = std::make_shared<Book>("QA204", "Calcul a plusieurs variables partie 2", 2011, 3, 2);
		std::shared_ptr<Book> book4 = std::make_shared<Book>("AC409", "Le Chateau ortrante", 1764, 16, 1);
		std::shared_ptr<Book> book5 = std::make_shared<Book>("BD302", "Harry Potter", 1999, 3, 1);
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
		//library.addSubscriber(sub4);
		//library.addSubscriber(sub5);
		//library.addSubscriber(sub6);
		//library.addSubscriber(sub7);

		std::cout << "\n\n";

		library.addBook(*book1);
		library.addBook(*book2);
		library.addBook(*book3);
		library.addBook(*book4);
		library.addBook(*book5);
		//library.addBook(*book1);
		//library.addBook(*book6);

		//unsigned short option = 0; // sorting options 1. sort by id, 2. sort by first name, 3. sort by last name, 4. sort by age

		std::cout << "\nPRINTING THE LIBRARY WITH SUBSCRIBERS SORTED BY ID and BOOKS SORTED BY QUOTE\n";
		//option = 1;
		//library.sortSubscriber(option);
		//library.sortBook(option);
		library.print();

		//std::cout << "\nPRINTING THE LIBRARY WITH SUBSCRIBERS SORTED BY FIRST NAME and BOOKS SORTED BY TITLE\n";
		//option = 2;
		//library.sortSubscriber(option);
		//library.sortBook(option);
		//library.print();

		/*std::cout << "\nPRINTING THE LIBRARY WITH SUBSCRIBERS SORTED BY LAST NAME and BOOKS SORTED BY YEAR\n";
		option = 3;
		library.sortSubscriber(option);
		library.sortBook(option);
		library.print();

		std::cout << "\nPRINTING THE LIBRARY WITH SUBSCRIBERS SORTED BY AGE and BOOKS SORTED BY READER MINIMAL AGE\n";
		option = 4;
		library.sortSubscriber(option);
		library.sortBook(option);
		library.print();*/

		/*std::cout << "\nREMOVING A SUBSCRIBER IN THE LIBRARY BASED ON THE ID:\n\n";

		std::string idSubscriber = "1630236";
		std::cout << '#' << idSubscriber << "\n\n";
		library.removeSubscriber(idSubscriber);

		std::cout << "\nREMOVING A BOOK IN THE LIBRARY BASED ON THE QUOTE:\n\n";
		const std::string quoteBook = "AC209";
		std::cout << quoteBook << "\n\n";
		library.removeBook(quoteBook);*/


		/*std::cout << "\nPRINTING THE LIBRARY WITH SUBSCRIBERS AND BOOKS SORTED BY DEFAULT OPTION\n";
		option = 5;
		library.sortSubscriber(option);
		library.sortBook(option);
		library.print();*/

		/*******************************************************************/
		/*                      BEGINNING OF TESTS                         */
		/* Les modifications restantes sont a la fin de la fonction main.  */
		/*******************************************************************/
		std::cout << "\nSEARCH BY TITLE...: Calcul\n";
		library.searchTitle("Calcul");

		std::cout << "\nSEARCH BY quote...: AC409\n";
		library.searchQuote("AC409");
		library.searchQuote("BD302");
		library.searchQuote("QA204");
		library.searchQuote("QA203");
		library.searchQuote("AC209");


		std::cout << "\nTESTS ON BORROWING\n";
		// should fail because Nicolas is too young
		if (library.borrowBook("1630236", "AC409", 160204)) {
			std::cout << "AC409 borrowed by 1630236\n";
		} else {
			std::cout << "!!!Borrowing of AC409 by 1630236 failed because Nicolas is too young!!!\n";
		}

		// should work
		if (library.borrowBook("1630236", "BD302", 160204)) {
			std::cout << "BD302 borrowed by 1630236\n";
		} else {
			std::cout << "!!!Borrowing failed!!!\n";
		}

		// Ne devrait pas marcher car le livre n'est pas disponible
		if (library.borrowBook("1839456", "BD302", 160204)) {
			std::cout << "BD302 borrowed by 1839456\n";
		} else {
			std::cout << "!!!Failed borrowing!!!\n";
		}

		// Shoud not work because the subscriber has the book
		if (library.borrowBook("1630236", "BD302", 160204)) {
			std::cout << "BD302 borrowed by 1630236\n";
		} else {
			std::cout << "!!!Borrowing failed!!!\n";
		}

		// Should work
		if (library.borrowBook("1630236", "QA204", 160204)) {
			std::cout << "QA204 borrowed by 1630236\n";
		} else {
			std::cout << "!!!Borrowing failed!!!\n";
		}

		// Ne devrait pas marcher car l'abonn� a atteint la limite de pr�ts
		if (library.borrowBook("1630236", "QA203", 160204)) {
			std::cout << "BD302 borrowed by 1630236\n";
		} else {
			std::cout << "!!!Borrowing failed!!!\n";
		}

		std::cout << "\nINFO ABONNE AVANT RETOUR";
		//library.infoSubscriber("1630236");

		std::cout << "\nTESTS ON BOOK RETURN\n";
		// // Devrait marcher
		if (library.returnBook("1630236", "BD302")) {
			std::cout << "BD302 return by 1630236\n";
		} else {
			std::cout << "!!!Failed return!!!\n";
		}
		// Ne devrait pas marcher car l'abonn� n'a jamais fait ce pr�t
		if (library.returnBook("1839456", "QA203")) {
			std::cout << "QA203 return by 1839456\n";
		} else {
			std::cout << "!!!Failed retun\n";
		}

		std::cout << "\nINFO ABONNE APRES RETOUR\n";
		//library.infoSubscriber("1630236");
		/*******************************/
		/*       FIN DES TESTS         */
		/*******************************/

		// // Liberer les ressources si il le faut
		// // A COMPLETER...




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
	catch (std::logic_error &e) {
		std::cout << e.what() << '\n';
	}
	catch (...) {
		std::cerr << "Unknown Exception thrown\n";
	}
}