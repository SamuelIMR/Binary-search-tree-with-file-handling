#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
using namespace std;

class Persona
{
    public:
        Persona();
        Persona(string, int, string);

        void setName(string);
        void setAge(int);
        void setProfesion(string);

        string getName();
        int getAge();
        string getProfesion();

    private:
        string name;
        int age;
        string profesion;
};

#endif // PERSONA_H
