#include "Principal.h"
#include <iostream>
//#include "Vetor2D.h"

Principal::Principal():
	//teste(&relogio,&gerenciadorGrafico,"texture/back.png")
	//fase1(&relogio, &gerenciadorGrafico, "texture/back.png"),
	//fase2(&relogio, &gerenciadorGrafico, "texture/caverna1.png")
	fase(nullptr)
{


}

Principal::~Principal()
{

}

int Principal::executar()
{
	relogio.restart();
	fase = new Selva(&relogio, &gerenciadorGrafico, "texture/back.png");

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

		fase->atualizar(t.asSeconds());

		if(fase->test() == true)
		{
			std::cout << "Entrei no teste da fase 1" << std::endl;
			delete fase;
			fase = new Caverna(&relogio, &gerenciadorGrafico, "texture/caverna1.png");
		}
	}
	return 0;
}
