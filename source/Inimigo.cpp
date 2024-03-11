#include "../headers/Inimigo.h"

namespace inimigo
{
	Inimigo::Inimigo(const Vetor2F Pos, const Vetor2F Vel, const Vetor2F Tam, const string CaminhoText) :
		Personagem(Pos, Vel, Tam, CaminhoText)
	{
	}

	Inimigo::~Inimigo()
	{
	}
	void Inimigo::colidir(EntidadeColidivel* outro, std::string tipoEntidade)
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
}


