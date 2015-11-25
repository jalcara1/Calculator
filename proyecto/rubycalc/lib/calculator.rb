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
    puts "En crearVar"
    @variables.push(valor)
    puts @variables
  end

  def getVariables(nombre)
    puts "En getVariables"
    @nombres << nombre
    puts @nombres
    return 0
  end
end
