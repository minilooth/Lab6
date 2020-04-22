#pragma once

#include <string>

using namespace std;

class EmptyBooksListException
{
	string error_;
public:
	EmptyBooksListException()
	{
		error_ = "Список книг пуст!";
	}

	const string what() const
	{
		return error_;
	}
};