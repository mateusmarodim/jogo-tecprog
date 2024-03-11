#pragma once
template <typename LT>
class Lista
{
private:

	template <typename ET>
	class ElementoLista
	{
	private:
		ElementoLista* pProx;
		ElementoLista* pAnt;
		ET info;

	public:
		ElementoLista(ElementoLista* Prox=nullptr,ElementoLista* Ant=nullptr, ET Info=nullptr);
		~ElementoLista();

		void setProx(ElementoLista* pp);
		void setAnt(ElementoLista* pa);
		void setInfo(ET inf);

		ElementoLista* getProx() const;
		ElementoLista* getAnt() const;
		const ET getInfo() const;
	};

	ElementoLista<LT>* pPrimeiro;
	ElementoLista<LT>* pAtual;
	ElementoLista<LT>* pFim;

public:
	Lista();
	~Lista();

	void inserir(LT info);
	void excluir();
	void remover(LT info);

	LT voltarInicio();
	LT irProximo();
};

#include "../headers/ListaImplementacao.h"


