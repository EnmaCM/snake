#include "render.hpp"
#include<iostream>
#include<ncurses.h>


Screen::Screen(int w,int h) {
    this->width = w;
    this->height = h;
    this->console = initscr();
    noecho();
}
Screen::~Screen() {
    endwin();
}

void Screen::render(std::vector<std::vector<std::string>> buffer) {
    std::string bufferParsed = vectorToString(buffer);
    clear();
    printw(bufferParsed.c_str());
    refresh();
}

 std::string Screen::vectorToString(std::vector<std::vector<std::string>> v) {
    std::string newB = "";
    std::string nl = "\n";

    for(int i = 0; i < this->height;i++) {
        for(int j = 0; j < this->width;j++) {
            newB += v[i][j];
        }
        newB += nl;
    }
    return newB;
}
