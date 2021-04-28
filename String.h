#pragma once
#include <cstring>
#include <iostream>
class String
{
public:
	String();
	String(const char*);
	~String();
	String(const String&);
	String& operator=(const String&);
	String& operator=(const char*);
	bool operator==(const String&);
	bool operator!=(const String&);
	friend std::ostream& operator <<(std::ostream&, const String&);
	friend std::istream& operator >>(std::istream&, String&);
	const char operator[](int);
	String& operator+=(const char);
	size_t getSize() const;
	void print() const;
	void removeLast();
private:
	size_t capacity;
	size_t size;
	char* text;
	void copy(const String&);
	void erase();
	void resize();
};

