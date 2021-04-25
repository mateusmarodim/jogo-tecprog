#include "Inimigo1.h"
#include <iostream>

Inimigo1::Inimigo1(Vetor2F pos, Vetor2F vel, Vetor2F tam):
	Inimigo(pos, vel, tam, "texture/jungleslime.png")
{
	velocidade.y = 100.0f;
	velocidade.x = 100.0f;
	posxInicial = pos.x;
	teste = false;
}

Inimigo1::~Inimigo1()
{
}

void Inimigo1::atualizar(float t)
{
	
	//velocidade.x = 100.0f;

	if (posxInicial +100 >= posicao.x)
	{
		velocidade.x *= -1;
	}
	if (posxInicial -100 <= posicao.x)
	{
		velocidade.x *= -1;
	}
	posicao.x += velocidade.x *t;
	posicao.y += velocidade.y * t;
	//std::cout << posicao.x << endl;
}

void Inimigo1::colidir(EntidadeColidivel* outro, std::string tipoEntidade)
{
	if (tipoEntidade == "tile")
	{
		velocidade.y = 0;
	}
}