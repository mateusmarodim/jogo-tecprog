#include "Caverna.h"
#include <iostream>

Caverna::Caverna(sf::Clock* rf, GerenciadorGrafico* gg, string cb) :
	Fase(rf, gg, cb)
{
	incluir();
}

Caverna::Caverna()
{
}

Caverna::~Caverna()
{
	listaboneco.excluir();
}

void Caverna::incluir()
{
	incluirJungleslime();
	incluirSpikedslime();
	incluirBau();
	incluirArmadilha();
	incluirFixos();
	//incluirP2();
}

void Caverna::desenharBackground()
{
	float posicaoX = 2270;
	float posicaoY = 1200;
	gerenciadorGrafico->desenhar(caminhoBackground, Vetor2F(posicaoX, posicaoY));
}

void Caverna::incluirJungleslime()
{
	srand(time(NULL));
	int i = rand() % 5 + 5;
	posicoes.push_back(Vetor2F(400.0, 385.0));
	posicoes.push_back(Vetor2F(1100.0, 785.0));
	posicoes.push_back(Vetor2F(1400.0, 785.0));
	posicoes.push_back(Vetor2F(1670.0, 785.0));
	posicoes.push_back(Vetor2F(2250.0, 1185.0));
	posicoes.push_back(Vetor2F(2650.0, 1185.0));
	posicoes.push_back(Vetor2F(3990.0, 1735.0));
	posicoes.push_back(Vetor2F(4365.0, 1735.0));
	posicoes.push_back(Vetor2F(5410.0, 1735.0));

	//int i = posicoes.size();
	//std::cout << i << endl;
	for (int j = 0; j < i; j++)
	{

		int r = rand() % (i - j);
		//std::cout << r << endl;
		Vetor2F temp = posicoes[r];
		posicoes[r] = posicoes[i - j - 1];
		posicoes[i - j - 1] = temp;
		adicionaEntidade(new SlimeDaSelva(Vetor2F(posicoes[i - j - 1])), "inimigo");
		posicoes.pop_back();
	}
	posicoes.clear();
}

void Caverna::incluirSpikedslime()
{
	srand(time(NULL));
	int i = rand() % 5 + 5;
	posicoes.push_back(Vetor2F(70.0, 400.0));
	posicoes.push_back(Vetor2F(700, 400.0));
	posicoes.push_back(Vetor2F(1950.0, 1200.0));
	posicoes.push_back(Vetor2F(2450.0, 1200.0));
	posicoes.push_back(Vetor2F(3050.0, 1600.0));
	posicoes.push_back(Vetor2F(3300.0, 1600.0));
	posicoes.push_back(Vetor2F(3600.0, 1600.0));
	posicoes.push_back(Vetor2F(4215.0, 1740.0));
	posicoes.push_back(Vetor2F(5690.0, 1740.0));

	//int i = posicoes.size();

	for (int j = 0; j < i; j++)
	{

		int r = rand() % (i - j);
Vetor2F temp = posicoes[r];
posicoes[r] = posicoes[i - j - 1];
posicoes[i - j - 1] = temp;
adicionaEntidade(new SlimeEspinhoso(this, Vetor2F(posicoes[i - j - 1])), "inimigo");
posicoes.pop_back();
	}
	posicoes.clear();
}



void Caverna::incluirBau()
{
	srand(time(NULL));
	int i =rand() % 5 + 5;
	posicoes.push_back(Vetor2F(-30.0, 400.0));
	posicoes.push_back(Vetor2F(250, 400.0));
	posicoes.push_back(Vetor2F(600, 400.0));
	posicoes.push_back(Vetor2F(1250, 800.0));
	posicoes.push_back(Vetor2F(2050.0, 1200.0));
	posicoes.push_back(Vetor2F(2900.0, 1600.0));
	posicoes.push_back(Vetor2F(3450.0, 1600.0));
	posicoes.push_back(Vetor2F(4140.0, 1740));
	posicoes.push_back(Vetor2F(5600.0, 1740));

	//int i = posicoes.size();

	for (int j = 0; j < i; j++)
	{
		int r = rand() % (i - j);
		Vetor2F temp = posicoes[r];
		posicoes[r] = posicoes[i - j - 1];
		posicoes[i - j - 1] = temp;
		adicionaEntidade(new Bau(Vetor2F(posicoes[i - j - 1])), "caixote");
		posicoes.pop_back();
	}
	posicoes.clear();
}

void Caverna::incluirArmadilha()
{
	srand(time(NULL));
	int i = rand() % 4 + 5;

	posicoes.push_back(Vetor2F(200.0, 390.0));
	posicoes.push_back(Vetor2F(830.0, 790.0));
	posicoes.push_back(Vetor2F(1000.0, 790.0));
	posicoes.push_back(Vetor2F(1500.0, 790.0));
	posicoes.push_back(Vetor2F(2750.0, 1190.0));
	posicoes.push_back(Vetor2F(3175.0, 1590.0));
	posicoes.push_back(Vetor2F(3880.0, 1730.0));
	posicoes.push_back(Vetor2F(5720.0, 1730.0));

	//int i = posicoes.size();

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

void Caverna::incluirFixos()
{

	posicoes.push_back(Vetor2F(4830, 1650));

	posicoes.push_back(Vetor2F(300.0, 180.0));
	posicoes.push_back(Vetor2F(300.0, 439.0));
	posicoes.push_back(Vetor2F(1300, 839.0));
	posicoes.push_back(Vetor2F(1565, 580));
	posicoes.push_back(Vetor2F(2300, 1239));
	posicoes.push_back(Vetor2F(2565, 980));
	posicoes.push_back(Vetor2F(3300, 1639));
	posicoes.push_back(Vetor2F(3565, 1380));
	posicoes.push_back(Vetor2F(4330, 1780));
	posicoes.push_back(Vetor2F(5330, 1780));


	int i = posicoes.size();

	for (int j = 0; j < i; j++)
	{
		if (j < i - 1)
			adicionaEntidade(new Piso(Vetor2F(posicoes[i - j - 1])), "tile");
		else
			adicionaEntidade(new SlimeRei(/*this,*/ static_cast<Jogador*>(listaboneco.voltarInicio()), Vetor2F(posicoes[i - j - 1])), "king");

	}
	posicoes.clear();
}

bool Caverna::test()
{
	if (listaboneco.voltarInicio()->getPosicao().x >= 5810)
	{
		return true;
		//listaboneco.excluir();
	}
	
}
