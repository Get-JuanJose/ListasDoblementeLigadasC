#pragma once
#include"Nodo.h"
class Lista
{	//Atributos.
private: Nodo* head, *end;
	//Metodos.
public:
	Lista();
	void InsertarInicio(int d);
	void InsertarFinal(int d);
	void InsertarOrdenado(int d);
	void Ordenar();
	void Buscar(int d);
	void Reemplazar(int d);
	void Eliminar();
	void SumarListas(Lista* lista1, Lista* lista2, Lista * lista3);
	//No requerido.
	void Mostrar();
	
	//Validacion.
	int Validacion(Lista* Lista1, Lista* Lista2, Lista* Lista3, int dec);
	void ValidacionSuma(Lista* Lista1, Lista* Lista2, Lista* Lista3);
};

