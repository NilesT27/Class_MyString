#include <iostream>
using namespace std;

class MyString
{
public:
	MyString()		// ����������� ��� ����������
	{
		str = nullptr;
		length = 0;
	}

	MyString(const char *str)		// ����������� � �����������
	{
		length = strlen(str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = str[i];
		}

		this->str[length] = '\0';
	}

	~MyString()		// ����������
	{
		delete[] this->str;
	}

	MyString(const MyString& other)		// ����������� �����������
	{
		length = strlen(other.str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}

		this->str[length] = '\0';
	}

	MyString &operator = (const MyString &other)	// ������������� �������� ������������
	{
		if (this->str != nullptr)
		{
			delete[] str;
		}

		length = strlen(other.str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}

		this->str[length] = '\0';

		return *this;
	}

	MyString operator + (const MyString& other)	// ������������� �������� �������� (������������)
	{
		MyString newStr;

		int thisLength = strlen(this->str);
		int otherLength = strlen(other.str);

		newStr.length = thisLength + otherLength;

		newStr.str = new char[thisLength + otherLength + 1];

		int i = 0;
		for (; i < thisLength; i++)
		{
			newStr.str[i] = this->str[i];
		}

		for (int j = 0; j < otherLength; j++, i++)
		{
			newStr.str[i] = other.str[j];
		}

		newStr.str[thisLength + otherLength] = '\0';

		return newStr;
	}

	int Length()	// ������� ��� �������� ����� ������
	{
		return length;
	}

	void Print()	// ������� ��� ������ ������ (��� ��� �������� ������ ��� ����������, ������ ������� ����� ��� ����������)
	{
		std::cout << str;
	}

	bool operator == (const MyString& other)	// ������������� �������� ���������
	{
		if (this->length != other.length)
		{
			return false;
		}

		for (int i = 0; i < this->length; i++)
		{
			if (this->str[i] != other.str[i])
			{
				return false;
			}
		}

		return true;
	}

	bool operator != (const MyString& other)	// ������������� �������� �����������
	{
		return !(this->operator==(other));
	}

	char& operator [] (int index)	// ������������� �������� ���������� ������, ��� ��������� ���������� �������
	{
		return this->str[index];
	}

	MyString(MyString&& other)		// ����������� �����������
	{
		this->length = other.length;
		this->str = other.str;
		other.str = nullptr;
	}

	friend ostream &operator << (ostream &out, const MyString& other)	// ������������� �������� ������
	{
		out << other.str;
		return out;
	}

	friend istream& operator >> (istream &in, MyString& other)	// ������������� �������� �����
	{
		in >> other.str;
		return in;
	}

private:
	char *str;
	int length;
};

int main()
{
	// ��������� ������ ������ ������ MyString

	MyString str1("Hello ");
	MyString str2("World");

	MyString result = str1 + str2;

	MyString str3 = "Well Code";

	//cout << str1.Length() << endl;
	//cout << str2.Length() << endl;
	//cout << result.Length() << endl;

	//bool equal = str1 == str2;	// ���... bool equal = str1.operator == (str2);
	//cout << equal << endl;

	//bool equal = str1 != str2;
	//cout << equal << endl;

	//result[0] = 'Q';
	//cout << result[0];
	//result.Print();
	
	cout << result << endl;
	cin >> result;
	cout << result << endl;

	cout << str3 << endl;

	return 0;
}