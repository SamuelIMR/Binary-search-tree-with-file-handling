#include "ABB.h"
#include "Persona.h"
#include <fstream>
#include <sstream>
#include <iostream>

ABB::ABB()
{
    //ctor
}

ABB::ABB(Nodo *raiz)
{
    this->raiz=raiz;
}

void ABB::nuevoN(Nodo *raiz, Persona p)
{
    if(raiz==nullptr)
    {
        raiz= new Nodo();
        raiz->setPersona(p);
    }
    else
    {
        if(p.getAge() < raiz->getPersona().getAge())
        {
            insertar(raiz->izq, p);
        }
        else
        {
            insertar(raiz->der, p);
        }
    }
}

void ABB::insertarNodo(Nodo *r, Persona p)
{
    Nodo *aux;                       //Esta función se utilizo para insertar los datos recuperado del txt directamente al árbol
    if(r==nullptr)                  //Verifica si el nodo es igual a null y de ser así crea uno nuevo e inicializa la clase persona
    {
        aux=new Nodo();
        aux->setPersona(p);
        raiz=aux;
    }
    else
    {
       if(p.getAge() < r->getPersona().getAge())  //Si la edad de la persona insertada es menor que la de la persona en la raiz
       {
           insertarNodo(r->izq, p);                //Se llamam nuevamente a la funcion insertar pero esta vez por su lado izquierdo
           r->izq=raiz;
       }
       else
       {
            insertarNodo(r->der,p);   //Caso contrario se llama a la fucnción insertar pero esta vez por su lado derecho
            r->der=raiz;
       }
       raiz=r;
    }


}

void ABB::insertar(Nodo *r, Persona p)
{
    Nodo *aux;                               //Inicializamos nuestro flujo al archivo y le asignamos nombre
    fstream archivo;                        //Abrimos o creamos el archivo y usamos ios::app para que los nuevos datos se inserten al final del archivo
    archivo.open("file01.txt", ios::app);   //sin modificar lo que ya se encuentra en el archivo
    if(r==nullptr)
    {
        aux=new Nodo();
        aux->setPersona(p);
        raiz=aux;

        archivo<<raiz->getPersona().getName();    //Ahora aprovechamos a la hora de insertar para que los datos tambien se guarden en el archivo
        archivo<<"|";
        archivo<<raiz->getPersona().getAge();
        archivo<<"|";
        archivo<<raiz->getPersona().getProfesion();
        archivo<<"*";
    }
    else
    {
       if(p.getAge() < r->getPersona().getAge())  //Si la edad de la persona es menor a la de la persona del nodo
       {
           insertar(r->izq, p);                 //llamamos a la funcion insertar pero por el lado izquierdo
           r->izq=raiz;
       }
       else
       {
            insertar(r->der,p);         //Caso contraio llamamos a la funcion por su lado derecho
            r->der=raiz;
       }
       raiz=r;
    }
    archivo.close();  //Cerramos el archivo
}

Nodo *ABB::buscar(Nodo *raiz, Persona p)
{
    if(raiz==nullptr)  //Validamos que exista el nodo
        return raiz;

    if(p.getAge() == raiz->getPersona().getAge())  //Si la edad de la persona a buscar es la misma que la del nodo regresamos la raiz
    {
        return raiz;
    }
    if(p.getAge() < raiz->getPersona().getAge())  //Si la edad buscada es menor que la del nodo llamamos a la funcion buscar por el lado izquierdo
    {
        return buscar(raiz->izq,p);
    }
    if(p.getAge() > raiz->getPersona().getAge())  //Caso contrario, si es mayor, llamamos a la funcion de buscar por el lado derecho
    {
        return buscar(raiz->der,p);
    }

}


bool ABB::hoja(Nodo *raiz)
{
    if(raiz->der==nullptr && raiz->izq==nullptr)
        return true;
}

Nodo *ABB::getMayor(Nodo *raiz)
{
    if(raiz)
    {
        Nodo *max=raiz;
        while(max->der)
        {
            max=max->der;
        }
        return max;
    }
    else
        return nullptr;
}

Nodo *ABB::getMenor(Nodo *raiz)
{
    Nodo *act=raiz;  //Metodo para obtener el mayor de los menores
    while(act && act->izq)  //Mientras existea el nodo y tenga un hijo izquierdo
    {
        act=act->izq;           //Actualizamos el nodo al hijo izquierdo
    }
    return act;             //Una vez salga del bucle retornamos el nodo

}

