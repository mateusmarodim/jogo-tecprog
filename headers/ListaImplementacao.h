#include "Lista.h"

template <typename LT>
template <typename ET>
Lista<LT>::ElementoLista<ET>::ElementoLista(ElementoLista* Prox, ElementoLista* Ant, ET Info):
	pProx(Prox),
	pAnt(Ant),
	info(Info)
{

}

template <typename LT>
template <typename ET>
Lista<LT>::ElementoLista<ET>::~ElementoLista()
{

}

template <typename LT>
template <typename ET>
void Lista<LT>::ElementoLista<ET>::setProx(ElementoLista* pp)
{
	pProx = pp;
}

template <typename LT>
template <typename ET>
void Lista<LT>::ElementoLista<ET>::setAnt(ElementoLista* pa)
{
	pAnt = pa;
}

template <typename LT>
template <typename ET>
void Lista<LT>::ElementoLista<ET>::setInfo(ET inf)
{
	info = inf;
}



template <typename LT>
template <typename ET>
 Lista<LT>::ElementoLista<ET> *Lista<LT>::ElementoLista<ET>::getProx() const
{
	return pProx;
}

 template <typename LT>
 template <typename ET>
Lista<LT>::ElementoLista<ET> *Lista<LT>::ElementoLista<ET>::getAnt() const
 {
	return pAnt;
 }

 template <typename LT>
 template <typename ET>
const ET Lista<LT>::ElementoLista<ET>::getInfo() const
 {
	return info;
 }

template<typename LT>
Lista<LT>::Lista():
	pPrimeiro(),
	pAtual(),
	pFim()
{
}

template<typename LT>
Lista<LT>::~Lista()

{
	excluir();
}

template<typename LT>
void Lista<LT>::inserir(LT info)
{
	ElementoLista<LT>* paux = nullptr;
	paux = new ElementoLista<LT>;
	paux->setInfo(info);
	
		if (pPrimeiro == nullptr)
		{
			pFim = paux;
			pPrimeiro = paux;
		}
		else
		{
			pFim->setProx(paux);
			paux->setAnt(pFim);

			pFim = paux;
		}

}

template<typename LT>
void Lista<LT>::excluir()
{
	ElementoLista<LT>* paux = nullptr;
	paux = pFim;

	while (paux != nullptr)
	{
		pFim = pFim->getAnt();

		delete paux;

		paux = pFim;
	}
	pFim = nullptr;
	pPrimeiro = nullptr;
}

template<typename LT>
void Lista<LT>::remover(LT info)
{
	ElementoLista<LT>* paux = nullptr;
	paux = pPrimeiro;

	while (paux != nullptr && paux->getInfo()!=info)
	{
		paux = paux->getProx();
	}

	if (paux->getAnt())
	{
		paux->getAnt()->setProx(paux->getProx());
	}
	else
	{
		pPrimeiro = paux->getProx();
	}

	if (paux->getProx())
	{
		paux->getProx()->setAnt(paux->getAnt());
	}
	else
	{
		pFim = paux->getAnt();
	}
	delete paux;
	
}

template<typename LT>
LT Lista<LT>::voltarInicio()
{
	pAtual = pPrimeiro;
	if (pAtual == nullptr)
		return nullptr;
	return pAtual->getInfo();
}

template<typename LT>
LT Lista<LT>::irProximo()
{
	pAtual = pAtual->getProx();
	if (pAtual == nullptr)
		return nullptr;
	return pAtual->getInfo();
}
