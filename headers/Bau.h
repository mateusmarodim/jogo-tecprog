#pragma once
#include "../headers/Obstaculo.h"

class Bau : public Obstaculo
{
private:
    bool colidindo;

public:
    Bau(const Vetor2F Pos = (0.0, 0.0),const  Vetor2F Vel = (0.0, 0.0),const  Vetor2F Tam = (0.0, 0.0));
    ~Bau();

    void atualizar(float t);
    void colidir(EntidadeColidivel* outro, std::string tipoEntidade);
};

