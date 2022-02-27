#include<random>

#ifndef food_HPP
#define food_HPP

class Food{
    int x_limit;
    int y_limit;
 
    public:
        int y_pos;
        int x_pos;
        std::string symbol;
        
        Food(int x_spawn_limit, int y_spawn_limit);
        bool reposition(std::vector<std::vector<int>> ocupped_spaces);
        bool reposition(std::vector<int> ocupped_space);
        int ramdomNumber(int fromN,int toN);
    
};
#endif