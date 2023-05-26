#include <iostream>
#include "ABB.h"
#include "Nodo.h"
#include "Persona.h"

using namespace std;

void menu();

int main()
{
    menu();

    return 0;
}

void menu()
{
    int opc, age, cont=0;
    string nombre, prof;
    ABB *arbol= new ABB(nullptr);
    Nodo *raiz=nullptr;
    Persona p;

    do
    {
       system("cls");
       cout<< "-*-*-*-MENU-*-*-*-"<<endl<<endl;
       cout<< "[1] Agregar elementos"<<endl;
       cout<< "[2] Buscar elemento"<<endl;
       cout<< "[3] Eliminar"<<endl;
       cout<< "[4] Recorrido Inorden"<<endl;
       cout<< "[5] Recorrido Postorden"<<endl;
       cout<< "[6] Recorrido Preorden"<<endl;
       cout<< "[7] Cargar Elementos"<<endl;
       cout<< "[8] Mostrar arbol"<<endl;
       cout<< "[9] Salir"<<endl;
       cin>>opc;


       switch(opc){
            case 1:
                cout<< "Nombre: ";
                cin>>nombre;
                p.setName(nombre);
                cout<< "Edad: ";
                cin>>age;
                p.setAge(age);
                cout<< "Profesion: ";
                cin>>prof;
                p.setProfesion(prof);
                arbol->insertar(arbol->raiz, p);
                break;
            case 2:
                cout<< "Ingrese la edad de la persona que desea buscar: ";
                cin>>age;
                p.setAge(age);
                if(arbol->buscar(arbol->raiz, p)==nullptr)
                {
                    cout<< "Persona no encontrada"<<endl;
                }
                else{
                    cout<< "Persona encontrada"<<endl;
                    cout<< "Nombre: "<< arbol->buscar(arbol->raiz,p)->getPersona().getName()<<endl;
                    cout<< "Edad: "<< arbol->buscar(arbol->raiz,p)->getPersona().getAge()<<endl;
                    cout<< "Profesion: "<< arbol->buscar(arbol->raiz,p)->getPersona().getProfesion()<<endl;
                }
                //arbol->buscar(arbol->raiz,p);
                system("pause");
                break;
            case 3:
                cout<< "Ingrese la edad de la persona que desea eliminar: ";
                cin>>age;
                p.setAge(age);
                arbol->eliminar(arbol->raiz,p);
                //arbol->replace(arbol->raiz);
                arbol->mostrar(arbol->raiz,cont);
                system("pause");
                break;
            case 4:
                cout<<"Recorrido InOrden"<<endl;
                arbol->inorden(arbol->raiz);
                system("pause");
                break;
            case 5:
                cout<< "Recorrido PostOrden"<<endl;
                arbol->postorden(arbol->raiz);
                system("pause");
                break;
            case 6:
                cout<< "Recorrido PreOrden"<<endl;
                arbol->preorden(arbol->raiz);
                system("pause");
                break;
            case 7:
                cout<< "Cargar elementos"<<endl;
                arbol->recuperar();
                system("pause");

                break;
            case 8:
                arbol->mostrar(arbol->raiz,cont);
                system("pause");
                break;
            case 9:
                break;

       }

    }while(opc!=9);
}
