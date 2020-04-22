#pragma once

#include <iostream>
#include <string>
#include <Windows.h>

#include "LibraryHandler.h"

using namespace std;

enum class MainMenuAction
{
	SELECT_LIBRARTY = 1,
	ADD_LIBRARY,
	EDIT_LIBRARY,
	SHOW_LIBRARIES,
	ADD_ADMISSION,
	EDIT_ADMISSION,
	SHOW_ADMISSIONS,
	QUIT
};

enum class LibraryEditMenuAction
{
	EDIT_TITLE = 1,
	EDIT_CITY,
	EDIT_ADDRESS,
	BACK_TO_MAIN_MENU
};

enum class AdmissionEditMenuAction
{
	EDIT_BOOK_AUTHOR = 1,
	EDIT_BOOK_TITLE,
	EDIT_BOOK_GENRE,
	EDIT_LIBRARY_TITLE,
	BACK_TO_MAIN_MENU
};

enum class LibraryMenuAction
{
	CHECK_ADMISSION = 1,
	EDIT_BOOK,
	SHOW_BOOKS,
	BACK_TO_MAIN_MENU
};

enum class BookEditMenuAction
{
	EDIT_AUTHOR = 1,
	EDIT_TITLE,
	EDIT_GENRE,
	BACK_TO_LIBRARY_MENU
};

MainMenuAction mainMenu();
LibraryEditMenuAction libraryEditMenu();
AdmissionEditMenuAction admissionEditMenu();
LibraryMenuAction libraryMenu();
BookEditMenuAction bookEditMenu();

istream& operator>>(istream& is, MainMenuAction& action);
istream& operator>>(istream& is, LibraryEditMenuAction& action);
istream& operator>>(istream& is, AdmissionEditMenuAction& action);
istream& operator>>(istream& is, LibraryMenuAction& action);
istream& operator>>(istream& is, BookEditMenuAction& action);
