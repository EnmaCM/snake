#include <iostream>
#include<ncurses.h>
#include<vector>
#include<cstring>
#include <chrono>
#include <thread>
#include "snake.hpp"
#include "render.hpp"
#include "logic.hpp"


int main() {
	bool play = true; 
	Logic game(20,20);
	keypad(stdscr,TRUE);
	Screen screen(20,20);
	initscr();
	cbreak();
	noecho();
	timeout(0);

	while(play) {	
		char input = getch();
		if(input == 'x') {
			play = false;
			break;
		} 

		game.update(input);
		if(game.game_over) {
			play = false;
			break;
		} 
			screen.render(game.buffer);
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
	
	}
	endwin();
	return 0;
}




