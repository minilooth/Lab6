#pragma once

#include <string>

using namespace std;

class EmptyAdmissionsListException
{
	string error_;
public:
	EmptyAdmissionsListException()
	{
		error_ = "Список поступлений пуст!";
	}

	const string what() const
	{
		return error_;
	}
};