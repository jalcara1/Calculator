#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

const int MAXBUF = 256;

using namespace std;
int
main(int argc, char *argv[]) {

  int estudiantes =0;
  int Average =0;
  ifstream filein;

  char buffer[MAXBUF];
  if(argv[0] == "grademidtermexam01.in"){
  ifstream filein("grademidtermexam01.in");//Fichero de entrada
  }else if(argv[0] == "grademidtermexam02.in"){
    ifstream filein("grademidtermexam02.in");//Fichero de entrada    
  }else{
    ifstream filein(argv[0]);//Fichero de entrada    
  }
  //   grademidtermexam01.in

  while (filein.getline(buffer,MAXBUF)) {

    string buffer2(buffer);
    istringstream ins(buffer2);

    char nombre[MAXBUF];    
    double num1;
    double num2;
    double result;

    ins >> nombre >> num1 >> num2;
    
    cout << nombre << ": "
	 << result
	 << endl;
    
    estudiantes++;
    Average  = Average + result;
  }
  
    cout << "Total students: " << estudiantes << endl;
    cout << "Average grade: " << Average/estudiantes << endl;
  
  
  // Inserte el código que procese los
  // ficheros de entrada y procese las notas
  // de cada grupo de estudiantes
  return 0;
}
