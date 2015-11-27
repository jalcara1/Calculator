require 'ast'
require 'scanner'
require 'token'
require 'calcex'

class Parser
  
  def initialize(istream)
    @scan = Scanner.new(istream)
  end
  
  def parse()
    return Prog()
  end
    
  private
  def Prog()
    result = Expr()
    t = @scan.getToken()
    
    if t.type != :eof then
      raise ParseError.new
    end
    
    return result
  end
    
  def Expr() 
    return RestExpr(Term())
  end
     
  def RestExpr(e) 
    t = @scan.getToken()
    
    if t.type == :add then
         return RestExpr(AddNode.new(e,Term()))
    end
    
    if t.type == :sub then
      return RestExpr(SubNode.new(e,Term()))
    end
      
    @scan.putBackToken()
    
    return e
  end
  
  def Term()
    RestTerm(Storable())
  end
  
  def RestTerm(e)
    t = @scan.getToken()
    if t.type == :times then
      return RestTerm(TimesNode.new(e,Storable()))
    end

    if t.type == :modulo then
      return RestTerm(ModuloNode.new(e,Storable()))
    end
    
    if t.type == :divide then
      return RestTerm(DivideNode.new(e, Storable()))
    end    
    @scan.putBackToken
    return e
  end
  
  def Storable()
    return MemOperation(Factor())
  end
    
  def MemOperation(result)
    t = @scan.getToken  #obtener un token

    if t.type == :keyword then
      if t.lex == "S" then
        return StoreNode.new(result)
      elsif t.lex == "M" then
        return MinusNode.new(result)
      elsif t.lex == "P" then
        return PlusNode.new(result)
      end
      raise ParseError.new
    end
    @scan.putBackToken()  #Devuelve el caracter ingresado
      return result      
  end
       
  def Factor() 
    t = @scan.getToken    
    if t.type == :number then
      return NumNode.new(t.lex.to_i)
    end
    
    if t.type == :identifier then
      return Assignable(t.lex)
    end

    if t.type == :keyword then
      if t.lex == ?R then
        return RecallNode.new
      elsif t.lex == ?C then
        return CleanNode.new
      end
      raise ParseError.new
    end

    if t.type == :lparen then
      result = Expr()
      t = @scan.getToken
      if t.type == :rparen then
        return result
      end
      raise ParseError.new
    end
    raise ParseError.new
  end
  
  def Assignable(identifier)
    return Assign(identifier)
  end
  
  def Assign(nombre)
    t = @scan.getToken  #obtener un token
    result = NumNode.new(0)
    
    if t.type == :igual then
      result = NumNode.new(Expr().evaluate())
      result.assignate(nombre,result.evaluate())
    else
      valor = result.encontrar(nombre);
      result = NumNode.new(valor);
    end
    @scan.putBackToken
    return result    
  end  
end
