#pragma once
#include <cmath>
#include "../headers/Vetor2D.h"

template <typename T>
Vetor2D<T>::Vetor2D(T X, T Y):
x{X} ,y{Y}
{

}

template <typename T>
Vetor2D<T>::~Vetor2D()
{

}

template <typename T>
Vetor2D<T> Vetor2D<T>::operator +(Vetor2D<T> v)
{
	return Vetor2D<T>(x + v.x, y + v.y);
}

template <typename T>
void Vetor2D<T>::operator +=(Vetor2D<T> v)
{
	x += v.x;
	y += v.y;
}

template <typename T>
Vetor2D<T> Vetor2D<T>::operator -(Vetor2D<T> v)
{
	return Vetor2D<T>(x - v.x, y - v.y);
}

template <typename T>
Vetor2D<T> Vetor2D<T>:: operator *(int i)
{
	return Vetor2D<T>(x * i, y * i);
}

template <typename T>
Vetor2D<T> Vetor2D<T>:: operator *(float f)
{
	return Vetor2D<T>(x * f, y * f);
}

template <typename T>
Vetor2D<T> Vetor2D<T>:: operator *(double d)
{
	return Vetor2D<T>(x * d, y * d);
}

template <typename T>
T Vetor2D<T>::operator *(Vetor2D<T> v)
{
	return x * v.x + y * v.y;
}

template <typename T>
bool Vetor2D<T>::operator <=(Vetor2D v)
{
	if(this->x <= v.x && this->y <= v.y)
	{
		return true;
	}
	return false;
}
