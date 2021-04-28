#pragma once
#include <iostream>


template <typename T>
class Vector
{
public:
	Vector();
	~Vector();
	Vector(const Vector<T>&);
	Vector<T>& operator=(const Vector<T>&);
	T& operator[](size_t);
	void insertAt(const T&,size_t);
	void pushBack(T);
	void print() const;
	void clear();
	friend std::ostream& operator <<(std::ostream& out, const Vector<T>& vector)
	{
		for (size_t i = 0; i < vector.size ; ++i)
		{
			out << vector.vector[i] << " ";
		}
		return out;
	}
	friend std::istream& operator >>(std::istream& in, const Vector<T>& vector)
	{
		for (size_t i = 0; i < vector.size; ++i)
		{
			in >> vector.vector[i];
		}
		return in;
	}
	size_t getSize() const;
private:
	size_t size;
	size_t capacity;
	T* vector;
	void copy(const Vector<T>&);
	void resize();
	void erase();
};


template<typename T>
inline Vector<T>::Vector()
{
	this->size = 0;
	this->capacity = 8;
	this->vector = new T[capacity];
}

template<typename T>
inline Vector<T>::~Vector()
{
	this->erase();
}

template<typename T>
inline Vector<T>::Vector(const Vector<T>& otherVector)
{
	this->copy(otherVector);
}

template<typename T>
inline Vector<T>& Vector<T>::operator=(const Vector<T>& otherVector)
{
	if (this != &otherVector)
	{
		this->erase();
		this->copy(otherVector);
	}
	return *this;
}

template<typename T>
inline T& Vector<T>::operator[](size_t index)
{
	return this->vector[index];
}

template<typename T>
inline void Vector<T>::insertAt(const T& element, size_t index)
{
	if (size >= capacity)
	{
		this->resize();
	}
	for (size_t i = size ; i > index; --i)
	{
		vector[i] = vector[i - 1];
	}
	this->size++;
	this->vector[index] = element;
}

template<typename T>
inline void Vector<T>::pushBack(T newElement)
{
	if (size >= capacity)
	{
		this->resize();
	}
	this->vector[size++] = newElement;
}

template<typename T>
inline void Vector<T>::print() const
{
	std::cout << this->size << std::endl;
	std::cout << this->capacity << std::endl;
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << vector[i];
		if (i != size - 1)
		{
			std::cout << " | ";
		}
	}
	std::cout << std::endl;
}

template<typename T>
inline void Vector<T>::clear()
{
	this->size = 0;
	this->capacity = 8;
	this->erase();
	this->vector = new T[capacity];
}

template<typename T>
inline size_t Vector<T>::getSize() const
{
	return this->size;
}

template<typename T>
inline void Vector<T>::copy(const Vector<T>& otherVector)
{
	this->vector = new T[otherVector.capacity];
	this->size = otherVector.size;
	this->capacity = otherVector.capacity;
	for (size_t i = 0; i < size; ++i)
	{
		this->vector[i] = otherVector.vector[i];
	}
}

template<typename T>
inline void Vector<T>::resize()
{
	this->capacity *= 2;
	T* newVector = new T[capacity];
	for (size_t i = 0; i < size; ++i)
	{
		newVector[i] = this->vector[i];
	}
	delete[] vector;
	this->vector = newVector;
}

template<typename T>
inline void Vector<T>::erase()
{	
	delete[] this->vector;
}
