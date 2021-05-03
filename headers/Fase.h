#pragma once
#include "Bibs.h"
#include <vector>


class Fase
{
protected:
	GerenciadorGrafico* gerenciadorGrafico;
	GerenciadorColisoes gerenciadorColisoes;
	ListaEntidade listaboneco;
	const string caminhoBackground;

	std::vector<Vetor2F> posicoes;
	sf::Clock* relogiof;
	
	SlimeSorridente* pJogador1;
	SlimeAmigo* pJogador2;

	bool podeAtirar;
	bool podePausar;

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
	
	virtual void deletaEspinho(Espinho* pesp);

	virtual void setPodeAtirar(bool ppa);
	virtual bool getPodeAtirar();


	virtual void pausar();

	virtual void gerenciarP2();
};

