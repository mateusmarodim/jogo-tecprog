#include "SlimeEspinhoso.h"
#include <iostream>

SlimeEspinhoso::SlimeEspinhoso(Fase* fs,const Vetor2F Pos, const  Vetor2F Vel, const  Vetor2F Tam):
	Inimigo(Pos, Vel, Tam, "texture/Pistoleirot.png")
{
	proj = nullptr;
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

	if (proj)
	{
		if (abs(proj->getPosicao().x - getPosicao().x) >= 100)
		{
			//std::cout << "oi rs" << endl;
			
			fase->deletaProjetil(proj);
			proj = nullptr;
			//delete proj;
			//proj->setDeletar();
		}
	}

	if (t >= 5.0 && !fase->getPodeAtirar())
	{
		atirar();
		//std::cout << "atirei um corno" << endl;
		relogio.restart();
		//if(fase->pausar())
	}

}

void SlimeEspinhoso::colidir(EntidadeColidivel* outro, std::string tipoEntidade)
{
	//std::cout << "ai" << std::endl;
}
void SlimeEspinhoso::atirar()
{
    proj = new Projetil(Vetor2F(getPosicao().x-20.0f,getPosicao().y),Vetor2F(10.0,0.0),Vetor2F(0.0,0.0));
	//std::cout << "ta criado" << std::endl;
	fase->adicionaEntidade(proj, "bala");
	
	//if((proj->getPosicao().x-getPosicao().x))
	
}

