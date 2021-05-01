#pragma once
#include "Fase.h"

class Selva : public Fase
{

public:
	Selva(sf::Clock* rf, GerenciadorGrafico* gg, string cb);
	Selva();
	~Selva();

	void incluir();
	void incluirJungleslime();
	void incluirSpikedslime();
	void incluirBau();
	void incluirPlataformam();
	void incluirFixos();
	
	bool test();
};

