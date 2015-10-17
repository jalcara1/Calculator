/*
 * fichero: condicion03.cpp
 *
 * compilar: $ g++ -o condicion03 condicion03.cpp
 * ejecutar: $ ./condicion03
 *
 */
#include <iostream>

using namespace std;

int main() {

  int a, b, c =0;
  
  cout << "Ingrese los lados del triangulo" << endl;
  cin >> a >> b >> c;

  if(a ==b && b ==c){

    cout << "El triangulo es equilatero" << endl;
    
  }else if(a !=b && a !=c && b !=c){

    cout << "El triangulo es escaleno" << endl;

  }else{

    cout << "El triangulo es isoceles" << endl;

  }

  return 0;  
}
