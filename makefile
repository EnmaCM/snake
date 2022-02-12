# LBFLAGS := --lib


clean: lo
	-rm -f *.o

lo: logic.hpp character.o snake.hpp render.hpp lo.o render.o logic.o logic.hpp food.hpp food.o 
	g++ lo.o  character.o render.o food.o logic.cpp snake.hpp render.hpp logic.hpp food.hpp -o lo -lncurses

character.o: 
	g++ -c character.cpp  -o character.o

lo.o:
	g++ -c lo.cpp -o lo.o -lncurses 	

render.o:
	g++ -c render.cpp -o render.o -lncurses

logic.o:
	g++ -c logic.cpp -o logic.o 
food.o:
	g++ -c food.cpp -o food.o

.DELETE_ON_ERROR: 
	-rm -f *.o