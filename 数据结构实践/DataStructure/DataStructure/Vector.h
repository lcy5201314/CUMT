#pragma once

#include <iostream>

using namespace std;


//���¶���intΪRank���ȣ�
typedef int Rank;


template<typename T> class Vector
{
	//˽�б���
private:
	Rank _size;          //��ģ
	int _capacity;       //����
	T* _elem;            //��������

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

