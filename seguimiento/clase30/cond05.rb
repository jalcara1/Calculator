#!/usr/bin/ruby
# fichero: cond05.rb
#
# proposito: mostrar valores que son considerados verdaderos y falso
#

# Cualquier valor diferente de nil y de false son considerados verdaderos

s = true
puts "s: #{s} es verdadero" if s

s = 10

puts "s: #{s} es considerado verdadero" if s

s = "Hola Mundo"

puts "s: #{s} es considerado verdadero" if s

def cond05a
  s = nil
  if s == nil
    puts "s no esta definida"
  end
end



