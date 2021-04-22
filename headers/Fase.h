#pragma once
#include "Bibs.h"

class Fase
{
protected:
	GerenciadorGrafico gerenciadorGrafico;
	GerenciadorColisoes gerenciadorColisoes;
	ListaEntidade listaboneco;
	sf::Clock* relogiof;

public:
	Fase(sf::Clock* rf);
	~Fase();

	//void adicionaEntidade(EntidadeColidivel* entidade,std::string tipoEntidade);
	void atualizar();
};

