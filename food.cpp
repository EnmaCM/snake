#include<random>
#include"food.hpp"

Food::Food(int x_spawn_limit, int y_spawn_limit) {
    this->x_limit = x_spawn_limit;
    this->y_limit = y_spawn_limit;
    this->y_pos = ramdomNumber(1,this->y_limit);
    this->x_pos = ramdomNumber(1,this->x_limit);
    this->symbol = "x";
}
    
bool Food::reposition(std::vector<std::vector<int>> ocupped_spaces){
    int x = 0;
    int y = 0;
    bool ocupped = true;

    while(ocupped) {
        y = ramdomNumber(1,this->y_limit);
        x = ramdomNumber(1,this->x_limit);
        
        for(int i = 0; i < ocupped_spaces.size(); i++) {
            if(ocupped_spaces[i][0] == x || ocupped_spaces[i][1] == y) {
                ocupped = true;
                break;
            } else{
                ocupped = false;
            }
        } 
        if(!ocupped) {
            break;
        }
    }
    this->y_pos = y;
    this->x_pos = x;
    return true;
}

    int Food::ramdomNumber(int fromN,int toN) {
        std::random_device r;
        std::default_random_engine e1(r());
        std::uniform_int_distribution<int> uniform_dist(fromN, toN-1);
        int mean = uniform_dist(e1);
        return mean;
    }
    
