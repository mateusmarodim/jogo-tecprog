#include "Fase.h"
#include <iostream>

Fase::Fase(sf::Clock* rf, GerenciadorGrafico* gg,string cb) :
	relogiof(rf), gerenciadorGrafico(gg), caminhoBackground(cb)
{
	//incluirP2();
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

void Fase::pausar()
{
	//GerenciadorEventos* g = GerenciadorEventos::getInstance();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P))
	{
		std::cout << "pause" << endl;
		//getchar();
		while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::M))
		{

		}
		relogiof->restart();
	}
}

