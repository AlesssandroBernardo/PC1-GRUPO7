#pragma once
#include <iostream>

using namespace std;

template <typename D>
struct Nodo {
	D element;
	Nodo* sgte;

	Nodo(D e, Nodo* s) {
		element = e;
		sgte = s;
	}
};

template <class D>
class Lista {
private:
	Nodo<D>* first;
	Nodo<D>* last;
	long cant;

public:
	Lista() {
		first = nullptr;
		last = nullptr;
		cant = 0;
	}

	void push_back(D valor) {
		Nodo<D>* nuevo = new Nodo<D> (valor, first);
		if (cant == 0)
			first = nuevo;

		else 
			last->sgte = nuevo;
			
		last = nuevo;	
		++cant;
	}

	void push_front(D valor) {
		Nodo<D>* nuevo = new Nodo<D>(valor);
		if (cant == 0)
			last = nuevo;

		else
			nuevo->sgte = inicio;

		inicio = nuevo;
		++cant;
	}

	void push_pos(D valor, int pos) {
		if (pos <= 0)
			push_front(valor);

		else if (pos >= cant)
			push_back(valor);

		else {
			Nodo<D>* aux = first;
			Nodo<D>* nuevo = new Nodo<D>(valor);
			for (int i = 0; i < pos - 1;++i)
				aux = aux->sgte;
			nuevo->sgte = aux->sgte;
			aux->sgte = nuevo;
			++cant;
		}
	}

	void delete_front() {
		if (cant == 0) return;
		
		else if (cant == 1) {
			delete first;
			first = last = nullptr;
		}

		else if (cant > 0) {
			Nodo<D>* aux = first;
			first = first->sgte;
			delete aux;
		}

		--cant;
	}

	void delete_back() {
		if (cant == 0 || cant == 1) {
			delete_front();
		}
		else {
			Nodo<D>* aux = first;
			for (int i = 0;i < cant - 2;++i)
				aux = aux->sgte;

			delete aux->sgte;
			last = aux;
			last->sgte = nullptr;
			--cant;
		}
	}

	void delete_pos(int pos) {
		if (cant == 0 || cant == 1)
			delete_front();

		else if (cant == pos)
			delete_back();

		else {
			Nodo<D>* aux = first;
			for (int i = 0; i < pos - 1;++i) 
				aux = aux->sgte->sgte;
			aux->sgte = aux->sgte->sgte;
			delete aux->sgte;
			--cant;
		}
	}
	
	void delete_element(D n) {
		if (first != NULL) {
			Nodo<D>* auxborrar = first;
			Nodo<D>* anterior = first;

			while ((auxborrar != nullptr) && (auxborrar->element != n)) {
				anterior = auxborrar;
				auxborrar = anterior->sgte;
			}

			if (auxborrar == nullptr)
				cout << "El elemento no ha sido encontrado... :(" << endl;

			else if (anterior == nullptr) {
				first = first->sgte;
				delete auxborrar;
			}

			else {
				anterior->sgte = auxborrar->sgte;
				delete auxborrar;
			}
		}
	}

	void search_element(D n) {

		if (first != NULL) {
			Nodo<D>* actual = first;

			while ((actual != nullptr) && (actual->element != n)) {
				actual = actual->sgte;
			}

			if (actual == nullptr)
				cout << "El elemento no ha sido encontrado... :(" << endl;

			else if (actual->element == n) {
				cout << "El elemento " << n << " ha sido encontrado... :)" << endl;
			}

		}
	}

	void delete_lista() {
		while (first != nullptr) {
			Nodo<D>* aux = first;
			first = aux->sgte;
			delete aux;
		}
	}

	void mostrar() {
		Nodo<D>* aux = inicio;
		int i = 0;
		while (aux != nullptr) {
			cout << i++ << ")" << aux->element << endl;
			aux = aux->sgte;
		}
		cout << "\n";

		if (aux == NULL)
			cout << "Lista vacia" << endl;
	}

	D obtenerElemento(int pos) {
		if (pos >= 0 && pos < cant) {
			Nodo<D>* aux = first;
			for (int i = 0; i < pos; i++)
			{
				aux = aux->sgte;
			}
			return aux->element;
		}
		else {
			return 0;
		}
	}
};