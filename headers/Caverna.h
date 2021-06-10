#pragma once
#include "Fase.h"
#include "Armadilha.h"
#include "SlimeRei.h"

class Caverna : public Fase
{
private:
	Armadilha* pArmadilha;
	SlimeRei* pSlimeR;

public:
	Caverna(sf::Clock* rf, GerenciadorGrafico* gg ,string cb);
	~Caverna();

	void desenharBackground();
	void incluir();
	void incluirSlimeDaSelva();
	void incluirSlimeEspinhoso();
	void incluirArmadilha();
	void incluirBau();
	void incluirFixos();

	Situacao fimFase();
};

