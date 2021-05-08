#pragma once
#include "GerenciadorColisoes.h"
#include "ListaEntidade.h"
#include "SlimeSorridente.h"
#include "SlimeAmigo.h"
#include "SlimeEspinhoso.h"
#include "SlimeDaSelva.h"
#include "Bau.h"
#include "Piso.h"
#include <vector>

using namespace inimigo;
using namespace jogador;

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

	SlimeDaSelva* pSlimeDS;
	SlimeEspinhoso* pSlimeE;
	Bau* pBau;
	Piso* pPiso;

	bool podeAtirar;
	bool podePausar;

public:
	Fase(sf::Clock* rf, GerenciadorGrafico* gg, string cb);
	virtual ~Fase();

	enum Situacao
	{
		passarDeFase, terminarJogo, continuar
	};

	virtual void adicionaEntidade(EntidadeColidivel* entidade,std::string tipoEntidade);
	virtual void atualizar(float t);
	virtual void carregarBackground();
	virtual void desenharBackground();

	virtual void incluir() = 0;
	virtual void incluirSlimeDaSelva() = 0;
	virtual void incluirSlimeEspinhoso() = 0;
	virtual void incluirBau() = 0;
	virtual void incluirFixos() = 0;
	virtual Situacao fimFase() = 0;
	
	virtual void deletaProjetil(Espinho* pproj);

	virtual void setPodeAtirar(bool ppa);
	virtual bool getPodeAtirar();

	
	virtual void pausar();
	virtual void gerenciarP2();

};

