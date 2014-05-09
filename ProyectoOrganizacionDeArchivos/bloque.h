#ifndef BLOQUE_H
#define BLOQUE_H

class Bloque
{
public:

    int *numeroDeBloques;
    int size;
    char reservar[4096];
    void resevando();

    Bloque();
};

#endif // BLOQUE_H
