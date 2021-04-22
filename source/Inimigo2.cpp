#include "Inimigo2.h"

Inimigo2::Inimigo2(Vetor2F pos, Vetor2F vel, Vetor2F tam):
	Inimigo(pos,vel,tam,"texture/lightblue.png")
{
}

Inimigo2::~Inimigo2()
{
}

void Inimigo2::atualizar(float t)
{
	//posicao = velocidade * t;
}

void Inimigo2::colidir(EntidadeColidivel* outro, std::string tipoEntidade)
{
	if (tipoEntidade == "jogador")
	{
		printf("te peguei boco");
	}
}

/*void Inimigo2::atirar(GerenciadorGrafico& g, float t)
{
}*/
