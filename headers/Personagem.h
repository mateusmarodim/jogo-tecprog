#pragma once
#include "Vetor2D.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"



class Personagem
{
protected:
    Vetor2F posicao;
	Vetor2F velocidade;
	const char* caminho;

public:
	Personagem(Vetor2F Pos = Vetor2F(0.0, 0.0), Vetor2F Vel = Vetor2F(0.0, 0.0), const char* caminhoText = nullptr);
	~Personagem();

	virtual void inicializar(GerenciadorGrafico &g);
	virtual void atualizar(float t);
	virtual void desenhar(GerenciadorGrafico &g);

};

