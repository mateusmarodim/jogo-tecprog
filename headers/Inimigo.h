#pragma once
#include "EntidadeColidivel.h"

class Inimigo : public EntidadeColidivel
{
public:
	Inimigo(Vetor2F pos = (0.0, 0.0), Vetor2F vel = (0.0, 0.0), const char* caminhoText = nullptr);
	~Inimigo();

	virtual void inicializar(GerenciadorGrafico& g);
	virtual void desenhar(GerenciadorGrafico& g);
};

