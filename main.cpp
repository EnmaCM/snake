#include <iostream>
#include<ncurses.h>
#include<vector>
#include<cstring>
#include <chrono>
#include <thread>
#include "objects/snake.hpp"
#include "graphics/render.hpp"
#include "logic/logic.hpp"
#include "game_over.hpp"


int main() {
	bool play = true;
	std::string error_message = ""; 
	Logic game(20,20);
	GameOver gameOverScreen("d",100,100,"./graphics/menus/",6);
	keypad(stdscr,TRUE);
	Screen screen(20,20);
	initscr();
	cbreak();
	noecho();
	timeout(0);
	if(gameOverScreen.error) {
		play = false;
		error_message = gameOverScreen.error_message;
	}

	while(play) {	
		char input = getch();
		if(input == 'x' || gameOverScreen.exit) {
			play = false;
			break;
		} 
		if(!game.game_over) {
			game.update(input);
		}
		if(game.game_over) {
			gameOverScreen.points(game.get_points());
			bool try_again = gameOverScreen.update(input);
			screen.render(gameOverScreen.menu);
			if(input == 'c' || gameOverScreen.try_again) {
				game = Logic(20,20);
				gameOverScreen.reset();
			}
		} else{
			screen.render(game.buffer);
		}
			std::this_thread::sleep_for(std::chrono::milliseconds(100));

	}
	endwin();
	std::cout<<error_message<<std::endl;

	return 0;
}




