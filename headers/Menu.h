#pragma once
#include "GerenciadorTeclado.h"
#include "GerenciadorGrafico.h"

class Menu
{
private:
	string caminhoTextura;
	GerenciadorGrafico* gg;
	bool selecionarFase;

public:
	Menu(const string Caminho=nullptr, GerenciadorGrafico* g =nullptr);
	~Menu();

	enum Opcao 
	{
		espera,novoJogo,selva,caverna,sair
	};

	void inicializar();
	void desenhar();
	void atualizar();
	void trocarMenu(string Caminho);
	void setSelecionarFase(bool sf);
	const bool getSelecionarFase() const;

	Opcao opcaoSelecionada();
};

