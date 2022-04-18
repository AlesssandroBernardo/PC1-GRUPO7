#pragma once
#include "ListaTarea.h"
#include "ListaPersona.hpp"
#include "Persona.hpp"
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>
#include <iostream>

using namespace System;
using namespace std;

class Asignacion {
private:
    ListaPersonas* listaP = new ListaPersonas();
    ListaTareas* listaT = new ListaTareas();
    int opcion;

public:
    Asignacion() {
        listaP = new ListaPersonas();
        listaT = new ListaTareas();
        opcion = 0;
    }

    void agregarPersona(ListaPersonas* ListaP) {
        int id;
        string Nombre;
        string Apellido;
        string genero;
        int edad;
        cout << "Ingrese su ID:" << endl;
        cin >> id;
        cin.ignore();
        cout << "Ingrese su nombre: ";
        getline(cin, Nombre); cout << endl;
        cout << "Ingrese su apellido: ";
        getline(cin, Apellido); cout << endl;
        cout << "Ingrese su genero (Masculino-Femenino-Otro): ";
        getline(cin, genero); cout << endl;
        cout << "Ingrese su edad: ";
        cin >> edad;
        ListaP->InsertarPersona(id, Nombre, Apellido, genero, edad);
    }

    void agregarTarea(ListaPersonas* ListaP, ListaTareas* ListaT) {
        string nombreTarea;
        string tipoUrgencia;
        string estado;
        string fechaCreacion;
        string auxPersona;
        int aux = 0;
        cout << "Ingrese el nombre de la tarea: ";
        cin.ignore();
        getline(cin, nombreTarea); cout << endl;
        cout << "Ingrese el tipo de urgencia(urgente-aplazable): ";
        getline(cin, tipoUrgencia); cout << endl;
        cout << "Ingrese su estado(completo, incompleto): ";
        getline(cin, estado); cout << endl;
        cout << "Ingrese la fecha de creacion: ";
        getline(cin, fechaCreacion); cout << endl;
        cout << "Ingrese su nombre: ";
        getline(cin, auxPersona); cout << endl;
        for (int i = 0; i < ListaP->getCantidad(); i++)
        {
            if (ListaP->getpersona(i)->getNombre() == auxPersona) {
                ListaT->InsertarTarea(nombreTarea, tipoUrgencia, estado, fechaCreacion, ListaP->getpersona(i));
                aux = 1;
            }
        }
        if (aux == 0) {
            cout << "Usted no ha sido registrado" << endl;
        }
    }

    void mostrarPersonas(ListaPersonas* listaP) {
        for (int i = 0; i < listaP->getCantidad(); i++)
        {
            cout << listaP->getpersona(i)->getNombre() << endl;
        }
    }

    void mostrarTareas(ListaPersonas* listaP, ListaTareas* ListaT) {
        for (int i = 0; i < listaP->getCantidad(); i++)
        {
            cout << listaP->getpersona(i)->getNombre() << ":" << endl;

            for (int j = 0; j < ListaT->getCantidad(); j++)
            {
                if (listaP->getpersona(i)->getNombre() == ListaT->getTarea(j)->getPersona()->getNombre()) {
                    cout << j + 1 << ".-" << ListaT->getTarea(j)->getNombrTarea() << "\t" << "Estado: " << ListaT->getTarea(j)->getEstado() << endl;
                }
            }
        }

    }
    void mostrarTareasTerminadas(ListaTareas* ListaT) {
        for (int i = 0; i < ListaT->getCantidad(); i++)
        {
            cout << "Usuario: " << ListaT->getTarea(i)->getPersona()->getNombre() << endl;
            if (ListaT->getTarea(i)->getEstado() == "completo") {
                for (int i = 0; i < ListaT->getCantidad(); i++) {
                    cout << "Tareas terminadas de: " << ListaT->getTarea(i)->getPersona()->getNombre() << endl;
                    cout << i + 1 << ListaT->getTarea(i)->getNombrTarea() << endl;
                }
            }
        }
    }

    void cambiarEstadoTarea(ListaTareas* ListaT) {
        string auxUsuario;
        string auxTarea;
        cout << "Ingrese un nombre de usuario registrado: " << endl;
        cin.ignore();
        getline(cin, auxUsuario); cout << endl;
        for (int i = 0; i < ListaT->getCantidad(); i++)
        {
            if (ListaT->getTarea(i)->getPersona()->getNombre() == auxUsuario) {
                cout << "Ingrese la tarea para cambiar su estado: " << endl;
                for (int i = 0; i < ListaT->getCantidad(); i++)
                {
                    if (ListaT->getTarea(i)->getPersona()->getNombre() == auxUsuario) {
                        cout << i+1<<".-"<<ListaT->getTarea(i)->getNombrTarea() << endl;
                    }
                }
                getline(cin, auxTarea); cout << endl;
                if (ListaT->getTarea(i)->getNombrTarea() == auxTarea) {
                    ListaT->getTarea(i)->setEst("completo") ; 
                }
            }
            else {
                cout << "El nombre puesto no es de un usuario registrado, intentelo nuevamente" << endl; break;
            }
        }
    }
    void mostrarTareasIncompletas(ListaTareas* listaT) {
        for (int i = 0; i < listaT->getCantidad(); i++)
        {
            if (listaT->getTarea(i)->getEstado() == "incompleto") {
                cout << "Tareas incompletas:" << endl;
                cout << listaT->getTarea(i)->getNombrTarea() << " -> " << listaT->getTarea(i)->getPersona()->getNombre() << endl;
            }
        }
    }

    void guardarDatos(ListaPersonas* listaP) {


        ofstream archEsc("NombreUsuarios.txt");
        for (int i = 0; i < listaP->getCantidad(); i++)
        {
            archEsc << listaP->getpersona(i)->getNombre() << endl;
            archEsc << listaP->getpersona(i)->getApellido() << endl;
            archEsc << listaP->getpersona(i)->getEdad() << endl;
            archEsc << listaP->getpersona(i)->getGenero() << endl;
            archEsc << listaP->getpersona(i)->getid() << endl;
            archEsc << endl;
        }
        ifstream archLect("NombreUsuarios.txt");

        archLect.close();
    }

    void limpiarPantalla() {
        system("cls");
        system("cls");

    }

    void mostrarMenu() {
        cout << "Ingrese una opcion" << endl;
        cout << "1.- Agregar un usuario" << endl;
        cout << "2.- Agregar una tarea" << endl;
        cout << "3.- Ver lista de tareas" << endl;
        cout << "4.- Mostrar tareas terminadas" << endl;
        cout << "5.-Cambiar estado de una tarea" << endl;
        cout << "6.- Mostrar tareas incompletas" << endl;
        cout << "7.- Guardar datos" << endl;
        cout << "8.- Limpiar consola" << endl;
        cout << "9.- Salir" << endl;
    }
    
    void Menu() {
        while (true)
        {
            mostrarMenu();
            cin >> opcion;
            switch (opcion)
            {
            case 1: agregarPersona(listaP); break;
            case 2: agregarTarea(listaP, listaT); break;
            case 3: mostrarTareas(listaP, listaT); break;
            case 4: mostrarTareasTerminadas(listaT); break;
            case 5: cambiarEstadoTarea(listaT); break;
            case 6: mostrarTareasIncompletas(listaT); break;
            case 7: guardarDatos(listaP);
            case 8:limpiarPantalla();
            case 9:return;


            default:
                break;
            }
        }
        delete listaP;
        delete listaT;
    }

};
