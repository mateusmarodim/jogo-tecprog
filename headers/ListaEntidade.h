#pragma once
#include "Lista.h"
#include "Entidade.h"
#include "GerenciadorGrafico.h"

class ListaEntidade
{
private:
	Lista<Entidade*> lp;

public:
	ListaEntidade();
	~ListaEntidade();

	void inserir(Entidade* info);
	void excluir();

	void iniciliazarEntidade(GerenciadorGrafico& g);
	void desenharEntidade(GerenciadorGrafico& g);
	void atualizar(float t);
	//void atualizarE(GerenciadorEventos& ge);

	Entidade* voltarInicio();
	Entidade* irProx();

};

