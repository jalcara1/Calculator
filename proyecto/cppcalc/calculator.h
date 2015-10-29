#pragma once // evita que se incluya dos veces un fichero

#include <string>

using namespace std;


class Calculator {
 public:
  Calculator();

  int eval(string flujo);
  void store(int val);
  int recall();
  
 private:
  int memory;

};

extern Calculator* calc;
