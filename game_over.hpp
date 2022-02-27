#include <string>
#include <fstream>
#include <iostream>
#include<vector>
#include<ncurses.h>

#ifndef GameOver_HPP
#define GameOver_HPP

class GameOver{
    public:
    bool error;
    std::string error_message = "";
    std::string menu;
    int placeholder_len;
    int placeholder_start_pos;
    std::vector<int> options_pos;
    int bullet_pos_from_list;
    bool try_again = false;
    bool exit = false;
    

   GameOver(std::string name,int width, int height,std::string directory,int placeholder_len) {
        this->menu = load_menu(name,width,height,directory);
        this->placeholder_start_pos = menu.find('$');
        this->options_pos = this->find_all('>',this->menu);
        for(int i = 0; i < this->options_pos.size();i++) {
            // std::cout<<i<<"yes";
            this->menu[options_pos[i]] = ' ';
        }
        this->placeholder_len = placeholder_len;
        this->bullet_pos_from_list = 0;
    }


    void reset() {
        this->try_again = false;
        this->exit = false;
        this->bullet_pos_from_list = 0;
    }
    bool update(char input) {

        switch (input)
        {
        case 'w':
            if(this->bullet_pos_from_list - 1 >= 0) {
                this->menu[this->options_pos[this->bullet_pos_from_list]] = ' ';
                this->bullet_pos_from_list -= 1;
            }
            break;
        case 's':
        
            if(this->bullet_pos_from_list + 1 < this->options_pos.size()) {
                this->menu[this->options_pos[this->bullet_pos_from_list]] = ' ';
                this->bullet_pos_from_list += 1;
            }
            break;
        case 'd':
            if(this->bullet_pos_from_list == 0) {
                this->try_again = true;
            } else if(this->bullet_pos_from_list == 1) {
                this->exit = true;
            }
            break;
        default:
            break;
        }
        this->menu[this->options_pos[this->bullet_pos_from_list]] = '>';

    }
    
    std::vector<int> find_all(char the_char,std::string on_buffer) {
        std::vector<int> positions;

        for(int i = 0; i < on_buffer.size(); i++) {
            if(on_buffer[i] == the_char) {
                positions.push_back(i);
            }
        }
        return positions;
    }

    bool points(int val) {
        std::string v = std::to_string(val);
        int j = 0;
        if(this->placeholder_start_pos == std::string::npos) {
            return false;
        }
        int pos = this->placeholder_start_pos;
        int len = this->placeholder_len;
      
        while(v.size() < len+1) {            
            v.push_back(' ');
        }

        for(int i = pos; i < pos+len; i++) {
            this->menu[i] = v[j];
            j++;
        }
        return true;
    }

    std::string load_menu(std::string name,int width, int height,std::string directory) {
        std::ifstream menu;
        std::string buffer;
        std::string path = directory +  name + std::to_string(width) + "x" + std::to_string(height);
        menu.open(path,std::ios::in);
        if(menu.fail() || !menu.is_open()) {
            this->error = true;
            this->error_message = "Can not open menu:" + path;
            return "";
        }
        std::string line;

        for(;;) {
            getline(menu,line);
            buffer += line + "\n";
            if(menu.eof()) {
                break;
            }
        }
        menu.close();
        this->error = false;
        return buffer;
    }



};
#endif
