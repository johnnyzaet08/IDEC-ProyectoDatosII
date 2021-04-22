#include <string.h>
#include <iostream>

using namespace std;

int main(){
    string tipo = "int";
    string nombre = "hola";
    string valor = "123";

    string text = "{\"tipo\":\"" + string(tipo) + "\", \"nombre\":\"" + string(nombre) + "\", \"valor\":\"" + string(valor) + "\"}";
    
    cout << text << endl;


    return 0;
}