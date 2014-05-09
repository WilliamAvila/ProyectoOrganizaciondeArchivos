#include "Data.h"
using namespace std;
Data::Data()
{
  this->puntero=new DefinicionDeCampo();
  this->c=new Campos();
    c->DefinirCampos();
this->byteArray=new char[c->size];


  //ctor;
}

Data::~Data()
{
    //dtor
}
void Data::VariableTOByteArray(){




}
void Data::ByteArrayTOVariable(){


}
int Data::ToInt(char*byteArray,int pos){
int acumulado=0;
memcpy(&acumulado,&byteArray[pos],4);
return acumulado;

}
void Data::ToString(char*byteArray,int pos,char variable[30]){
memcpy(&variable[0],&byteArray[pos],30);
}
