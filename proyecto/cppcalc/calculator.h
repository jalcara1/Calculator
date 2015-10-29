#pragma once
#include <string>
#include <iostream>
using namespace std;

class Calculator{
 public:
   Calculator();

   int eval(string expr);
   void store(int val);
   int recall();

 private:
   int memory;
};
extern Calculator* calc;


