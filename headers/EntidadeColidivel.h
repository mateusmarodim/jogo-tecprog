#pragma once
#include "Vetor2D.h"
#include "GerenciadorGrafico.h"
#include "Entidade.h"


class EntidadeColidivel : public Entidade
{
protected:
	Vetor2F velocidade;
	Vetor2F posicao;
	Vetor2F tamanho;
	const char* caminho;

public:
	EntidadeColidivel(Vetor2F pos = Vetor2F(0.0, 0.0), Vetor2F vel = Vetor2F(0.0, 0.0), Vetor2F tam = Vetor2F(0.0, 0.0), const char* caminhoText = nullptr);
	~EntidadeColidivel();

	virtual void inicializar(GerenciadorGrafico& g);
	virtual void desenhar(GerenciadorGrafico& g);
	virtual void colidir(EntidadeColidivel* outro, std::string tipoEntidade) = 0;

	virtual const Vetor2F getPosicao()const;
	const Vetor2F getTamanho()const;


};

