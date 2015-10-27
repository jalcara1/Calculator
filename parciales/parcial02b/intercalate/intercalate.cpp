using namespace std;
#include <iostream>
#include "intercalate.h"

int* intercalate(const int arr1[], const int arr2[], const int nbr, const int fact){

  int *resultFin = new int[nbr];
  int posicion =0;
  int posicion1 =0;
  int posicion2 =0;

  if(nbr == fact){
    posicion2 = 0;
  }else{
    posicion2 = fact;
  }

  while(posicion < nbr){

    for(int i = 0; i < fact; i++){

      if(posicion2 >=nbr){
	posicion2 =0;
      }
      
      resultFin[posicion] = arr2[posicion2];
      posicion++;
      posicion2++;
    }

    if(posicion >= nbr){
      break;
    }

    for(int j = 0; j < fact; j++){

      if(posicion1 >= nbr){
	posicion1 =0;
      }
      
      resultFin[posicion] = arr1[posicion1];
      posicion++;
      posicion1++;
    }

    posicion1 +=fact;
    posicion2 +=fact;
  }

  return resultFin;
  
 
}
