#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <list>
#include <queue>
#include <regex>

#include "LibraryHandler.h"

#include "BookNotFoundException.h"
#include "EmptyBooksListException.h"

#include "InvalidInputException.h"

using namespace std;

class Library
{
	queue<Book, list<Book>> books_;

	static Book* editableBook_;

	string title_;
	string city_;
	string address_;

	void editBookTitle();
	void editBookAuthor();
	void editBookGenre();
public:
	Library();
	Library(const string& title, const string& city, const string& address);
	Library(const queue<Book, list<Book>>& books, const string& title, const string& city, const string& address);

	void setBooks(const queue<Book, list<Book>>& books);
	void setTitle(const string& title);
	void setCity(const string& city);
	void setAddress(const string& address);

	void setEditableBook(unsigned id);

	queue<Book, list<Book>> getBooks() const;
	string getTitle() const;
	string getCity() const;
	string getAddress() const;

	void checkAdmissions();
	void showBooks();
	void editBook();
	static void showEditableBook();

	friend ostream& operator<<(ostream& os, Library& library);

	~Library();
};

