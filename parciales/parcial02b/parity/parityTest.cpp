#include "parityTest.h"

Parity parityTest(const char word[], int& nEven, int &nOdd) {

  int posicion =0;
  nEven = 0;
  nOdd = 0;

  while(word[posicion] != '\0'){

    if( isEvenParity(word[posicion]) ){
      nEven++;

    }else if( isOddParity(word[posicion]) ){
      nOdd++;
    }
    posicion++;
  }

  if(nEven > nOdd){
    return even;

  }else if(nEven < nOdd){
    return odd;

  }else{
    return none;

  }  
}
