#include<iostream>
#include<string>
#include<ncurses.h>
#include<vector>


#ifndef render_HPP
#define render_HPP
class Screen{
	public:
		int width;
		int height;
		std::vector<std::vector<std::string>> buffer;

        WINDOW * console;


	Screen(int w,int h);
    ~Screen();
	void render(std::vector<std::vector<std::string>> buffer);
	void render(std::string buffer);
	std::string vectorToString(std::vector<std::vector<std::string>> v);

};
#endif