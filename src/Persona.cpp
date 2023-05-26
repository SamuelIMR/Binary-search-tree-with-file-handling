#include "Persona.h"

Persona::Persona()
{
    name="";
    age=0;
    profesion="";
}

Persona::Persona(string n, int a, string p)
{
    this->name=n;
    this->age=a;
    this->profesion=p;
}

void Persona::setName(string n)
{
    this->name=n;
}

void Persona::setAge(int a)
{
    this->age=a;
}

void Persona::setProfesion(string p)
{
    this->profesion=p;
}

string Persona::getName()
{
    return name;
}

int Persona::getAge()
{
    return age;
}

string Persona::getProfesion()
{
    return profesion;
}
