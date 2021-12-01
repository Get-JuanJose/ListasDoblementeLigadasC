#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include <wchar.h>
#include"Lista.h"
//LISTA DOBLEMENTE LIGADA CIRCULAR.

using namespace std;
void menuListas();
void menuTrabajo();
void casosEliminar(int, Lista*, Lista*, Lista*);

int main()
{
	setlocale(LC_ALL, "");
	//Instancia.
	Lista* L1 = new Lista();
	Lista* L2 = new Lista();
	Lista* L3 = new Lista();
	int opc, decTrabajo, dato, aux=0;
	opc = 0;
	decTrabajo = 0;
	dato = 0;
	do
	{
		menuListas();
		cin >> opc;
		switch (opc)
		{
		case 1:// Insertar Inicio.
			cout << "Desea ingresar un dato para cual lista: " << endl;
			cout << "1. Lista 1." << endl;
			cout << "2. Lista 2." << endl;
			cin >> decTrabajo;
			switch (decTrabajo)
			{
			case 1:
				cout << "Ingrese el dato: " << endl;
				cin >> dato;
				L1->InsertarInicio(dato);
				break;
			case 2:
				cout << "Ingrese el dato: " << endl;
				cin >> dato;
				L2->InsertarInicio(dato);
				break;
			default:
				cout << "El dato no equivale a una lista." << endl;
				break;
			}
			break;
		case 2://Insertar Final.
			cout << "Desea ingresar un dato para cual lista: " << endl;
			cout << "1. Lista 1." << endl;
			cout << "2. Lista 2." << endl;
			cin >> decTrabajo;
			switch (decTrabajo)
			{
			case 1:
				cout << "Ingrese el dato: " << endl;
				cin >> dato;
				L1->InsertarFinal(dato);
				break;
			case 2:
				cout << "Ingrese el dato: " << endl;
				cin >> dato;
				L2->InsertarFinal(dato);
				break;
			default:
				cout << "El dato no equivale a una lista." << endl;
				break;
			}
			break;
		case 3://Insertar Ordenado.
			cout << "Desea ingresar un dato para cual lista: " << endl;
			cout << "1. Lista 1." << endl;
			cout << "2. Lista 2." << endl;
			cin >> decTrabajo;
			switch (decTrabajo)
			{
			case 1:
				cout << "Ingrese el dato: " << endl;
				cin >> dato;
				L1->InsertarOrdenado(dato);
				L1->Ordenar();
				break;
			case 2:
				cout << "Ingrese el dato: " << endl;
				cin >> dato;				
				L2->InsertarOrdenado(dato);
				L2->Ordenar();
				break;
			default:
				cout << "El dato no equivale a una lista." << endl;
				break;
			}
			break;
		case 4://Ordenar
			menuTrabajo();
			cin >> decTrabajo;
			aux = L1->Validacion(L1, L2, L3, decTrabajo);
			switch (aux)
			{
			case 1:
				L1->Ordenar();
				cout << "Se ordeno la lista 1." << endl;
				break;
			case 2:
				L2->Ordenar();
				cout << "Se ordeno la lista 2." << endl;
				break;
			case 3:
				L3->Ordenar();
				cout << "Se ordeno la lista 3." << endl;
				break;
			case 4:
				cout << "Regresando al menu principal." << endl;
				break;
			default:
				if (aux == 0)
				{
					cout << "no se puede realizar en una lista vacia." << endl;
				}
				else
				{
					cout << "El dato no equivale a una lista.";
				}
				break;
			}
			break;
		case 5://Buscar.
			menuTrabajo();
			cin >> decTrabajo;
			aux = L1->Validacion(L1, L2, L3, decTrabajo);
			switch (aux)
			{
			case 1:
				cout << "Ingrese el dato: " << endl;
				cin >> dato;
				L1->Buscar(dato);
				break;
			case 2:
				cout << "Ingrese el dato: " << endl;
				cin >> dato;
				L2->Buscar(dato);
				break;
			case 3:
				cout << "Ingrese el dato: " << endl;
				cin >> dato;
				L3->Buscar(dato);
				break;
			case 4:
				cout << "Regresando al menu principal." << endl;
				break;
			default:
				if (aux == 0)
				{
					cout << "no se puede realizar en una lista vacia." << endl;
				}
				else
				{
					cout << "El dato no equivale a una lista.";
				}
				break;
			}

			break;
		case 6://Reemplazar dato
			menuTrabajo();
			cin >> decTrabajo;
			aux = L1->Validacion(L1, L2, L3, decTrabajo);
			switch (aux)
			{
			case 1:
				cout << "Ingrese el dato: " << endl;
				cin >> dato;
				L1->Reemplazar(dato);
				break;
			case 2:
				cout << "Ingrese el dato: " << endl;
				cin >> dato;
				L2->Reemplazar(dato);
				break;
			case 3:
				cout << "Ingrese el dato: " << endl;
				cin >> dato;
				L3->Reemplazar(dato);
				break;
			case 4:
				cout << "Regresando al menu principal." << endl;
				break;
			default:

				if (aux == 0)
				{
					cout << "no se puede realizar en una lista vacia." << endl;
				}
				else
				{
					if (aux != 4)
					{
						cout << "El dato no equivale a una lista.";
					}
				}
				break;
			}
			break;
		case 7://Validar cuando la lista este vacia. con switch. //Mostrar
			menuTrabajo();
			cin >> decTrabajo;
			aux = L1->Validacion(L1, L2, L3, decTrabajo);
			switch (aux)
			{
			case 1:
				cout << "Lista 1: " << endl;
				L1->Mostrar();
				break;
			case 2:
				cout << "Lista 2: " << endl;
				L2->Mostrar();
				break;
			case 3:
				cout << "Lista 3: " << endl;
				L3->Mostrar();
				break;
			case 4:
				cout << "Regresando al menu principal." << endl;
				break;
			default:
				cout << "Dato incorrecto." << endl;
				break;
			}
			break;
		case 8://Sumar listas
			L3->SumarListas(L1, L2, L3);
			break;
		case 9://Eliminar
			menuTrabajo();
			cin >> decTrabajo;
			aux = L1->Validacion(L1, L2, L3, decTrabajo);
			casosEliminar(aux, L1, L2, L3);
			break;
		case 10:
			cout << "Gracias por utilizar mi programa!" << endl;
			break;
		default:
			break;
		}
		cin.get();
		cin.get();
		system("cls");
	} while (opc != 10);

	return 0;
}

