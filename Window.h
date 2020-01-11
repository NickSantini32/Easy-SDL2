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
	SDL_Event _event;
	int _width, _height, _x, _y;
	int mouseX, mouseY;
	std::string _title;
	int background[4] = {255,255,255,255};

	void clearRenderer();
	void present();

	static bool check8Bit(int num);

public:
	Window(const std::string title, int width, int height); //will be centered automatically
	Window(const std::string title, int width, int height, int x, int y);
	~Window();
	
	//Window Properties
	void setPos(int x, int y); // Sets the position of the window with the origin at the top left
							   //Pass SDL_WINDOWPOS_CENTERED as x or y to be centered on that axis
	const int getX() const;
	const int getY() const;
	void setSize(int w, int h);
	const int getWidth() const;
	const int getHeight() const;
	void hide();
	void show();

	//background color setters
	void setR(int r);
	void setG(int g);
	void setB(int b);
	void setA(int a);
	//background color getters
	const int getR() const;
	const int getG() const;
	const int getB() const;
	const int getA() const;

	//Input Handling
	const bool pollEvents();
	const int keyPressEvent();
	const int keyReleaseEvent();
	const int mousePressEvent();
	const int mouseReleaseEvent();
	const int getMouseX() const;
	const int getMouseY() const;

	//Drawing
	void clear(); // clears the window
	void drawFullRect(Rect &rect);
	void drawLineRect(Rect &rect);
	void refresh(); // put at the end of your loop to present everything you have drawn
};

#endif