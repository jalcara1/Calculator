#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

const int MAXBUF = 256;

using namespace std;

int main(){
  
  char buffer[MAXBUF];
  ifstream filein("shortlonglines01.in");//Fichero de entrada

  while (filein.getline(buffer,MAXBUF)) {

    string buffer2(buffer);
    istringstream ins(buffer2);

    string nombre;

    ins >> nombre;

    cout << nombre << endl;
  }
    
  /*
   * Inserte el codigo en C++ que procese lineas largas y las
   * convierta en una sola linea.
   */
  return 0;
}
