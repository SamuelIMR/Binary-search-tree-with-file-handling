#include "Nodo.h"

Nodo::Nodo()
{
    this->der=nullptr;
    this->izq=nullptr;
    this->p=p;
}

Nodo::Nodo(Nodo *i, Nodo *d, Persona p)
{
    izq=i;
    der=d;
    p=p;
}

void Nodo::setPersona(Persona p)
{
    this->p=p;
}

Persona Nodo::getPersona()
{
    return p;
}







