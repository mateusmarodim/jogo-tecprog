#pragma once
#include "EntidadeColidivel.h"

class Obstaculo : public EntidadeColidivel
{
public:
    Obstaculo(Vetor2F pos = (0.0, 0.0), Vetor2F vel = (0.0, 0.0), Vetor2F tam = (0.0, 0.0), const char* caminhoText = nullptr);
    ~Obstaculo();

    virtual void desenhar(GerenciadorGrafico& g);
};

