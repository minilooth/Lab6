#include "Menu.h"

MainMenuAction mainMenu()
{
	MainMenuAction action;

	while (true)
	{
		try
		{
			system("cls");
			cout << "Главное меню: " << endl;
			cout << "1 - Выбрать библиотеку." << endl;
			cout << "2 - Добавить библиотеку." << endl;
			cout << "3 - Редактировать библиотеку." << endl;
			cout << "4 - Список библиотек." << endl;
			cout << "5 - Добавить поступление." << endl;
			cout << "6 - Редактировать поступления." << endl;
			cout << "7 - Список поступлений." << endl;
			cout << "8 - Выход." << endl;
			cout << "Ваш выбор: ";
			cin >> action;

			return action;
		}
		catch (InvalidInputException & ex)
		{
			cout << endl << ex.what();
			Sleep(1000);
		}
	}
}

LibraryEditMenuAction libraryEditMenu()
{
	LibraryEditMenuAction action;

	while (true)
	{
		try
		{
			system("cls");
			LibraryHandler::showEditableLibrary();
			cout << "Меню редактирования библиотеки: " << endl;
			cout << "1 - Редактировать название библиотеки." << endl;
			cout << "2 - Редактировать город библиотеки." << endl;
			cout << "3 - Редактировать адрес библиотеки." << endl;
			cout << "4 - Вернуться в главное меню." << endl;
			cout << "Ваш выбор: ";
			cin >> action;

			return action;
		}
		catch (InvalidInputException & ex)
		{
			cout << endl << ex.what();
			Sleep(1000);
		}
	}
}

AdmissionEditMenuAction admissionEditMenu()
{
	AdmissionEditMenuAction action;

	while (true)
	{
		try
		{
			system("cls");
			LibraryHandler::showEditableAdmission();
			cout << "Меню редактирования поступления: " << endl;
			cout << "1 - Редактировать автора книги." << endl;
			cout << "2 - Редактировать название книги." << endl;
			cout << "3 - Редактировать жанр книги." << endl;
			cout << "4 - Редактировать название библиотеки." << endl;
			cout << "5 - Вернуться в главное меню." << endl;
			cout << "Ваш выбор: ";
			cin >> action;

			return action;
		}
		catch (InvalidInputException & ex)
		{
			cout << endl << ex.what();
			Sleep(1000);
		}
	}
}

LibraryMenuAction libraryMenu()
{
	LibraryMenuAction action;

	while (true)
	{
		try
		{
			system("cls");
			cout << "Меню управления библиотекой:" << endl;
			cout << "1 - Актуальные поступления." << endl;
			cout << "2 - Редактировать книгу." << endl;
			cout << "3 - Список книг." << endl;
			cout << "4 - Вернуться в главное меню." << endl;
			cout << "Ваш выбор: ";
			cin >> action;

			return action;
		}
		catch (InvalidInputException & ex)
		{
			cout << endl << ex.what();
			Sleep(1000);
		}
	}
}

BookEditMenuAction bookEditMenu()
{
	BookEditMenuAction action;

	while (true)
	{
		try
		{
			system("cls");
			Library::showEditableBook();
			cout << "Меню редактирования книги:" << endl;
			cout << "1 - Редактировать автора." << endl;
			cout << "2 - Редактировать название." << endl;
			cout << "3 - Редактировать жанр." << endl;
			cout << "4 - Вернуться в меню управления библиотекой." << endl;
			cout << "Ваш выбор: ";
			cin >> action;

			return action;
		}
		catch (InvalidInputException & ex)
		{
			cout << endl << ex.what();
			Sleep(1000);
		}
	}
}

istream& operator>>(istream& is, MainMenuAction& action)
{
	string choice;
	cin >> choice;

	if (!regex_match(choice, regex("^[0-9]+$")))
	{
		throw InvalidInputException();
	}

	action = static_cast<MainMenuAction>(stoul(choice));

	return is;
}

istream& operator>>(istream& is, LibraryEditMenuAction& action)
{
	string choice;
	cin >> choice;

	if (!regex_match(choice, regex("^[0-9]+$")))
	{
		throw InvalidInputException();
	}

	action = static_cast<LibraryEditMenuAction>(stoul(choice));

	return is;
}

istream& operator>>(istream& is, AdmissionEditMenuAction& action)
{
	string choice;
	cin >> choice;

	if (!regex_match(choice, regex("^[0-9]+$")))
	{
		throw InvalidInputException();
	}
	
	action = static_cast<AdmissionEditMenuAction>(stoul(choice));

	return is;
}

istream& operator>>(istream& is, LibraryMenuAction& action)
{
	string choice;
	cin >> choice;

	if (!regex_match(choice, regex("^[0-9]+$")))
	{
		throw InvalidInputException();
	}

	action = static_cast<LibraryMenuAction>(stoul(choice));

	return is;
}

istream& operator>>(istream& is, BookEditMenuAction& action)
{
	string choice;
	cin >> choice;

	if (!regex_match(choice, regex("^[0-9]+$")))
	{
		throw InvalidInputException();
	}

	action = static_cast<BookEditMenuAction>(stoul(choice));

	return is;
}
