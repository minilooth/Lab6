#include "Book.h"

Book::Book() = default;

Book::Book(const string & author, const string & title, const string & genre)
{
	author_ = author;
	title_ = title;
	genre_ = genre;
}

void Book::setAuthor(const string& author)
{
	author_ = author;
}

void Book::setTitle(const string& title)
{
	title_ = title;
}

void Book::setGenre(const string& genre)
{
	genre_ = genre;
}

string Book::getAuthor() const
{
	return author_;
}

string Book::getTitle() const
{
	return title_;
}

string Book::getGenre() const
{
	return genre_;
}

Book::~Book() = default;

ostream& operator<<(ostream& os, const Book& book)
{
	os << "|" << setw(22) << left << book.getAuthor()
		<< "|" << setw(26) << left << book.getTitle()
		<< "|" << setw(26) << left << book.getGenre()
		<< "|";
	return os;
}
