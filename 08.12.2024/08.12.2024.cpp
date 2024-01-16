#include <iostream>
#include <cstring>
using namespace std;

class MyString
{
	char* str;
	static int count;
	int field = 80;
public:
	MyString()
	{
		str = new char[field];
		count++;
	}
	MyString(const char* text)
	{
		str = new char[strlen(text) + 1];
		strcpy_s(str, strlen(text) + 1, text);
		count++;
	}
	MyString(const MyString& other)
	{
		str = new char[strlen(other.str) + 1];
		strcpy_s(str, strlen(other.str) + 1, other.str);
		count++;
	}
	~MyString()
	{
		delete[] str;
		count--;
	}

	MyString& operator++()
	{
		int len = strlen(str);
		char* newStr = new char[len + 2];
		strcpy_s(newStr, len + 2, str);
		newStr[len] = 'x';
		newStr[len + 1] = '\0';
		delete[] str;
		str = newStr;
		return *this;
	}

	MyString operator++(int) 
	{
		MyString temp = *this;
		++(*this);
		return temp;
	}

	MyString& operator--() 
	{
		int len = strlen(str);
		if (len > 0)
		{
			char* newStr = new char[len];
			strncpy_s(newStr, len, str, len - 1);
			newStr[len - 1] = '\0';
			delete[] str;
			str = newStr;
		}
		return *this;
	}

	MyString operator--(int) 
	{
		MyString temp = *this;
		--(*this);
		return temp;
	}

	void input()
	{
		char buffer[256];
		cin.getline(buffer, 256);
		str = new char[strlen(buffer) + 1];
		strcpy_s(str, strlen(buffer) + 1, buffer);
	}

	void output() const
	{
		cout << "String: " << str << endl;
	}

	static int getCount()
	{
		return count;
	}
};

int MyString::count = 0;

int main()
{
	MyString str;
	str.input();
	str.output();
	cout << "Count: " << str.getCount() << endl;
	++str;
	str.output();
	str++;
	str.output();
	--str;
	str.output();
	str--;
	str.output();
}

