#include "Fase.h"
#include <iostream>

Fase::Fase(sf::Clock* rf, GerenciadorGrafico* gg,string cb) :
	relogiof(rf), gerenciadorGrafico(gg), caminhoBackground(cb)
{
	carregarBackground();

	pJogador1 = new SlimeSorridente(Vetor2F(-100.0, 200.0));
	pJogador2 = nullptr;

	pBau = nullptr;
	pSlimeDS = nullptr;
	pSlimeE = nullptr;
	pPiso = nullptr;

	listaboneco.inserir(pJogador1);
	listaboneco.iniciliazarEntidade(*gerenciadorGrafico);
	gerenciadorColisoes.inserirColidivel("jogador", static_cast<EntidadeColidivel*>(listaboneco.voltarInicio()));

	podeAtirar = true;
	podePausar = true;
}

Fase::~Fase()
{
}

void Fase::adicionaEntidade(EntidadeColidivel* entidade, string tipoEntidade)
{
	listaboneco.inserir(entidade);
	entidade->inicializar(*gerenciadorGrafico);

	gerenciadorColisoes.inserirColidivel(tipoEntidade, entidade);
}


void Fase::atualizar(float t)
{
	if (!podePausar)
	{
		t = 0;
	}
	gerenciadorGrafico->limpar();
	desenharBackground();
	listaboneco.desenharEntidade(*gerenciadorGrafico);
	listaboneco.atualizar(t);
	gerenciadorColisoes.verificaColisoes();
	gerenciarP2();
	gerenciadorGrafico->centralizar(listaboneco.voltarInicio()->getPosicao());

	//gerenciadorColisoes.imprimir();
	gerenciadorGrafico->mostrar();
	pausar();
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


void Fase::deletaProjetil(Espinho* pproj)
{
	if (pproj)
	{
		gerenciadorColisoes.removerColidivel(gerenciadorColisoes.encontrar("espinho"));
		listaboneco.remover(pproj);
		delete pproj;
	}
}

void Fase::setPodeAtirar(bool ppa)
{
	podeAtirar = ppa;
}

const bool Fase::getPodeAtirar()const
{
	return podeAtirar;
}


void Fase::pausar()
{
	GerenciadorTeclado* gTeclado = GerenciadorTeclado::getTeclado();

	if (gTeclado->tecladoUtilidade() == 9 && podePausar)
	{
		setPodeAtirar(false);
		podePausar = false;
	}
	if (gTeclado->tecladoUtilidade() == 10 && !podePausar)
	{
		std::cout << "pause" << endl;
		listaboneco.reiniciaRelogio();
		relogiof->restart();
		setPodeAtirar(true);
		podePausar = true;
	}
}

void Fase::gerenciarP2()
{
	GerenciadorTeclado* gTeclado = GerenciadorTeclado::getTeclado();

	if (!pJogador2)
	{
		if (gTeclado->tecladoUtilidade()==7)
		{
			pJogador2 = new SlimeAmigo((pJogador1->getPosicao()));
			adicionaEntidade(pJogador2, "jogador2");
		}
	}
	else if (gTeclado->tecladoUtilidade() == 8)
	{
		gerenciadorColisoes.removerColidivel(gerenciadorColisoes.encontrar("jogador2"));
		listaboneco.remover(pJogador2);
		delete pJogador2;
		pJogador2 = nullptr;
	}


}

