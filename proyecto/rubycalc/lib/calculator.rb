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
    @salidaF = ""
  end
  
  def eval(expr)
    parser = Parser.new(StringIO.new(expr))
    ast = parser.parse()
    return ast.evaluate()
  end

  def crearVar(nombre, valor)    
    entra = true    
    posN = @nombres.length
    
    while posN >= 0 do
      if @nombres[posN] == nombre then
        @variables[posN] = valor
        entra = false
      end
      posN -= 1
    end

    if entra == true then
      @variables.push(valor)
      @nombres.push(nombre)
    end

    salida(nombre,valor)
  end

  def getVariables(nombre)
    posN = @nombres.length
    while posN >= 0 do
      if @nombres[posN] == nombre then
        return @variables[posN]
      end
      posN -= 1
    end
    return 0
  end

  def salida(nombre,valor)
    if @salidaF == "" then
      @salidaF = @salidaF + nombre + " <- " + valor.to_s
    else
      @salidaF = @salidaF + ", " + nombre + " <- " + valor.to_s
    end
  end

  def getSalida()
    return @salidaF
  end

  def limpiarSalida()
    @salidaF = ""    
  end
end
