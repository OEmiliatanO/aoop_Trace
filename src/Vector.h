#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <vector>
#include <iostream>
#include "Trace.h"

using std::cout;
using std::cerr;
using std::endl;

template<class T>
class vector
{
private:
	std::vector<T> v;
public:
	vector(const size_t& size = 0): v(size) 
	{
		TRACE(Dump, "vector<T>::vector(int)");
		cerr << "   count = 1" << endl;
	}

	~vector()
	{
		TRACE(Dump, "vector<T>::~vector(int)");
		cerr << "   count = 1" << endl;
	}

	T& elem(const size_t& i) { return v[i]; }
	T& operator[](const size_t& i) { return v[i]; }
};

template<>
class vector<void*>
{
private:
	std::vector<void*> v;
	static int cnt;
public:
	vector(const size_t& size = 0): v(size) 
	{
		TRACE(Dump, "vector<void*>::vector(int)");
		cerr << "   count = " << ++cnt << endl;
	}

	~vector()
	{
		TRACE(Dump, "vector<void*>::~vector(int)");
		cerr << "   count = " << cnt-- << endl;
	}

	void*& elem(const size_t& i) { return v[i]; }
	void*& operator[](const size_t& i) { return v[i]; }

};

template<typename T>
class vector<T*> : private vector<void*>
{
private:
	std::vector<T*> v;
public:
	vector(const size_t& size): vector<void*>(size), v(size)
	{
		TRACE(Dump, "vector<T*>::vector(int)");
	}
	~vector()
	{
		TRACE(Dump, "vector<T*>::~vector(int)");		
	}

	T*& elem(const size_t& i) { return v[i]; }
	T*& operator[](const size_t& i) { return v[i]; }
};

#endif
