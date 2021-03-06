#include <iostream>
#include "ast.h"
using namespace std;

AST::AST(){}  AST::~AST(){}

BinaryNode::BinaryNode(AST* left, AST* right):AST(), leftTree(left), rightTree(right)
{}

BinaryNode::~BinaryNode(){

  try{
    delete leftTree;
  }catch(...){}

  try{
    delete rightTree;
  }catch(...){}
}

AST* BinaryNode::getLeftSubTree()const{
  return leftTree;
}

AST* BinaryNode::getRightSubTree()const{
  return rightTree;
}

UnaryNode::UnaryNode(AST* sub):AST(), subTree(sub)
{}

UnaryNode::~UnaryNode(){
  try{
    delete subTree;
  }catch(...){}
}

AST* UnaryNode::getSubTree()const{
  return subTree;
}

AddNode::AddNode(AST* left, AST* right):BinaryNode(left,right)
{}

int AddNode::evaluate(){
  return getLeftSubTree()->evaluate() + getRightSubTree()->evaluate();
}

SubNode::SubNode(AST* left, AST* right):BinaryNode(left,right)
{}

int SubNode::evaluate(){
  return getLeftSubTree()->evaluate() - getRightSubTree()->evaluate();
}

TimesNode::TimesNode(AST* left, AST* right):BinaryNode(left,right)
{}

int TimesNode::evaluate(){
  return getLeftSubTree()->evaluate() * getRightSubTree()->evaluate();
}

DivideNode::DivideNode(AST* left, AST* right):BinaryNode(left,right)
{}

int DivideNode::evaluate(){
  return getLeftSubTree()->evaluate() / getRightSubTree()->evaluate();
}

ModuloNode::ModuloNode(AST* left, AST* right):BinaryNode(left,right)
{}

int ModuloNode::evaluate(){
  return getLeftSubTree()->evaluate() % getRightSubTree()->evaluate();
}

StoreNode::StoreNode(AST* sub):UnaryNode(sub)
{}

int StoreNode::evaluate(){
  calc->store(getSubTree()->evaluate());
  return calc->recall();
}

PlusNode::PlusNode(AST* sub):UnaryNode(sub)
{}

int PlusNode::evaluate(){
  int resultPlus = calc->plus(getSubTree()->evaluate());
  return resultPlus;
}

MinusNode::MinusNode(AST* sub):UnaryNode(sub)
{}

int MinusNode::evaluate(){
  int resultMinus = calc->minus(getSubTree()->evaluate());
  return resultMinus;
}

NumNode::NumNode(int n):AST(), val(n)
{}

int NumNode::evaluate(){
  return val;
}

int NumNode::encontrar(string nombre){
  int valor = calc->getVariables(nombre);
  return valor;
}

void NumNode::assignate(string nombre, int valor){
  
  calc->crearVar(nombre, valor);
}

RecallNode::RecallNode():AST()
{}

int RecallNode::evaluate(){
  return calc->recall();
}

CleanNode::CleanNode():
  AST()
{}
int CleanNode::evaluate(){
  return calc->Clean();
}
