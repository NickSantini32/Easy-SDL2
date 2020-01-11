#ifndef RECT_H
#define RECT_H
#pragma once
#include "SDL.h"
#include <stdexcept>

class Rect{
	friend class Window;

private:	
	SDL_Rect _rect;
	int colorData[4];

	static bool check8Bit(int num);
	
public:
	//constructors
	Rect();
	Rect(int x, int y, int height, int width);
	Rect(int x, int y, int height, int width, int r, int g, int b);
	Rect(int x, int y, int height, int width, int r, int g, int b, int a);

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

	//color acessors
	const int getR() const;
	const int getG() const;
	const int getB() const;
	const int getA() const;
	//color setters
	void setR(int r);
	void setG(int g);
	void setB(int b);
	void setA(int a);

};
#endif
