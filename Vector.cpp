#include "Vector.h"
#include "iostream"
#include <cassert>

void Vector::clean() {
	delete[] varr;
	varr = nullptr;
}

void Vector::copy(const Vector& other) {
	vsize = other.vsize;
	vcapacity = other.vcapacity;
	varr = new int[vcapacity];
	for (int i = 0; i < vsize; i++) {
		varr[i] = other.varr[i];
	}
}

Vector::~Vector() {
	clean();
}

Vector& Vector::operator=(const Vector& other) {
	if (this != &other) {
		clean();
		copy(other);
	}
	return *this;
}

Vector::Vector(const int* arr[4], const int size, const int capacity) {
	
	vsize = size;
	vcapacity = capacity;
	for (int i = 0; i < vsize; i++) {
		varr[i] = *arr[i];
	}
}

const int Vector::size() const
{
	return vsize;
}

const int Vector::capacity() const
{
	return vcapacity;
}

int& Vector::at(size_t index) const
{
	if(index >= vsize) {
		throw "Out of range.";
	};
	return varr[index];
}

void Vector::push_back(const int element)
{
	varr[vsize] = element;
	vsize++;
}

void Vector::erase(const int index)
{
	if (index >= vsize) {
		throw "Out of range.";
	};

	for (int i = index; i < vsize - 1; i++) {
		varr[i] = varr[i + 1];
	}
	vsize--;
}

void Vector::reserve(size_t capacity)
{
	int* arr = new int[capacity];
	for (int i = 0; i < std::min(capacity, vsize); i++) {
		arr[i] = varr[i];
	}
	delete[] this->varr;
	this->varr = arr;
}

