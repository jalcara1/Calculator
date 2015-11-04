#!/usr/bin/ruby
# coding: utf-8

def cond01
  s = gets.chomp
  v = s.to_i
  
  if v == 10 then
    puts "v: #{v} es igual de 10"
  elsif v == 20 then       #ó else if
    puts "v: #{v} es igual a 20"
  elsif v == 30 || v == 40  
    puts "v: #{v} es igual a 30 o 40"
  else
    puts "No es igual a 10, 20, 30, 40"
  end

end
  
