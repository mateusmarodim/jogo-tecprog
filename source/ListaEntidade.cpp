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


void ListaEntidade::iniciliazarEntidade(GerenciadorGrafico& g)
{
	Entidade* pp = lp.voltarInicio();
	while (pp != NULL)
	{
		
		pp->inicializar(g);
		//std::cout << "oi" << std::endl;
		pp = lp.irProximo();
	}
}

void ListaEntidade::desenharEntidade(GerenciadorGrafico& g)
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


Entidade* ListaEntidade::voltarInicio()
{
	return lp.voltarInicio();
}

Entidade* ListaEntidade::irProx()
{
	return lp.irProximo();
}