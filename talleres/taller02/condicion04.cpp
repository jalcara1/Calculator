/*
 *condicion04.cpp
 *
 *Compilar: g++ -o condicion04 condicion04.cpp
 *Ejecutar: ./condicion04
 *
*/

using namespace std;
#include <iostream>

int main(){

  float a,b,c;

  cout << "Ingrese tres numeros separados por spacio" << endl;

  cin >> a >> b >> c;
  float medio =  max(min(min(a,b), min(a,c)), max(min(a,b), min(b,c)));

  cout << min(min(a,b),c) << " " <<  medio  << " " << max(max(a,b),c) << endl;

  return 0;
  
}
