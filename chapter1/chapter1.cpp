#include <iostream>
#include <Ch1.h>
using namespace std;

void AllUniqueCharacters(){
	cout << "Enter string to test" << endl;
	string str;
	getline(cin,str);
	cout << "Result is: " << boolalpha << AllUniqueCharacters(str) << endl;
}
void ReverseString(){
	cout << "Enter string to test" << endl;
	string str;
	getline(cin, str);
	reverse(const_cast<char*>(str.c_str()));//using const_cast is not very good thing
	cout << "Result is: " << str << endl;
}
void IsPermutation(){
	cout << "Enter first string" << endl;
	string one, two;
	getline(cin, one);
	cout << "Enter second string" << endl;
	getline(cin, two);
	cout << "Result is: " << boolalpha << isPermutation(one, two) << endl;
}
int main(int argc, char* argv[])
{
	char choice;
	do{
		cout << "Select problem to test:" << endl;
		cout << "1 - Unique string" << endl;
		cout << "2 - Reverse string" << endl;
		cout << "3 - Are two strings permutation" << endl;
		cout << "0 - Exit" << endl;

		cin >> choice;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');//skip everything until new line

		switch (choice){
		case '1': AllUniqueCharacters(); break;
		case '2': ReverseString(); break;
		case '3': IsPermutation(); break;
		}

	} while (choice != '0');
	return 0;
}

