class A
  def comp
    puts "Soy la claseA"
  end
end

class B<A
  def comp
    puts "Soy la clase B"
  end
end

class NiANiB
  def comp
    puts "No soy ni A ni B"
  end
end

def evalComp a
  a.comp
end
