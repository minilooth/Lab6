#pragma once

#include <string>

using namespace std;

class EmptyAdmissionsListException
{
	string error_;
public:
	EmptyAdmissionsListException()
	{
		error_ = "������ ����������� ����!";
	}

	const string what() const
	{
		return error_;
	}
};