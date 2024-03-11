#include "../headers/SlimeEspinhoso.h"
#include "../headers/Fase.h"
#include <iostream>

namespace inimigo
{
	SlimeEspinhoso::SlimeEspinhoso(Fase* fs, const Vetor2F Pos, const  Vetor2F Vel, const  Vetor2F Tam) :
		Inimigo(Pos, Vel, Tam, "texture/Pistoleirot.png")
	{
		proj = nullptr;
		fase = fs;
		posxInicial = Pos.x;
		podePular = false;
	}

	SlimeEspinhoso::~SlimeEspinhoso()
	{

	}

	void SlimeEspinhoso::atualizar(float t)
	{
		t = relogio.getElapsedTime().asSeconds();

		if (proj)
		{
			if (abs(proj->getPosicao().x - getPosicao().x) >= 100)
			{
				fase->deletaProjetil(proj);
				proj = nullptr;
			}
		}

		if (t >= 5.0 && fase->getPodeAtirar())
		{
			atirar();
			relogio.restart();
		}

	}
	void SlimeEspinhoso::atirar()
	{
		proj = new Espinho(Vetor2F(getPosicao().x - 20.0f, getPosicao().y), Vetor2F(10.0, 0.0), Vetor2F(0.0, 0.0));
		fase->adicionaEntidade(proj, "espinho");
	}
}


