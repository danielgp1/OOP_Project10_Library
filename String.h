#pragma once
#include <cstring>
#include <iostream>
#include <cmath>
class String
{
public:
	String();
	String(const char*);
	~String();
	String(const String&);
	String& operator=(const String&);
	String& operator=(const char*);
	bool operator==(const String&) const;
	bool operator==(const char*) const;
	bool operator!=(const String&) const;
	friend std::ostream& operator <<(std::ostream&, const String&);
	friend std::istream& operator >>(std::istream&, String&);
	String operator+(String&);
	const char operator[](int) const;
	String& operator+=(const char);
	size_t getSize() const;
	void print() const;
	void removeLast();
	int StringToNumber();
private:
	size_t capacity;
	size_t size;
	char* text;
	void copy(const String&);
	void erase();
	void resize();
};

