#include "../headers/SlimeDaSelva.h"
#include <iostream>

namespace inimigo
{
	SlimeDaSelva::SlimeDaSelva(const Vetor2F pos, const  Vetor2F vel, const  Vetor2F tam) :
		Inimigo(pos, vel, tam, "texture/jungleslime.png"),
		veloX{100.0f}, posxInicial{pos.x}
	{
		velocidade.y = 50.0f;
		velocidade.x = 100.0f;
		podePular = false;
	}

	SlimeDaSelva::~SlimeDaSelva()
	{

	}

	void SlimeDaSelva::atualizar(float t)
	{
		if (posxInicial + 100.0 <= posicao.x)
		{
			velocidade.x = -veloX;
		}
		else if (posxInicial - 100.0 >= posicao.x)
		{
			velocidade.x = veloX;
		}
		posicao.x += velocidade.x * t;
		posicao.y += velocidade.y * t;
	}


}

