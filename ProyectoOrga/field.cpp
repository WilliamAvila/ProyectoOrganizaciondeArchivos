#include "Field.h"

Field::Field()
{
    value=new char[40];
    tam=40;
    tag=0;
    //ctor
}

Field::~Field()
{
    //dtor
}
void Field::setInt(int& valueInt)
{
  memcpy(value,(char*)&valueInt,sizeof(int));
  tag=2;


}

void Field::setString(char *valueStr)
{
   value=valueStr;
   tag=1;

}

void Field::printField()
{
        cout<<value;
}

int Field::getType()
{
    return tag;

}

int Field::getSize()
{
    return tam;
}
int Field::toInt()
{ int i;
    memcpy(&i,value,sizeof(int));
    return i;
}
