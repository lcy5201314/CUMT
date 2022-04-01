#pragma once

#include <iostream>

using namespace std;


//重新定义int为Rank（秩）
typedef int Rank;


template<typename T> class Vector
{
	//私有变量
private:
	Rank _size;          //规模
	int _capacity;       //容量
	T* _elem;            //数据区域

public:
	Vector();
	~Vector();



};

template<typename T> Vector<T>::Vector()
{
}

template<typename T> Vector<T>::~Vector()
{
}

