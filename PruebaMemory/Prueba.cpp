#include <iostream>
#include <stdlib.h>
#include <malloc.h>

using namespace std;

int main(){
    int tamano = 2;
    int *memoryT;
    
    memoryT = (int *) malloc(tamano);
    cout << memoryT << endl;

    memoryT[1] = 12;
    memoryT[2] = 17;

    cout << &memoryT[1] << endl;
    cout << memoryT[2] << endl;
    
    return 0;
}