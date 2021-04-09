#include "ListaPersonagem.h"
#include <iostream>

ListaPersonagem::ListaPersonagem()
{

}

ListaPersonagem::~ListaPersonagem()
{
	excluir();
}

void ListaPersonagem::inserir(Personagem* info)
{
	lp.inserir(info);
}

void ListaPersonagem::excluir()
{
	Personagem* pp = lp.voltarInicio();

	while (pp != NULL)
	{
		delete pp;
		pp = lp.irProximo();
	}
	lp.excluir();
}


void ListaPersonagem::iniciliazarPersonagem(GerenciadorGrafico& g)
{
	Personagem* pp = lp.voltarInicio();
	while (pp != NULL)
	{
		pp->inicializar(g);
		pp = lp.irProximo();
	}
}

void ListaPersonagem::desenharPersonagem(GerenciadorGrafico& g)
{
	Personagem* pp = lp.voltarInicio();
	
	while (pp != NULL)
	{
		pp->desenhar(g);
		pp = lp.irProximo();
	}
}



void ListaPersonagem::atualizar(float t)
{
	Personagem* pp = lp.voltarInicio();

	while (pp != nullptr)
	{
		pp->atualizar(t);
		pp = lp.irProximo();
	}
}

/*void ListaPersonagem::atualizarE(GerenciadorEventos& ge)
{
	Personagem* pp = lp.voltarInicio();

	while (pp != nullptr)
	{
		pp->atualizar(ge);
		pp = lp.irProximo();
	}
}*/

/*
Personagem* ListaPersonagem::voltarInicio()
{

}

Personagem* ListaPersonagem::irProx()
{

}*/