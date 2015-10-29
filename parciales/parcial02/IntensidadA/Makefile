OBJECTS=iluminanciaA.o intensidadA.o

intensidad:	$(OBJECTS)
		g++ $ -o $@ $(OBJECTS)

iluminancia.o:	iluminanciaA.cpp iluminanciaA.h intensidadA.cpp
		g++ -c $<

intensidadA.o:	iluminanciaA.cpp iluminanciaA.h intensidadA.cpp

clean:
	rm -f *~
	rm -f *.gch
	rm -f *.o
	rm -f *.exe
