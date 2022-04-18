#pragma once
#include "Persona.hpp"
#include "Lista.hpp"

class ListaPersonas {
private:
	Lista<Persona*> vectorPersona;

	int cant;

public:
	ListaPersonas() {
		;
		cant = 0;
	}

	void InsertarPersona(int a, string b, string c, string d, int e) {
		vectorPersona.push_back(new Persona(a, b, c, d, e));
		cant++;
	}

	void eliminarPersona(Persona* name) {
		vectorPersona.delete_element(name);
	}

	void eliminarTodos() {
		vectorPersona.delete_lista();
	}

	void buscarPersona(Persona* n) {
		vectorPersona.search_element(n);
	}

	void eliminarTarea(Persona* n) {
		vectorPersona.delete_element(n);
	}

	void ordenarPorEdad() {

	}

	void mostrarGenero() {

	}

	int getCantidad() { return cant; }
	
	Persona* getpersona(int n) {
		return vectorPersona.obtenerElemento(n);
	}
};