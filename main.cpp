#include <iostream>
#include <cstdlib>
#include <malloc.h>
#include "Server.h"


int main(int argc, char *argv[]){

    int tamano = atoi(argv[2]);
    int puerto = atoi(argv[1]);
    
    int *totalMemory;

    if((totalMemory = (int *)malloc(tamano))==NULL){
        std::cout << "No se pudo crear el espacio de memoria solicitado" << std::endl;
    } else{
        std::cout << "Espacio de memoria creado con: " << tamano << " bytes" << std::endl;
    }
    std::cout << totalMemory << std::endl;

    std::cout << "Puerto del servidor:  " << puerto << std::endl;
    
    Server *Servidor = new Server(puerto);
   
    std::string tipo = "int";
    std::string nombre = "hola";
    std::string valor = "123";
    std::string memoria = "00xA";

    std::string text = "{\"tipo\":\"" + tipo + "\", \"nombre\":\"" + nombre + "\", \"valor\":\"" + valor + "\", \"memoria\":\"" + memoria +"\"}";

    //while(true){
        Servidor->Recibir();
        Servidor->Enviar(text);
    //}

    return 0;
}