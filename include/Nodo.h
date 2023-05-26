#ifndef NODO_H
#define NODO_H
#include "Persona.h"


class Nodo
{
    public:
        Nodo();
        Nodo(Nodo *, Nodo *, Persona);


        void setPersona(Persona);
        Persona getPersona();

        Nodo *izq;
        Nodo *der;

    private:
        Persona p;
};

#endif // NODO_H
