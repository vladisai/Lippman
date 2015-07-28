#include <bits/stdc++.h>

using namespace std;

template<typename T>
class Vector
{
	public:

		Vector() = default;		
		Vector(const int &sz);
		Vector(const int &sz, const T &val);
		Vector(const initializer_list<T> &li);
		Vector(initializer_list<T> &&li);	
		Vector(const Vector<T> &v);
		Vector(Vector<T> &&v);

		void push_back(const T &val);
		void push_back(T &&val);

		T& front() &;
		const T& front() const &;
		T&& front() &&;

		T& back() &;
		const T& back() const &;
		T&& back() &&;

		int size() const;
		void resize(const int &nsize);
		void reserve(const int &nsize);

		Vector<T>& operator = (const Vector<T> &v);
		Vector<T>& operator = (Vector<T> &&v);

		T& operator [] (const int &ind);	
		const T& operator [] (const int &ind) const;

		~Vector();

	private:
		allocator<T> al;
		T *start;
		int reserved = 0;
		int currentSize = 0;

		void reallocate(const int &nsize);

};
