#pragma once

#include <string>

using namespace std;

class AdmissionNotFoundException
{
	string error_;
public:
	AdmissionNotFoundException()
	{
		error_ = "����������� �� �������!";
	}

	const string what() const
	{
		return error_;
	}
};