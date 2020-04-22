#pragma once

#include <string>

using namespace std;

class BookNotFoundException
{
	string error_;
public:
	BookNotFoundException()
	{
		error_ = " нига не найдена!";
	}

	const string what() const
	{
		return error_;
	}
};