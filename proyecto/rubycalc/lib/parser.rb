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
      print "Expected EOF. Found ", t.type, ".\n"
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
    # Write your Term() code here. This code is just temporary
    # so you can try the calculator out before finishing it.
    
    # t = @scan.getToken()
    
    # if t.type == :number then
    #   val = t.lex.to_i
    #   return NumNode.new(val)
    # end
    
    # puts "Term not implemented\n"
    
    # raise ParseError.new
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
    # puts "RestTerm not implemented"
    # raise ParseError.new # "Parse Error"
  end

  def Storable()
    result = Factor()
    t = @scan.getToken  #obtener un token

    if t.type == :keyword then
      if t.lex == "S" then
        return StoreNode.new(result)
      elsif t.lex == "M" then
        return MinusNode.new(result)
      elsif t.lex == "P" then
        return PlusNode.new(result)
      end
      puts "Expected s found: "+t.lex.to_s
      raise ParseError.new
    end
    @scan.putBackToken()  #Devuelve el caracter ingresado
    return result
    # puts "Storable not implemented"
    # raise ParseError.new # "Parse Error"
  end
   
  def Factor() 
    t = @scan.getToken    
    if t.type == :number then
      return NumNode.new(t.lex.to_i)
    end

    if t.type == :keyword then
      if t.lex == ?R then
        return RecallNode.new
      elsif t.lex == ?C then
        return CleanNode.new
      end
      puts "Expected R found: " + t.lex
      raise ParseError.new
    end

    if t.type == :lparen then
      result = Expr()
      t = @scan.getToken
      if t.type == :rparen then
        return result
      end
      puts "Expected ) found: " + t.type.to_s
      raise ParseError.new
    end

    puts "Expected number, R, ( found: " + t.type.to_s
    raise ParseError.new
        
    # puts "Factor not implemented"
    # raise ParserError.new # "Parse Error"
  end         
end
