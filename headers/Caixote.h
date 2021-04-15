#pragma once
#include "Obstaculo.h"

class Caixote : public Obstaculo
{
private:
    bool colidindo;
public:
    Caixote(Vetor2F pos = (0.0, 0.0), Vetor2F vel = (0.0, 0.0), Vetor2F tam = (0.0, 0.0));
    ~Caixote();


    void desenhar(GerenciadorGrafico& g);
    void atualizar(float t);
    void colidir(EntidadeColidivel* outro, std::string tipoEntidade);
};

