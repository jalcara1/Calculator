/*
 *procesarecos.cpp
 *
 *Compilar: g++ -c procesarecos procesarecos.cpp
 *Ejecutar: ./procesarecos
 *
*/

using namespace std;
#include <iostream>
#include "eco.h"

int main(){

  int longitud, retraso, num, procesos =0;
  float factor =0;
  
  cout << "Cuantos procesos ingresara: " << endl;
  cin >> procesos;  

  for(int i =0; i< procesos; i++){
    
    cout << "Ingrese: longitud, retraso, factor" << endl;
    cin >> longitud >> retraso >> factor;
    int arr[longitud];

    cout << "ingrese los numeros" << endl;    
    for(int j=0; j< longitud; j++){
      cin >> num;
      arr[j] = num;      
    }

    imprimirEco(arr, longitud);

    imprimirEco(creacionDeEco(arr, longitud, retraso, factor), longitud);
    
  }

  return 0;
}
