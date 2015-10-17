/*
 *condicion01.cpp
 *
 *Compilar: g++ -o condicion01 condicion01.cpp
 *Ejecutar: ./condicion01
 *
*/

#include <iostream>
using namespace std;

int main(){
  
  int c =0;
  cout << "Ingrese un numero: " << endl;

  cout << (((cin>>c)&&(c==0))?"Es cero":"No es cero")<<endl;
    return 0;

}
