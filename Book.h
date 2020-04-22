#pragma once

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Book
{
	string author_;
	string title_;
	string genre_;
public:
	Book();
	Book(const string& author, const string& title, const string& genre);

	void setAuthor(const string& author);
	void setTitle(const string& title);
	void setGenre(const string& genre);

	string getAuthor() const;
	string getTitle() const;
	string getGenre() const;

	friend ostream& operator<< (ostream& os,const Book& book);

	~Book();
};

