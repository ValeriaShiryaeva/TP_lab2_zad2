#pragma once
#include <iostream>
#include <string>
#include<fstream>
using namespace std;

class Text
{
private:
	string* text;
	int size;
public:
	string& operator[](int);
	void push_back(string);
	void pop_back();
	void clear();
	int getSize() { return size; }

};

