#pragma once
#include <iostream>

using namespace std;

class String
{
protected:
	char* _str;
	int size;
public:
	
	String() :String(0, 0) {}
	explicit String(int c) :String(0, c) {}
	String(const char* s) :String(s, 0) {}
	String(const char* s, int c);
	String(const String& obj) :String(obj._str, obj.size) {}
	~String();
	String operator=(const String& obj);

	int length() const;
	void clear();
	
	String operator+(const String& obj);
	String& operator+=(const String& obj);

	bool operator==(const String& obj);
	bool operator!=(const String& obj);


	friend ostream& operator<<(ostream& out, const String& obj);
	friend istream& operator>>(istream& in, String& obj);
	
};