void menuListas()
{
	cout << "\n \t Lista Doble Circular\n\n";
	cout << "\n \t Listas S.A \n\n";
	cout << "1. Insertar al Inicio. " << endl;
	cout << "2. Insertar al Final. " << endl;
	cout << "3. Insertar Ordenado. " << endl;
	cout << "4. Ordenar lista. " << endl;
	cout << "5. Buscar Y/O eliminar un dato. " << endl;
	cout << "6. Reemplazar dato. " << endl;
	cout << "7. Mostrar Listas. " << endl;
	cout << "8. Sumar listas. " << endl;
	cout << "9. Eliminar lista completa. " << endl;
	cout << "10. Salir." << endl;
	cout << "\t\t\t\t \t\t\t\t\tCreado en conjunto por: brian y juan jose \n\n";
	cout << "\t ¿Qué desea hacer?\n";
}
void menuTrabajo()
{
	cout << "Sobre cual lista desea trabajar" << endl;
	cout << "1. Lista 1." << endl;
	cout << "2. Lista 2." << endl;
	cout << "3. Lista 3." << endl;
	cout << "4. Regresar." << endl;
}


void casosEliminar(int dec, Lista* lista1, Lista* lista2, Lista* lista3)
{
	switch (dec)
	{
	case 1:
		lista1->Eliminar();
		break;
	case 2:
		lista2->Eliminar();
		break;
	case 3:
		lista3->Eliminar();
		break;
	case 4:
		cout << "regresando al menu principal." << endl;
	default:
		cout << "Ha ingresado un dato incorrecto." << endl;
		break;
	}
}