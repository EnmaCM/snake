#include<vector>
#include<iostream>

#ifndef snake_HPP
#define snake_HPP
class Snake{
	private:
		std::string direction;
		std::string last_direction;
	
	public:
		std::vector<std::vector<int>> snakeParts = {{0,0},{0,0}};
		std::vector<std::vector<int>> last_snake_parts = {{0,0},{0,0}};
		int x;
		int y;
	 	std::string simbol;

	    Snake(int x,int y);
		void change_direction(std::string new_direction);
	    std::vector<std::vector<int>> move(int w_width,int w_heigh);
	    std::vector<int> moveHeadTo(std::string new_direction,int win_limit_x,int win_limit_y);
		std::string get_current_direction();
};
#endif
