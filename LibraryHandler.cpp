#include "LibraryHandler.h"

stack<Library, vector<Library>> LibraryHandler::libraries_;
priority_queue<Admission, vector<Admission>> LibraryHandler::admissions_;
Library* LibraryHandler::editableLibrary_ = nullptr;
Admission* LibraryHandler::editableAdmission_ = nullptr;
Library* LibraryHandler::currentLibrary_ = nullptr;

LibraryHandler::LibraryHandler()
{
	editableLibrary_ = nullptr;
	editableAdmission_ = nullptr;
	currentLibrary_ = nullptr;
}

LibraryHandler::LibraryHandler(const stack<Library, vector<Library>> & libraries, const priority_queue<Admission, vector<Admission>> & admissions)
{
	libraries_ = libraries;
	admissions_ = admissions;
	editableLibrary_ = nullptr;
	editableAdmission_ = nullptr;
	currentLibrary_ = nullptr;
}

void LibraryHandler::setLibraries(const stack<Library, vector<Library>>& libraries)
{
	libraries_ = libraries;
}

void LibraryHandler::setAdmissions(const priority_queue<Admission, vector<Admission>>& admissions)
{
	admissions_ = admissions;
}

stack<Library, vector<Library>> LibraryHandler::getLibraries()
{
	return libraries_;
}

priority_queue<Admission, vector<Admission>>& LibraryHandler::getAdmissions()
{
	return admissions_;
}

void LibraryHandler::setEditableLibrary(unsigned id)
{
	vector<Library> librariesVector;

	while (!libraries_.empty())
	{
		librariesVector.push_back(libraries_.top());
		libraries_.pop();
	}

	for (unsigned i = 0; i < librariesVector.size(); i++)
	{
		libraries_.emplace(librariesVector.at(i));
		if (i + 1 == id)
		{
			editableLibrary_ = &libraries_.top();
		}
	}
}

void LibraryHandler::setEditableAdmission(unsigned id)
{
	vector<Admission> admissionsVector;

	while (!admissions_.empty())
	{
		admissionsVector.push_back(admissions_.top());
		admissions_.pop();
	}

	for (unsigned i = 0; i < admissionsVector.size(); i++)
	{
		if (i + 1 == id)
		{
			editableAdmission_ = new Admission(admissionsVector.at(i));
		}
		else
		{
			admissions_.emplace(admissionsVector.at(i));
		}
	}
}

void LibraryHandler::setCurrentLibrary(unsigned id)
{
	vector<Library> librariesVector;

	while (!libraries_.empty())
	{
		librariesVector.push_back(libraries_.top());
		libraries_.pop();
	}

	for (unsigned i = 0; i < librariesVector.size(); i++)
	{
		libraries_.emplace(librariesVector.at(i));
		if (i + 1 == id)
		{
			currentLibrary_ = &libraries_.top();
		}
	}
}

void LibraryHandler::editLibraryTitle()
{
	try
	{
		showEditableLibrary();

		string title;
		cout << "Введите новое название библиотеки: ";
		cin >> title;

		if (!regex_match(title, regex("^[a-zA-Zа-яА-Я]+$")))
		{
			throw InvalidInputException();
		}

		if (isLibraryExists(title))
		{
			throw LibraryAlreadyExistsException();
		}

		editableLibrary_->setTitle(title);

		system("cls");
		showEditableLibrary();
		cout << "Название библиотеки успешно изменено!" << endl;
	}
	catch (LibraryAlreadyExistsException & ex)
	{
		system("cls");
		showEditableLibrary();
		cout << ex.what() << endl;
	}
	catch (InvalidInputException & ex)
	{
		system("cls");
		showEditableLibrary();
		cout << ex.what() << endl;
	}
}

void LibraryHandler::editLibraryCity()
{
	try
	{
		showEditableLibrary();

		string city;
		cout << "Введите новый город библиотеки: ";
		cin >> city;

		if (!regex_match(city, regex("^[a-zA-Zа-яА-Я]+$")))
		{
			throw InvalidInputException();
		}

		editableLibrary_->setCity(city);

		system("cls");
		showEditableLibrary();
		cout << "Город библиотеки успешно изменен!" << endl;
	}
	catch (InvalidInputException & ex)
	{
		system("cls");
		showEditableLibrary();
		cout << ex.what() << endl;
	}
}

