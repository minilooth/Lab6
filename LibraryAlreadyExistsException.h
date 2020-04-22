#pragma once

#include <iostream>
#include <string>

using namespace std;

class LibraryAlreadyExistsException
{
	string error_;
public:
	LibraryAlreadyExistsException()
	{
		error_ = "Библиотека уже существует!";
	}

	const string what() const
	{
		return error_;
	}
};

