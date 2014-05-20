#ifndef BLOQUE_H
#define BLOQUE_H
#include <stdio.h>
class Bloque
{
public:
    Bloque();
    void writeRegister(char *registro, const char *filename,int sizeArray);
    void readRegister(const char *filename, char *valor, int size);
    int sizeBloques(const char *filename);
    int getCantR();
    long size;
};

#endif // BLOQUE_H
