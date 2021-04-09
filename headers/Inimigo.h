#pragma once
#include "Personagem.h"

class Inimigo : public Personagem
{
public:
	Inimigo(Vetor2F pos = (0.0, 0.0), Vetor2F vel = (0.0, 0.0), const char* caminhoText = nullptr);
	~Inimigo();

	virtual void inicializar(GerenciadorGrafico& g);
	virtual void desenhar(GerenciadorGrafico& g);
	virtual void atualizar(float t);
};

