#include "ListaEntidade.h"
#include <iostream>

ListaEntidade::ListaEntidade()
{

}

ListaEntidade::~ListaEntidade()
{
	excluir();
}

void ListaEntidade::inserir(Entidade* info)
{
	lp.inserir(info);
}

void ListaEntidade::excluir()
{
	Entidade* pp = lp.voltarInicio();

	while (pp != NULL)
	{
		delete pp;
		pp = lp.irProximo();
	}
	lp.excluir();
}


void ListaEntidade::iniciliazarPersonagem(GerenciadorGrafico& g)
{
	Entidade* pp = lp.voltarInicio();
	while (pp != NULL)
	{
		pp->inicializar(g);
		pp = lp.irProximo();
	}
}

void ListaEntidade::desenharPersonagem(GerenciadorGrafico& g)
{
	Entidade* pp = lp.voltarInicio();
	
	while (pp != NULL)
	{
		pp->desenhar(g);
		pp = lp.irProximo();
	}
}



void ListaEntidade::atualizar(float t)
{
	Entidade* pp = lp.voltarInicio();

	while (pp != nullptr)
	{
		pp->atualizar(t);
		pp = lp.irProximo();
	}
}

/*void ListaEntidade::atualizarE(GerenciadorEventos& ge)
{
	Entidade* pp = lp.voltarInicio();

	while (pp != nullptr)
	{
		pp->atualizar(ge);
		pp = lp.irProximo();
	}
}*/

/*
Entidade* ListaEntidade::voltarInicio()
{

}

Entidade* ListaEntidade::irProx()
{

}*/