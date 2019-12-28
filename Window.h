#ifndef WINDOW_H
#define WINDOW_H
#pragma once
#include "SDL.h"
#include "Rect.h"
//#include "SDL_ttf.h"
#include <string>

class Window{
private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;
	int _width, _height;
	std::string _title;
	int background[4] = {255,255,255,255};

	void clearRenderer();
	void present();

public:
	Window(const std::string title, int width, int height); //will be centered automatically
	Window(const std::string title, int width, int height, int x, int y);
	~Window();
	
	//Window Properties
	void setPos(int x, int y); // Sets the position of the window with the origin at the top left
							   //Pass SDL_WINDOWPOS_CENTERED as x or y to be centered on that axis
	void getPos(int* x, int* y); // Fills parameters with X and Y coords of window
	void hide();
	void show();
	int* BackgroundColor(); //returns a pointer to an array of size 4 containing r, g, b, and opacity of background
	const int* BackgroundColor() const;

	//Drawing
	void clear(); // clears the window
	void drawFullRect(Rect &rect);
	void drawLineRect(Rect& rect);
	void refresh(); // put at the end of your loop to present everything you have drawn
};

#endif