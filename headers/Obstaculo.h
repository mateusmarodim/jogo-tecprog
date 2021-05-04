#pragma once
#include "EntidadeColidivel.h"

class Obstaculo : public EntidadeColidivel
{
public:
    Obstaculo(const Vetor2F Pos = (0.0, 0.0),const  Vetor2F Vel = (0.0, 0.0),const  Vetor2F Tam = (0.0, 0.0), const string CaminhoText = nullptr);
    virtual  ~Obstaculo();

    virtual void colidir(EntidadeColidivel* outro, string tipoEntidade);
};

