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

	if (posxInicial +100.0 >= posicao.x)
	{
		velocidade.x *= -1;
	}
	if (posxInicial -100.0 <= posicao.x)
	{
		velocidade.x *= -1;
	}
	posicao.x += velocidade.x *t;
	posicao.y += velocidade.y * t;
	//std::cout << posicao.x << endl;
}

void Inimigo1::colidir(EntidadeColidivel* outro, std::string tipoEntidade)
{
	Vetor2F distancia = posicao - outro->getPosicao();
	Vetor2F distanciaCentros = (tamanho + outro->getTamanho()) * 0.5;
	float intersectaX = abs(distancia.x) - distanciaCentros.x;
	float intersectaY = abs(distancia.y) - distanciaCentros.y;

	if (tipoEntidade == "tile")
	{
		if (intersectaX > intersectaY)
		{
			if (distancia.x > 0)
			{
				posicao.x += -1 * intersectaX;
			}
			else
			{
				posicao.x += 1 * intersectaX;
			}
			velocidade.y = 0.0f;
		}
		else
		{
			if (distancia.y > 0)
			{
				posicao.y += -1 * intersectaY;
			}
			else
			{
				posicao.y += 1 * intersectaY;
			}
		}
	}
}