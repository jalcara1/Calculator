/*
 * fichero: entrada02.cpp
 * compilar: $ g++ -o entrada02 entrada02.cpp
 *
 * ejecutar: $ ./entrada02
 *
 * proposito: Mostrar como se leen datos de la entrada estandar
 *            sin formato.
 */
#include <iostream>
using namespace std;

int main(){
  
  const streamsize TOTALDATOS = 80;
  char* elementos = new char[TOTALDATOS];

  cout << "Entre un conjunto de caracteres: ";
  cin.read(elementos, TOTALDATOS);

  if (!cin) {
    if(cin.eof()){
      cerr << "Fin de entrada inesperada" << endl;
    }else if(cin.bad()){
      cerr << "Problemas en el flujo de entrada" << endl;
    }else{
      cerr << "problema de flujo recuperable" << endl;
    }
  }
  else {
    cout << elementos << endl;
  }

  return 0;
}
