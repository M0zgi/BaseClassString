#include"BaseClassString.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::cout.setf(std::ios_base::boolalpha);

	locale loc(cout.getloc(), new ::numpunct);
	cout.imbue(loc);


	MyString str("� ������ str");

	//str.print();

	cout << "C����� str: " << str;

	int lenght = str.countLenght();

	cout << "����� ������ str: " << lenght << " �������(��)." << endl;

	cout << "------------------------------------------------" << endl;

	MyString str2("� ������ str2");

	cout << "C����� str2: " << str2;

	lenght = str2.countLenght();

	cout << "����� ������ str2: " << lenght << " �������(��)." << endl;

	cout << "------------------------------------------------" << endl;

	MyString str3;

	cout << "C����� str3 = str2 = str: "; str3 = str2 = str;
	cout << str3 << endl;
	lenght = str3.countLenght();
	cout << "����� ������ str3: " << lenght << " �������(��)." << endl;
	cout << "C����� str: " << str;
	cout << "C����� str2: " << str2;	

	cout << "------------------------------------------------" << endl;

	str3.clearString();
	cout << "C����� str3.clearString() -> str3(\"� ����� ����� str3\")" << endl;
	str3 = "� ����� ����� str3";
	cout << "C����� str3: " << str3;
	lenght = str3.countLenght();
	cout << "����� ������ str3: " << lenght << " �������(��)." << endl;

	cout << "------------------------------------------------" << endl;

	MyString str4 = "� ����� ����� str4 = str3 + str = ";
	cout << "C����� str4: " << str4;

	str4 = str3 + " + " + str;
	cout << "C����� str4: " << str4 << endl;

	cout << "------------------------------------------------" << endl;

	MyString str5 = "� ����� ����� str5 += str = ";
	cout << "C����� str5: " << str5;

	str5 += str;
	cout << "C����� str5: " << str5 << endl;

	cout << "------------------------------------------------" << endl;

	bool check = str == str2;

	cout << "C����� str1 == str2 ? " << check << endl;

	check = str == str3;

	cout << "C����� str1 == str3 ? " << check << endl;

	cout << "------------------------------------------------" << endl;

	check = str != str2;

	cout << "C����� str1 != str2 " << check << endl;

	check = str != str3;

	cout << "C����� str1 != str3 " << check << endl;

	cout << endl;
	system("pause");
}