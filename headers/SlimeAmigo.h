#pragma once
#include "Jogador.h"

class SlimeAmigo : public Jogador
{
public:
	SlimeAmigo(const Vetor2F Pos = (0.0, 0.0), const Vetor2F Vel = (0.0, 0.0), const Vetor2F Tam = (0.0, 0.0));
	~SlimeAmigo();

	void atualizar(float t);
};

