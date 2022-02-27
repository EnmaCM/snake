# LBFLAGS := --lib


clean: snakeGame
	-rm -f bin/*.o

snakeGame: game_over.hpp logic/logic.hpp character.o objects/snake.hpp graphics/render.hpp main.o render.o logic.o logic/logic.hpp objects/food.hpp food.o 
	g++ bin/main.o game_over.hpp bin/character.o bin/render.o bin/food.o logic/logic.cpp objects/snake.hpp graphics/render.hpp logic/logic.hpp objects/food.hpp -o snakeGame -lncurses

character.o: 
	g++ -c objects/character.cpp  -o bin/character.o

main.o:
	g++ -c main.cpp -o bin/main.o -lncurses 	

render.o:
	g++ -c graphics/render.cpp -o bin/render.o -lncursesw	

logic.o:
	g++ -c logic/logic.cpp -o bin/logic.o 
food.o:
	g++ -c objects/food.cpp -o bin/food.o

.DELETE_ON_ERROR: 
	-rm -f bin/	*.o
