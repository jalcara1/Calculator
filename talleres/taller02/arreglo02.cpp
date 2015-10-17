/*
 * fichero: arreglo02.cpp
 *
 * compilar: $ g++ -o arreglo02 arreglo02.cpp
 * ejecutar: $ ./arreglo02
*/

#include "arreglo02.h"
#include <iostream>

using namespace std;

void imprimirArreglo(char nombre[], int arreglo[], const int n){
  
  cout << nombre << endl;
  for(int i =0; i<n; i++){
    cout << nombre << "["<< i << "]" <<  "= "<< arreglo[i] << endl;
  }
 
}

void concatenarArreglos(int dest[], int fuente[], const int n){

  for(int i =0; i< n; i++){
    dest[n+i] = fuente[i];
  }
  
}

