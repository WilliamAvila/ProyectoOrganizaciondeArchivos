#include "bloque.h"

Bloque::Bloque()
{
    size=0;
}

void Bloque::writeRegister(char *registro, const char *filename, int sizeArray)
{
    FILE *f= fopen(filename,"ab");
    fwrite(registro,sizeof(char),sizeArray,f);
    fclose(f);

}

void Bloque::readRegister(const char *filename, char *valor, int size)
{    FILE *f= fopen(filename,"rb");
     fseek (f , 200 , SEEK_SET);
     fread(valor,1,size,f);
     fclose(f);

}

int Bloque::sizeBloques(const char *filename)
{   FILE *f= fopen(filename,"rb");
    fseek (f , 0 , SEEK_END);
    size=ftell(f)-200;
    rewind(f);
    fclose(f);

    return size;

}

int Bloque::getCantR()
{
    return size/200;

}
