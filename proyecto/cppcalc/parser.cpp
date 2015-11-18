#include "parser.h"
#include "calcex.h"
#include "ast.h"
#include <string>
#include <sstream>
using namespace std;

Parser::Parser(istream* in){
  scan = new Scanner(in);
}

Parser::~Parser(){
  try{
    delete scan;
  }catch(...){}
}

AST* Parser::parse(){
  return Prog();
}

AST* Parser::Prog(){
  AST* result = Expr();
  Token* t = scan->getToken();

  if(t->getType() != eof){
    throw ParseError;
  }
  return result;
}

AST* Parser::Expr(){
  return RestExpr(Term());
}

AST* Parser::RestExpr(AST* e){
  Token* t = scan->getToken();

  if(t->getType() == add){
    return RestExpr(new AddNode(e,Term()));
  }

  if(t->getType() == sub){
    return RestExpr(new SubNode(e,Term()));
  }
  scan->putBackToken();

  return e;
}

AST* Parser::Term(){
  
  return RestTerm(Storable());
}

AST* Parser::RestTerm(AST* e){
  Token* t = scan->getToken();
  
  if(t->getType() == times){
    return RestTerm(new TimesNode(e,Storable()));
  }

  if(t->getType() == divide){
    return RestTerm(new DivideNode(e,Storable()));
  }

  if(t->getType() == modulo){
    return RestTerm(new ModuloNode(e,Storable()));
  }
  
  scan->putBackToken();

  return e;
}

AST* Parser::Storable(){

  return MemOperation(Factor());
}

AST* Parser::MemOperation(AST* result){

  Token *t = scan->getToken();

  if(t->getType() == keyword){

      if(t->getLex() == "S"){
    
      return new StoreNode(result);
      
    }else if(t->getLex() == "P"){

      return new PlusNode(result);

    }else if(t->getLex() == "M"){

      return new MinusNode(result);

    }else{
      throw ParseError;
    }
  }
  scan ->putBackToken();
  return result;
}

AST* Parser::Factor(){
  Token* t = scan->getToken();

  //cout << t->getType() << endl;
  
  if(t->getType() == number){
    istringstream in(t->getLex());
    int numero;
    in >> numero;
    return new NumNode(numero);
    
  }else if(t->getType() == identifier){
    istringstream in(t->getLex());
    string identifier;
    in >> identifier;
    return Assignable(identifier);
  }
  
  if(t->getType() == keyword){

    if(t->getLex() == "R"){

      return new RecallNode();
    }else if(t->getLex() == "C"){

      return new CleanNode();
    }
    throw ParseError;
  }

  if(t->getType() == lparen){
    AST* result = Expr();
    t = scan->getToken();
    if(t->getType() == rparen ){      
      return result;
    }
    throw ParseError;
  }
  throw ParseError;
}

AST* Parser::Assignable(string identifier){

  return  (Assign(identifier));
}

AST* Parser::Assign(string nombre){  
  Token *t = scan -> getToken();  
  NumNode* result = new NumNode(0);

  int valor;  

  if(t -> getType() == igual){
    
    result = new NumNode(Expr() -> evaluate());
    result -> assignate(nombre,result -> evaluate());
    
    
  }else{
    
    valor = result -> encontrar(nombre);    
    result  =  new NumNode(valor);    
  }
  scan -> putBackToken();  
  return result;
}
