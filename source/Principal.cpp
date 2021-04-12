#include "../headers/Principal.h"
#include <iostream>
//#include "Vetor2D.h"
//Vetor2F(220.0, 220.0), Vetor2F(5, 5), "Slime.png"
Principal::Principal()
{
	/*listaboneco.inserir(new Entidade(Vetor2F(220.0, 220.0), Vetor2F(5, 50), "Slime.png"));
	listaboneco.inserir(new Entidade(Vetor2F(200.0, 220.0), Vetor2F(100, 100), "sorvetao.jpg"));
	listaboneco.inserir(new Entidade(Vetor2F(500.0, 520.0), Vetor2F(5, 5), "possivel inimigo.png"));*/
	listaboneco.inserir(new Jogador(Vetor2F(400.0, 400.0)));
	listaboneco.inserir(new Inimigo1(Vetor2F(400.0 , 400.0)));

	//Jogador jogador(Vetor2F(200.0,400.0));
	//jogador.inicializar(gerenciadorGrafico);


	listaboneco.iniciliazarEntidade(gerenciadorGrafico);

	gerenciadorColisoes.inserirColidivel("jogador", static_cast<EntidadeColidivel*>(listaboneco.voltarInicio()));
	gerenciadorColisoes.inserirColidivel("inimigo", static_cast<EntidadeColidivel*>(listaboneco.irProx()));
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
		/*	else
			{
				jogador->tratarevento(event)
			}*/
		}

		gerenciadorGrafico.limpar();
		gerenciadorGrafico.centralizar(listaboneco.voltarInicio()->getPosicao());
		//gerenciadorEventos.eventos();
		
		//jogador.atualizar(t.asSeconds());
		listaboneco.atualizar(t.asSeconds());

		//jogador.desenhar(gerenciadorGrafico);
		listaboneco.desenharEntidade(gerenciadorGrafico);

		gerenciadorColisoes.verificaColisoes();

		gerenciadorGrafico.mostrar();


	}
	return 0;
}