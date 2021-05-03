#pragma once
#include "EntidadeColidivel.h"

class Espinho: public EntidadeColidivel
{
public:
    Espinho(Vetor2F Pos = (0.0,0.0), Vetor2F Vel = (0.0,0.0), Vetor2F Tam = (0.0,0.0));
    ~Espinho();
    virtual void atualizar(float f);
    virtual void colidir(EntidadeColidivel* outro, string tipoEntidade);
};
