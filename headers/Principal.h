#pragma once
#include "Personagem.h"
#include "ListaPersonagem.h"


class Principal
{
private:
	bool fechar;
	sf::RenderWindow* janela;
	sf::Clock relogio;
	ListaPersonagem listaBonecos;
public:
	Principal();
	~Principal();
	int executar();
};

