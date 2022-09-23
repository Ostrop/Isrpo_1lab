#include "windows.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#pragma warning(disable:4996)

using namespace std;

class String
{
public:
	String();
	String(int);
	bool operator+(String);
	bool operator-(String);
	void InPut();
	void Print();
private:
	char* arr;
	int length;
};


String::String()
{

	this->length = 11;
	this->arr = new char[this->length]{ 'n', 'e', 'w', ' ', 's',
		't', 'r', 'i', 'n', 'g', '\n' };
}

String::String(int length)
{
	if (length > 0)
		this->length = length + 1;
	else
		this->length = 10;
	this->arr = new char[this->length];
}

void String::InPut()
{
	char buf;
	for (size_t i = 0; i < this->length - 1; i++)
	{
		cin >> buf;
		this->arr[i] = buf;
	}
	this->arr[length - 1] = '\n';
}

void String::Print()
{
	for (size_t i = 0; i < length; i++)
		cout << this->arr[i];
}


bool String::operator+(String scnstring)
{
	String result = String(this->length + scnstring.length + 1);
	for (int i = 0; i < this->length; i++)
	{
		result.arr[i] = this->arr[i];
	}
	for (int i = this->length; i < this->length + scnstring.length; i++)
	{
		result.arr[i] = scnstring.arr[i];
		if (i == this->length + scnstring.length)
			result.arr[i + 1] = '\n';
	}
	result.Print();
	return true;
}

bool String::operator-(String scnstring)
{
	//String result = String(this->length - scnstring.length);
	//char* buffer = result.arr;
	//string buf = this->arr;
	//string buf2 = scnstring.arr;
	//buf.erase(buf.find('\n'), this->length);
	//buf2.erase(buf2.find('\n'), scnstring.length);
	////Проблема тут..
	////buf.erase(buf.find(buf2), scnstring.length - 1);
	//cout << buf;
	////strcpy(result.arr, buf.c_str());
	//result.Print();
	//return true;


	String result = String(this->length - scnstring.length);
	char* buffer = result.arr;

	string str1 = this->arr;
	str1.erase(str1.find("\n"), str1.length());

	string str2 = scnstring.arr;
	str2.erase(str2.find("\n"), str2.length());

	int delPos = str1.find(str2);

	if (delPos >= 0)
	{
		str1.erase(delPos, scnstring.length - 1);
		strcpy(buffer, str1.c_str());
		result.arr = buffer;
		result.Print();
		return true;
	}
	else
	return false;
}

//
//bool String::operator - (String str)
//{
//	String result = String(this->length - str.length);
//	char* buffer = result.arr;
//
//	string str1 = this->arr;
//	str1.erase(str1.find("\n"), str1.length());
//
//	string str2 = str.arr;
//	str2.erase(str2.find("\n"), str2.length());
//
//	int delPos = str1.find(str2);
//
//	if (delPos >= 0)
//	{
//		str1.erase(delPos, str.length - 1);
//		strcpy(buffer, str1.c_str());
//		result.arr = buffer;
//		result.Print();
//		return true;
//	}
//	else
//		return false;
//}



int main()
{
	String st1 = String(5);
	st1.InPut();
	String st2 = String(2);
	st2.InPut();
	st1.Print();
	st2.Print();
	st1 - st2;
}
