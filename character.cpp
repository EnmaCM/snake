#include "snake.hpp"
#include<iostream>
#include<vector>
#include<cstring>


Snake::Snake(int x,int y){
	this->direction = "DOWN";
	this->simbol = "o";
	this->x = x;
	this->y = y;
	snakeParts[0][0] = x;
	snakeParts[0][1] = y;	
	snakeParts[1][0] = ++x;
	snakeParts[1][1] = y;
}

void Snake::change_direction(std::string new_direction) {
	this->last_direction = this->direction;
	this->direction = new_direction;
}

std::vector<std::vector<int>> Snake::move(int w_width,int w_heigh){
	//initialize the snake vector with the new head's coordinates in it
	std::vector<std::vector<int>> newSnake = {moveHeadTo(this->direction,w_width,w_heigh)};
	this->last_snake_parts = this->snakeParts;

	if(last_snake_parts[0][0] != newSnake[0][0] || last_snake_parts[0][1] != newSnake[0][1] ) {
		for(int i = 0; i < this->snakeParts.size()-1; i++) {
			newSnake.push_back(this->snakeParts[i]);
		}
	} else{
		newSnake = this->last_snake_parts;
	}
	this->snakeParts = newSnake;
	return newSnake;
}

std::vector<int> Snake::moveHeadTo(std::string new_direction,int win_limit_x,int win_limit_y){
	std::vector<int> headPos = this->snakeParts[0];
	std::vector<int>newHeadPos;
	int x = headPos[1];
	int y = headPos[0];
		 
	if(new_direction == "UP" && y-1 > 0 ) {
		newHeadPos = {headPos[0]-1,headPos[1]};		
	}
    else if((new_direction == "DOWN") && (y+1 < win_limit_y)){
	   		newHeadPos = {headPos[0]+1,headPos[1]};
	}
	else if((new_direction == "LEFT") && (x-1 > 0)){
			newHeadPos = {headPos[0],headPos[1]-1};
	}
	else if( (new_direction == "RIGHT") && (x + 1 < win_limit_x)) {
			newHeadPos = {headPos[0],headPos[1]+1};		
	} 
	else {
		// if(new_direction == "UP" || new_direction == "DOWN")
		// newHeadPos =  this->moveHeadTo(this->last_direction,win_limit_x,win_limit_y);
		newHeadPos = headPos;
	}
	return newHeadPos;
}



std::string Snake::get_current_direction() {
	std::string dir = this->direction;
	return dir;
}
		


