#pragma once
#include "SFML/Graphics.hpp"
#include <map>
#include <string>
#include "Vetor2D.h"

using namespace std;

class GerenciadorGrafico
{
private:
	sf::RenderWindow* janela;
	sf::View camera;
	std::map<string, sf::Texture*> texturas;
	sf::Texture* text;
	sf::Sprite sprite;

public:
	GerenciadorGrafico();
	~GerenciadorGrafico();

	void mostrar();
	void limpar(int r = 0, int g = 0, int b = 0);
	void desenhar(string caminho, Vetor2F posicao /*Vetor2F escala*/);
	bool carregarTextura(string caminho);
	void centralizar(Vetor2F centro);
	sf::RenderWindow* getJanela();
	const Vetor2F getTamanho(const std::string& caminho) const;
	//void desenharRetanguloSolido(const Vetor2F centro, const Vetor2F dimensao, const Cor cor) const;

};

