#pragma once
#include "Inimigo.h"
#include "Principal.h"

class Principal;

class Pistoleiro : public Inimigo
{
private:
    Principal *fase;
    sf::Clock cooldownTiro;
public:
	Pistoleiro(Vetor2F pos = (0.0, 0.0), Vetor2F vel = (0.0, 0.0), Vetor2F tam = (0.0,0.0));
	~Pistoleiro();

	//void desenhar(GerenciadorGrafico& g);
	void atualizar(float t);
	void colidir(EntidadeColidivel* outro, std::string tipoEntidade);
    void atirar();
};