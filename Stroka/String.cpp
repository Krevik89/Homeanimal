#include "String.h"

String::String(const char* s, int c) {
	int len = 0;
	if (s)
		len = strlen(s);
	if (len >= c)
		c = len + 1;
	size = c;
	if (c) {
		_str = new char[c] {0};
		if (len)
			strcpy_s(_str, c, s);
	}
	else
		_str = 0;
}

String String::operator=(const String& obj) {
	if (this != &obj) {
		if (size < obj.size) {
			delete[] _str;
			size = obj.size;
			_str = new char[obj.size];
		}
		strcpy_s(_str, size, obj._str);
	}
	return *this;
}

String::~String() {
	delete[] _str;
}

int String::length() const {
	return strlen(_str);
}

void String::clear() {
	delete[]_str;
	_str = 0;
	size = 0;
}

String String::operator+(const String& obj) {
	int lenR = strlen(obj._str);
	int lenN = lenR + strlen(_str);
	String temp(_str, lenN + 1);
	strcat_s(temp._str,strlen(temp._str)+strlen(obj._str)+2, obj._str);
	return temp;
}

String& String::operator+=(const String& obj) {
	*this = *this + obj;
	return *this;
}

bool String::operator==(const String& obj) {
	int lenR = strlen(obj._str);
	int lenN = strlen(_str);
	if (lenN != lenR)
		return false;
	for (size_t i = 0; i < lenN; i++)
		if (_str[i] != obj._str[i])
			return false;
	return true;
}

bool String::operator!=(const String& obj) {
	return !(operator==(obj));
}

ostream& operator<<(ostream& out, const String& obj) {
	out << obj._str;
	return out;
}

istream& operator>>(istream& in, String& obj) {
	char* buf = new char[255] { 0 };
	in.getline(buf, 255);
	int cap = strlen(buf);
	obj._str = buf;
	obj.size = cap;
	return in;
	//delete[]buf;
}