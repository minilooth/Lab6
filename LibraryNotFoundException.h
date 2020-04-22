#pragma once

#include <iostream>
#include <string>

using namespace std;

class LibraryNotFoundException
{
	string error_;
public:
	LibraryNotFoundException()
	{
		error_ = "Библиотека не найдена!";
	}

	const string what() const
	{
		return error_;
	}
};