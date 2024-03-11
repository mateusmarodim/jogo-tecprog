#pragma once
#include "../headers/PlataformaMovedica.h"
#include "../headers/Fase.h"

class Selva : public Fase
{
private:
	PlataformaMovedica* pPlataformaM;

public:
	Selva(sf::Clock* rf, GerenciadorGrafico* gg, string cb);
	~Selva();

	void incluir();
	void incluirSlimeDaSelva();
	void incluirSlimeEspinhoso();
	void incluirBau();
	void incluirPlataformam();
	void incluirFixos();
	
	Situacao  fimFase();
};

