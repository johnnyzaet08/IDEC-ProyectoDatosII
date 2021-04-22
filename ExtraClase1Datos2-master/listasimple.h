//
// Created by ignacio on 8/3/21.
//

#ifndef EXTRACLASE1DATOS2_LISTASIMPLE_H
#define EXTRACLASE1DATOS2_LISTASIMPLE_H




#include "collector.h"

class ListaSimple {

private:

public:
    Nodo * inicio;
    Collector * collector = new Collector();

    // Constructores
    ListaSimple(){
        inicio = NULL;
    }

    // Metodos
    void insertarAlInicio(int _dato);
    bool estaVacia();
    void imprimir();
    int getInicio();
    void eliminar(int _dato);
    void eliminarDir(Nodo * _dato);
};

int ListaSimple::getInicio(){
    std::cout << "Dato en primer nodo es: " << inicio->dato;
    return inicio->dato;
}

void ListaSimple::insertarAlInicio(int _dato){
    if (inicio == NULL) {
        inicio = new Nodo(_dato);
    }else {
        if (collector->estaVacia()){
            Nodo * nuevo = new Nodo(_dato);
            nuevo->siguiente = inicio;
            inicio = nuevo;
        } else{
            collector->getNode()->dato->dato = _dato;
            collector->getNode()->dato->siguiente = inicio;
            inicio = collector->getNode()->dato;
            collector->eliminar();
        }
    }
}


void ListaSimple::eliminar(int _dato){
    if (!estaVacia()){
        if (_dato == inicio->dato) {
            Nodo * eliminado = inicio;
            inicio = inicio->siguiente;
            eliminado->siguiente = NULL;
            collector->insertarAlFinal(eliminado);
            delete eliminado;
        }
        else {
            Nodo * nodo_anterior = inicio;
            Nodo * tmp;
            tmp = inicio;
            while (tmp != NULL){
                if (tmp->dato == _dato){
                    collector->insertarAlFinal(tmp);
                    nodo_anterior->siguiente = tmp->siguiente;
                    tmp->siguiente = NULL;
                    delete tmp;
                }
                nodo_anterior = tmp;
                tmp = tmp->siguiente;
            }
        }
    }
}

void ListaSimple::eliminarDir(Nodo * _dato){
    if (!estaVacia()){
        if (_dato == inicio) {
            Nodo * eliminado = inicio;
            inicio = inicio->siguiente;
            eliminado->siguiente = NULL;
            collector->insertarAlFinal(eliminado);
            delete eliminado;
        }
        else {
            Nodo * nodo_anterior = inicio;
            Nodo * tmp;
            tmp = inicio;
            while (tmp != NULL){
                if (tmp == _dato){
                    collector->insertarAlFinal(tmp);
                    nodo_anterior->siguiente = tmp->siguiente;
                    tmp->siguiente = NULL;
                    delete tmp;
                }
                nodo_anterior = tmp;
                tmp = tmp->siguiente;
            }
        }
    }
}

bool ListaSimple::estaVacia(){
    return inicio == NULL;
}

void ListaSimple::imprimir(){
    if (!estaVacia()){
        Nodo * tmp = inicio;
        while (tmp != NULL){
            std::cout << tmp->dato << " ";
            tmp = tmp->siguiente;
        }
        std::cout << std::endl;
    }
    else
        std::cout << "No hay elementos" << std::endl;
}

#endif //EXTRACLASE1DATOS2_LISTASIMPLE_H