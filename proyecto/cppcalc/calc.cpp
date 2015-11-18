#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include "calcex.h"
#include "calculator.h"
using namespace std;

Calculator* calc;
const int MAXBUF = 256;

int main(int argc, char* argv[]){

  int cont =1;
  
  string line;
  int result;
  calc = new Calculator();

  if(argc > 1){  
    while(cont < argc){
    
      char buffer[MAXBUF];
      ifstream filein(argv[cont]);//Fichero de entrada

      while (filein.getline(buffer,MAXBUF)) {
	try{
	  string buffer2(buffer);
	  istringstream ins(buffer2);

	  string valorLinea;
	  ins >> valorLinea;

	  result = calc->eval(valorLinea);

	  if(ins){
	    cout << "=> " << result << endl;
	  }
	}catch(Exception e){
	  cout << "* parse error" << endl;
	}      
      }
      cont++;
    }
  }else{
    while(cout << ">"){  
      try{    
	getline(cin, line);
	
	if(cin.eof()){
	  break;
	}

	result = calc->eval(line);

	cout << "=> " << result << endl;
      }catch(Exception e){
	cout << "* parse error" << endl;
      }
    }
  }
  delete calc;  
}
