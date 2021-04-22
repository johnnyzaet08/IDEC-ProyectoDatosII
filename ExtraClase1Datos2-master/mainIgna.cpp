#include <iostream>
#include "listasimple.h"


void pruebas(){
    ListaSimple * lista = new ListaSimple();
    lista->insertarAlInicio(3);
    lista->insertarAlInicio(2);
    lista->insertarAlInicio(1);
    std::cout << "Direccion nodo 1: ";
    std::cout << lista->inicio << "\n";

    std::cout << "Valor nodo 1: ";
    std::cout << lista->inicio->dato<< "\n";
    lista->eliminar(1);
    std::cout << "Lista:";
    lista->imprimir();

    std::cout << "Dirrecion nodo 1 collector: ";
    std::cout << lista->collector->inicio->dato<< "\n";

    lista->insertarAlInicio(8);
    std::cout << "Lista:";
    lista->imprimir();

    std::cout << "Direccion nodo 1: ";
    std::cout << lista->inicio << "\n";
    std::cout << "Valor nodo 1: ";
    std::cout << lista->inicio->dato<< "\n";

    std::cout << "Eliminando primer elemento...... \n";
    lista->eliminarDir(lista->inicio);
    std::cout << "Lista: ";
    lista->imprimir();

    std::cout << "Modificar primer elemento...... \n";
    lista->inicio->modif(80);
    lista->imprimir();

    std::cout << "Consultando dato de primer elemento...... \n";
    lista->inicio->consulta();
}

int main()
{
    pruebas();
}