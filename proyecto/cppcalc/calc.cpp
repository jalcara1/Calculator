#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include "calcex.h"
#include "calculator.h"
using namespace std;

Calculator* calc;

int main(int argc, char* argv[]){

  int cont =1;
  int MAXBUF = 256;
  
  string line;
  int result;
  calc = new Calculator();

  if(argc > 1){  
    while(cont < argc){
    
      char buffer[MAXBUF];
      ifstream filein(argv[cont]);//Fichero de entrada

      while (filein.getline(buffer,MAXBUF)) {
	try{
	  
	  istringstream ins(buffer);

	  string valorLinea;
	  ins >> valorLinea;

	  result = calc->eval(valorLinea);

	  if(ins){
	    
	    if(calc->getSalida() != ""){
	      cout << "=> "<< result;
	      cout << " [" << calc->getSalida() << "]" << endl;
	      calc->limpiarSalida();
	    }else{
	      cout << "=> " << result << endl;
	    }
	    
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
	
	if(calc->getSalida() != ""){
	  cout << "=> "<< result;
	  cout << " [" << calc->getSalida() << "]" << endl;
	  calc->limpiarSalida();
	}else{
	  cout << "=> " << result << endl;	  
	}
	  
	
      }catch(Exception e){
	cout << "* parse error" << endl;
      }
    }
  }
  delete calc;
  return 0;
}
