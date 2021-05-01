#pragma once
#include "Inimigo.h"
#include "Caverna.h"

class Caverna;

class SlimeRei : public Inimigo
{
private:
	//Caverna* pCaverna;
	Jogador* pJogador;
	bool podePular;
public:
	SlimeRei(/*Caverna* pc = nullptr,*/ Jogador* pj = nullptr,const  Vetor2F Pos = (0.0, 0.0),const  Vetor2F Vel = (0.0, 0.0),const  Vetor2F Tam = (0.0, 0.0));
	~SlimeRei();
	void atualizar(float t);
	void colidir(EntidadeColidivel* outro, std::string tipoEntidade);
	void mover();
};