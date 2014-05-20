#include "metadata.h"

Metadata::Metadata()
{

}

void  Metadata::insertEncabezado(char* encabezado, const char *filename,int sizeArray){
     FILE *f= fopen(filename,"wb");
     fwrite(encabezado,sizeof(char),sizeArray,f);
     fclose(f);

}


void Metadata::escribirTipos( const char *filename){
     FILE *f= fopen(filename,"ab");
     for(list<int>::const_iterator it =this->tipos.begin();
         it!=this->tipos.end();
         it++){
            fwrite(&(*it),sizeof(char),4,f);

         }
     fclose(f);

}

void Metadata::readEncabezado( const char *filename,char *valor,int size){
    FILE *f= fopen(filename,"rb");
    fread(valor,1,size,f);
    fclose(f);

}
