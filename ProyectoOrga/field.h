#ifndef FIELD_H
#define FIELD_H
#include <iostream>
#include <cstring>
using namespace std;


class Field
{
    public:
        int tam;
        int tag;
        char*value;
        void setInt(int &valueInt);
        void setString(char *valueStr);
        void printField();


        int getType();
        int getSize();
        int toInt();
        char *toStr();


        Field();
        virtual ~Field();
    protected:
    private:
};

#endif // FIELD_H
