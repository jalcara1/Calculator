/*
 *eco.cpp
 *
 *Compilar: g++ -c eco.cpp
 *
*/

using namespace std;
#include <iostream>
#include "eco.h"

int*
creacionDeEco(const int arreglo[], const int longitud, const int retraso, float factor){

  int *arr = new int[longitud];
  int pos =0;
  
  for(int k =0; k< longitud; k++){
    
    if(k >= retraso){
      
      arr[k] = arreglo[k]+(arreglo[pos]*factor);
      pos++;
    }else{
      
      arr[k] = arreglo[k];
    }
  }
  
  return arr;
  
}

void
imprimirEco(const int eco[], const int longitud){
  
  cout << eco[0];
  for(int i =1; i< longitud; i++){
    cout << ", " << eco[i];
  }
  cout << "" << endl;
}



