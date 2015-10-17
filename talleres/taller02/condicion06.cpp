/*
 * fichero: condicion06.cpp
 *
 * compilar: $ g++ -o condicion06 condicion06.cpp
 * ejecutar: $ ./condicion03
 *
 */

#include <iostream>
using namespace std;

int main() {

  int n;
  char c;
  
  cout << "Ingrese las cordenadas (Letra-Numero)" << endl;
  cin >> c >> n;

  int cn = c;

  if((cn%2 ==0 && n%2 ==0) || (cn%2 !=0 && n%2 !=0)){
    cout << "blanco" << endl;
  }else{
    cout << "negro" << endl;
  }

  return 0;
  
}
