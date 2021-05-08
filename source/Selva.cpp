#include "Selva.h"
#include <iostream>

Selva::Selva(sf::Clock* rf, GerenciadorGrafico* gg, string cb):
	Fase(rf,gg,cb)
{
	std::cout << "selva" << endl;
	pPlataformaM = nullptr;
	incluir();
}

//Selva::Selva()
//{
//}

Selva::~Selva()
{
	//listaboneco.excluir();
}

void Selva::incluir()
{
	incluirSlimeDaSelva();
	incluirSlimeEspinhoso();
	incluirBau();
	incluirPlataformam();
	incluirFixos();
}

void Selva::incluirSlimeDaSelva()
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
		Vetor2F temp = posicoes[r];
		posicoes[r] = posicoes[i - j - 1];
		posicoes[i - j - 1] = temp;

		pSlimeDS = new SlimeDaSelva(Vetor2F(posicoes[i - j - 1]));
		adicionaEntidade(pSlimeDS, "inimigo");
		posicoes.pop_back();
	}
	posicoes.clear();
}

void Selva::incluirSlimeEspinhoso()
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

		pSlimeE = new SlimeEspinhoso(this, Vetor2F(posicoes[i - j - 1]));
		adicionaEntidade(pSlimeE, "inimigo");
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

		pBau = new Bau(Vetor2F(posicoes[i - j - 1]));
		adicionaEntidade(pBau, "caixote");
		posicoes.pop_back();
	}
	posicoes.clear();
}

void Selva::incluirPlataformam()
{
	srand(time(NULL));
	int i = rand() % 3 + 5;

	posicoes.push_back(Vetor2F(0.0, 309.0));
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

		pPlataformaM = new PlataformaMovedica(Vetor2F(posicoes[i - j - 1]));
		adicionaEntidade(pPlataformaM, "plataformamovedica");
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
			pPiso = new Piso(Vetor2F(posicoes[i - j - 1]));

			adicionaEntidade(pPiso, "tile");
		}

		else
		{
			pPlataformaM = new PlataformaMovedica(Vetor2F(posicoes[i - j - 1]));
			adicionaEntidade(pPlataformaM, "plataformamovedica");
		}
		
	}
	posicoes.clear();
}

Selva::Situacao Selva::fimFase()
{
	if (pJogador1->getPosicao().x >= 4300)
	{
		return passarDeFase;
	}
	else
		return continuar;
}
