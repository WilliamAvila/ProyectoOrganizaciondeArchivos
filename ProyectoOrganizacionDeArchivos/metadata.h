#ifndef METADATA_H
#define METADATA_H
#include <list>
class Metadata
{
public:
    int siguienteMetadata;
    int cantidadMetadata;
    int size=0;
    std::list< DefinicionDeCampo*>campos;
    Metadata();
};

#endif // METADATA_H
