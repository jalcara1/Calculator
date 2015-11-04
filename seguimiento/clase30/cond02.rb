#!/usr/bin/ruby
# fichero: cond02.rb
#
# proposito: mostrar otros tipos de condiciones
#
s = gets.chomp
v = s.to_i

unless v == 10 then #amenos que v == 10
  puts "v: #{v} es diferente de 10"
else
  puts "Imposible"
end

