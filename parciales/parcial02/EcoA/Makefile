OBJECTS=eco.o

procesarecos:	$(OBJECTS)
		g++ $ -o $@ procesarecos.cpp $(OBJECTS)

eco.o:	eco.cpp eco.h procesarecos.cpp
	g++ $ -c $<

clean:
	rm -f *~
	rm -f *.gch
	rm -f *.o
	rm -f *.exe 
