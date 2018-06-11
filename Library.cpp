// Library.cpp: Cpp file for the implementation of the class Library
// Created by pam on 10/06/18.
//

#include "Library.h"

// Ctor
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

Library::~Library() {

	for (int i = 0; i < MAX_SUB; i++) {
		if(subscribers_[i] != nullptr){
			//delete subscribers_[i];
			subscribers_[i] = nullptr;
		}

	}

	delete[] subscribers_;
	subscribers_ = nullptr;

	for (int j = 0; j < MAX_BOOK; j++) {
		if(books_[j] != nullptr){
			//delete books_[j];
			books_[j] = nullptr;
		}
	}

	delete[] books_;
	books_ = nullptr;

	for (int k = 0; k < MAX_BORROW; k++) {
		if(borrows_[k] != nullptr){
			//delete borrows_[k];
			borrows_[k] = nullptr;
		}
	}

	delete[] borrows_;
	borrows_ = nullptr;

}

void Library::addSubscriber(Subscriber subscriber) {
	subscribers_[nSubscribers_++] = &subscriber;
}

void Library::removeSubscriber(const std::string& id) {
	for (int i = 0; i < nSubscribers_; i++) {
		if( id == subscribers_[i]->getId()){
			for (int j = i; j < nSubscribers_ ; j++) {
				subscribers_[j] = subscribers_[j+1];
			}
			subscribers_[nSubscribers_ -1] = nullptr;
			break;
		}
	}
}
