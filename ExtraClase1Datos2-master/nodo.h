//
// Created by ignacio on 8/3/21.
//
#include <cstdlib>

#ifndef EXTRACLASE1DATOS2_NODO_H
#define EXTRACLASE1DATOS2_NODO_H

class Nodo {
public:
    // Atributos
    int dato;
    Nodo * siguiente;


    // Constructores
    Nodo(){
        dato = 0;
        siguiente = NULL;
    }

    Nodo(int _dato){
        dato = _dato;
        siguiente = NULL;
    }

    Nodo(int _dato, Nodo * _siguiente){
        dato = _dato;
        siguiente = _siguiente;
    }

    void * operator new(size_t size){
        std::cout << "Overloading new con tamano: " << size << std::endl;
        void * p = ::new Nodo();
        return p;
    }

    void operator delete(void * p){
        free(p);
    }

    void modif(int _dato){
        dato = _dato;
    }

    int consulta(){
        std::cout << "El dato que contiene este nodo es: " << dato;
        return dato;
    }
};

#endif //EXTRACLASE1DATOS2_NODO_H
