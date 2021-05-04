#include "String.h"
#include <cstring>

String::String()
{
	capacity = 8;
	size = 0;
	text = new char[capacity];
	text[0] = '\0';
}

String::String(const char* _string)
{
	this->capacity = strlen(_string) + 1;
	this->text = new char[capacity];
	strcpy_s(this->text, capacity, _string);
	this->size = strlen(_string);
}

String::~String()
{
	this->erase();
}

String::String(const String& _string)
{
	this->copy(_string);
}

String& String::operator=(const String& _string)
{
	if (this != &_string)
	{
		this->erase();
		this->copy(_string);
	}
	return *this;
}

String& String::operator=(const char* text)
{
	this->erase();
	this->capacity = strlen(text) + 1;
	this->text = new char[capacity];
	this->size = strlen(text);
	strcpy_s(this->text, capacity, text);
	return *this;
}

bool String::operator==(const String& _string)
{
	return !strcmp(this->text, _string.text);
}

bool String::operator!=(const String& _string)
{
	return strcmp(this->text, _string.text);
}

String String::operator+(String& other)
{
	String temp;
	temp.copy(*this);
	for (int i = 0; i < other.size; ++i)
	{
		temp += other[i];
	}
	return temp;
}

const char String::operator[](int index)
{
	return this->text[index];
}

String& String::operator+=(const char _element)
{
	if (this->size + 1 >= this->capacity)
	{
		this->resize();
	}
	this->text[size] = _element;
	this->size++;
	this->text[size] = '\0';
	return *this;
}

size_t String::getSize() const
{
	return this->size;
}

void String::print() const
{
	std::cout << this->text << std::endl;
	std::cout << this->capacity << std::endl;
	std::cout << this->size << std::endl;
}

void String::removeLast()
{
	if (this->size >= 1)
	{
		this->size--;
		char* newString = new char[capacity];
		for (size_t i = 0; i < size; ++i)
		{
			newString[i] = text[i];
		}
		delete[] text;
		this->text = newString;
		this->text[size] = '\0';
	}
}

int String::StringToNumber()
{
	int numbersCount = 0;
	for (size_t i = 0; i < this->size; ++i)
	{
		if (this->text[i] >= '0' && this->text[i] <= '9')
		{
			numbersCount++;
		}
	}
	int position = pow(10,numbersCount - 1);
	int number = 0;
	for (size_t i = 0; i < this->size; ++i)
	{
		if (this->text[i] >= '0' && this->text[i] <= '9')
		{
			number += (text[i]-48)*position ;
			position /= 10;
		}
	}
	return number;
}


void String::copy(const String& _string)
{
	this->capacity = _string.capacity;
	this->size = _string.size;
	this->text = new char[this->capacity];
	strcpy_s(this->text, this->capacity, _string.text);
}

void String::erase()
{
	delete[] this->text;
}

void String::resize()
{
	this->capacity *= 2;
	char* newString = new char[capacity];
	for (size_t i = 0; i < size; ++i)
	{
		newString[i] = text[i];
	}
	delete[] text;
	this->text = newString;

}

std::ostream& operator<<(std::ostream& out, const String& _string)
{
	out << _string.text;
	return out;
}

std::istream& operator>>(std::istream& in, String& _string)
{
	char element = ' ';
	while (element != '\n')
	{
		element = in.get();
		_string += element;
	}
	_string.removeLast();
	return in;
}
