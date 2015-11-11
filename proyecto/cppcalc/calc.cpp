#include <iostream>
#include <sstream>
#include <string>
#include "calcex.h"
#include "calculator.h"
using namespace std;

Calculator* calc;

int main(int argc, char* argv[]){
  
  string line;
  calc = new Calculator();

  while(cout << ">"){
  
    try{
      //cout << "Please enter a calculator expression: ";
    
      getline(cin, line);
      // line + '\n';

      //calc = new Calculator();

      if(cin.eof()){
	break;
      }

      int result = calc->eval(line);

      //cout << "The result is " << result << endl;
      cout << result << endl;

      //delete calc;
    
    }catch(Exception ex){
      cout << "* parse error" << endl;
    }
  }
  delete calc;
  
}

