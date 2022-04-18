#pragma once
#include "Tipo.hpp"
#include "Persona.hpp"
#include<iostream>
#include<string>
using namespace std;

class Tarea 
{
public:
	Tarea(string nombreTarea, string tipoUrgencia, string estado, string fechaCreacion,Persona*objpersona);
	~Tarea();

	void setTarea(string tarea);
	void setTipoUrg(string tipUrg);
	void setEst(string est);
	void setFecha(string fecha);
	void setPersona(Persona* objPersona);

	string getNombrTarea();
	string getTipoUrg();
	string getEstado();
	string getFecha();
	Persona* getPersona();

private:
	string nombreTarea;
	string tipoUrgencia;
	string estado;
	string fechaCreacion;
	Persona* objpersona;
};

Tarea::Tarea(string nombretarea = " ", string u = " ", string e= " ", string fechCreac=" ",Persona* objpersona=new Persona(0," "," "," ",0)) { 
	this->nombreTarea = nombretarea;
	this->tipoUrgencia = u;
	this->estado = e;
	this->fechaCreacion = fechCreac;
	this->objpersona = objpersona;

}

Tarea::~Tarea() {
};

void Tarea::setTarea(string tarea) {
	this->nombreTarea = tarea;
}
void Tarea::setTipoUrg(string tipo) {
	this->tipoUrgencia = tipo;
}
void Tarea::setEst(string est) {
	this->estado = est;
}
void Tarea::setFecha(string fecha) {
	this->fechaCreacion = fecha;
	
}
void Tarea::setPersona(Persona* objPersona) {
	this->objpersona = objPersona;
}

string Tarea::getNombrTarea() {
	return this->nombreTarea;
}
string Tarea::getTipoUrg() {
	return this->tipoUrgencia;
}
string Tarea::getEstado() {
	return this->estado;
}
string Tarea::getFecha() {
	return this->fechaCreacion;
}
Persona* Tarea::getPersona() {
	return this->objpersona;
}



