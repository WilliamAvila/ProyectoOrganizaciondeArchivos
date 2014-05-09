#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <cstring>
#include "DefinicionDeCampo.h"
#include "Campos.h"
#include <cstring>

class Data
{
    public:
        char*byteArray;
        Campos *c;
        DefinicionDeCampo * puntero;
        void VariableTOByteArray();
        void ToString(char*byteArray, int pos,char variable[]);
        int ToInt(char * byteArray,int pos);
        void ByteArrayTOVariable();
        Data();
        virtual ~Data();
    protected:
    private:
};

#endif // DATA_H
