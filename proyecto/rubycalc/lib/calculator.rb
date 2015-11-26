require 'parser'
require 'ast'
require 'stringio'

class Calculator  
  attr_accessor :memory
  
  # attr_reader :memory
  # attr_writer :memory
  
  def initialize()
    @memory = 0
    @variables = Array.new
    @nombres = Array.new
  end
  
  def eval(expr)
    parser = Parser.new(StringIO.new(expr))
    ast = parser.parse()
    return ast.evaluate()
  end

  def crearVar(nombre, valor)    
    #puts "En crearVar"
    entra = true    
    posN = @nombres.length
    
    while posN >= 0 do
      #puts "Ciclo crear"
      if @nombres[posN] == nombre then
       # puts "Lo encontro"
        @variables[posN] = valor
        entra = false
        #puts "Lo modifico"
      end
      posN -= 1
    end

    if entra == true then
      #puts "No lo encontro"
      @variables.push(valor)
      @nombres.push(nombre)
      #puts "Lo creo"
    end
  end

  def getVariables(nombre)
    #puts "En getVariables"
    posN = @nombres.length
    while posN >= 0 do
     # puts "Ciclo get"
      if @nombres[posN] == nombre then
      #  puts "Lo encontro"
        return @variables[posN]
      end
      posN -= 1
    end
    #puts "No lo encontro"
    return 0
  end
end
