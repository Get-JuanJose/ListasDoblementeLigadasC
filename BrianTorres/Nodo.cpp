#include "Nodo.h"

Nodo::Nodo()
{
    dato = 0;
    ld = nullptr;
    li = nullptr;
}

int Nodo::GetDato()
{
    return dato;
}

void Nodo::SetDato(int d)
{
    dato = d;
}

Nodo* Nodo::Getld()
{
    return ld;
}

Nodo* Nodo::Getli()
{
    return li;
}

void Nodo::Setld(Nodo* l)
{
    ld = l;
}

void Nodo::Setli(Nodo* l)
{
    li = l;
}
