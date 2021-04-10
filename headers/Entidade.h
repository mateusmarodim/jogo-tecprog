#pragma once
#include "Vetor2D.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"

class Entidade
{

protected:
	Vetor2F posicao;
	const char* caminho;

public:
	Entidade(Vetor2F Pos = Vetor2F(0.0, 0.0), const char* caminhoText = nullptr);
	~Entidade();

	virtual void inicializar(GerenciadorGrafico& g);
	virtual void atualizar(float t) = 0;
	virtual void desenhar(GerenciadorGrafico& g);

};
