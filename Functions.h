#pragma once

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

template<typename T>
void printAdapter(T adapter)
{
	unsigned i = 0;
	while (!adapter.empty())
	{
		cout << "|" << setw(6) << left << ++i;
		cout << adapter.top() << endl;
		adapter.pop();
	}
}

template<typename T>
void printQueue(T queue)
{
	unsigned i = 0;
	while (!queue.empty())
	{
		cout << "|" << setw(6) << left << ++i;
		cout << queue.front() << endl;
		queue.pop();
	}
}