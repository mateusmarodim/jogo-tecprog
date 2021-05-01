#include "Fase.h"
#include <iostream>

Fase::Fase(sf::Clock* rf, GerenciadorGrafico* gg,string cb) :
	relogiof(rf), gerenciadorGrafico(gg), caminhoBackground(cb)
{
	carregarBackground();

	pJogador1 = new SlimeSorridente(Vetor2F(-100.0, 350.0));
	pJogador2 = nullptr;

	listaboneco.inserir(pJogador1);
	listaboneco.iniciliazarEntidade(*gerenciadorGrafico);
	gerenciadorColisoes.inserirColidivel("jogador", static_cast<EntidadeColidivel*>(listaboneco.voltarInicio()));

	podeAtirar = false;
	podePausar = true;
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
	//GerenciadorEventos* g = GerenciadorEventos::getTeclado();
	
	gerenciadorGrafico->limpar();
	desenharBackground();
	gerenciadorGrafico->centralizar(listaboneco.voltarInicio()->getPosicao());
	listaboneco.atualizar(t);
	gerenciadorColisoes.verificaColisoes();
	gerenciarP2();
	listaboneco.desenharEntidade(*gerenciadorGrafico);

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


void Fase::deletaProjetil(Projetil* pproj)
{
	if (pproj)
	{
		//std::cout << "vou deletar um corno" << endl;
		gerenciadorColisoes.removerColidivel(gerenciadorColisoes.encontrar("bala"));
		listaboneco.remover(pproj);
		delete pproj;
	}
}

void Fase::setPodeAtirar(bool ppa)
{
	podeAtirar = ppa;
}

bool Fase::getPodeAtirar()
{
	return podeAtirar;
}


void Fase::pausar()
{
	GerenciadorEventos* g = GerenciadorEventos::getTeclado();

	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P))
	{
		setPodeAtirar(true);
		podePausar = false;
		while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R))
		{
		}
		std::cout << "pause" << endl;
		listaboneco.reiniciaRelogio();
		relogiof->restart();
		setPodeAtirar(false);
		podePausar = true;
	}*/
	
	if ((g->Teclado() == 9) && podePausar)
	{
		setPodeAtirar(true);
		podePausar = false;


	}
	else if (!podePausar)
	{
		while (!(g->Teclado() == 10))
		{

		}
		std::cout << "pause" << endl;
		listaboneco.reiniciaRelogio();
		relogiof->restart();
		setPodeAtirar(false);
		podePausar = true;
	}

}

void Fase::gerenciarP2()
{
	GerenciadorEventos* g = GerenciadorEventos::getTeclado();

	if (!pJogador2)
	{
		if (g->Teclado()==7)
		{
			pJogador2 = new SlimeAmigo((pJogador1->getPosicao()));
			adicionaEntidade(pJogador2, "jogador2");
		}
	}
	else if (g->Teclado() == 8)
	{
		gerenciadorColisoes.removerColidivel(gerenciadorColisoes.encontrar("jogador2"));
		listaboneco.remover(pJogador2);
		delete pJogador2;
		pJogador2 = nullptr;
	}


}

