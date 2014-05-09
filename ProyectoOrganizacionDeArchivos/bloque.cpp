#include "bloque.h"
#include "filebinario.h"

Bloque::Bloque()
{
    this->size=4096;
    for(int i=0;i<size;i++)
         reservar[i]='-';
    this->numeroDeBloques=new int();
    *numeroDeBloques=0;

}

void Bloque::resevando()
{

}
