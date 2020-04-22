#pragma once

#include <string>

using namespace std;

class EmptyLibrariesListException
{
	string error_;
public:
	EmptyLibrariesListException()
	{
		error_ = "Список библиотек пуст!";
	}

	const string what() const
	{
		return error_;
	}
};