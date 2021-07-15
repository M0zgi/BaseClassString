#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<Windows.h>

using namespace std;

struct numpunct
	: std::numpunct<char>
{
	std::string do_truename() const { return "��"; }
	std::string do_falsename() const { return "���"; }
};

class MyString
{
public:
	
	// 1). ����������� ��� ����������;
	MyString() {str = nullptr; }

	// 2). �����������, ����������� � �������� ��������� C-������ (������������� ������� ������);
	MyString(const char* str);

	// 3) ����������� �����������;
	MyString(const MyString& obj);

	// 4) �������� ������������;
	MyString& operator =(const MyString& obj);

	// 5). ��������� ����� ������;
	int countLenght();

	// 6) ������� ������ (������� ������ ������);
	void clearString();

	//void print() { cout << str; }

	
	// 7). ����������
	~MyString();

	//8) ������������ �����(����������� ��������� + � += );
	MyString operator+(const MyString& obj);

	MyString &operator+=(const MyString& obj);

	//9) �������� �� ���������(==) � �� ����������� (!=).

	bool operator==(const MyString& obj);

	bool operator!=(const MyString& obj);

	//��������� ��������� ������
	friend ostream& operator << (ostream& out, const MyString& obj);

private:
	char* str;

};

inline MyString::MyString(const char* str)
{
	int lenght = strlen(str);
	this->str = new char [lenght + 1];
	strcpy(this->str, str);
}

inline MyString::MyString(const MyString& obj)
{
	int lenght = strlen(obj.str);
	this->str = new char[lenght + 1];
	strcpy(this->str, obj.str);
}

inline MyString& MyString::operator=(const MyString& obj)
{
	
	if (this->str != nullptr)
	{
		delete[]this->str;
	}
	
	int lenght = strlen(obj.str);    
	this->str = new char[lenght + 1];
	strcpy(this->str, obj.str);

	return *this;
}

inline int MyString::countLenght()
{
	return strlen(this->str);
}

inline void MyString::clearString()
{
	if (this->str != nullptr)
	{
		delete[]this->str;
	}

	this->str = nullptr;
}

MyString::~MyString()
{
	//������� ������������ ������ ���������� ��� ������ char *str
	delete []this->str;
}

inline MyString MyString::operator+(const MyString& obj)
{
	MyString tmp;

	tmp.str = new char[strlen(this->str) + strlen(obj.str) + 1];

	//int i = 0;

	//for (; i < strlen(this->str); i++)
	//{
	//	tmp.str[i] = this->str[i];
	//}

	//for (size_t j = 0; j < strlen(obj.str); j++, i++)
	//{
	//	tmp.str[i] = obj.str[j];
	//	
	//}

	//tmp.str[i] = '\0';

	tmp.str = strcpy(tmp.str, this->str);
	tmp.str = strcat(tmp.str, obj.str);

	return tmp;
}

inline MyString &MyString::operator+=(const MyString& obj)
{
	MyString tmp;

	tmp.str = new char[strlen(this->str) + strlen(obj.str) + 1];
	tmp.str = strcpy(tmp.str, this->str);
	tmp.str = strcat(tmp.str, obj.str);

	this->clearString();
	
	this->str = new char[strlen(tmp.str) + 1];

	strcpy(this->str, tmp.str);

	return *this;
}

inline bool MyString::operator==(const MyString& obj)
{
	return !strcmp(this->str, obj.str);
}

inline bool MyString::operator!=(const MyString& obj)
{
	return strcmp(this->str, obj.str);
}

ostream& operator<<(ostream& out, const MyString& obj)
{	
	for (size_t i = 0; i < strlen(obj.str); i++)
	{
		out << obj.str[i];
	}

	out << endl;

	return out;
}