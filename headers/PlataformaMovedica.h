#pragma once
#include "Obstaculo.h"

class PlataformaMovedica : public Obstaculo
{
private:
    sf::Clock teste;
public:
    PlataformaMovedica(Vetor2F pos = (0.0, 0.0), Vetor2F vel = (0.0, 0.0), Vetor2F tam = (0.0, 0.0));
    ~PlataformaMovedica();


    void desenhar(GerenciadorGrafico& g);
    void atualizar(float t);
    void colidir(EntidadeColidivel* outro, std::string tipoEntidade);
};

