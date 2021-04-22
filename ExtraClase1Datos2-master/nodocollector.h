//
// Created by ignacio on 8/3/21.
//

#ifndef EXTRACLASE1DATOS2_NODOCOLLECTOR_H
#define EXTRACLASE1DATOS2_NODOCOLLECTOR_H

#include <cstdlib>

class NodoCollector {
public:
    // Atributos
    Nodo * dato;
    NodoCollector * siguiente;


    // Constructores
    NodoCollector(){
        dato = 0;
        siguiente = NULL;
    }

    NodoCollector(Nodo * _dato){
        dato = _dato;
        siguiente = NULL;
    }
    NodoCollector(Nodo * _dato, NodoCollector * _siguiente){
        dato = _dato;
        siguiente = _siguiente;
    }
};

#endif //EXTRACLASE1DATOS2_NODOCOLLECTOR_H
