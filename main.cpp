#include <iostream>
#include <string>
#include <Windows.h>

#include "LibraryHandler.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	auto libraryHandler = new LibraryHandler();

	while (true)
	{
		switch (mainMenu())
		{
		case MainMenuAction::SELECT_LIBRARTY :
			system("cls");
			LibraryHandler::selectLibrary();
			break;
		case MainMenuAction::ADD_LIBRARY :
			system("cls");
			LibraryHandler::addLibrary();
			system("pause");
			break;
		case MainMenuAction::EDIT_LIBRARY :
			system("cls");
			LibraryHandler::editLibrary();
			break;
		case MainMenuAction::SHOW_LIBRARIES :
			system("cls");
			LibraryHandler::showLibraries();
			system("pause");
			break;
		case MainMenuAction::ADD_ADMISSION :
			system("cls");
			LibraryHandler::addAdmission();
			system("pause");
			break;
		case MainMenuAction::EDIT_ADMISSION :
			system("cls");
			LibraryHandler::editAdmission();
			break;
		case MainMenuAction::SHOW_ADMISSIONS :
			system("cls");
			LibraryHandler::showAdmissions();
			system("pause");
			break;
		case MainMenuAction::QUIT :
			delete libraryHandler;
			return 0;
		default:
			break;
		}
	}
}