#include "ByteString.h"

int ByteString::CheckString(const char* s) {
	if (!s) return 0;
	int len = strlen(s);
	for (int n = 0; n < len; n++)
		if ((s[n] != '0') && (s[n] != '1'))
			return 0;
	return 1;
}

ByteString::ByteString() {
	_str = 0;
	size = 0;
}

ByteString::ByteString(const char* s) : String(s) {
	if (!CheckString(s)) {
		delete[] _str;
		_str = 0;
		size = 0;
	}
}

ByteString::ByteString(const ByteString& b) : String(b._str) {
	if (!CheckString(b._str)) {
		delete[] _str;
		_str = 0;
		size = 0;
	}
}

ByteString::~ByteString() {
	delete[] _str;
}

const ByteString& ByteString::operator=(const ByteString& b) {
	if (_str)
		delete[] _str;
	if (b._str) {
		_str = _strdup(b._str);
		size = b.size;
	}
	else {
		_str = 0;
		size = 0;
	}
	return *this;
}

ByteString ByteString::operator-() {
	ByteString Res(*this);
	int len = strlen(Res._str);
	for (size_t i = 0; i < len; i++) {
		if (Res._str[i] == '0') Res._str[i] = '1';
		else if (Res._str[i] == '1') Res._str[i] = '0';
	}
	return Res + "0001";
}

const ByteString ByteString::operator+(const ByteString& b) {
	int m, p = 0, a1, a2;
	int len = length(), lenB = b.length();
	len > lenB ? m = len : m = lenB;
	char* r = new char[m + 1];
	memset(r, '0', m);
	r[m] = 0;
	int n1 = len - 1, n2 = lenB - 1;
	for (int n = m - 1; n >= 0; n--) {
		if (n1 >= 0) a1 = _str[n1] - '0';
		else a1 = 0;
		if (n2 >= 0) a2 = b._str[n2] - '0';
		else a2 = 0;
		switch (a1 + a2 + p) {
		case 3:
			r[n] = 1;
			p = 2;
			break;
		case 2:
			r[n] = '0';
			p = 1;
			break;
		case 1:
			r[n] = '1';
			p = 0;
			break;
		case 0:
			r[n] = '0';
			p = 0;
			break;
		}
		n1--;
		n2--;
	}
	return ByteString(r);
}

ByteString& ByteString::operator+=(const ByteString& b) {
	*this = *this + b;
	return *this;
}

bool ByteString::operator==(const ByteString& b) {
	int l;
	int len = length(), lenB = b.length();
	len > lenB ? l = len : l = lenB;
	int r = 1;;
	int n1 = len - 1, n2 = lenB - 1, k;
	k = l - 1;
	while (k >= 0) {
		if ((n1 >= 0) && (n2 >= 0) && (_str[n1] != b._str[n2])) return 0;
		if ((n1 < 0) && (b._str[n2] != '0')) return 0;
		if ((n2 < 0) && (_str[n1] != '0')) return 0;
		k--; n1--; n2--;
	}
	return 1;
}

bool ByteString::operator!=(const ByteString& b) {
	return !(operator==(b));
}