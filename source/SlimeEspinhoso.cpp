#include "SlimeEspinhoso.h"
#include <iostream>

SlimeEspinhoso::SlimeEspinhoso(Fase* fs,const Vetor2F Pos, const  Vetor2F Vel, const  Vetor2F Tam):
	Inimigo(Pos, Vel, Tam, "texture/Pistoleirot.png")
{
	esp = nullptr;
	fase = fs;
	posxInicial = Pos.x;
}

SlimeEspinhoso::~SlimeEspinhoso()
{

}

void SlimeEspinhoso::atualizar(float t)
{
	// float tempo = cooldownTiro.getElapsedTime().asSeconds();
	t = relogio.getElapsedTime().asSeconds();

	if (esp)
	{
		if (abs(esp->getPosicao().x - getPosicao().x) >= 100)
		{	
			fase->deletaProjetil(esp);
			esp = nullptr;
		}
	}

	if (t >= 5.0 && !fase->getPodeAtirar())
	{
		atirar();
		relogio.restart();
	}

}

void SlimeEspinhoso::colidir(EntidadeColidivel* outro, std::string tipoEntidade)
{
	//std::cout << "ai" << std::endl;
}
void SlimeEspinhoso::atirar()
{
    esp = new Espinho(Vetor2F(getPosicao().x-20.0f,getPosicao().y),Vetor2F(10.0,0.0),Vetor2F(0.0,0.0));
	fase->adicionaEntidade(esp, "bala");
	
}

