#pragma once
#include <stdexcept>
#include <cassert>
#include <iostream>

template <typename T>
class Vector
{
public:
	Vector();
	Vector(const Vector& vector);
	~Vector();

	void pushBack(const T& value);
	void insert(const T& value, int index);
	void remove(int index);
	void swapToRemove(int index);
	void clear();
	void add(const T& value);

	void sort();
	void search();

	 int find(const T& value);
	int size() { return _size; };
	int capacity() { return _capacity; };

	T* begin() { return _data; }
	T* end() { return _data + _size; }

	T& operator [] (int index)
	{
		assert(index < _size && index >= 0 && "Index is out of range");

		return _data[index];
	}

	const T& operator [] (int index) const
	{
		assert(index < _size && index >= 0 && "Index is out of range");

		return _data[index];
	}

private:
	T* _data;

	int _size = 0;
	int _capacity = 1;

	void increaseCapacity();
};

template <typename T>
Vector<T>::Vector()
	: _data(new T[1])
{}

template <typename T>
Vector<T>::Vector(const Vector& vector)
	: _data(new T[vector._capacity()])
{
	_size = vector._size();
	_capacity = vector._capacity();

	for (T* itr = vector.begin(); itr < vector.end(); itr++)
	{
		pushback(itr);
	}
}

template <typename T>
Vector<T>::~Vector()
{
	delete[] _data;
}

template <typename T>
void Vector<T>::pushBack(const T& value)
{
	if (_size >= _capacity)
	{
		increaseCapacity();
	}

	_data[_size++] = value;
}

template <typename T>
void Vector<T>::insert(const T& value, int index)
{
	assert(index < _size && index >= 0 && "Index is out of range");

	if (_size >= _capacity)
	{
		increaseCapacity();
	}

	for (int i = _size; i > index; i--)
	{
		_data[i] = _data[i - 1];
 	}
	_data[index] = value;

	_size++;
}

template <typename T>
void Vector<T>::remove(int index)
{
	assert(index < _size && index >= 0 && "Index is out of range");

	// Todo: föredrar att du inte använder end() utan data, samma som ovan, borde kalla swapToRemove

	//index = *(end() - 1);

	for (int i = index; i < _size - 1; i++)
	{
		_data[i] = _data[i + 1];
	}
	
	_size--;
}

template <typename T>
void Vector<T>::swapToRemove(int index)
{
	assert(index < _size && index >= 0 && "Index is out of range");

	index = _data[--size];
}

template <typename T>
int Vector<T>::find(const T& value)
{
	for (int i = 0; i < _size; i++)
	{
		if (_data[i] == value)
		{
			return i;
		}
	}
	return -1;
}

template <typename T>
void Vector<T>::clear()
{
	delete[] _data;
	_size = 0;
}

template <typename T>
void Vector<T>::add(const T& value)
{
	if (_size >= _capacity)
	{
		increaseCapacity();
	}

	*end() = *begin();
	*begin = value;
	_size++;
}

template <typename T>
void Vector<T>::increaseCapacity()
{
	_capacity *= 2;

	T* newArray = new T[_capacity];

	try
	{
		for (int i = 0; i < _size; i++)
		{
			newArray[i] = _data[i];
		}
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception thrown with message: " << e.what() << std::endl;
	}
	
	delete[] _data;
	_data = newArray;
}