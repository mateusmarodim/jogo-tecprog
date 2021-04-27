#include "King.h"
#include <iostream>

King::King(Vetor2F pos, Vetor2F vel, Vetor2F tam):
	Inimigo(pos,vel,tam,"texture/king.png")
{
	velocidade.y = 100.0f;
}

King::~King()
{
}

void King::atualizar(float t)
{
	posicao += velocidade * t;
}

void King::colidir(EntidadeColidivel* outro, std::string tipoEntidade)
{
	if (tipoEntidade == "jogador")
	{
		std::cout << "oi rs" << endl;
	}
	if (tipoEntidade == "tile")
	{
		velocidade.y = 0;
	}
}
