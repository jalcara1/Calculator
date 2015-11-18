#include "calculator.h"
#include "parser.h"
#include "ast.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

Calculator::Calculator():memory(0){
}

int Calculator::eval(string expr){

  Parser* parser = new Parser(new istringstream(expr));

  AST* tree = parser->parse();

  int result = tree->evaluate();

  delete tree;
  delete parser;
  
  return result;
}

void Calculator::store(int val){
  memory =val;
}

int Calculator::recall(){
  return memory;
}

int Calculator::Clean(){
  memory =0;
  return 0;
}

int Calculator::plus(int val){
  memory +=val;
  return memory;
}


int Calculator::minus(int val){
  memory -=val;
  return memory;
}

void Calculator::crearVar(string nombre, int valor){

  string vallor =  static_cast<ostringstream*>(&(ostringstream() << valor))->str();

  salida(nombre, vallor);
  
  if(variables.count(nombre) ==1){
     variables[nombre] =valor;
  }else{
     variables.insert(pair<string,int>(nombre,valor));
  }  
}

int Calculator::getVariables(string nombre){

  if(variables.count(nombre) ==1){
    return variables[nombre];
  }else{
    return 0;
  }  
}

string Calculator::salida(string nombre, string valor){

  if(salidaF == ""){
    salidaF = salidaF + nombre + " <- " + valor;
  }else{
    salidaF += ", " + nombre + " <- " + valor;    
  }
  return salidaF;

}

string Calculator::getSalida(){
  return salidaF;
}

void Calculator::limpiarSalida(){
  salidaF = "";
}

			      
