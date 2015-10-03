/*
 *expr02.cpp
 *Ordenamiento de forma ascendente
 *
 *Compilar: g++ -o expr02 expr02.cpp
 *Ejecutar: ./expr02
 *
*/

#include <iostream>
using namespace std;

int main(){
  
  int a,b,c;
  
  cout << "Ingrese tres numeros separados por spacio" << endl;
  
  cin >> a >> b >> c;
  int medio =  max(min(min(a,b), min(a,c)), max(min(a,b), min(b,c)));

  cout << min(min(a,b),c) << " " <<  medio  << " " << max(max(a,b),c) << endl;

  return 0;


}
