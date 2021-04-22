#include "Armadilha.h"

Armadilha::Armadilha(Vetor2F pos, Vetor2F vel, Vetor2F tam):
	Obstaculo(pos, vel, tam, "texture/pink.png")
{
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
}
