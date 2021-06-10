#pragma once
#include "Obstaculo.h"

class PlataformaMovedica : public Obstaculo
{
private:
    float posiniY;
    float velfix;
public:
    PlataformaMovedica(const Vetor2F Pos = (0.0, 0.0),const  Vetor2F Vel = (0.0, 0.0),const  Vetor2F Tam = (0.0, 0.0));
    ~PlataformaMovedica();

    void atualizar(float t);
    void colidir(EntidadeColidivel* outro, std::string tipoEntidade);
};

