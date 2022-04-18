#pragma once
#include <iostream>

using namespace std;

class Persona {
private:
    int id;
    string Nombre;
    string Apellido;
    string genero;
    int edad;
public:
    Persona(int i, string n, string a, string g, int e){
        this->id = i;
        this->Nombre = n;
        this->Apellido = a;
        this->genero = g;
        this->edad = e;
    }
    int getid() { return id; }
    string getNombre() { return Nombre; }
    string getApellido() { return Apellido; }
    string getGenero() { return genero; }
    int getEdad() { return edad; }

    void setId(int i) { id = i; }
    void setNombre(string n) { Nombre = n; }
    void setApellido(string a) { Apellido = a; }
    void setgenero(string g) { genero = g; }
    void setedad(int e) { edad = e; }

};

