#include<string>
#include<vector>
#include "snake.hpp"
#include "food.hpp"

class Logic{
	private:
		Snake player;
		Food fruit;
        std::vector<std::vector<std::string>> original_buffer;
		std::string figure;
		int points = 0;

	public:
		std::vector<std::vector<std::string>> buffer;
		std::vector<std::vector<std::string>> last_buffer;

		int bWith;
		int bHeight;
		bool game_over = false;
	
		Logic(int width,int height);
        std::vector<std::vector<std::string>> update(char input);
		std::vector<std::vector<std::string>> updateSnake();
		void change_direction(std::string direction);
        void refresh_buffer();
		void update_fruit(bool);
		void clear(std::vector<std::vector<int>> in_coordinates);
		int get_points() {
			return this->points;
		}
		
};


