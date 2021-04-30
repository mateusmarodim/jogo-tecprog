#pragma once
#include "Bibs.h"
#include <vector>

class Fase
{
protected:
	GerenciadorGrafico* gerenciadorGrafico;
	GerenciadorColisoes gerenciadorColisoes;
	ListaEntidade listaboneco;
	sf::Clock* relogiof;
	std::vector<Vetor2F> posicoes;
	const string caminhoBackground;

	Jogador* pjogador;
	

public:
	Fase(sf::Clock* rf, GerenciadorGrafico* gg, string cb);
	Fase();
	virtual ~Fase();

	virtual void adicionaEntidade(EntidadeColidivel* entidade,std::string tipoEntidade);
	virtual void atualizar(float t);
	virtual void carregarBackground();
	virtual void desenharBackground();

	virtual void incluir() = 0;
	virtual void incluirSpikedslime() = 0;
	virtual void incluirBau() = 0;
	virtual void incluirFixos() = 0;
	
	virtual void deletaProjetil(Projetil* pproj);

	virtual void pausar();
};

