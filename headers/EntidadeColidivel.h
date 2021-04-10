#pragma once
#include "Vetor2D.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"
#include "Entidade.h"


class EntidadeColidivel : public Entidade
{
protected:
	Vetor2F velocidade;
	Vetor2F posicao;
	const char* caminho;

public:
	EntidadeColidivel(Vetor2F Pos = Vetor2F(0.0, 0.0), Vetor2F Vel = Vetor2F(0.0, 0.0), const char* caminhoText = nullptr);
	~EntidadeColidivel();

	virtual void inicializar(GerenciadorGrafico& g);
	virtual void desenhar(GerenciadorGrafico& g);

};

