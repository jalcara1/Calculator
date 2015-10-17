/*
 * fichero: ciclo06.cpp
 *
 * compilar: $ g++ -o ciclo06 ciclo06.cpp
 * ejecutar: $ ./ciclo06
 *
 */

#include <iostream>
using namespace std;

int main() {

  int a, b, cont;

  int cant;
  cout << "Cuantos pares de caracteres desea ingreser" << endl;
  cin >> cant;

  cout << "Ingrese los pares de carateres separados por espacio" << endl;
  for(int i =1; i<=cant; i++){
    cin >> a >> b;
    for(int j =a; j<=b; j++){
      cont += j;
    }
    cout << cont << endl;
    cont =0;
  }

  return 0;
}
