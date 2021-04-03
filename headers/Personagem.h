#pragma once
#include "Vetor2D.h"
#include "GerenciadorGrafico.h"



class Personagem
{
private:
	Vetor2F posicao;
	Vetor2F velocidade;
	const char* caminho;

public:
	Personagem(Vetor2F Pos = Vetor2F(0.0, 0.0), Vetor2F Vel = Vetor2F(0.0, 0.0), const char* caminhoText = nullptr);
	~Personagem();

	void inicializar(GerenciadorGrafico &g);
	void atualizar(float t);
	void desenhar(GerenciadorGrafico &g);

};

