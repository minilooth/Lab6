#include "Menu.h"

MainMenuAction mainMenu()
{
	MainMenuAction action;

	while (true)
	{
		try
		{
			system("cls");
			cout << "������� ����: " << endl;
			cout << "1 - ������� ����������." << endl;
			cout << "2 - �������� ����������." << endl;
			cout << "3 - ������������� ����������." << endl;
			cout << "4 - ������ ���������." << endl;
			cout << "5 - �������� �����������." << endl;
			cout << "6 - ������������� �����������." << endl;
			cout << "7 - ������ �����������." << endl;
			cout << "8 - �����." << endl;
			cout << "��� �����: ";
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
			cout << "���� �������������� ����������: " << endl;
			cout << "1 - ������������� �������� ����������." << endl;
			cout << "2 - ������������� ����� ����������." << endl;
			cout << "3 - ������������� ����� ����������." << endl;
			cout << "4 - ��������� � ������� ����." << endl;
			cout << "��� �����: ";
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
			cout << "���� �������������� �����������: " << endl;
			cout << "1 - ������������� ������ �����." << endl;
			cout << "2 - ������������� �������� �����." << endl;
			cout << "3 - ������������� ���� �����." << endl;
			cout << "4 - ������������� �������� ����������." << endl;
			cout << "5 - ��������� � ������� ����." << endl;
			cout << "��� �����: ";
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
			cout << "���� ���������� �����������:" << endl;
			cout << "1 - ���������� �����������." << endl;
			cout << "2 - ������������� �����." << endl;
			cout << "3 - ������ ����." << endl;
			cout << "4 - ��������� � ������� ����." << endl;
			cout << "��� �����: ";
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
			cout << "���� �������������� �����:" << endl;
			cout << "1 - ������������� ������." << endl;
			cout << "2 - ������������� ��������." << endl;
			cout << "3 - ������������� ����." << endl;
			cout << "4 - ��������� � ���� ���������� �����������." << endl;
			cout << "��� �����: ";
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
