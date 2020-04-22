#include "Library.h"

Book* Library::editableBook_ = nullptr;

Library::Library()
{
	editableBook_ = nullptr;
}

Library::Library(const string & title, const string & city, const string & address)
{
	title_ = title;
	city_ = city;
	editableBook_ = nullptr;
	address_ = address;
}

Library::Library(const queue<Book, list<Book>>& books, const string& title, const string& city, const string& address)
{
	books_ = books;
	title_ = title;
	city_ = city;
	address_ = address;
	editableBook_ = nullptr;
}

void Library::setBooks(const queue<Book, list<Book>>& books)
{
	books_ = books;
}

void Library::setTitle(const string& title)
{
	title_ = title;
}

void Library::setCity(const string& city)
{
	city_ = city;
}

void Library::setAddress(const string& address)
{
	address_ = address;
}

void Library::setEditableBook(unsigned id)
{
	list<Book> booksList;

	while (!books_.empty())
	{
		booksList.push_back(books_.front());
		books_.pop();
	}

	unsigned counter = 0;
	while(!booksList.empty())
	{
		++counter;
		books_.push(booksList.front());
		booksList.pop_front();
		if (counter == id)
		{
			editableBook_ = &books_.back();
		}
	}
}

queue<Book, list<Book>> Library::getBooks() const
{
	return books_;
}

string Library::getTitle() const
{
	return title_;
}

string Library::getCity() const
{
	return city_;
}

string Library::getAddress() const
{
	return address_;
}

void Library::checkAdmissions()
{
	if (!LibraryHandler::getAdmissions().empty() && const_cast<Admission&>(LibraryHandler::getAdmissions().top()).getLibraryTitle() == this->title_)
	{
		cout << "У вас имеется новое поступление!" << endl;

		cout << "+----------------------+--------------------------+--------------------------+--------------------------------+" << endl;
		cout << "|      Автор книги     |      Название книги      |        Жанр книги        |       Название библиотеки      |" << endl;
		cout << "+----------------------+--------------------------+--------------------------+--------------------------------+" << endl;

		cout << LibraryHandler::getAdmissions().top() << endl;

		cout << "+----------------------+--------------------------+--------------------------+--------------------------------+" << endl;

		this->books_.push(*const_cast<Admission&>(LibraryHandler::getAdmissions().top()).getBook());
		LibraryHandler::getAdmissions().pop();

		cout << "Поступление успешно принято!" << endl;
	}
	else
	{
		cout << "Новых поступлений нет!" << endl;
	}
}

void Library::showBooks()
{
	try
	{
		if (books_.empty())
		{
			throw EmptyBooksListException();
		}

		cout << "+------+----------------------+--------------------------+--------------------------+" << endl;
		cout << "|  Ид  |      Автор книги     |      Название книги      |        Жанр книги        |" << endl;
		cout << "+------+----------------------+--------------------------+--------------------------+" << endl;

		printQueue(books_);

		cout << "+------+----------------------+--------------------------+--------------------------+" << endl;
	}
	catch (EmptyBooksListException & ex)
	{
		system("cls");
		cout << ex.what() << endl;
	}
}

void Library::editBook()
{
	try
	{
		if (books_.empty())
		{
			throw EmptyBooksListException();
		}

		showBooks();

		string id;
		cout << "Введите ид книги для редактирования: ";
		cin >> id;

		if (!regex_match(id, regex("^[0-9]+$")))
		{
			throw InvalidInputException();
		}

		if (stoul(id) > books_.size())
		{
			throw BookNotFoundException();
		}

		setEditableBook(stoul(id));

		while (true)
		{
			switch (bookEditMenu())
			{
			case BookEditMenuAction::EDIT_AUTHOR:
				system("cls");
				editBookAuthor();
				system("pause");
				break;
			case BookEditMenuAction::EDIT_TITLE:
				system("cls");
				editBookTitle();
				system("pause");
				break;
			case BookEditMenuAction::EDIT_GENRE:
				system("cls");
				editBookGenre();
				system("pause");
				break;
			case BookEditMenuAction::BACK_TO_LIBRARY_MENU:
				editableBook_ = nullptr;
				return;
			default:
				break;
			}
		}
	}
	catch (EmptyBooksListException & ex)
	{
		system("cls");
		cout << ex.what() << endl;
		system("pause");
	}
	catch (BookNotFoundException & ex)
	{
		system("cls");
		cout << ex.what() << endl;
		system("pause");
	}
	catch (InvalidInputException & ex)
	{
		system("cls");
		cout << ex.what() << endl;
		system("pause");
	}
}

void Library::editBookTitle()
{
	try
	{
		showEditableBook();

		string title;
		cout << "Введите новое название книги: " << endl;
		cin >> title;

		if (!regex_match(title, regex("^[a-zA-Zа-яА-Я]+$")))
		{
			throw InvalidInputException();
		}

		editableBook_->setTitle(title);

		system("cls");
		showEditableBook();
		cout << "Название книги успешно изменено!" << endl;
	}
	catch (InvalidInputException & ex)
	{
		system("cls");
		showEditableBook();
		cout << ex.what() << endl;
	}
}

void Library::editBookAuthor()
{
	try
	{
		showEditableBook();

		string author;
		cout << "Введите нового автора книги: ";
		cin >> author;

		if (!regex_match(author, regex("^[a-zA-Zа-яА-Я.]+$")))
		{
			throw InvalidInputException();
		}

		editableBook_->setAuthor(author);

		system("cls");
		showEditableBook();
		cout << "Автор книги успешно изменен!" << endl;
	}
	catch (InvalidInputException & ex)
	{
		system("cls");
		showEditableBook();
		cout << ex.what() << endl;
	}
}

void Library::editBookGenre()
{
	try
	{
		showEditableBook();

		string genre;
		cout << "Введите новый жанр книги: ";
		cin >> genre;

		if (!regex_match(genre, regex("^[a-zA-Zа-яА-Я]+$")))
		{
			throw InvalidInputException();
		}

		editableBook_->setGenre(genre);

		system("cls");
		showEditableBook();
		cout << "Жанр книги успешно изменен!" << endl;
	}
	catch (InvalidInputException & ex)
	{
		system("cls");
		showEditableBook();
		cout << ex.what() << endl;
	}
}

void Library::showEditableBook()
{
	cout << "+----------------------+--------------------------+--------------------------+" << endl;
	cout << "|      Автор книги     |      Название книги      |        Жанр книги        |" << endl;
	cout << "+----------------------+--------------------------+--------------------------+" << endl;

	cout << *editableBook_ << endl;

	cout << "+----------------------+--------------------------+--------------------------+" << endl;
}

ostream& operator<<(ostream& os, Library& library)
{
	os << "|" << setw(22) << left << library.title_
		<< "|" << setw(21) << left << library.city_
		<< "|" << setw(26) << left << library.address_
		<< "|";
	return os;
}

Library::~Library()
{
	editableBook_ = nullptr;
}


