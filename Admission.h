#pragma once

#include <iostream>
#include <iomanip>
#include <string>

#include "Book.h"

using namespace std;

class Admission
{
	Book book_;
	string libraryTitle_;
public:
	Admission();
	Admission(const Admission& admission);
	Admission(const Book& book, const string& libraryTitle);

	void setBook(const Book& book);
	void setLibraryTitle(const string& libraryTitle);

	Book* getBook();
	string getLibraryTitle() const;

	friend bool operator < (const Admission& first, const Admission& second);
	friend ostream& operator<<(ostream& os, const Admission& admission);

	~Admission();
};

