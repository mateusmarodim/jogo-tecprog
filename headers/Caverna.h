#pragma once
#include "Fase.h"
#include "SlimeRei.h"

class Caverna : public Fase
{
public:
	Caverna(sf::Clock* rf, GerenciadorGrafico* gg, string cb);
	Caverna();
	~Caverna();

	void desenharBackground();

	void incluir();
	void incluirJungleslime();
	void incluirSpikedslime();
	void incluirArmadilha();
	void incluirBau();
	void incluirFixos();

	bool test();
};

