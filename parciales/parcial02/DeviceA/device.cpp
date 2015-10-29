using namespace std;
#include <iostream>
#include "device.h"

Device::Device():factorOne(10){
}
Device::Device(int factorOne):factorOne(factorOne){
}
int Device::getFactorOne(){
  return factorOne;
}
Device::~Device(){
}


DevByTen::DevByTen():Device(){
}
DevByTen::DevByTen(int factorOne):Device(factorOne){
}
int DevByTen::compute(){
  return getFactorOne() *10;
}
DevByTen::~DevByTen(){
}


DevByFive::DevByFive():Device(){
}
DevByFive::DevByFive(int factorOne):Device(factorOne){
}
int DevByFive::compute(){
  return getFactorOne() *5;
}
DevByFive::~DevByFive(){
}


Device2::Device2():factorTwo(20), Device(){  
}
Device2::Device2(int factorTwo, int factorOne):factorTwo(factorTwo), Device(factorOne){
}
int Device2::getFactorTwo(){
  return factorTwo;
}
Device2::~Device2(){
}


Dev2MinusFive::Dev2MinusFive():Device2(){
}
Dev2MinusFive::Dev2MinusFive(int factorTwo):Device2(factorTwo){  
}
int Dev2MinusFive::compute(){
  return getFactorOne() + (factorTwo() -5);
}
Dev2MinusFive::~Dev2MinusFive(){
}


Dev2AddTen::DevAddTen():Device2(){
}
Dev2AddTen::DevAddTen(int factorTwo):Device(factorTwo){
}
int Dev2AddTen::compute(){
  return getFactorOne() + (getFactorTwo() +10);
}
Dev2AddTen::~De2AddTen(){
}
					       
