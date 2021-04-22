#include "Pistoleiro.h"
#include <iostream>

Pistoleiro::Pistoleiro(Vetor2F pos, Vetor2F vel, Vetor2F tam):
	Inimigo(pos, vel, tam, "texture/red.png")
{
}

Pistoleiro::~Pistoleiro()
{
}

void Pistoleiro::atualizar(float t)
{
	float tempo = cooldownTiro.getElapsedTime().asSeconds();
	atirar();
	if (tempo >= 5.0) 
	{
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
	/*Projetil* proj = nullptr;
    proj = new Projetil(Vetor2F(getPosicao().x-20.0f,getPosicao().y-20.0f),Vetor2F(10.0,0.0),Vetor2F(0.0,0.0));
	std::cout << "ta criado" << std::endl;
	fase->adicionaEntidade(proj, "tiro");*/
	
}