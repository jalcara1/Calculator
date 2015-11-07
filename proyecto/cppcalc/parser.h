#pragma once
#include "ast.h"
#include "scanner.h"

class Parser{
 public:
  Parser(istream* in);
  ~Parser();
  AST* parse();

 private:
  AST* Prog();
  AST* Expr();
  AST* RestExpr(AST* e);
  AST* Term();
  AST* RestTerm(AST* t);
  AST* Storable(); 
  AST* MemOperation(AST* result);
  AST* Factor();
  AST* Assignable(string identifier);
  AST* Assign(string igual);
  
  Scanner* scan;
};


