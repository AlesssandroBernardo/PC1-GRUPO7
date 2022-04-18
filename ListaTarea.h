#include "Tarea.hpp"
#include "Lista.hpp"
#include "vector"
#include<fstream>
#include <string>
#include <vector>
#include <conio.h>
#include <iostream>


class ListaTareas {
private:
	Lista<Tarea*> vectorTarea;
	int cant;

public:
	ListaTareas() {;
		cant = 0;
	}
	
	void InsertarTarea(string a, string b, string c, string d,Persona* objPersona) {
		vectorTarea.push_back(new Tarea(a, b, c, d, objPersona));
		cant++;
	}
	
	void eliminarTarea(int pos){
		vectorTarea.delete_pos(pos);
	}

	void eliminarTodos(){
		vectorTarea.delete_lista();
	}

	void buscarTarea(Tarea* n){
		vectorTarea.search_element(n);
	}

	int getCantidad() { return cant; }

	void mostrarUgente(){
		
	}

	void eliminarTarea(Tarea* n){
		vectorTarea.delete_element(n);
	}

	void ordenarPorEstado(){
	
	}

	int setCantidad() { return cant; }

	Tarea* getTarea(int n) {
		return vectorTarea.obtenerElemento(n);
	}

};