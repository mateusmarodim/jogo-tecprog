#pragma once
#include "Lista.h"
#include "Personagem.h"
#include "GerenciadorGrafico.h"

class ListaPersonagem
{
private:
	Lista<Personagem*> lp;

public:
	ListaPersonagem();
	~ListaPersonagem();

	void inserir(Personagem* info);
	void excluir();

	void iniciliazarPersonagem(GerenciadorGrafico& g);
	void desenharPersonagem(GerenciadorGrafico& g);
	void atualizar(float t);

	/*Personagem* voltarInicio();
	Personagem* irProx();*/

};

