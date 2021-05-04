#pragma once
#include "Vetor2D.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"


class EntidadeColidivel 
{
protected:
	Vetor2F velocidade;
	Vetor2F posicao;
	Vetor2F tamanho;
	const string caminho;
	sf::Clock relogio;

public:
	EntidadeColidivel(const Vetor2F Pos = (0.0, 0.0),const Vetor2F Vel = (0.0, 0.0),const Vetor2F Tam = (0.0, 0.0), const string CaminhoText = nullptr);
	//EntidadeColidivel();
	virtual ~EntidadeColidivel();

	virtual void atualizar(float t) = 0;
	virtual void inicializar(GerenciadorGrafico& g);
	virtual void desenhar(GerenciadorGrafico& g);
	virtual void colidir(EntidadeColidivel* outro, std::string tipoEntidade) = 0;
	virtual const Vetor2F getPosicao()const;
	virtual const Vetor2F getTamanho()const;
	virtual const Vetor2F getVelocidade()const;
	virtual const sf::Clock* getTempo();
	virtual void reiniciaRelogio();
	


};

