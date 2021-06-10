#pragma once
#include "Lista.h"
#include "EntidadeColidivel.h"

class ListaEntidade
{
private:
	Lista<EntidadeColidivel*> lp;

public:
	ListaEntidade();
	~ListaEntidade();

	void inserir(EntidadeColidivel* info);
	void excluir();
	void remover(EntidadeColidivel* info);

	void iniciliazarEntidade(GerenciadorGrafico& g);
	void desenharEntidade(GerenciadorGrafico& g);
	void atualizar(float t);
	void reiniciaRelogio();

	EntidadeColidivel* voltarInicio();
	EntidadeColidivel* irProx();
};

