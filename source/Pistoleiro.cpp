#include "Pistoleiro.h"
#include <iostream>

Pistoleiro::Pistoleiro(Fase* fs, Vetor2F pos, Vetor2F vel, Vetor2F tam):
	Inimigo(pos, vel, tam, "texture/Pistoleirot.png")
{
	fase = fs;
}

Pistoleiro::~Pistoleiro()
{
}

void Pistoleiro::atualizar(float t)
{
	float tempo = cooldownTiro.getElapsedTime().asSeconds();

	if (tempo >= 5.0) 
	{
		atirar();
		std::cout << "dentro if" << std::endl;
		

		cooldownTiro.restart();
	}
}

void Pistoleiro::colidir(EntidadeColidivel* outro, std::string tipoEntidade)
{
	//std::cout << "ai" << std::endl;
}
void Pistoleiro::atirar()
{
	Projetil* proj = nullptr;
    proj = new Projetil(Vetor2F(getPosicao().x-20.0f,getPosicao().y),Vetor2F(10.0,0.0),Vetor2F(0.0,0.0));
	std::cout << "ta criado" << std::endl;
	fase->adicionaEntidade(proj, "tiro");
	
}