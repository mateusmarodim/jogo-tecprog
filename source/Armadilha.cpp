#include "../headers/../headers/Armadilha.h"

Armadilha::Armadilha(const Vetor2F Pos,const  Vetor2F Vel,const  Vetor2F Tam):
	Obstaculo(Pos, Vel, Tam, "texture/trap.png")
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
