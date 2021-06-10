#include "ListaEntidade.h"
#include <iostream>

ListaEntidade::ListaEntidade()
{

}

ListaEntidade::~ListaEntidade()
{
	excluir();
}

void ListaEntidade::inserir(EntidadeColidivel* info)
{
	lp.inserir(info);
}

void ListaEntidade::remover(EntidadeColidivel* info)
{
	lp.remover(info);
}

void ListaEntidade::excluir()
{
	EntidadeColidivel* pp = lp.voltarInicio();

	while (pp != NULL)
	{
		delete pp;
		pp = lp.irProximo();
	}
	lp.excluir();

}


void ListaEntidade::iniciliazarEntidade(GerenciadorGrafico& g)
{
	EntidadeColidivel* pp = lp.voltarInicio();
	while (pp != NULL)
	{
		
		pp->inicializar(g);
		pp = lp.irProximo();
	}
}

void ListaEntidade::desenharEntidade(GerenciadorGrafico& g)
{
	EntidadeColidivel* pp = lp.voltarInicio();
	
	while (pp != NULL)
	{
		pp->desenhar(g);
		pp = lp.irProximo();
	}
}



void ListaEntidade::atualizar(float t)
{
	EntidadeColidivel* pp = lp.voltarInicio();

	while (pp != nullptr)
	{
		pp->atualizar(t);
		pp = lp.irProximo();
	}
}

void ListaEntidade::reiniciaRelogio()
{
	EntidadeColidivel* pp = lp.voltarInicio();

	while (pp != NULL)
	{
		pp->reiniciaRelogio();
		pp = lp.irProximo();
	}
}


EntidadeColidivel* ListaEntidade::voltarInicio()
{
	return lp.voltarInicio();
}

EntidadeColidivel* ListaEntidade::irProx()
{
	return lp.irProximo();
}