#pragma once
#include"Personagem.h"
#include <math.h>

class Jogador : public Personagem
{
protected:
	unsigned int vida;
	bool podepular;
	//sf::Clock cooldownDano;

	//bool colidindo;
	//GerenciadorEventos ge;
public:
	Jogador(const Vetor2F Pos = (0.0,0.0),const Vetor2F Vel = (0.0,0.0),const Vetor2F Tam = (0.0,0.0), const string CaminhoText=nullptr);
	virtual ~Jogador();

	//void desenhar(GerenciadorGrafico& gg);
	virtual void colidir(EntidadeColidivel* outro, std::string tipoEntidade);
	//controle
	//tratar
};

