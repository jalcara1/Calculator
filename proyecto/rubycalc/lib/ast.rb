require 'set'
#
class BinaryNode
  attr_reader :left, :right
  
  def initialize(left,right)
    @left = left
    @right = right
  end
end
#
#   
class UnaryNode
  attr_reader :subTree
   
  def initialize(subTree)
    @subTree = subTree
  end
end
#
#
class StoreNode < UnaryNode
  def initialize(sub)
    super(sub)
  end
  
  def evaluate
    $calc.memory = subTree.evaluate
  end
end
#
#
class MinusNode < UnaryNode
  # def initialize(sub)
  #   super(sub)
  # end

  def evaluate
    $calc.memory -= subTree.evaluate
  end
end
#
#
class PlusNode < UnaryNode
  # def initialize(sub)
  #   super(sub)
  # end

  def evaluate
    $calc.memory += subTree.evaluate
  end
end
#
#
class RecallNode
  def evaluate
    $calc.memory
  end
end
#
class CleanNode
  def evaluate
    $calc.memory = 0
  end
end
#
#
class AddNode < BinaryNode
  def initialize(left, right)
    super(left,right)
  end
   
  def evaluate() 
    @left.evaluate() + @right.evaluate()
  end
end
#
#
class DivideNode < BinaryNode
  def initialize(left, right)
    super(left,right)
  end
   
  def evaluate() 
    @left.evaluate() / @right.evaluate()
  end
end
#
#
class ModuloNode < BinaryNode
  def initialize(left, right)
    super(left,right)
  end

  def evaluate()
    @left.evaluate() % @right.evaluate()
  end
end
#
#
class TimesNode < BinaryNode
  def initialize(left, right)
    super(left,right)
  end
   
  def evaluate() 
    @left.evaluate() * @right.evaluate()
  end
end
#
#
class SubNode < BinaryNode
  def initialize(left, right)
    super(left,right)
  end
   
  def evaluate() 
    @left.evaluate() - @right.evaluate()
  end
end
#
#
class NumNode 
  def initialize(num)
    @num = num
  end
   
  def evaluate() 
    @num
  end

  def assignate(nombre,valor)
    puts "En ast->assignate"
    $calc.crearVar(nombre,valor)    
  end

  def encontrar(nombre)
    puts "En ast->encontrar"
    puts nombre
    return $calc.getVariables(nombre)    
  end
end
#
