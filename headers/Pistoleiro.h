#pragma once
#include "Fase.h"


class Fase;

class Pistoleiro : public Inimigo
{
private:
    Fase* fase;
    sf::Clock cooldownTiro;
	int posxInicial;
	Projetil* proj;
public:
	Pistoleiro(Fase* fs = nullptr, Vetor2F pos = (0.0, 0.0), Vetor2F vel = (0.0, 0.0), Vetor2F tam = (0.0,0.0));
	~Pistoleiro();

	//void desenhar(GerenciadorGrafico& g);
	void atualizar(float t);
	void colidir(EntidadeColidivel* outro, std::string tipoEntidade);
    void atirar();
};