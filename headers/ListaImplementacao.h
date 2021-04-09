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
 Lista<LT>::ElementoLista<ET> *Lista<LT>::ElementoLista<ET>::getProx()
{
	return pProx;
}

 template <typename LT>
 template <typename ET>
Lista<LT>::ElementoLista<ET> *Lista<LT>::ElementoLista<ET>::getAnt()
 {
	return pAnt;
 }

 template <typename LT>
 template <typename ET>
ET Lista<LT>::ElementoLista<ET>::getInfo()
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
		//delete paux->getInfo();

		pFim = pFim->getAnt();

		delete paux;

		paux = pFim;
	}
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