void LibraryHandler::editLibraryAddress()
{
	try
	{
		showEditableLibrary();

		string address;
		cout << "Введите новый адрес библиотеки: ";
		cin >> address;

		if (!regex_match(address, regex("^[a-zA-Zа-яА-Я0-9.]+$")))
		{
			throw InvalidInputException();
		}

		editableLibrary_->setAddress(address);

		system("cls");
		showEditableLibrary();
		cout << "Адрес библиотеки успешно изменен!" << endl;
	}
	catch (InvalidInputException & ex)
	{
		system("cls");
		showEditableLibrary();
		cout << ex.what() << endl;
	}
}

void LibraryHandler::editAdmissionBookTitle()
{
	try
	{
		showEditableAdmission();

		string bookTitle;
		cout << "Введите новое название книги: " << endl;
		cin >> bookTitle;

		if (!regex_match(bookTitle, regex("^[a-zA-Zа-яА-Я]+$")))
		{
			throw InvalidInputException();
		}

		editableAdmission_->getBook()->setTitle(bookTitle);

		system("cls");
		showEditableAdmission();
		cout << "Название книги успешно изменено!" << endl;
	}
	catch (InvalidInputException & ex)
	{
		system("cls");
		showEditableAdmission();
		cout << ex.what() << endl;
	}
}

void LibraryHandler::editAdmissionBookAuthor()
{
	try
	{
		showEditableAdmission();

		string bookAuthor;
		cout << "Введите нового автора книги: ";
		cin >> bookAuthor;

		if (!regex_match(bookAuthor, regex("^[a-zA-Zа-яА-Я.]+$")))
		{
			throw InvalidInputException();
		}

		editableAdmission_->getBook()->setAuthor(bookAuthor);

		system("cls");
		showEditableAdmission();
		cout << "Автор книги успешно изменен!" << endl;
	}
	catch (InvalidInputException & ex)
	{
		system("cls");
		showEditableAdmission();
		cout << ex.what() << endl;
	}
}

void LibraryHandler::editAdmissionBookGenre()
{
	try
	{
		showEditableAdmission();

		string bookGenre;
		cout << "Введите новый жанр книги: ";
		cin >> bookGenre;

		if (!regex_match(bookGenre, regex("^[a-zA-Zа-яА-Я]+$")))
		{
			throw InvalidInputException();
		}

		editableAdmission_->getBook()->setGenre(bookGenre);

		system("cls");
		showEditableAdmission();
		cout << "Жанр книги успешно изменен!" << endl;
	}
	catch (InvalidInputException & ex)
	{
		system("cls");
		showEditableAdmission();
		cout << ex.what() << endl;
	}
}

void LibraryHandler::editAdmissionLibraryTitle()
{
	try
	{
		showEditableAdmission();

		string libraryTitle;
		cout << "Введите новое название библиотеки: ";
		cin >> libraryTitle;

		if (!regex_match(libraryTitle, regex("^[a-zA-Zа-яА-Я]+$")))
		{
			throw InvalidInputException();
		}

		if (!isLibraryExists(libraryTitle))
		{
			throw LibraryNotFoundException();
		}

		editableAdmission_->setLibraryTitle(libraryTitle);

		system("cls");
		showEditableAdmission();
		cout << "Название библиотеки успешно изменено!" << endl;
	}
	catch (LibraryNotFoundException & ex)
	{
		system("cls");
		showEditableAdmission();
		cout << ex.what() << endl;
	}
	catch (InvalidInputException & ex)
	{
		system("cls");
		showEditableAdmission();
		cout << ex.what() << endl;
	}
}

bool LibraryHandler::isLibraryExists(const string& title)
{
	bool isFound = false;
	vector<Library> librariesVector;

	while (!libraries_.empty())
	{
		librariesVector.emplace_back(libraries_.top());
		libraries_.pop();
	}

	for (auto it = librariesVector.begin(); it != librariesVector.end(); it++)
	{
		if (it->getTitle() == title)
		{
			isFound = true;
		}
		libraries_.emplace(*it);
	}

	return isFound;
}

