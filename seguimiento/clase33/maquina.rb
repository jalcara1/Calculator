#!/usr/bin/env ruby

def delta(state,caracter)
  case state

  when :estado0
    case caracter
    when 'a'
      return :estado1
    else
      return :error
    end
    

  when :estado1
    case caracter
    when 'a'
      return :estado1
    when 'b'
      return :estado2
    when 'c'
      return :estado3
    else
      return :error
    end
    

  when :estato2
    return :error

  when :estado3
    case caracter
    when 'b'
      return :estado2
    else
      return :error
    end
  end
end


def accept(state)
  Set.new([:estado2, :estado3]).include?(state)
  #Arreglo, que pregunta si hay un estado                                         
  #No busca en los estado repetidos
end


def main()
  print "Entre una secuencia de caracteres a validar> "
  s = gets.chomp
  state = :estado0
  s.each_char do |c|
    state = delta(state,c)
  end

  if accept(state)then
    puts "Cadena aceptada"
  else
    puts "Cadena rechazada"
  end
end

main
  
