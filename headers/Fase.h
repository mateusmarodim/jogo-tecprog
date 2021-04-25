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
	

public:
	Fase(sf::Clock* rf, GerenciadorGrafico* gg, string cb);
	Fase();
	~Fase();

	void adicionaEntidade(EntidadeColidivel* entidade,std::string tipoEntidade);
	void atualizar(float t);
	void carregarBackground();
	void desenharBackground();
	void incluirJungleslime();
	void incluirSpikedslime();
	void incluirBau();
	void incluirPlataformam();
	void incluirArmadilha();
	void incluirFixos();

	void deletaProjetil(Projetil* pproj);
};