void LibraryHandler::selectLibrary()
{
	try
	{
		if (libraries_.empty())
		{
			throw EmptyLibrariesListException();
		}

		showLibraries();

		string id;
		cout << "Введите ид библиотеки для выбора: ";
		cin >> id;

		if (!regex_match(id, regex("^[0-9]+$")))
		{
			throw InvalidInputException();
		}

		if (stoul(id) > libraries_.size())
		{
			throw LibraryNotFoundException();
		}

		setCurrentLibrary(stoul(id));

		while (true)
		{
			switch (libraryMenu())
			{
			case LibraryMenuAction::CHECK_ADMISSION:
				system("cls");
				currentLibrary_->checkAdmissions();
				system("pause");
				break;
			case LibraryMenuAction::EDIT_BOOK:
				system("cls");
				currentLibrary_->editBook();
				break;
			case LibraryMenuAction::SHOW_BOOKS:
				system("cls");
				currentLibrary_->showBooks();
				system("pause");
				break;
			case LibraryMenuAction::BACK_TO_MAIN_MENU:
				currentLibrary_ = nullptr;
				return;
			default:
				break;
			}
		}
	}
	catch (EmptyLibrariesListException & ex)
	{
		system("cls");
		cout << ex.what() << endl;
		system("pause");
	}
	catch (LibraryNotFoundException & ex)
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

void LibraryHandler::addLibrary()
{
	try
	{
		string title;
		cout << "Введите название библиотеки: ";
		cin >> title;

		if (!regex_match(title, regex("^[a-zA-Zа-яА-Я]+$")))
		{
			throw InvalidInputException();
		}

		string city;
		cout << "Введите город библиотеки: ";
		cin >> city;

		if (!regex_match(city, regex("^[a-zA-Zа-яА-Я]+$")))
		{
			throw InvalidInputException();
		}

		string address;
		cout << "Введите адрес библиотеки: ";
		cin >> address;

		if (!regex_match(address, regex("^[a-zA-Zа-яА-Я0-9.]+$")))
		{
			throw InvalidInputException();
		}

		if (isLibraryExists(title))
		{
			throw LibraryAlreadyExistsException();
		}

		libraries_.push(Library(title, city, address));

		system("cls");
		cout << "Библиотека успешно добавлена!" << endl;
	}
	catch (LibraryAlreadyExistsException & ex)
	{
		system("cls");
		cout << ex.what() << endl;
	}
	catch (InvalidInputException & ex)
	{
		system("cls");
		cout << ex.what() << endl;
	}
}

void LibraryHandler::showLibraries()
{
	try
	{
		if (libraries_.empty())
		{
			throw EmptyLibrariesListException();
		}

		cout << "+------+----------------------+---------------------+--------------------------+" << endl;
		cout << "|  Ид  |       Название       |        Город        |           Адрес          |" << endl;
		cout << "+------+----------------------+---------------------+--------------------------+" << endl;

		printAdapter(libraries_);

		cout << "+------+----------------------+---------------------+--------------------------+" << endl;
	}
	catch (EmptyLibrariesListException & ex)
	{
		system("cls");
		cout << ex.what() << endl;
	}
}

void LibraryHandler::editLibrary()
{
	try
	{
		if (libraries_.empty())
		{
			throw EmptyLibrariesListException();
		}

		showLibraries();

		string id;
		cout << "Введите ид библиотеки для редактирования: ";
		cin >> id;

		if (!regex_match(id, regex("^[0-9]+$")))
		{
			throw InvalidInputException();
		}

		if (stoul(id) > libraries_.size())
		{
			throw LibraryNotFoundException();
		}

		setEditableLibrary(stoul(id));

		while (true)
		{
			switch (libraryEditMenu())
			{
			case LibraryEditMenuAction::EDIT_TITLE:
				system("cls");
				editLibraryTitle();
				system("pause");
				break;
			case LibraryEditMenuAction::EDIT_CITY:
				system("cls");
				editLibraryCity();
				system("pause");
				break;
			case LibraryEditMenuAction::EDIT_ADDRESS:
				system("cls");
				editLibraryAddress();
				system("pause");
				break;
			case LibraryEditMenuAction::BACK_TO_MAIN_MENU:
				editableLibrary_ = nullptr;
				return;
			default:
				break;
			}
		}
	}
	catch (EmptyLibrariesListException & ex)
	{
		system("cls");
		cout << ex.what() << endl;
		system("pause");
	}
	catch (LibraryNotFoundException & ex)
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

void LibraryHandler::showEditableLibrary()
{
	cout << "+----------------------+---------------------+--------------------------+" << endl;
	cout << "|       Название       |        Город        |           Адрес          |" << endl;
	cout << "+----------------------+---------------------+--------------------------+" << endl;

	cout << *editableLibrary_ << endl;

	cout << "+----------------------+---------------------+--------------------------+" << endl;
}

void LibraryHandler::addAdmission()
{
	try
	{
		if (libraries_.empty())
		{
			throw EmptyLibrariesListException();
		}

		string bookTitle;
		cout << "Введите название книги: ";
		cin >> bookTitle;

		if (!regex_match(bookTitle, regex("^[a-zA-Zа-яА-Я]+$")))
		{
			throw InvalidInputException();
		}

		string bookAuthor;
		cout << "Введите автора книги: ";
		cin >> bookAuthor;

		if (!regex_match(bookAuthor, regex("^[a-zA-Zа-яА-Я]+$")))
		{
			throw InvalidInputException();
		}

		string bookGenre;
		cout << "Введите жанр книги: ";
		cin >> bookGenre;

		if (!regex_match(bookGenre, regex("^[a-zA-Zа-яА-Я]+$")))
		{
			throw InvalidInputException();
		}

		string libraryTitle;
		cout << "Введите название библиотеки: ";
		cin >> libraryTitle;

		if (!regex_match(libraryTitle, regex("^[a-zA-Zа-яА-Я]+$")))
		{
			throw InvalidInputException();
		}

		if (!isLibraryExists(libraryTitle))
		{
			throw LibraryNotFoundException();
		}

		admissions_.push(Admission(Book(bookAuthor, bookTitle, bookGenre), libraryTitle));

		cout << "Поступление успешно добавлено!" << endl;
	}
	catch (LibraryNotFoundException & ex)
	{
		system("cls");
		cout << ex.what() << endl;
	}
	catch (EmptyLibrariesListException & ex)
	{
		system("cls");
		cout << ex.what() << endl;
	}
	catch (InvalidInputException & ex)
	{
		system("cls");
		cout << ex.what() << endl;
	}
}

void LibraryHandler::showAdmissions()
{
	try
	{
		if (admissions_.empty())
		{
			throw EmptyAdmissionsListException();
		}

		cout << "+------+----------------------+--------------------------+--------------------------+--------------------------------+" << endl;
		cout << "|  Ид  |      Автор книги     |      Название книги      |        Жанр книги        |       Название библиотеки      |" << endl;
		cout << "+------+----------------------+--------------------------+--------------------------+--------------------------------+" << endl;

		printAdapter(admissions_);

		cout << "+------+----------------------+--------------------------+--------------------------+--------------------------------+" << endl;
	}
	catch (EmptyAdmissionsListException & ex)
	{
		system("cls");
		cout << ex.what() << endl;
	}
}

void LibraryHandler::editAdmission()
{
	try
	{
		if (admissions_.empty())
		{
			throw EmptyAdmissionsListException();
		}

		showAdmissions();

		string id;
		cout << "Введите ид поступления для редактирования: ";
		cin >> id;

		if (!regex_match(id, regex("^[0-9]$")))
		{
			throw InvalidInputException();
		}

		if (stoul(id) > admissions_.size())
		{
			throw AdmissionNotFoundException();
		}

		setEditableAdmission(stoul(id));

		while (true)
		{
			switch (admissionEditMenu())
			{
			case AdmissionEditMenuAction::EDIT_BOOK_AUTHOR:
				system("cls");
				editAdmissionBookAuthor();
				system("pause");
				break;
			case AdmissionEditMenuAction::EDIT_BOOK_TITLE:
				system("cls");
				editAdmissionBookTitle();
				system("pause");
				break;
			case AdmissionEditMenuAction::EDIT_BOOK_GENRE:
				system("cls");
				editAdmissionBookGenre();
				system("pause");
				break;
			case AdmissionEditMenuAction::EDIT_LIBRARY_TITLE:
				system("cls");
				editAdmissionLibraryTitle();
				system("pause");
				break;
			case AdmissionEditMenuAction::BACK_TO_MAIN_MENU:
				admissions_.emplace(*editableAdmission_);
				editableAdmission_ = nullptr;
				return;
			default:
				break;
			}
		}
	}
	catch (EmptyAdmissionsListException & ex)
	{
		system("cls");
		cout << ex.what() << endl;
		system("pause");
	}
	catch (AdmissionNotFoundException & ex)
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

void LibraryHandler::showEditableAdmission()
{
	cout << "+----------------------+--------------------------+--------------------------+--------------------------------+" << endl;
	cout << "|      Автор книги     |      Название книги      |        Жанр книги        |       Название библиотеки      |" << endl;
	cout << "+----------------------+--------------------------+--------------------------+--------------------------------+" << endl;

	cout << *editableAdmission_ << endl;

	cout << "+----------------------+--------------------------+--------------------------+--------------------------------+" << endl;
}

LibraryHandler::~LibraryHandler()
{
	editableLibrary_ = nullptr;
	editableAdmission_ = nullptr;
	currentLibrary_ = nullptr;
}
