#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<Windows.h>

using namespace std;

struct numpunct
	: std::numpunct<char>
{
	std::string do_truename() const { return "Да"; }
	std::string do_falsename() const { return "Нет"; }
};

class MyString
{

private:
	char* str;
	int length;

public:
	
	// 1). конструктор без параметров;
	MyString() {str = nullptr, length = 0; }

	// 2). конструктор, принимающий в качестве параметра C-строку (заканчивается нулевым байтом);
	MyString(const char* str);

	// 3) конструктор копирования;
	MyString(const MyString& obj);

	// 4) оператор присваивания;
	MyString& operator =(const MyString& obj);

	// 5). получение длины строки;
	int countLenght();

	// 6) очистка строки (сделать строку пустой);
	void clearString();

	//void print() { cout << str; }

	
	// 7). деструктор
	~MyString();

	//8) конкатенация строк(перегрузить операторы + и += );
	MyString operator+(const MyString& obj);

	MyString &operator+=(const MyString& obj);

	//9) проверка на равенство(==) и на неравенство (!=).

	bool operator==(const MyString& obj);

	bool operator!=(const MyString& obj);

	//перегузка оператора вывода
	friend ostream& operator << (ostream& out, const MyString& obj);
};

inline MyString::MyString(const char* str)
{
	this->length = strlen(str);
	this->str = new char [length + 1];
	strcpy(this->str, str);
}

inline MyString::MyString(const MyString& obj)
{
	this->length = strlen(obj.str);
	this->str = new char[length + 1];
	strcpy(this->str, obj.str);
}

inline MyString& MyString::operator=(const MyString& obj)
{
	
	if (this->str != nullptr)
	{
		delete[]this->str;
	}
	
	this->length = strlen(obj.str);
	this->str = new char[length + 1];
	strcpy(this->str, obj.str);

	return *this;
}

inline int MyString::countLenght()
{
	//return strlen(this->str);
	return length;
}

inline void MyString::clearString()
{
	if (this->str != nullptr)
	{
		delete[]this->str;
	}

	this->str = nullptr;
	this->length = 0;
}

MyString::~MyString()
{
	//очищаем динамическую память выделенную под массив char *str
	delete []this->str;
}

inline MyString MyString::operator+(const MyString& obj)
{
	MyString tmp;

	length = strlen(this->str) + strlen(obj.str);

	tmp.str = new char[length + 1];

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

	length = strlen(this->str) + strlen(obj.str);

	tmp.str = new char[length + 1];
	tmp.str = strcpy(tmp.str, this->str);
	tmp.str = strcat(tmp.str, obj.str);

	this->clearString();
	
	length = strlen(tmp.str);

	this->str = new char[length + 1];

	strcpy(this->str, tmp.str);

	return *this;
}

inline bool MyString::operator==(const MyString& obj)
{
	if (this->length != obj.length)
		return false;	
	
	return !strcmp(this->str, obj.str);
}

inline bool MyString::operator!=(const MyString& obj)
{
	//if (this->length != obj.length)
		//return true;
	
	//return strcmp(this->str, obj.str);

	return !(this->operator==(obj));
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