/*
 * fichero: string01.cpp
 *
 * compilar: $ g++ -o string01 string01.cpp
 * ejecutar: $ ./string01
 */
#include <string>
#include <iostream>

using namespace std;

int main() {

  string s("Hello World");
  cout << s << endl;
  cout << "size: " << s.size() << endl;
  cout << "max_size: " << s.max_size() << endl;
  //  cout << "reserve: " << s.reserve() << endl;
  cout << "capacity: " << s.capacity() << endl;

  return 0;
}
