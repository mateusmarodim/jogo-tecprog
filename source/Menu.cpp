#include "Menu.h"
#include <iostream>

Menu::Menu(const string Caminho, GerenciadorGrafico* g)
{
	caminhoTextura = Caminho;
	gg = g;
	selecionarFase = true;
}

Menu::~Menu()
{
}

void Menu::inicializar()
{
	gg->carregarTextura(caminhoTextura);
}

void Menu::desenhar()
{
	gg->desenhar(caminhoTextura, Vetor2F(400.0,300.0));
}

void Menu::atualizar()
{
	desenhar();
	gg->mostrar();
	gg->limpar();
}

void Menu::trocarMenu(string Caminho)
{
	caminhoTextura = Caminho;
	gg->carregarTextura(caminhoTextura);
}

void Menu::setSelecionarFase(bool sf)
{
	selecionarFase = sf;
}

const bool Menu::getSelecionarFase() const
{
	return selecionarFase;
}

Menu::Opcao  Menu::opcaoSelecionada()
{
	GerenciadorTeclado* gt = GerenciadorTeclado::getTeclado();

	if (gt->tecladoUtilidade()==12)
	{
		return novoJogo;
	}

	if (gt->tecladoUtilidade()==13)
	{
		return selva;
	}

	if (gt->tecladoUtilidade() == 14)
	{
		return caverna;
	}

	if (gt->tecladoUtilidade() == 15)
	{
		return sair;
	}

	return espera;
}

