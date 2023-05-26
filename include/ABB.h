#ifndef ABB_H
#define ABB_H
#include "Persona.h"
#include "Nodo.h"

class ABB
{
    public:
        ABB();
        ABB(Nodo *);
        void insertar(Nodo *, Persona);
        void insertarNodo(Nodo *, Persona p);
        Nodo *buscar(Nodo *, Persona);
        Nodo *eliminar(Nodo *, Persona);
        void nuevoN(Nodo *,Persona);
        void inorden(Nodo *);
        void postorden(Nodo *);
        void preorden(Nodo *);
        void mostrar(Nodo *, int);
        void recuperar();
        Nodo *getMayor(Nodo *);
        Nodo *getMenor(Nodo *);
        bool hoja(Nodo *);
        void replace(Nodo *);
        Nodo *raiz;
    private:

};

#endif // ABB_H
