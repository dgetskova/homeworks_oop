#pragma once 
#include "double_vector.h"
#include <iostream>
#include <algorithm>

DoubleVector::DoubleVector()
{
	size = 0;
	array = NULL;
}

 DoubleVector:: DoubleVector(int size_value, double* value)
{
	allocate(size_value);
	for (size_t i = 0; i < size; i++)
		array[i] = value[i];
}

DoubleVector::~DoubleVector(){ free(*this); }


DoubleVector DoubleVector::operator-() const
{
	return DoubleVector(*this) *= -1;
}


void DoubleVector::free(DoubleVector& vector)
{
	vector.size = 0;
	delete []vector.array;
}

void DoubleVector::toSize(const DoubleVector& other)
{
	if (size >= other.size)
		return;

	double *temp = NULL;
	try{
		temp = new double[other.size];
	}
	catch (std::bad_alloc) { std::cout << "Erroe with memory"; }

	
	//Sets the first num bytes of the block of memory pointed by ptr to the specified value(interpreted as an unsigned char).
	memset(temp, 0, sizeof(double)*other.size);
	memcpy(temp, array, sizeof(double) * size);

	delete[]array;
	array = temp;
	size = other.size;
	temp = NULL;
}

void DoubleVector::allocate(int size_came)
{
	size = size_came;
	try{
		this->array = new double[size];
	}
	catch (std::bad_alloc) { std::cout << "Erroe with memory"; }
	for (size_t i = 0; i < this->size; i++)
	{
		this->array[i] = 0;
	}
}

DoubleVector::DoubleVector(const DoubleVector& other)
{
	allocate(other.size);

	for (size_t i = 0; i < size; i++)
	{
		array[i] = other.array[i];
	}
}

DoubleVector& DoubleVector :: operator=(const DoubleVector& other)
{
	if (this != &other)
	{
		free(*this);
		allocate(other.size);
		for (size_t i = 0; i < size; i++)
		{
			array[i] = other.array[i];
		}
	}
	return *this;
}

bool DoubleVector :: is_in_bound(unsigned int index)const
{
	return (index >= 0 && index <= size);
}


double DoubleVector:: operator[](int index)
{
	if (!is_in_bound(index))
		return 0;
	
	return array[index];
}


DoubleVector  DoubleVector :: operator + (const DoubleVector& other)const 
{
	DoubleVector v(*this);
	v += other;
	return v;
}

DoubleVector& DoubleVector :: operator +=(const DoubleVector& other)
{

	toSize(other);
	//have to be other size because other size can be smaller than this size
	//in case for is until this->size we are accessing foreign memory
	for (size_t i = 0; i < other.size; i++)
		this->array[i] = this->array[i] + other.array[i];

	return *this;
}
void DoubleVector:: print()const
{
	std::cout << "size: " << this->size<<std::endl;
	for (size_t i = 0; i < this->size; i++)
		std::cout << "array[" << i << "] : " << this->array[i]<<std::endl;
}

DoubleVector DoubleVector::operator -(const DoubleVector& other)const
{
	DoubleVector result(*this);
	return result -= other;
}

DoubleVector& DoubleVector::operator -= (const DoubleVector& other)
{
	return *this+=(-other);//DoubleVector::operator+=
}

DoubleVector DoubleVector :: operator *(int number)const
{
	DoubleVector res(*this);
	res *= number;
	return res;
}

DoubleVector& DoubleVector :: operator *=(int number)
{
	for (size_t i = 0; i < this->size; i++)
		this->array[i] = this->array[i] * number;
	return *this;
}


DoubleVector  DoubleVector :: operator / (int number) const
{
	 DoubleVector to_return(*this);
	 to_return /= number;
	return to_return;
}

DoubleVector& DoubleVector :: operator/=(int number)
{
	for (size_t i = 0; i < size; i++)
		this->array[i] /= number;
	return *this;
}

double DoubleVector :: operator %(const DoubleVector& other)
{
	toSize(other);
	double scalar = 0;
	double part = 0;
	for (size_t i = 0; i < other.size; i++)
	{
		part = this->array[i] * other.array[i];
		scalar += part;
	}
	return scalar;
}