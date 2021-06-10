#pragma once

template <typename T>
class Vetor2D
{
public:
	T x, y;

	Vetor2D(T X = 0.0, T Y = 0.0);
	~Vetor2D();

	Vetor2D operator +(Vetor2D v);
	void operator +=(Vetor2D v);
	Vetor2D operator -(Vetor2D v);
	Vetor2D operator *(int i);
	Vetor2D operator *(float f);
	Vetor2D operator *(double d);
	bool operator <=(Vetor2D v);
	T operator *(Vetor2D v);

};

typedef Vetor2D<float> Vetor2F;
typedef Vetor2D<unsigned> Veotr2U;

#include "Vetor2DImplementacao.h"
