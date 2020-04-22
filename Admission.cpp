#include "Admission.h"

Admission::Admission() = default;

Admission::Admission(const Admission & admission)
{
	book_ = Book(admission.book_.getAuthor(), admission.book_.getTitle(), admission.book_.getTitle());
	libraryTitle_ = admission.libraryTitle_;
}

Admission::Admission(const Book & book, const string & libraryTitle)
{
	book_ = book;
	libraryTitle_ = libraryTitle;
}

void Admission::setBook(const Book& book)
{
	book_ = book;
}

void Admission::setLibraryTitle(const string& libraryTitle)
{
	libraryTitle_ = libraryTitle;
}

Book* Admission::getBook()
{
	return &book_;
}

string Admission::getLibraryTitle() const
{
	return libraryTitle_;
}

bool operator < (const Admission& first, const Admission& second)
{
	return first.libraryTitle_ < second.libraryTitle_;
}

ostream& operator<<(ostream& os, const Admission& admission)
{
	os << admission.book_ << setw(32) << left << admission.libraryTitle_
		<< "|";
	return os;
}

Admission::~Admission() = default;
