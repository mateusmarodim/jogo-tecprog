#pragma once
#include "Texto.h"
#include "GerenciadorGrafico.h"

class Botao
{
private:
	Texto txt;
	Vetor2F posicao;
	Vetor2F tamanho;
	string caminhoTxt;

public:
	Botao(Vetor2F Pos = (0.0,0.0), Vetor2F Tam = (0.0, 0.0),string Caminho = nullptr);
	~Botao();

	void desenhar(GerenciadorGrafico& g);
};

