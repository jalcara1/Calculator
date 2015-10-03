/*
 *expr03.cpp
 *Ordenamiento de forma descendente
 *
 *Compilar: g++ -o expr03expr03.cpp
 *Ejecutar: ./expr03
 *
 */

#include <iostream>
using namespace std;

int main(){

  int a, b, c;

  cout << "Ingrese tres numeros separado por spacio" << endl;
  cin >> a >> b >> c;

  int medio = max(min(a,b), min(c,b));

  cout << max(max(a, b), c)<<" "<< medio <<" "<<min(min(a, b), c) << endl;
  
}
  
