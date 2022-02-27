#include "logic.hpp"
#include "../objects/snake.hpp"

Logic::Logic(int width,int height) : player(10,10),fruit(width-1,height-1) {

    this->bWith = width;
    this->bHeight = height;
    std::vector<std::vector<std::string>> buffer;
    this->figure = "·";

    for(int i = 0; i < height;i++) {
        std::vector<std::string> placeholder;
        buffer.push_back(placeholder);
        for(int j = 0; j < width;j++) {
            buffer[i].push_back(figure);
        }
    }
    this->original_buffer = buffer;
    this->buffer = buffer;
    this->buffer[fruit.x_pos][fruit.y_pos] = this->fruit.symbol; 
}


std::vector<std::vector<std::string>> Logic::update(char input) {

    std::string current_direction = this->player.get_current_direction();
    this->last_buffer = this->buffer;

    if(input == 'w' && current_direction != "DOWN") {
        this->change_direction("UP");
    } else if (input == 's' && current_direction != "UP"){
        this->change_direction("DOWN");
    } else if(input == 'd' && current_direction != "LEFT") {
        this->change_direction("RIGHT");
    } else if(input == 'a' && current_direction != "RIGHT") {
        this->change_direction("LEFT");
    }

    this->clear(player.snakeParts);
    this->clear(std::vector<std::vector<int>>{std::vector<int>{fruit.x_pos,fruit.y_pos}});
    this->updateSnake();
    this->update_fruit(false);
    return this->buffer;
}


std::vector<std::vector<std::string>> Logic::updateSnake() {
    this->player.move(this->bWith-1,this->bHeight-1);
    int x_head = this->player.snakeParts[0][0];
    int y_head = this->player.snakeParts[0][1];
    int x_las_head = this->player.last_snake_parts[0][0];
    int y_las_head = this->player.last_snake_parts[0][1];

    if(this->last_buffer[x_head][y_head] == "x") {
        this->player.snakeParts.push_back(this->player.last_snake_parts[this->player.last_snake_parts.size()-1]);
        this->update_fruit(true);
        this->points += 1;    
    }
    if(this->last_buffer[x_head][y_head] == this->player.simbol) {
        if(x_las_head != x_head || y_las_head != y_head){
            this->game_over = true;
            return this->buffer;
        }
    }
    if(x_las_head == x_head && y_las_head == y_head) {
        this->game_over = true;
        return this->buffer;
    }


    std::vector<std::vector<int>> snake = this->player.snakeParts;
    for(int i = 0; i < snake.size();i++) {
        this->buffer[snake[i][0]][snake[i][1]] = this->player.simbol;
    }
    
    return this->buffer;
}

void Logic::change_direction(std::string direction) {
    return player.change_direction(direction);
}

void Logic::clear(std::vector<std::vector<int>> in_coordinates) {
    for(int i = 0; i < in_coordinates.size(); i++) {
        this->buffer[in_coordinates[i][0]][in_coordinates[i][1]] = this->figure;
    }
}

void Logic::refresh_buffer() {
    this->buffer = this->original_buffer;
}

void Logic::update_fruit(bool change_pos) {
    if(change_pos) {
        this->fruit.reposition(this->player.snakeParts);
    }
    this->buffer[fruit.x_pos][fruit.y_pos] = this->fruit.symbol; 
}
