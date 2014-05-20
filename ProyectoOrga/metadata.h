#ifndef METADATA_H
#define METADATA_H
#include "list"
#include "field.h"
#include "QDebug"
using namespace std;
class Metadata
{
public:
    Metadata();
    list<Field*>Encabezados;
    list<int>tipos;
   // const char *filename;
    void insertEncabezado(char *encabezado, const char *filename,int sizeArray);
    void readEncabezado(const char *filename, char *valor, int size);
    void escribirTipos(const char *filename);



};

#endif // METADATA_H
