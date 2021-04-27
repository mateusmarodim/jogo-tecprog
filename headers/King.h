#pragma once
#include "Inimigo.h"
#include "Caverna.h"

class Caverna;

class King : public Inimigo
{
private:
	Caverna* pCaverna;
	Jogador* pJogador;
	bool podePular;
	sf::Clock cooldownPulo;
public:
	King(Caverna* pc = nullptr, Jogador* pj = nullptr, Vetor2F pos = (0.0, 0.0), Vetor2F vel = (0.0, 0.0), Vetor2F tam = (0.0, 0.0));
	~King();
	void atualizar(float t);
	void colidir(EntidadeColidivel* outro, std::string tipoEntidade);
	void mover();
};