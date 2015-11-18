#pragma once // evita que se incluya dos veces un fichero
#include <string>
#include <map>
using namespace std;

class Calculator{
 public:
  Calculator();

  int eval(string flujo);  
  void store(int val);
  int recall();
  int Clean();
  int plus(int val);
  int minus(int val);
  void crearVar(string nombre, int valor); //Crear variable
  int getVariables(string nombre);
  
 private:
  int memory;
  map<string,int>variables;

};

extern Calculator* calc;
