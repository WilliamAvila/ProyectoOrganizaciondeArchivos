#ifndef DEFINICIONDECAMPO_H
#define DEFINICIONDECAMPO_H


class DefinicionDeCampo
{
    public:
        char Nombre[30];
        int size;
        int tipo;
        DefinicionDeCampo();
        virtual ~DefinicionDeCampo();
    protected:
    private:
};

#endif // DEFINICIONDECAMPO_H
