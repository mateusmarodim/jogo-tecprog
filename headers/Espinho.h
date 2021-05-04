#pragma once
#include "EntidadeColidivel.h"

class Espinho: public EntidadeColidivel
{
private:
   // bool deletar;
public:
    Espinho(const Vetor2F Pos = (0.0,0.0), const Vetor2F Vel = (0.0,0.0), const Vetor2F Tam = (0.0,0.0));
    ~Espinho();
    virtual void atualizar(float f);
    virtual void colidir(EntidadeColidivel* outro, string tipoEntidade);
    
   // void setDeletar();
   // bool getDeletar();
};