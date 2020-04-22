#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

#include "Admission.h"
#include "Library.h"

#include "Menu.h"

#include "Functions.h"

#include "EmptyLibrariesListException.h"
#include "LibraryAlreadyExistsException.h"
#include "LibraryNotFoundException.h"

#include "EmptyAdmisisonsListException.h"
#include "AdmissionNotFoundException.h"

using namespace std;

class Library;

class LibraryHandler
{
	static stack<Library, vector<Library>> libraries_;
	static priority_queue<Admission, vector<Admission>> admissions_;

	static Library* editableLibrary_;
	static Library* currentLibrary_;
	static Admission* editableAdmission_;

	static void setEditableLibrary(unsigned id);
	static void setEditableAdmission(unsigned id);
	static void setCurrentLibrary(unsigned id);

	static void editLibraryTitle();
	static void editLibraryCity();
	static void editLibraryAddress();

	static void editAdmissionBookTitle();
	static void editAdmissionBookAuthor();
	static void editAdmissionBookGenre();
	static void editAdmissionLibraryTitle();

	static bool isLibraryExists(const string& title);
public:
	LibraryHandler();
	LibraryHandler(const stack<Library, vector<Library>>& libraries, const priority_queue<Admission, vector<Admission>>& admissions);

	static void setLibraries(const stack<Library, vector<Library>>& libraries);
	static void setAdmissions(const priority_queue<Admission, vector<Admission>>& admissions);

	static stack<Library, vector<Library>> getLibraries();
	static priority_queue<Admission, vector<Admission>>& getAdmissions();

	static void selectLibrary();
	static void addLibrary();
	static void showLibraries();
	static void editLibrary();
	static void showEditableLibrary();

	static void addAdmission();
	static void showAdmissions();
	static void editAdmission();
	static void showEditableAdmission();


	~LibraryHandler();
};

