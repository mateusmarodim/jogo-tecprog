#include "Fase.h"
#include <iostream>

Fase::Fase(sf::Clock* rf, GerenciadorGrafico* gg,string cb) :
	relogiof(rf), gerenciadorGrafico(gg), caminhoBackground(cb)
{
	carregarBackground();

	listaboneco.inserir(new Jogador(Vetor2F(-100.0, 350.0)));
	listaboneco.iniciliazarEntidade(*gerenciadorGrafico);
	gerenciadorColisoes.inserirColidivel("jogador", static_cast<EntidadeColidivel*>(listaboneco.voltarInicio()));

	incluirJungleslime();
	incluirSpikedslime();
	incluirBau();
	incluirPlataformam();
	incluirFixos();

}

Fase::Fase()
{
}

Fase::~Fase()
{
	listaboneco.excluir();
}

void Fase::adicionaEntidade(EntidadeColidivel* entidade, string tipoEntidade)
{
	listaboneco.inserir(entidade);
	entidade->inicializar(*gerenciadorGrafico);

	gerenciadorColisoes.inserirColidivel(tipoEntidade, entidade);
}

void Fase::atualizar(float t)
{
	gerenciadorGrafico->limpar();
	desenharBackground();
	gerenciadorGrafico->centralizar(listaboneco.voltarInicio()->getPosicao());

	listaboneco.atualizar(t);
	
	listaboneco.desenharEntidade(*gerenciadorGrafico);

	gerenciadorColisoes.verificaColisoes();
	//gerenciadorColisoes.imprimir(); 
	gerenciadorGrafico->mostrar();
}

void Fase::carregarBackground()
{
	gerenciadorGrafico->carregarTextura(caminhoBackground);
}

void Fase::desenharBackground()
{
	float posicaoX = 2070;
	float posicaoY = -300;
	gerenciadorGrafico->desenhar(caminhoBackground, Vetor2F(posicaoX, posicaoY));
}

void Fase::incluirJungleslime()
{
	srand(time(NULL));
	int i = 1;//rand() % 3 + 5;
	posicoes.push_back(Vetor2F(200.0,400.0));
	posicoes.push_back(Vetor2F(1050,400.0));
	posicoes.push_back(Vetor2F(1750.0,400.0));
	posicoes.push_back(Vetor2F(2520.0,161.0));
	posicoes.push_back(Vetor2F(2720.0,161.0));
	posicoes.push_back(Vetor2F(2520.0,600.0));
	posicoes.push_back(Vetor2F(3660.0,400.0));

	//std::cout << i << endl;
	for (int j = 0; j < i; j++)
	{

		int r = rand() % (i-j);
		//std::cout << r << endl;
		Vetor2F temp = posicoes[r];
		posicoes[r] = posicoes[i - j-1];
		posicoes[i - j-1] = temp;
		adicionaEntidade(new Inimigo1(Vetor2F(posicoes[i - j-1])), "inimigo");
		posicoes.pop_back();
	}
	posicoes.clear();
}

void Fase::incluirSpikedslime()
{
	srand(time(NULL));
	int i = rand() % 3 + 5;
	posicoes.push_back(Vetor2F(500.0, 400.0));
	posicoes.push_back(Vetor2F(750, 400.0));
	posicoes.push_back(Vetor2F(1300.0, 400.0));
	posicoes.push_back(Vetor2F(3000.0, 161.0));
	posicoes.push_back(Vetor2F(3000, 600.0));
	posicoes.push_back(Vetor2F(4000.0, 400.0));
	posicoes.push_back(Vetor2F(4200.0, 400.0));




	//std::cout << i << endl;
	for (int j = 0; j < i; j++)
	{

		int r = rand() % (i - j);
		Vetor2F temp = posicoes[r];
		posicoes[r] = posicoes[i - j - 1];
		posicoes[i - j - 1] = temp;
		adicionaEntidade(new Pistoleiro(this,Vetor2F(posicoes[i - j - 1])), "inimigo");
		posicoes.pop_back();
	}
	posicoes.clear();
}

