#include "Selva.h"
#include <iostream>

Selva::Selva(sf::Clock* rf, GerenciadorGrafico* gg, string cb):
	Fase(rf,gg,cb)
{
	carregarBackground();

	
	listaboneco.inserir(new Jogador(Vetor2F(-100.0, 350.0)));
	listaboneco.iniciliazarEntidade(*gerenciadorGrafico);
	gerenciadorColisoes.inserirColidivel("jogador", static_cast<EntidadeColidivel*>(listaboneco.voltarInicio()));

	incluir();

}

Selva::Selva()
{
}

Selva::~Selva()
{
	listaboneco.excluir();
}

void Selva::incluir()
{
	incluirJungleslime();
	incluirSpikedslime();
	incluirBau();
	incluirPlataformam();
	incluirFixos();
}

void Selva::incluirJungleslime()
{
	srand(time(NULL));
	int i = rand() % 3 + 5;
	posicoes.push_back(Vetor2F(200.0, 390.0));
	posicoes.push_back(Vetor2F(1050, 400.0));
	posicoes.push_back(Vetor2F(1750.0, 400.0));
	posicoes.push_back(Vetor2F(2520.0, 161.0));
	posicoes.push_back(Vetor2F(2720.0, 161.0));
	posicoes.push_back(Vetor2F(2520.0, 600.0));
	posicoes.push_back(Vetor2F(3660.0, 400.0));

	//std::cout << i << endl;
	for (int j = 0; j < i; j++)
	{

		int r = rand() % (i - j);
		//std::cout << r << endl;
		Vetor2F temp = posicoes[r];
		posicoes[r] = posicoes[i - j - 1];
		posicoes[i - j - 1] = temp;
		adicionaEntidade(new Inimigo1(Vetor2F(posicoes[i - j - 1])), "inimigo");
		posicoes.pop_back();
	}
	posicoes.clear();
}

void Selva::incluirSpikedslime()
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
		adicionaEntidade(new Pistoleiro(this, Vetor2F(posicoes[i - j - 1])), "inimigo");
		posicoes.pop_back();
	}
	posicoes.clear();
}

void Selva::incluirBau()
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

void Selva::incluirPlataformam()
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

void Selva::incluirFixos()
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
			adicionaEntidade(new Tile(Vetor2F(posicoes[i - j - 1])), "tile");
		}
		else
			adicionaEntidade(new PlataformaMovedica(Vetor2F(posicoes[i - j - 1])), "plataformamovedica");
	}
	posicoes.clear();
}

bool Selva::test()
{
	if (listaboneco.voltarInicio()->getPosicao().x >= 4300)
	{
		//std::cout << "fechar " << endl;
		return true;
		listaboneco.excluir();
	}
}
