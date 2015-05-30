#include <iostream>
#include <memory>
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
void replace20(){
	cout << "Enter string:" << endl;
	string str;
	getline(cin, str);
	auto num_spaces = count(str.begin(), str.end(), ' ');
	unique_ptr<char[]> char_arr(new char[str.length() + 1 + 2 * num_spaces]);
	strcpy(char_arr.get(), str.c_str());
	replace20(char_arr.get(), str.length());
	cout << "Result is: " << char_arr.get() << endl;
}
void compress(){
	cout << "Enter string to compress:" << endl;
	string str;
	getline(cin, str);
	if (string::npos != str.find_first_of("0123456789")){
		cout << "The string must not have digits" << endl;
		return;
	}
	str = compress(str);
	cout << "Result is: " << str << endl;
	cout << "Decompressed back:" << endl;
	cout << decompress(str) << endl;
}
int main(int argc, char* argv[])
{
	char choice;
	do{
		cout << "\n===========================================\nSelect problem to test:" << endl;
		cout << "1 - Unique string" << endl;
		cout << "2 - Reverse string" << endl;
		cout << "3 - Are two strings permutation" << endl;
		cout << "4 - Replace spaces with '%20' in string" << endl;
		cout << "5 - Compress string" << endl;

		cout << "0 - Exit" << endl;

		cin >> choice;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');//skip everything until new line

		switch (choice){
		case '1': AllUniqueCharacters(); break;
		case '2': ReverseString(); break;
		case '3': IsPermutation(); break;
		case '4': replace20(); break;
		case '5':compress(); break;
		}

	} while (choice != '0');
	return 0;
}

