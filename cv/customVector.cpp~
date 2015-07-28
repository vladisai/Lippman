#include "customVector.h"

template<typename T>
Vector<T>::Vector(const int &n)
{
	start = al.allocate(n);	
	T *ptr = start;
	while (ptr != start + n)
		al.construct(ptr++);
	reserved = n;
	currentSize = n;
}

template<typename T>
Vector<T>::Vector(const int &n, const T &val)
{
	cerr << "initialier n t" << endl;
	start = al.allocate(n);	
	T *ptr = start;
	while (ptr != start + n)
		al.construct(ptr++, val);
	reserved = n;
	currentSize = n;
}

template<typename T>
Vector<T>::Vector(initializer_list<T> &&li)
{
	cerr << "initializer && " << endl;
	start = al.allocate(li.size());
	T *ptr = start;
	auto it = li.begin();
	while (ptr != start + li.size())
		al.construct(ptr++, std::move(*it)), it++; 
	reserved = li.size();
	currentSize = li.size();
}

template<typename T>
Vector<T>::Vector(const initializer_list<T> &li)
{
	start = al.allocate(li.size());
	T *ptr = start;
	auto it = li.begin();
	while (ptr != start + li.size())
		al.construct(ptr++, *it++); 
	reserved = li.size();
	currentSize = li.size();
}

template<typename T>
Vector<T>::Vector(const Vector<T> &v)
{
	start = al.allocate(v.size());
	T *ptr = start;
	while (ptr != start + v.size())
		al.construct(ptr++, v[ptr - start]);
	reserved = v.size();
	currentSize = v.size();
}

template<typename T>
Vector<T>::Vector(Vector<T> &&v)
{
	cerr << "initializer from &&v " << endl;
	start = v.start;
	currentSize = v.currentSize;
	reserved = v.reserved;
	v.start = 0;
	v.currentSize = 0;
	v.reserved = 0;
}

template<typename T>
void Vector<T>::push_back(const T &val)
{
	if (reserved == currentSize)
	{
		reallocate(reserved * 2);
	}
	al.construct(start + currentSize, val);
	currentSize++;
}

template<typename T>
void Vector<T>::push_back(T &&val)
{
	if (reserved == currentSize)
	{
		reallocate(reserved * 2);
	}
	al.construct(start + currentSize, val);
	currentSize++;
}

template<typename T>
T& Vector<T>::front() &
{
	return *start;	
}

template<typename T>
const T& Vector<T>::front() const &
{
	return *start;
}

template<typename T>
T&& Vector<T>::front() &&
{
	return std::move(*start);
}

template<typename T>
T& Vector<T>::back() &
{
	return *(start + currentSize - 1);	
}

template<typename T>
const T& Vector<T>::back() const &
{
	return *(start + currentSize - 1);
}

template<typename T>
T&& Vector<T>::back() &&
{
	return std::move(*(start + currentSize - 1));
}

template<typename T>
int Vector<T>::size() const
{
	return currentSize;	
}

template<typename T>
void Vector<T>::resize(const int &nsize)
{
	if (nsize < currentSize)
	{
		currentSize = nsize;
	}	
	else
	{
		if (nsize > reserved)
			reallocate(nsize);

		T *ptr = start + currentSize;
		while (ptr != start + nsize)
		{
			al.construct(ptr++);
		}
		currentSize = nsize;
	}
}

template<typename T>
void Vector<T>::reserve(const int &nsize)
{
	reallocate(nsize);
}

template<typename T>
Vector<T>& Vector<T> :: operator = (const Vector<T> &v)
{
	reserved = v.reserved;
	currentSize = v.currentSize;	
	start = al.allocate(currentSize);	
	T *ptr = start;
	while (*ptr != start + currentSize)
		al.construct(ptr++, v[ptr - start]);
	return *this;
}

template<typename T>
Vector<T>& Vector<T> :: operator = (Vector<T> &&v)
{
	cerr << "move = operator" << endl;
	start = v.start;
	currentSize = v.currentSize;
	reserved = v.reserved;	
	v.start = 0;
	v.currentSize = 0;
	v.reserved = 0;
	return *this;
}

template<typename T>
T& Vector<T> :: operator [] (const int &ind)
{
	return *(start + ind);	
}

template<typename T>
const T& Vector<T> :: operator [] (const int &ind) const
{
	return *(start + ind);
}

template<typename T>
void Vector<T>::reallocate(const int &nsize)
{
	T *nstart = al.allocate(nsize);
	while (start != start + min(currentSize, nsize))
	{
		al.construct(nstart++, std::move(*start++));
	}
	delete[] start;
	start = nstart;
	reserved = nsize;
}

template<typename T>
Vector<T>::~Vector()
{
	delete[] start;
}
