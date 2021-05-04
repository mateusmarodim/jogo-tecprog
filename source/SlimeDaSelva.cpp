#include "SlimeDaSelva.h"
#include <iostream>

SlimeDaSelva::SlimeDaSelva(const Vetor2F pos, const  Vetor2F vel, const  Vetor2F tam):
	Inimigo(pos, vel, tam, "texture/jungleslime.png")
{
	velocidade.y = 50.0f;
	velo = 100.0f;
	velocidade.x = 100.0f;
	posxInicial = pos.x;
}

SlimeDaSelva::~SlimeDaSelva()
{
}

void SlimeDaSelva::atualizar(float t)
{
	
	//velocidade.x = vel;

	if (posxInicial +100.0 <= posicao.x)
	{
		std::cout << posicao.x << endl;
		velocidade.x = -velo;
	}
	else if (posxInicial -100.0 >= posicao.x)
	{
		std::cout << posicao.x << endl;
		velocidade.x = velo;
	}
	posicao.x += velocidade.x *t;
	posicao.y += velocidade.y * t;
	//std::cout << posicao.x << endl;
}

void SlimeDaSelva::colidir(EntidadeColidivel* outro, std::string tipoEntidade)
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