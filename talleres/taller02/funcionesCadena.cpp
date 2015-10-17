char* borrarblancosinicio(char *s){

  int cont = 0;
  while(*s == 32){
    *s = '\0';
    cont++;
    s++;
  }

  return s - cont;
  
}

const char* indiceAlaDerecha(const char *s, int c){

  const char* poscicion;
  while(*s != '\0'){
    if(*s == c){
      poscicion = s;
      s++;
    }else{
      s++;
    }
  }
  if(*poscicion == c){
    return poscicion;
  }

  return s;
}
