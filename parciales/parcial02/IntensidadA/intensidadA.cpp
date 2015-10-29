using namespace std;
#include <iostream>
#include "iluminanciaA.h"

int main(){
  

  float pRojo, pVerde;
  int rojo, verde, azul;

  cout << "Ingrese los valores" << endl;
  cin >> pRojo >> pVerde >> rojo >> verde >> azul;

  float pAzul = 1 -(pRojo + pVerde);
  int pColor = (pRojo*rojo) + (pVerde*verde) + (pAzul*azul);

  revisarIluminancia(pRojo, pVerde, rojo, verde, azul);

  cout << pColor << "  " << pAzul << endl;
  
    return 0;
}
