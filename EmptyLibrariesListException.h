#pragma once

#include <string>

using namespace std;

class EmptyLibrariesListException
{
	string error_;
public:
	EmptyLibrariesListException()
	{
		error_ = "������ ��������� ����!";
	}

	const string what() const
	{
		return error_;
	}
};