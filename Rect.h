#ifndef RECT_H
#define RECT_H
#pragma once
#include "SDL.h"

class Rect{
	friend class Window;

private:	
	SDL_Rect _rect;
	int colorData[4];

	
public:
	//constructors
	Rect();
	Rect(int x, int y, int height, int width);
	Rect(int x, int y, int height, int width, int r, int g, int b);
	Rect(int x, int y, int height, int width, int r, int g, int b, int o);

	bool collidesWith(Rect& rect);

	//size and position
	int& x();
	int& y();
	int& width();
	int& height();
	//accessor versions
	const int& x() const;
	const int& y() const;
	const int& width() const;
	const int& height() const;

	//colors
	int& r();
	int& g();
	int& b();
	int& opacity();
	//accessor versions
	const int& r() const;
	const int& g() const;
	const int& b() const;
	const int& opacity() const;

};
#endif
