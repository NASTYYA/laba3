// ConsoleApplication2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include <string>
using namespace std;

class String
{
private:
	list<char> word;
	string s_cstring;
public:

	friend bool operator< (const String& str1, const String& str2);
	friend bool operator+ (const String& str1, const String& str2);
	String() { }
	String(string wor) {
		for (int i = 0; i < wor.size(); i++)
		{
			word.push_back(wor[i]);
		}
	}


	String(const String& ob) {
		for (char i : ob.word)
		{
			word.push_back(i);
		}
		cout << "Копирующий конструкор";
	}

	int Size() {
		return word.size();
	}

	void Print() {
		string output = "";
		for (char i : word) {
			output += i;
		}
		cout << output;
	}

	static String ConcatStrings(String st1, String st2) {
		string rez = "";
		for (char i : st1.word) {
			rez += i;
		}
		for (char i : st2.word) {
			rez += i;
		}
		String st3(rez);
		return st3;
	}

};



bool operator<(String& str1, String& str2)
{
	return (str1.Size() < str2.Size());
}
bool operator>(String& str1, String& str2)
{
	return (str1 > str2);
}
bool operator==(String &str1, String &str2)
{
	return (str1 == str2);
}

string operator+ (String& str1, String& str2)
{
	return (str1 + str2);
}

int main()
{
	setlocale(LC_ALL, "");
	cout << "Введите строку:" << endl;
	string s1;
	cin >> s1;
	cout << "\n\n" << endl;

	
	cout << "Введите строку для сравнения:" << endl;
	string s2;
	cin >> s2;
	


	if (s1 > s2)
	{
		cout << "s1>s2";

	}
	if (s1 < s2)
	{
		cout << "s1>s2";
	}
	else if (s1 == s2)
	{
		cout << "s1=s2";
	}



	cout << "\n\nВведите строки для сложения" << endl;
	string s3;
	cin >> s3;
	string s4;
	cin >> s4;
	String rezu = s3+ s4;
	cout << "\n\n" << endl;
	rezu.Print();
	cin >>s3 ;

}


