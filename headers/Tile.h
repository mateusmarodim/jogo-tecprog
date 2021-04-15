#pragma once
#include "EntidadeColidivel.h"

class Tile : public EntidadeColidivel
{
public:
	Tile(Vetor2F pos = (0.0, 0.0), Vetor2F vel = (0.0, 0.0), Vetor2F tam = (0.0, 0.0));
	Tile();

	void desenhar(GerenciadorGrafico& g);
	void atualizar(float t);
	void colidir(EntidadeColidivel* outro, std::string tipoEntidade);
};