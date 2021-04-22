#include "Principal.h"
#include <iostream>
//#include "Vetor2D.h"
//Vetor2F(220.0, 220.0), Vetor2F(5, 5), "Slime.png"
Principal::Principal():
	teste(&relogio)
{
	/*
	/*listaboneco.inserir(new Entidade(Vetor2F(220.0, 220.0), Vetor2F(5, 50), "Slime.png"));
	listaboneco.inserir(new Entidade(Vetor2F(200.0, 220.0), Vetor2F(100, 100), "sorvetao.jpg"));
	listaboneco.inserir(new Entidade(Vetor2F(500.0, 520.0), Vetor2F(5, 5), "possivel inimigo.png"));
	listaboneco.inserir(new Jogador(Vetor2F(-100.0, 350.0)));
	listaboneco.inserir(new Inimigo1(Vetor2F(400.0 , 400.0)));
	listaboneco.inserir(new Pistoleiro(Vetor2F(-150.0, 400.0)));
	//listaboneco.inserir(new Tile(Vetor2F(300.0, 300.0)));
	listaboneco.inserir(new Tile(Vetor2F(300.0, 439.0)));
	listaboneco.inserir(new Caixote(Vetor2F(300, 400)));
	listaboneco.inserir(new PlataformaMovedica(Vetor2F(-240.0, 439.0)));
	//listaboneco.inserir(new PlataformaMovedica(Vetor2F(250.0, 400.0)));
	listaboneco.inserir(new Armadilha(Vetor2F(150, 422)));
	//listaboneco.inserir(new Armadilha(Vetor2F(23, 419)));

	listaboneco.iniciliazarEntidade(gerenciadorGrafico);

	gerenciadorColisoes.inserirColidivel("jogador", static_cast<EntidadeColidivel*>(listaboneco.voltarInicio()));
	gerenciadorColisoes.inserirColidivel("inimigo", static_cast<EntidadeColidivel*>(listaboneco.irProx()));
	gerenciadorColisoes.inserirColidivel("inimigo", static_cast<EntidadeColidivel*>(listaboneco.irProx()));
	gerenciadorColisoes.inserirColidivel("tile", static_cast<EntidadeColidivel*>(listaboneco.irProx()));
	//gerenciadorColisoes.inserirColidivel("tile", static_cast<EntidadeColidivel*>(listaboneco.irProx()));
	gerenciadorColisoes.inserirColidivel("caixote", static_cast<EntidadeColidivel*>(listaboneco.irProx()));
	gerenciadorColisoes.inserirColidivel("plataformamovedica", static_cast<EntidadeColidivel*>(listaboneco.irProx()));
	gerenciadorColisoes.inserirColidivel("armadilha", static_cast<EntidadeColidivel*>(listaboneco.irProx()));
	//gerenciadorColisoes.inserirColidivel("armadilha", static_cast<EntidadeColidivel*>(listaboneco.irProx()));
	*/

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

		/*gerenciadorGrafico.limpar();
		gerenciadorGrafico.centralizar(listaboneco.voltarInicio()->getPosicao());
		//gerenciadorEventos.eventos();
		
		//jogador.atualizar(t.asSeconds());
		listaboneco.atualizar(t.asSeconds());

		//jogador.desenhar(gerenciadorGrafico);
		listaboneco.desenharEntidade(gerenciadorGrafico);
		gerenciadorColisoes.verificaColisoes();
		

		gerenciadorGrafico.mostrar();*/

		teste.atualizar();
	}
	return 0;
}

/*void Principal::adicionaEntidade(EntidadeColidivel* entidade, string tipoEntidade)
{
	
	listaboneco.inserir(entidade);
	entidade->inicializar(gerenciadorGrafico);

	gerenciadorColisoes.inserirColidivel(tipoEntidade, entidade);
	std::cout << "ta adicionado" << std::endl;
	
}*/