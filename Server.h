//
// Created by Johnny on 8/3/21.
//

#ifndef PROYECYO1_DATOS2_SERVER_H
#define PROYECYO1_DATOS2_SERVER_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <jsoncpp/json/value.h>
#include <jsoncpp/json/json.h>

class Server{
    public:
        int bufsize = 1024;
        char buffer[1024];
        int client, server;
        Json::Reader reader;
        Json::Value dataS, dataR;
        Json::StyledWriter writer;

    //Constructor
    Server(int port){
        struct sockaddr_in server_addr;
        socklen_t size;

        client = socket(AF_INET, SOCK_STREAM, 0);
        if (client < 0) {
            std::cout << "\nError estableciendo el socket" << std::endl;
            exit(1);
        }
        std::cout << "\n=> Socket server creado..." << std::endl;

        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
        server_addr.sin_port = htons(port);


        if ((bind(client, (struct sockaddr*)&server_addr,sizeof(server_addr))) < 0) 
        {
            std::cout << "=> Error estableciendo conexion" << std::endl;
            exit(1);
        }

        size = sizeof(server_addr);
        std::cout << "=> Buscando clientes" << std::endl;

        listen(client, 1);

        int clientCount = 1;
        server = accept(client,(struct sockaddr *)&server_addr,&size);

        if (server < 0) 
            std::cout << "=> Error aceptando el cliente" << std::endl;

        std::cout << "=> Conectado con el cliente #" << clientCount << std::endl;
        strcpy(buffer, "=> Server connected...\n");
        send(server, buffer, bufsize, 0);

    }

    //Metodos
    void Recibir();
    void Enviar(std::string);

};

void Server::Recibir(){
    int bufsizeR = 1024;
    char bufferR[1024];
    recv(server, bufferR, bufsizeR, 0);
    std::string text = bufferR;
    std::cout << text << std::endl;
}

void Server::Enviar(std::string text){
    int bufsizeS = 1024;
    char bufferS[1024];
    reader.parse(text, dataS);
    std::string data = writer.write(dataS);
    std::copy(data.begin(), data.end(), bufferS);
    send(server, bufferS, bufsizeS, 0);
}

#endif PROYECYO1_DATOS2_SERVER_H