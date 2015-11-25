require 'parser'
require 'ast'
require 'stringio'

class Calculator  
  attr_accessor :memory
  
  # attr_reader :memory
  # attr_writer :memory
  
  def initialize()
    @memory = 0
  end
  
  def eval(expr)
    parser = Parser.new(StringIO.new(expr))
    ast = parser.parse()
    return ast.evaluate()
  end

  def crearVar(nombre, valor)
    puts "En crearVar"
    return 0
  end

  def getVariables(nombre)
    puts "En getVariables"
    return 0
  end
end
