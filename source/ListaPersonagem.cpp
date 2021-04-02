#include "ListaPersonagem.h"

ListaPersonagem::ElLista::ElLista(Personagem* Info, ElLista* Ant, ElLista* Prox) :
	info{Info}, ant{Ant}, prox{Prox}
{
}

ListaPersonagem::ElLista::~ElLista()
{
}

Personagem* ListaPersonagem::ElLista::getInfo()
{
	return info;
}

void ListaPersonagem::ElLista::setInfo(Personagem* Info)
{
	info = Info;
}

ListaPersonagem::ElLista* ListaPersonagem::ElLista::getAnt()
{
	return ant;
}

void ListaPersonagem::ElLista::setAnt(ElLista* Ant)
{
	ant = Ant;
}

ListaPersonagem::ElLista* ListaPersonagem::ElLista::getProx()
{
	return prox;
}

void ListaPersonagem::ElLista::setProx(ElLista* Prox)
{
	prox = Prox;
}

ListaPersonagem::ListaPersonagem():
	inicio{nullptr},fim{nullptr},atual{nullptr}
{
}

ListaPersonagem::~ListaPersonagem()
{
}

void ListaPersonagem::inserir(Personagem* info)
{
	if (info)
	{
		ElLista* novo = new ElLista(info);

		if (!inicio)
		{
			inicio = novo;
			fim = novo;
		}
		else
		{
			fim->setProx(novo);
			novo->setAnt(fim);

			fim = novo;
		}
	}
}

void ListaPersonagem::esvaziar()
{
	ElLista* paux = inicio;
	atual = inicio;

	while (atual != nullptr)
	{
		paux = atual->getProx();
		delete atual;
		atual = nullptr;

	}

	inicio = nullptr;
	fim = nullptr;
	atual = nullptr;
}

Personagem* ListaPersonagem::voltarInicio()
{
	atual = inicio;

	if (atual)
		return atual->getInfo();
	else
		return nullptr;

}

Personagem* ListaPersonagem::irProximo()
{
	atual = atual->getProx();
	
	if (atual)
		return atual->getInfo();
	else
		return nullptr;
}

void ListaPersonagem::atualizarPersonagens(float t)
{
	Personagem* p = voltarInicio();

	while (p)
	{
		p->atualizar(t);

		p = irProximo();
	}
}

void ListaPersonagem::desenharPersonagens(sf::RenderWindow* janela)
{
	Personagem* p = voltarInicio();

	while (p)
	{
		p->desenhar(janela);

		p = irProximo();
	}
}

void ListaPersonagem::destruirPersonagens()
{
	Personagem* p = voltarInicio();

	while (p)
	{
		delete p;

		p = irProximo();
	}

	esvaziar();
}
