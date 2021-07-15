#include"BaseClassString.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::cout.setf(std::ios_base::boolalpha);

	locale loc(cout.getloc(), new ::numpunct);
	cout.imbue(loc);


	MyString str("Я строка str");

	//str.print();

	cout << "Cтрока str: " << str;

	int lenght = str.countLenght();

	cout << "Длина строки str: " << lenght << " символа(ов)." << endl;

	cout << "------------------------------------------------" << endl;

	MyString str2("Я строка str2");

	cout << "Cтрока str2: " << str2;

	lenght = str2.countLenght();

	cout << "Длина строки str2: " << lenght << " символа(ов)." << endl;

	cout << "------------------------------------------------" << endl;

	MyString str3;

	cout << "Cтрока str3 = str2 = str: "; str3 = str2 = str;
	cout << str3 << endl;
	lenght = str3.countLenght();
	cout << "Длина строки str3: " << lenght << " символа(ов)." << endl;
	cout << "Cтрока str: " << str;
	cout << "Cтрока str2: " << str2;	

	cout << "------------------------------------------------" << endl;

	str3.clearString();
	cout << "Cтрока str3.clearString() -> str3(\"Я новая срока str3\")" << endl;
	str3 = "Я новая срока str3";
	cout << "Cтрока str3: " << str3;
	lenght = str3.countLenght();
	cout << "Длина строки str3: " << lenght << " символа(ов)." << endl;

	cout << "------------------------------------------------" << endl;

	MyString str4 = "Я новая срока str4 = str3 + str = ";
	cout << "Cтрока str4: " << str4;

	str4 = str3 + " + " + str;
	cout << "Cтрока str4: " << str4 << endl;

	cout << "------------------------------------------------" << endl;

	MyString str5 = "Я новая срока str5 += str = ";
	cout << "Cтрока str5: " << str5;

	str5 += str;
	cout << "Cтрока str5: " << str5 << endl;

	lenght = str5.countLenght();
	cout << "Длина строки str3: " << lenght << " символа(ов)." << endl;

	cout << "------------------------------------------------" << endl;

	bool check = str == str2;

	cout << "Cтрока str1 == str2 ? " << check << endl;

	check = str == str3;

	cout << "Cтрока str1 == str3 ? " << check << endl;

	cout << "------------------------------------------------" << endl;

	check = str != str2;

	cout << "Cтрока str1 != str2 " << check << endl;

	check = str != str3;

	cout << "Cтрока str1 != str3 " << check << endl;

	cout << endl;
	system("pause");
}