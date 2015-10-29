using namespace std;
#include <iostream>
#include <string>

int main(){

  
  string s;
  int patrones, asciim, asciiM, contT, contB, contM =0;

  cout << "Cuantos patrones desea ingresar: " << endl;
  cin >> patrones;
  
  while(patrones >0){
    cout << "Ingrese el patron: " << endl;
    cin >> s;
    
    for(int i =0; i < s.size()-1; i+=2){

      asciim = s[i];
      if(asciim >= 97 && asciim <= 122){
      
	asciiM = s[i+1];      
	if(asciiM >= 65 && asciiM <=90){
	
	  contB++;
	}else{
	  contM++;
	}
      
      }else{
	contM++;
      }
    
      contT++;

    }
    
    cout << s << " Total: " << contT << " Buenas: " << contB << " Malas: " << contM << endl;
    contT =0;
    contB =0;
    contM =0;
    patrones--;
  }

  return 0;
  
}
