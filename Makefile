OPT = -g -Wall

a4: Main.o Position.o Pit.o Participant.o PartArray.o Hero.o Snorc.o Escape.o random.o
	g++ $(OPT) -o a4 Main.o Position.o Pit.o Participant.o PartArray.o Hero.o Snorc.o Escape.o random.o

Main.o: Main.cc Escape.h
	g++ $(OPT) -c Main.cc

Position.o: Position.cc Position.h
	g++ $(OPT) -c Position.cc

Pit.o: Pit.cc Pit.h
	g++ $(OPT) -c Pit.cc

Participant.o: Participant.cc Participant.h
	g++ $(OPT) -c Participant.cc

PartArray.o: PartArray.cc PartArray.h
	g++ $(OPT) -c PartArray.cc

Hero.o: Hero.cc Hero.h
	g++ $(OPT) -c Hero.cc

Snorc.o: Snorc.cc Snorc.h
	g++ $(OPT) -c Snorc.cc

Escape.o: Escape.cc Escape.h
	g++ $(OPT) -c Escape.cc

random.o: random.cc 
	g++ $(OPT) -c random.cc

clean: 
	rm -f *.o a4