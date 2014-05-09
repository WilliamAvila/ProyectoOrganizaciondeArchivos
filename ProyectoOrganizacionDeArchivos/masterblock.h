#ifndef MASTERBLOCK_H
#define MASTERBLOCK_H
#include "bloque.h"
class MasterBlock:public Bloque
{
public:
    int final;
    int inicio;
    int siguienteBloque;
    int siguienteTabla;

    MasterBlock();
};

#endif // MASTERBLOCK_H
