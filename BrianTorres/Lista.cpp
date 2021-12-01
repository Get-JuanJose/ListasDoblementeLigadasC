#include "Lista.h"
#include <iostream>

using namespace std;
Lista::Lista()
{
	head = nullptr;
	end = nullptr;
}

void Lista::InsertarInicio(int d)
{
	Nodo* x = new Nodo();

	x->SetDato(d);

	if(head ==nullptr)
	{
		head = x;
		end = x;
		x->Setld(head);
		x->Setli(head);
	}
	else
	{
		x->Setld(head);
		head->Setli(x);
		head = x;
		//
		end->Setld(head);
		head->Setli(end);
	}
 }

void Lista::InsertarFinal(int d)
{
	Nodo* x = new Nodo();

	x->SetDato(d);

	if (head == nullptr)
	{
		head = x;
		end = x;
		x->Setld(head);
		x->Setli(head);
	}
	else
	{
		end->Setld(x);
		x->Setli(end);
		end = x;
		end->Setld(head);
		head->Setli(end);

	}
}


void Lista::InsertarOrdenado(int d)
{
	int sw = 0;
	Nodo* p = head, * q = head, * fin = head;
	Nodo* x = new Nodo();
	x->SetDato(d);
	if (head == nullptr)
	{
		head = x;
		head->Setld(x);
		head->Setli(x);
		cout << "¡¡Se insertó el dato correctamente!!" << endl;
	}
	else
	{
		do
		{
			fin = head->Getli();
			if (fin->GetDato() < d && sw == 0)
			{
				sw = 1;
				x->Setld(head);
				x->Setli(fin);
				head->Setli(x);
				fin->Setld(x);
				cout << "¡¡Se insertó el dato correctamente!!" << endl;
			}
			if (d <= p->GetDato() && sw == 0)
			{
				sw = 1;
				if (p == head)
				{
					q = head->Getli();
					x->Setli(q);
					x->Setld(head);
					head->Setli(x);
					head = x;
					q->Setld(head);
					p = q;
					cout << "¡¡Se insertó el dato correctamente!!" << endl;
				}
				else
				{
					p = p->Getli();
					p->Setld(x);
					x->Setli(p);
					x->Setld(q);
					q->Setli(x);
					p = q;
					cout << "¡¡Se insertó el dato correctamente!!" << endl;
				}
			}
			p = p->Getld();
			q = q->Getld();
		} while (p != head);
	}
}

void Lista::Ordenar()
{
	int aux;
	Nodo* p = head, * q;
	if (head != nullptr)
	{
		do
		{
			q = p->Getld();
			while (q != head)
			{
				if (p->GetDato() > q->GetDato())
				{
					aux = q->GetDato();
					q->SetDato(p->GetDato());
					p->SetDato(aux);
				}
				q = q->Getld();
			}
			p = p->Getld();
			q = q->Getld();
		} while (p != head);
	}
	else
	{
		cout << "Como vas a ordenar una lista vacia???" << endl;
	}
		
}

void Lista::Buscar(int d)
{
	Nodo* p = head, * q = head->Getld();
	string dec;
	int noencontrado = 0;
	do
	{
		if (p->GetDato() == d)
		{
			noencontrado = 1;
			cout << "\tEl dato ha sido encontrado." << endl;
			if (p == head && q == head)
			{				
				p->SetDato(0);
				cout << "SOLO HAY UN NODO." << endl;
				Eliminar();
				p = nullptr;
			}
			else
			{
				cout << "Desea eliminar el dato (Si, No)" << endl;
				cin >> dec;
				if (dec == "Si" || dec == "si" || dec == "SI" || dec == "sI")
				{
					if(p == head && q != head)
					{
						head = q;

						q->Setli(p->Getli());
						p = p->Getli();
						p->Setld(q);
					}
					else
					{
						if (p != head)
						{
							q->Setli(p->Getli());
							p = p->Getli();
							p->Setld(q);
						}
					}				
				}
				else
				{
					q = q->Getld();
					p = p->Getld();
				}
			}		
		}
		else
		{
			q = q->Getld();
			p = p->Getld();
		}
	} while (p != head || (p==nullptr && q ==nullptr));
	if (noencontrado == 0)
	{
		cout << "El dato no fue encontrado." << endl;
	}
}

