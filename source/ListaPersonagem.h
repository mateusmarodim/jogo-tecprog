#pragma once
#include "Personagem.h"
class ListaPersonagem
{
private:
	class ElLista
	{
	private:
		Personagem* info;
		ElLista* ant;
		ElLista* prox;
	public:
		ElLista(Personagem* Info = nullptr,ElLista* Ant = nullptr,ElLista* Prox = nullptr);
		~ElLista();
		Personagem* getInfo();
		void setInfo(Personagem* Info);
		ElLista* getAnt();
		void setAnt(ElLista* Ant);
		ElLista* getProx();
		void setProx(ElLista* Prox);
	};

	ElLista* inicio;
	ElLista* fim;
	ElLista* atual;
public:
	ListaPersonagem();
	~ListaPersonagem();

	void inserir(Personagem* info);
	void esvaziar();
	Personagem* voltarInicio();
	Personagem* irProximo();

	void atualizarPersonagens(float t);
	void desenharPersonagens(sf::RenderWindow* janela);
	void destruirPersonagens();
};

