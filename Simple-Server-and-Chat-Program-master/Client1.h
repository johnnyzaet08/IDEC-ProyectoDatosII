//
// Created by Johnny on 8/3/21.
//

#ifndef PROYECYO1_DATOS2_CLIENT_H
#define PROYECYO1_DATOS2_CLIENT_H

#include <iostream>
#include <string.h>
#include <cstdlib>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

class Client{
    public:
        int bufsize = 1024;
        char buffer[1024];
        int client;
        int portNum = 1500;
        const char* ip = "127.0.0.1";
    
    //Constructor
    Client(){
        struct sockaddr_in server_addr;
        client = socket(AF_INET, SOCK_STREAM, 0);

        if (client < 0){
            std::cout << "\nError al establecer el socket" << std::endl;
            exit(1);
        }

        std::cout << "\n=> Socket del cliente creado" << std::endl;
        
        server_addr.sin_addr.s_addr = inet_addr(ip);
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(portNum);

        if (connect(client,(struct sockaddr *)&server_addr, sizeof(server_addr)) == 0)
            std::cout << "=> Conectando al servidor en el puerto: " << portNum << std::endl;
        
        std::cout << "=> Esperando confirmacion" << std::endl;
        recv(client, buffer, bufsize, 0);
        std::cout << "=> conexion confirmada  ";  
        std::cout << buffer << std::endl;
    }

    //Metodos
    void Recibir();
    void Enviar(std::string);

};

void Client::Recibir(){
    //int bufsize = 1024;
    //char buffer[1024];
    recv(client, buffer, bufsize, 0);
    std::cout << "El servidor dice: " << buffer << std::endl;
}

void Client::Enviar(std::string text){
    //int bufsizeS = 1024;
    //char bufferS[1024];
    std::cout << "Escriba el mensaje: ";
    std::cin >> buffer;
    send(client, buffer, bufsize, 0);
}

#endif PROYECYO1_DATOS2_CLIENT_H