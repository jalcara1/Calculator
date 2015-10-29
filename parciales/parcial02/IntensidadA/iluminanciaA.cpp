/*
 *iluminancia.cpp
 *
 *Compilar: g++ -c iluminancia.cpp
 *
*/

using namespace std;
#include <iostream>
#include "iluminanciaA.h"

void
revisarIluminancia(float pRojo, float pVerde, int rojo, int verde, int azul){

  float pAzul = 1 -(pRojo + pVerde);
  int pColor = (pRojo*rojo) + (pVerde*verde) + (pAzul*azul);

  while(true){

    if((pRojo + pVerde) > 1){

      cout << "Error de datos" << endl;
      break;
    }

    if(pColor < 10){
      
      cout << "Oscuro" << endl;
      break;
	
    }else if(pColor >= 50 && pColor <= 200){

      cout << "Bien" << endl;
      break;
      
    }else if(pColor >= 250){

      cout << "Transparente" << endl;
      break;
      
    }
  }
  
}
