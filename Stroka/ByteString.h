#pragma once
#include<iostream>
#include"String.h"
using namespace std;

class ByteString:public String
{
protected:
	int CheckString(const char* s);
public:
	
	ByteString();
	ByteString(const char* s);
	ByteString(const ByteString& b);
	~ByteString();
	
	const ByteString& operator=(const ByteString& b);
	
	ByteString operator-();
	
	const ByteString  operator+(const ByteString& b);
	ByteString& operator+=(const ByteString& b);

	bool operator==(const ByteString& b);
	bool operator!=(const ByteString& b);

};

