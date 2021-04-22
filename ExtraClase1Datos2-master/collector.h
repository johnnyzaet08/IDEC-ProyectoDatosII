//
// Created by ignacio on 8/3/21.
//

#ifndef EXTRACLASE1DATOS2_COLLECTOR_H
#define EXTRACLASE1DATOS2_COLLECTOR_H

#include "nodo.h"
#include "nodocollector.h"

class Collector {

private:
    // Atributos

public:

    NodoCollector * inicio;

    // Constructores
    Collector(){
        inicio = NULL;
    }
    // Metodos
    NodoCollector * getNode();
    void insertarAlFinal(Nodo * _dato);
    void eliminar();
    bool estaVacia();
    void imprimir();
};

NodoCollector * Collector::getNode(){
    return inicio;
}

void Collector::insertarAlFinal(Nodo * _dato){
    if (inicio == NULL){
        inicio = new NodoCollector(_dato);
    }
    else {
        NodoCollector * tmp = inicio;
        while (tmp->siguiente != NULL) {
            tmp = tmp->siguiente;
        }
        tmp->siguiente = new NodoCollector(_dato);
    }
}

void Collector::eliminar(){
    if (!estaVacia()){
        NodoCollector * tmp = inicio;
        inicio = tmp->siguiente;
        tmp->siguiente = NULL;
        delete tmp;
    } else{
        std::cout << "No hay elementos" << std::endl;
    }
}


bool Collector::estaVacia(){
    return inicio == NULL;
}

void Collector::imprimir(){
    if (!estaVacia()){
        NodoCollector * tmp = inicio;
        while (tmp != NULL){
            std::cout << &(tmp->dato) << " ";
            tmp = tmp->siguiente;
        }
        std::cout << std::endl;
    }
    else
        std::cout << "No hay elementos" << std::endl;
}

#endif //EXTRACLASE1DATOS2_COLLECTOR_H