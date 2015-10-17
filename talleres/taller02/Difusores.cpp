using namespace std;
#include <iostream>
#include "Difusores.h"

//De la clase difusor llamo el metodo difusor
//Le paso los atributos al constructor y los inicializo
Difusor::Difusor():anguloDifusion(0.0f){
  
}
//Le paso los atributos a los atributos de si mismo
Difusor::Difusor(float anguloDifusion):anguloDifusion(anguloDifusion){

}

float Difusor::obtAnguloDifusion(){
  return anguloDifusion;
}

bool Difusor::potenciaDifusion(float potencia){
  
}

void Difusor::estAnguloDifusion(float anguloDifusion){  
  this->anguloDifusion = anguloDifusion;
}

Difusor::~Difusor(){

}


//De la clase DifusorCentral llamo el metodo DifusorCentral
//Le paso los atributos al constructor y los inicializo
//Le paso el constructor vacio del padre
DifusorCentral::DifusorCentral():difusorCentral(0.0f), Difusor(){

}
//Le paso los atributos a los atributos de si mismo
//Le paso el PADRE y los atributos del padre
DifusorCentral::DifusorCentral(float difusorCentral, float anguloDifusion):difusorCentral(difusorCentral),Difusor(anguloDifusion){

}
void DifusorCentral::establecerDifusorCentral(float difusorCentral){
  this->difusorCentral = difusorCentral;
}
bool DifusorCentral::potenciaDifusor(float potencia){
  if(obtAnguloDifusion() + difusorCentral == potencia){
    return true;
  }else{
    return false;
  }
}
DifusorCentral::~DifusorCentral(){

}


//De la clase DifusorBivalente llamo el metodo DifusorBivalente
//Le paso los atributos al constructor y los inicializo
//Le paso el contructor vacio del padre
DifusorBivalente::DifusorBivalente():anguloPost(0.0f), Difusor(){

}
//Le paso los atributos a los atributos de si mismo
//Le paso el PADRE y los atributos del padre
DifusorBivalente::DifusorBivalente(float anguloPost, float anguloDifusion):anguloPost(anguloPost), Difusor(anguloDifusion){

}
void DifusorBivalente::estAnguloPost(float anguloPost){
  this->anguloPost = anguloPost;
}
float DifusorBivalente::obtAnguloPost(){
  return anguloPost;
}
DifusorBivalente::~DifusorBivalente(){

}


//De la clase DifusorBivalenteCentral llamo el metodo DifusorBivalenteCentral
//Le paso los atributos al constructor y los inicializo
//Le paso el constructor vacio del padre
DifusorBivalenteCentral::DifusorBivalenteCentral():difusorBic(0.0f), DifusorBivalente(){

}
//Le paso los atributos a los atributos de si mismo
//Le paso el PADRE y los atributos del padre
DifusorBivalenteCentral::DifusorBivalenteCentral(float difusorBic, float anguloPost, float anguloDifusion):difusorBic(difusorBic),DifusorBivalente(anguloPost, anguloDifusion){

}
void DifusorBivalenteCentral::establecerDifusorBic(float difusorBic){
  this->difusorBic = difusorBic;
}
bool DifusorBivalenteCentral::potenciaDifusion(float potencia){
  if(obtAnguloPost()+obtAnguloDifusion() == potencia){
    return true;
  }else{
    return false;
  }
}
DifusorBivalenteCentral::~DifusorBivalenteCentral(){

}