void Lista::Reemplazar(int d)
{
	int reemplazo = 0, i=0;
	Nodo* p = head;
	Mostrar();
	do
	{	
		if (p->GetDato() == d)
		{
			i++;
			cout << "\tEl dato numero "<< i<<" ha sido encontrado." << endl;
			cout << "Por cual dato lo desea reemplazar: " << endl;
			cin >> reemplazo;
			p->SetDato(reemplazo);
			cout << "El dato ha sido Reemplazado correctamente" << endl;
		}
		p = p->Getld();
	} while (p != head );
}

void Lista::Eliminar()
{
	Nodo* p=head, *q = head->Getli();
	do
	{
		p = p->Getli();	
		q = q->Getli();
		p = nullptr;
		p = q;
		
		cout << "El dato de la lista ha sido borrada correctamente" << endl;
	} while (p!=head);
	head = nullptr;
	cout << "Los datos de la lista se eliminaron correctamente." << endl;
}

void Lista::SumarListas(Lista *lista1, Lista *lista2, Lista *lista3)
{
	Nodo* p, * q;
	p = lista1->head;
	q = lista2->head;
	bool sumarHead = true;
	ValidacionSuma(lista1, lista2, lista3);
	if (p != nullptr || q != nullptr) 
	{
		do
		{
			if ((sumarHead == true || (p != lista1->head && q != lista2->head))&&(p!= nullptr && q!= nullptr))
			{
				lista3->InsertarFinal(p->GetDato() + q->GetDato());
				p = p->Getld();
				q = q->Getld();
				sumarHead = false;
			}
			else
			{
				if (p != lista1->head || q == nullptr)
				{
					lista3->InsertarFinal(p->GetDato());
					p = p->Getld();
				}
				if (q != lista2->head || p==nullptr)
				{
					lista3->InsertarFinal(q->GetDato());
					q = q->Getld();
				}
			}
		} while (p != lista1->head || q != lista2->head);
		cout << "Las listas han sido sumadas y almacenadas en la Lista 3." << endl;
	}
	else
	{
		if (p == nullptr && q == nullptr)
		{
			cout << "No se pueden sumar listas vacias." << endl;
		}	
	}
}
// Excluido.
void Lista::Mostrar()
{
	Nodo* p= head;
	if(head!= nullptr)
	{
		do
		{
			cout << "|" << p->GetDato() << "|";
			p = p->Getld();
		} while (p != head);
	}	
	else
	{
		cout << "La lista no tiene datos." << endl;
	}
}

int Lista::Validacion(Lista* Lista1, Lista* Lista2, Lista* Lista3, int dec)
{
	int aux = -1;
	if (Lista1->head != nullptr && Lista2->head != nullptr && Lista3->head != nullptr)
	{
		aux = 4;
	}
	else
	{
		if ((Lista1->head == nullptr) && (dec == 1))
		{
			cout << "Lista 1 vacia." << endl;
		}
		else
		{
			if (dec == 1 || dec == 4)
			{
				aux = dec;
			}
		}
		if (Lista2->head == nullptr && (dec == 2))
		{
			cout << "Lista 2 vacia." << endl;
		}
		else
		{
			if (dec == 2 || dec == 4)
			{
				aux = dec;
			}
		}
		if (Lista3->head == nullptr && (dec == 3))
		{
			cout << "Lista 3 vacia." << endl;
		}
		else
		{
			if (dec == 3 || dec == 4)
			{
				aux = dec;
			}
		}
	}
	return aux;
}

void Lista::ValidacionSuma(Lista* Lista1, Lista* Lista2, Lista* Lista3)
{
	if(Lista1->head == nullptr || Lista2->head == nullptr || Lista3->head == nullptr)
	{
		if (Lista1->head == nullptr)
		{
			cout << "Lista 1 vacia." << endl;
		}
		if (Lista2->head == nullptr)
		{
			cout << "Lista 2 vacia." << endl;
		}
		if (Lista3->head == nullptr)
		{
		
		}
	}
}