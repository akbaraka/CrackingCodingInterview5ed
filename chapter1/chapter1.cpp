#include <iostream>
#include <Ch1.h>
using namespace std;

void AllUniqueCharacters(){
	cout << "Enter string to test" << endl;
	string str;
	getline(cin,str);
	cout << "Result is: " << boolalpha << AllUniqueCharacters(str) << endl;
}
int main(int argc, char* argv[])
{
	char choice;
	do{
		cout << "Select problem to test:" << endl;
		cout << "1 - Unique string" << endl;

		cout << "0 - Exit" << endl;

		cin >> choice;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');//skip everything until new line

		switch (choice){
		case '1': AllUniqueCharacters(); break;
		}

	} while (choice != '0');
	return 0;
}

