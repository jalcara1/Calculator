/*
 *condicion02.cpp
 *
 *Compilar: g++ -o condicion02 condicion02.cpp
 *Ejecutar: ./condicion02
 *
 */

#include <iostream>
using namespace std;

int main(){

  int a, b;

  cout << "Ingrese dos numeros separados por espacio: " << endl;

  cout << (((cin>>a)&&(a!=0)&&((cin>>b)&&(b!=0))) ? "Son diferentes de cero" : "Uno de los dos es cero") << endl;

  return 0;
}
 
