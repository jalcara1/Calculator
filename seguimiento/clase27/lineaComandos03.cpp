/*
 * fichero: lineaComandos03.cpp
 * compile: $ g++ -o lineaComandos03 lineaComandos03.cpp
 * ejecutar: $ ./lineaComandos03
 */
#include <iostream>

using namespace std;

int
main(int argc, char *argv[], char *env[]) {

  for (int i = 0; env[i] != NULL; i++) {
    cout << "Variable[" << i << "]=" << env[i] << endl;
  }

  return 0;
}
// filename: lineaComandos03.cpp
