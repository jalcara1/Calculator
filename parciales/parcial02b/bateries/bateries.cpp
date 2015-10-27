using namespace std;
#include <iostream>
#include "bateries.h"

Batery::Batery(){}
Batery::~Batery(){}

B2Batery::B2Batery(float charge[2]):charge(),prop(){
  
  this -> charge[0] = charge[0];
  this -> charge[1] = charge[1];
  this -> prop[0] = charge[0]/getTotalCharge();
  this -> prop[1] = charge[1]/getTotalCharge();
}

B2Batery::~B2Batery(){}

float B2Batery::getTotalCharge(){
  float Total = charge[0] + charge [1];
  return Total;
}

float B2Batery::getCharge(int pos){
  return charge[pos];
}

float B2Batery::setDischarge(float amount){
  if(getTotalCharge() >0){
    charge[0] -= amount * prop[0];
    charge[1] -= amount * prop[1];
  }
  
  return getTotalCharge();
}

float getTotalBateries(Batery **bateries, int nBateries){
  
  float Result =0;
  for(int i =0 ; i< nBateries ; i++){
    Result += bateries[i] -> getTotalCharge();
  }
  
  return Result;
}
