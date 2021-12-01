#pragma once
class Nodo
{
private:
	int dato;
	Nodo* ld, *li;
public:
	Nodo();
	int GetDato();
	void SetDato(int);
	Nodo* Getld();
	Nodo* Getli();
	void  Setld(Nodo*);	
	void Setli(Nodo*);
};