void Fase::incluirBau()
{
	srand(time(NULL));
	int i = rand() % 3 + 5;
	posicoes.push_back(Vetor2F(0.0, 400.0));
	posicoes.push_back(Vetor2F(400, 400.0));
	posicoes.push_back(Vetor2F(1200.0, 400.0));
	posicoes.push_back(Vetor2F(2300.0, 161.0));
	posicoes.push_back(Vetor2F(2300, 600.0));
	posicoes.push_back(Vetor2F(3500.0, 400.0));
	posicoes.push_back(Vetor2F(3800.0, 400.0));

	for (int j = 0; j < i; j++)
	{
		int r = rand() % (i - j);
		Vetor2F temp = posicoes[r];
		posicoes[r] = posicoes[i - j - 1];
		posicoes[i - j - 1] = temp;
		adicionaEntidade(new Caixote(Vetor2F(posicoes[i - j - 1])), "caixote");
		posicoes.pop_back();
	}
	posicoes.clear();
}

void Fase::incluirPlataformam()
{
	srand(time(NULL));
	int i = rand() % 3 + 5;

	posicoes.push_back(Vetor2F(625.0, 309.0));
	posicoes.push_back(Vetor2F(1525.0, 309.0));
	posicoes.push_back(Vetor2F(2050.0, 539.0));
	posicoes.push_back(Vetor2F(2450.0, 70.0));
	posicoes.push_back(Vetor2F(2600.0, 70.0));
	posicoes.push_back(Vetor2F(2750.0, 70.0));
	posicoes.push_back(Vetor2F(3190.0, 349.0));


	for (int j = 0; j < i; j++)
	{
		int r = rand() % (i - j);
		Vetor2F temp = posicoes[r];
		posicoes[r] = posicoes[i - j - 1];
		posicoes[i - j - 1] = temp;
		adicionaEntidade(new PlataformaMovedica(Vetor2F(posicoes[i - j - 1])), "plataformamovedica");
		posicoes.pop_back();
	}
	posicoes.clear();
}

void Fase::incluirArmadilha()
{
	srand(time(NULL));
	int i = rand() % 3 + 5;
	posicoes.push_back(Vetor2F(500.0, 400.0));
	posicoes.push_back(Vetor2F(750, 400.0));
	posicoes.push_back(Vetor2F(1300.0, 400.0));
	posicoes.push_back(Vetor2F(3000.0, 161.0));
	posicoes.push_back(Vetor2F(3000, 600.0));
	posicoes.push_back(Vetor2F(4000.0, 400.0));
	posicoes.push_back(Vetor2F(4200.0, 400.0));

	for (int j = 0; j < i; j++)
	{
		int r = rand() % (i - j);
		Vetor2F temp = posicoes[r];
		posicoes[r] = posicoes[i - j - 1];
		posicoes[i - j - 1] = temp;
		adicionaEntidade(new Armadilha(Vetor2F(posicoes[i - j - 1])), "armadilha");
		posicoes.pop_back();
	}
	posicoes.clear();
}

void Fase::incluirFixos()
{
	int i = 9;
	posicoes.push_back(Vetor2F(1950.0, 439.0));
	posicoes.push_back(Vetor2F(2050.0, 349.0));
	posicoes.push_back(Vetor2F(3290.0, 439.0));
	posicoes.push_back(Vetor2F(3190.0, 539.0));

	posicoes.push_back(Vetor2F(300.0, 439.0));
	posicoes.push_back(Vetor2F(1400, 439.0));
	posicoes.push_back(Vetor2F(2620, 200.0));
	posicoes.push_back(Vetor2F(2620, 639.0));
	posicoes.push_back(Vetor2F(3840, 439.0));

	

	for (int j = 0; j < i; j++)
	{
		if (j <= 4)
		{
			adicionaEntidade(new Tile(Vetor2F(posicoes[i - j-1])), "tile");
		}
		else
			adicionaEntidade(new PlataformaMovedica(Vetor2F(posicoes[i - j -1])), "plataformamovedica");
	}
	posicoes.clear();
}

void Fase::deletaProjetil(Projetil* pproj)
{
	if (pproj)
	{
		std::cout << "vou deletar um corno" << endl;
		gerenciadorColisoes.removerColidivel(gerenciadorColisoes.encontrar("bala"));
		listaboneco.remover(pproj);
		delete pproj;
	}
}

