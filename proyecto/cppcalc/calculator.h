#pragma once // evita que se incluya dos veces un fichero
#include <string>
#include <map>
using namespace std;

class Calculator{
 public:
  Calculator();

  int eval(string flujo);

  /*
   *Para borrar solo mirar como funciona
   
   *Parser* parser = new Parser(new istringstream(expr));

   *AST* tree = parser->parse();

   *int result = tree->evaluate();
  */
  
  void store(int val);
  int recall();
  int Clean();
  int plus(int val);
  int minus(int val);
  void crearVar(string nombre, int valor); //Crear variable
  int getVariables();
  
 private:
  int memory;
  map<string,int>variables;

};

extern Calculator* calc;
