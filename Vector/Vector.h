#pragma once
#include <stdexcept>

template <typename T>
class Vector
{
public:
	Vector();
	Vector(const Vector& vector);
	~Vector();

	void PushBack(const T& value);
	void Insert(const T& value, int index);
	void Remove(int index);
	void Clear();
	void Add(const T& value);

	void Sort();
	void Search();

	int Find(const T& value);
	int Size() { return size; };

	T* begin() { return data; }
	T* end() { return data + size; }
	T* Iterator() { return begin();  }

	T& operator [] (int index)
	{
		assert(index < size && index >= 0 && "Index was out of range");

		return data[index];
	}

	const T& operator [] (int index) const
	{
		assert(index < size && index >= 0 && "Index was out of range");

		return data[index];
	}

private:
	T* data;

	int size = 0;
	int capacity = 1;

	void IncreaseCapacity();
};

template <typename T>
Vector<T>::Vector()
	: data(new T[capacity])
{}

template <typename T>
Vector<T>::Vector(const Vector& vector)
	: data(new T[vector.Size()])
{
	for (T* itr = vector.begin(); itr < vector.end(); itr++)
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

	*end() = value;
	size++;
}

template <typename T>
void Vector<T>::Insert(const T& value, int index)
{
	assert(index < size && index >= 0 && "Index was out of range");

	if (size >= capacity)
	{
		IncreaseCapacity();
	}

	*end() = data[index];
	data[index] = value;

	size++;
}

template <typename T>
void Vector<T>::Remove(int index)
{
	assert(index < size && index >= 0 && "Index was out of range");

	index = *(end() - 1);
	
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
void Vector<T>::Add(const T& value)
{
	if (size >= capacity)
	{
		IncreaseCapacity();
	}

	*end() = *begin();
	*begin = value;
	size++;
}

template <typename T>
void Vector<T>::IncreaseCapacity()
{
	capacity *= 2;

	T* newArray = new T[capacity];

	try
	{
		int i = 0;
		for (T* itr = begin(); itr < end(); itr++)
		{
			newArray[i] = *itr;
			i++;
		}
	}
	catch (const std::exception& e)
	{
		std::cout << "exception thrown with message: " << e.what() << std::endl;
	}
	
	delete[] data;
	data = newArray;
}