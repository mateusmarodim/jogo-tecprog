#pragma once
#include "Inimigo.h"

class Inimigo1 : public Inimigo
{
public:
	Inimigo1(Vetor2F Pos = (0.0, 0.0), Vetor2F Vel = (0.0, 0.0));
	~Inimigo1();

	void inicializar(GerenciadorGrafico& g);
	void desenhar(GerenciadorGrafico& g);
	void atualizar(float t);
};

