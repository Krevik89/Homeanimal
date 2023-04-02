#include <iostream>
#include "String.h"
#include "ByteString.h"
#include <Windows.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ByteString a("0101");
	ByteString b, c;
	cout << "a = " << a << endl;
	b = a;
	cout << "b = a;\nb = " << b << endl;
	cout << "a == b ? " << boolalpha << (a == b) << endl;

	b = -b;
	cout << "b = -b;\nb = " << b << endl;
	cout << "a == b ? " << boolalpha << (a == b) << endl;

	c = a + b;
	cout << "c = a + b;\nc = " << c << endl;
	
}


