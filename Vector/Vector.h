#pragma once
#include <stdexcept>

template <typename T>
class Vector
{
public:
	Vector();
	Vector(const Vector& vector);
	~Vector();

	T* data;

	void PushBack(const T& value);
	void Insert(const T& value, const int& index);
	void Remove(const int& index);
	void Clear();

	int Find(const T& value);
	int Size() { return size; };

	typedef T* iterator;
	iterator Begin() { return data; }
	iterator End() { return &data[size]; }

	iterator Iterator() { return Begin();  }

	T& operator [] (int index)
	{
		if (index >= size || index < 0)
		{
			throw std::out_of_range("Index is Out of Range!");
		}

		return data[index];
	}

	T operator [] (int index) const
	{
		if (index >= size || index < 0)
		{
			throw std::out_of_range("Index is Out of Range!");
		}

		return data[index];
	}

private:
	int size = 0;
	int capacity = 1;

	void IncreaseCapacity();
};

template <typename T>
Vector<T>::Vector()
{
	data = new T[capacity];
}

template <typename T>
Vector<T>::Vector(const Vector& vector)
{
	data = new T[vector.Size()];
	for (T* itr = vector.Begin(); itr < vector.End(); itr++)
	{
		this.Pushback(itr);
	}
	size = vector.Size();
}

template <typename T>
Vector<T>::~Vector()
{
	delete[] data;
	data = nullptr;
}

template <typename T>
void Vector<T>::PushBack(const T& value)
{
	if (size >= capacity)
	{
		IncreaseCapacity();
	}

	*End() = value;
	size++;
}

template <typename T>
void Vector<T>::Insert(const T& value, const int& index)
{
	if (index >= size || index < 0)
	{
		throw std::out_of_range("Index is Out of Range!");
	}

	if (size + 1 >= capacity)
	{
		IncreaseCapacity();
	}

	for (T* itr = End() + 1; itr > Begin() + index; itr--)
	{
		*itr = *(itr - 1);
	}

	data[index] = value;
	size++;
}

template <typename T>
void Vector<T>::Remove(const int& index)
{
	if (index >= size || index < 0)
	{
		throw std::out_of_range("Index is Out of Range!");
	}

	for (T* itr = Begin() + index; itr < End(); itr++)
	{
		*itr = *(itr + 1);
	}
	
	size--;
}

template <typename T>
int Vector<T>::Find(const T& value)
{
	for (int i = 0; i < size; i++)
	{
		if (data[i] == value)
		{
			return i;
		}
	}
}

template <typename T>
void Vector<T>::Clear()
{
	delete[] data;
	size = 0;
}

template <typename T>
void Vector<T>::IncreaseCapacity()
{
	capacity *= 2;

	T* newArray = new T[capacity];

	int i = 0;
	for (T* itr = Begin(); itr < End(); itr++)
	{
		newArray[i] = *itr;
		i++;
	}

	delete[] data;
	data = newArray;
}