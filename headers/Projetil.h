#pragma once
#include "EntidadeColidivel.h"

class Projetil: public EntidadeColidivel
{
private:
   // bool deletar;
public:
    Projetil(Vetor2F Pos = (0.0,0.0), Vetor2F Vel = (0.0,0.0), Vetor2F Tam = (0.0,0.0));
    ~Projetil();
    virtual void atualizar(float f);
    virtual void colidir(EntidadeColidivel* outro, string tipoEntidade);
    
   // void setDeletar();
   // bool getDeletar();
};