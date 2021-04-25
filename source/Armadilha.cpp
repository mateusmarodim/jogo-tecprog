#include "Armadilha.h"

Armadilha::Armadilha(Vetor2F pos, Vetor2F vel, Vetor2F tam):
	Obstaculo(pos, vel, tam, "texture/trap.png")
{
	velocidade.y = 100.0f;
}

Armadilha::~Armadilha()
{
}

void Armadilha::atualizar(float t)
{
	posicao += velocidade * t;
}

void Armadilha::colidir(EntidadeColidivel* outro, std::string tipoEntidade)
{
	if (tipoEntidade == "tile")
	{
		velocidade.y = 0;
	}
}
