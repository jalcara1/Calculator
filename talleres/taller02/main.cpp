/*
 *main.cpp
 *
 *Compilar: g++ -c main main.cpp
 *
 */

using namespace std;
#include <iostream>
#include "funciones.cpp"

int main(void){

  int a, b, c;

  cout << "Ingrese tres numeros separados por spacio" << endl;
  cin >> a;
  cin >> b;
  cin >> c;

  int result = sumaEnt(sumaEnt(a,b),multEnt(c,multEnt(sumaEnt(multEnt(a,b),c),restEnt(a,b))));

  cout << result << endl;

  return 0;
}

