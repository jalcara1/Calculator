#include "parser.h"
#include "calcex.h"
#include <string>
#include <sstream>

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
    //cout << "Syntax Error: Expected EOF, found token at column " << t->getCol() << endl;
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
  //write your Term() code here. This code is just temporary
  //so you can try the calculator out before finishing it.
  // Token* t = scan->getToken();

  //  if (t->getType() == number) {
  //     istringstream in(t->getLex());
  //     int val;
  //     in >> val;
  //     return new NumNode(val);
  //  }

  //  cout << "Term not implemented" << endl;

  //  throw ParseError;
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

  // Token *t = scan->getToken();

  // if(t->getType() == keyword){

  //   if(t->getLex() == "S"){

  //     return new StoreNode(result);
  //   }
  //   cout << " Syntax error: Expected S found: " << t -> getLex()
  // 	 << "line: " << t->getLine()
  // 	 << "col: " << t ->getCol()
  // 	 << endl;

  //   throw ParseError;
  // }
  // scan ->putBackToken();

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
      // cout << " Syntax error: Expected S found: " << t -> getLex()
      // 	   << "line: " << t->getLine()
      // 	 << "col: " << t ->getCol()
      // 	 << endl;
    
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
    // cout << " Syntax error: Expected R found: " << t -> getLex()
    // 	 << "line: " << t->getLine()
    // 	 << "col: " << t ->getCol()
    // 	 << endl;

    throw ParseError;
  }

  if(t->getType() == lparen){
    AST* result = Expr();
    t = scan->getToken();
    if(t->getType() == rparen ){      
      return result;
    }
    // cout << "Syntax error: Expected ) found: " << t-> getLex()
    // 	 << " line: " << t->getLine()
    // 	 << " col: " << t-> getCol()
    // 	 << endl;

    throw ParseError;
  }
  // cout << "Syntax error: Expected number, R, ("
  //      << " line: " << t->getLine()
  //      << " col: " << t-> getCol()
  //      << endl;
  throw ParseError;
}

AST* Parser::Assignable(string nombre){
  
  return Assign(nombre);
}
AST* Parser::Assign(string nombre){
  
  Token* t = scan->getToken();
  NumNode* result = new NumNode(0);
  
  if(t->getType() == igual){
    scan->putBackToken();
    //t = scan->getToken;
    result = new NumNode(Expr()->evaluate());
    result->assignate(nombre,result->evaluate());
  }else{
    int prueba = result->encontrar(nombre);
    result = new NumNode(prueba);
    result->assignate(nombre,prueba);
  }

  scan->putBackToken();
  return result;
}


//
//
