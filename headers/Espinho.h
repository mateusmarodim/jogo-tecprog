#pragma once
#include "../headers/EntidadeColidivel.h"

class Espinho: public EntidadeColidivel
{
private:

public:
    Espinho(const Vetor2F Pos = (0.0,0.0), const Vetor2F Vel = (0.0,0.0), const Vetor2F Tam = (0.0,0.0));
    ~Espinho();

    void atualizar(float f);
    void colidir(EntidadeColidivel* outro, string tipoEntidade);
};