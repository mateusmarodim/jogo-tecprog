#include "Principal.h"
#include <iostream>
//#include "Vetor2D.h"

Principal::Principal():
	teste(&relogio,&gerenciadorGrafico,"texture/back.png")
{


}

Principal::~Principal()
{

}

int Principal::executar()
{
	relogio.restart();

	while (gerenciadorGrafico.getJanela()->isOpen())
	{
		sf::Time t = relogio.getElapsedTime();
		relogio.restart();
		sf::Event event;

		while (gerenciadorGrafico.getJanela()->pollEvent(event))
		{
		
			if (event.type == sf::Event::Closed)
				gerenciadorGrafico.getJanela()->close();
		}


		teste.atualizar(t.asSeconds());
	}
	return 0;
}
