#include "../headers/Slimers.h"
#include <iostream>
//#include "../headers/Vetor2D.h"

Slimers::Slimers()
{
	menu = nullptr;
	fase = nullptr;
}

Slimers::~Slimers()
{

}

int Slimers::executar()
{
	relogio.restart();
	menu = new Menu("texture/menuPrincipal.png",&gerenciadorGrafico);
	menu->inicializar();
	
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

		
		
		if (menu)
		{
			menu->atualizar();
			if (menu->opcaoSelecionada() == 1 && menu->getSelecionarFase())
			{
				menu->setSelecionarFase(false);
				menu->trocarMenu("texture/menuSelecao.png");
			}
			else if (menu->opcaoSelecionada() == 4 && menu->getSelecionarFase())
			{
				gerenciadorGrafico.getJanela()->close();
			}

			if (menu->opcaoSelecionada() == 2 && !menu->getSelecionarFase())
			{
				fase = new Selva(&relogio, &gerenciadorGrafico, "texture/selva.png");
				delete menu;
				menu = nullptr;
				relogio.restart();
			}

			if(menu->opcaoSelecionada() == 3 && !menu->getSelecionarFase() )
			{
				fase = new Caverna(&relogio, &gerenciadorGrafico, "texture/caverna.png");
				delete menu;
				menu = nullptr;
				relogio.restart();
			}
			
		}

		if (!menu)
		{
			fase->atualizar(t.asSeconds());

			if (fase->fimFase() == 0)
			{
				delete fase;
				fase = new Caverna(&relogio, &gerenciadorGrafico, "texture/caverna.png");
				relogio.restart();
			}
			if (fase->fimFase() == 1)
			{
				gerenciadorGrafico.getJanela()->close();
			}
		}
		
	}
	return 0;
}
