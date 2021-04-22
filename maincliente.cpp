#include "Client.h"
#include <string.h>

int main(){
    Client *Cliente = new Client();
    std::string tipo = "int";
    std::string nombre = "hola";
    std::string valor = "123";

    std::string text = "{\"tipo\":\"" + tipo + "\", \"nombre\":\"" + nombre + "\", \"valor\":\"" + valor + "\"}";

        
    Cliente->Enviar(text);
    Cliente->Recibir();

    return 0;
}
