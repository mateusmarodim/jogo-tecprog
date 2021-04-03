#include "Principal.h"
#include <iostream>
//#include "Vetor2D.h"
//Vetor2F(220.0, 220.0), Vetor2F(5, 5), "Slime.png"
Principal::Principal()
{
	listaboneco.inserir(new Personagem(Vetor2F(220.0, 220.0), Vetor2F(5, 5), "Slime.png"));
	listaboneco.inserir(new Personagem(Vetor2F(500.0, 220.0), Vetor2F(5, 5), "Slime.png"));

	listaboneco.iniciliazarPersonagem(gerenciadorGrafico);
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
		//gerenciadorEventos.eventos();

		gerenciadorGrafico.limpar();
	
		listaboneco.atualizar(t.asSeconds());

		listaboneco.desenharPersonagem(gerenciadorGrafico);

		gerenciadorGrafico.mostrar();

		
	}
	return 0;
}