/*
 *funciones2.cpp
 *
 *Compilar: g++ -o funciones2 funciones2.cpp
 *Ejecutar: ./funciones2
 *
*/

#include <iostream>
#include "funciones2.h"
using namespace std;


int mcd(int a, int b){
  
  int c;
  while (a != b){
    if (a > b){
	a = a - b;
    }else{
      b = b - a;
    }
  }

  c=a;
  cout << c << endl;
  
  return c;
  
}

void simpFrac(int a, int b){

  int c = mcd(a,b);

  a = a / c;
  b = b / c;

  cout << a << " " << b << endl;
}
		 

