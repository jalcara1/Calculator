/*
 *main.cpp
 *
 *Compilar: g++ -c main main.cpp
 *
 */

#include <iostream>
#include "funciones.h"
using namespace std;
int main(void){
  int a, b, c;
  cout << "Ingrese tres numeros separados por spacio" << endl;
  cin >> a;
  cin >> b;
  cin >> c;
  int result = sumaEnt(sumaEnt(a,b),multEnt(c,multEnt(sumaEnt(multEnt(a,b),c),restaEnt(a,b))));
  cout << result << endl;
  return 0;
}

