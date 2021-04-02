#include "Principal.h"

Principal::Principal() : 
	fechar{false},
	janela{ new sf::RenderWindow(sf::VideoMode(800, 600), "Jogo") }
{
	listaBonecos.inserir(new Personagem(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(100, 100), "Slime.png"));
	listaBonecos.inserir(new Personagem(sf::Vector2f(400.0f, 300.0f), sf::Vector2f(50, 50), "Slime.png"));
	listaBonecos.inserir(new Personagem(sf::Vector2f(200.0f, 200.0f), sf::Vector2f(75, 75), "Slime.png"));
}

Principal::~Principal()
{
	delete janela;

	listaBonecos.destruirPersonagens();
}

int Principal::executar()
{
	relogio.restart();

	sf::Event e;

	while (!fechar)
	{
		if (janela->pollEvent(e))
		{
			if ((e.type) == sf::Event::Closed)
			{
				fechar = true;
			}
		}
		sf::Time t = relogio.getElapsedTime();
		janela->clear();
		listaBonecos.atualizarPersonagens(t.asSeconds());
		listaBonecos.desenharPersonagens(janela);
		janela->display();

		relogio.restart();
	}
	return 0;
}