/*
void ABB::eliminar(Nodo *r, Persona p)
{
    if(r== nullptr)
        return;

    if(r->getPersona().getAge() == p.getAge()){///hoja
        if(hoja(r)){
            delete r;
            r=nullptr;
            return;
        }
    if(r->izq== nullptr or r->der == nullptr){///1 hijo
        Nodo *aux(r);

        if(r->izq == nullptr)
            r=r->der;

        r=r->izq;

        delete aux;
        return;
    }///2 hijos

    Persona sus(getMayor(r->izq)->getPersona());

    r->setPersona(sus);

    eliminar(r->izq,sus);

    }
    else{
        if(p.getAge() < r->getPersona().getAge())
            eliminar(r->izq,p);
        else
            eliminar(r->der,p);
    }
}

*/
Nodo *ABB::eliminar(Nodo *root, Persona p)
{
    if(root==nullptr)   //Validamos que exista el nodo raiz
        return root;

    if(p.getAge() < root->getPersona().getAge())   //Si la edad de la persona a eliminar es menor que la edad de la persona de la raiz
        root->izq= eliminar(root->izq, p);          //llamamos a la funcion eliminar por el lado izquierdo

    else if(p.getAge() > root->getPersona().getAge())
        root->der=(eliminar(root->der,p));          //Caso contrario llamamos a la función eliminar por el lado derecho

    else
    {
        if(root->izq==nullptr)  //Si tiene hijo derecho
        {
            Nodo *aux=root->der;  //Guardamos el hijo derecho en un auxiliar
            delete root;            //Eliminamos el nodo que deseabamos
            return aux;
                        //Retornamos el auxiliar para reemplazar
        }
        else if(root->der==nullptr) //Si tiene hijo izquierdo
        {
            Nodo *aux=root->izq;  //Se realiza el mismo procedimiento que si tuviera hijo derecho
            delete root;
            return aux;
        }
        Nodo *temp= getMenor(root->der);  //Creamos un nodo temporal que almacena el menor de los mayores
        root->setPersona(temp->getPersona()); //Inicializamos la clase de la raiz con la clase del nodo temporal (menor de los mayores)
        root->der=eliminar(root->der, temp->getPersona()); //Y ahora eliminamos el

    }
    return root;//Retornamos la raiz
}

void ABB::replace(Nodo *root)
{
    Nodo *aux=root;
    fstream archivo;
    archivo.open("file01.txt",ios::out);
    if(aux)
    {
       archivo<< aux->getPersona().getName();
       archivo<<"|";
       archivo<< aux->getPersona().getAge();
       archivo<<"|";
       archivo<< aux->getPersona().getProfesion();
       archivo<<"*";
       replace(aux->izq);
       replace(aux->der);
    }
    archivo.close();
}

void ABB::mostrar(Nodo *raiz, int cont)
{
    if(raiz==nullptr)
    {
        return;
    }
    else{
        mostrar(raiz->der,cont+1);
        for(int i=0; i<cont; i++)
        {
            cout<< "     ";
        }
        cout<<raiz->getPersona().getAge()<<endl;
        mostrar(raiz->izq,cont+1);
    }

}

void ABB::inorden(Nodo *aux)
{
   if(aux)
   {
       inorden(aux->izq);
       //cout<< "-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
       cout<< "Nombre: " << aux->getPersona().getName()<<endl;
       cout<< "Edad: " << aux->getPersona().getAge()<<endl;
       cout<< "Profesion: " << aux->getPersona().getProfesion()<<endl;
       cout<< "-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
       inorden(aux->der);

   }
}

void ABB::preorden(Nodo *aux)
{
    if(aux)
    {
       //cout<< "-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
       cout<< "Nombre: " << aux->getPersona().getName()<<endl;
       cout<< "Edad: " << aux->getPersona().getAge()<<endl;
       cout<< "Profesion: " << aux->getPersona().getProfesion()<<endl;
       cout<< "-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
       preorden(aux->izq);
       preorden(aux->der);
    }
}

void ABB::postorden(Nodo *aux)
{
    if(aux)
    {
        postorden(aux->izq);
        postorden(aux->der);
        //cout<< "-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
        cout<< "Nombre: " << aux->getPersona().getName()<<endl;
        cout<< "Edad: " << aux->getPersona().getAge()<<endl;
        cout<< "Profesion: " << aux->getPersona().getProfesion()<<endl;
        cout<< "-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
    }
}

void ABB::recuperar()
{
    string name, prof, edad;    //Creamos las variables de los atributos de la clase
    int age;
    ifstream archivo("file01.txt", ios::in); //Abrimos el archivo

    if(!archivo.good())  //Validamos que el archivo se abriera de manera correcta
    {
        cout<< "Error al abrir el archivo "<<endl;
    }
    else
    {
        while(!archivo.eof())   //Mientras no sea el final del arhcivo
        {
            getline(archivo,name, '|');  //Recuperamos loa atributos con delimitadores de campo
            getline(archivo,edad,'|');
            getline(archivo,prof, '*'); //Y separamos las clases con el delimitador de registro
            age=stoi(edad);

            Persona paux(name,age,prof);  //Inicializamos la clase persona con los datos recuperados del archivo

            if(archivo.eof())
            {
                break;
            }
            insertarNodo(raiz, paux);  //Insertamos los nodos al arbol. Solo se insertan en el arbol, no se vuelven a insertar en el archivo
        }
    }
    archivo.close();  //Cerramos el archivo
}
