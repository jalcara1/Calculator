class Nada

end
#en el interpretador nada1 = Nada.new

class Estudian
  attr_reader :nombre, :edad
  attr_accessor :edad
  def initialize(nombre, edad)
    @nombre = nombre
    @edad = edad
  end

  def imprimir
    puts "Nombre: #{@nombre} edad: #{@edad}"
  end
end
#en el interpretador est1 = Estudiante.new("Juan", 800)
#est1.imprimir


