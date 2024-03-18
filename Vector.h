#pragma once
class Vector
{
	size_t vsize;
	size_t vcapacity;
	int* varr;
	void clean();
	void copy(const Vector& other);

public:
	Vector()
		:vsize(0)
		,vcapacity(4)
		,varr(nullptr)
	{
		varr = new int[vcapacity];
	}

	~Vector();
	Vector(const Vector& other);
	Vector& operator=(const Vector& other);
	Vector(const int* arr[4], const int size, const int capacity);
	const int size() const;
	const int capacity() const;
	int& at(size_t index) const;
	void push_back(const int element);
	void erase(const int index);
	void reserve(size_t capacity);
};

