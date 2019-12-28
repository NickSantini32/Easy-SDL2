#include "Rect.h"
#include "SDL.h"
//#include <iostream>
#include "Window.h"

using namespace std;

Rect::Rect() {
	_rect.x = 0;
	_rect.y = 0;
	_rect.w = 0;
	_rect.h = 0;
	colorData[0] = 0;
	colorData[1] = 0;
	colorData[2] = 0;
	colorData[3] = 255;
}
Rect::Rect(int x, int y, int height, int width) {
	_rect.x = x;
	_rect.y = y;
	_rect.w = width;
	_rect.h = height;
	colorData[0] = 0;
	colorData[1] = 0;
	colorData[2] = 0;
	colorData[3] = 255;
}
Rect::Rect(int x, int y, int height, int width, int r, int g, int b) {
	_rect.x = x;
	_rect.y = y;
	_rect.w = width;
	_rect.h = height;
	colorData[0] = r;
	colorData[1] = g;
	colorData[2] = b;
	colorData[3] = 255;
}
Rect::Rect(int x, int y, int height, int width, int r, int g, int b, int o) {
	_rect.x = x;
	_rect.y = y;
	_rect.w = width;
	_rect.h = height;
	colorData[0] = r;
	colorData[1] = g;
	colorData[2] = b;
	colorData[3] = o;
}


bool Rect::collidesWith(Rect& obj) {
	if (x() + width() >= obj.x() && obj.x() + obj.width() >= x()) { // collision on x axis
		if (y() + height() >= obj.y() && obj.y() + obj.height() >= y()) { // collision on y axis
			return true;
		}
	}	
	return false;
}


int& Rect::x() { return _rect.x; }
int& Rect::y() { return _rect.y; }
int& Rect::width() { return _rect.w; }
int& Rect::height() { return _rect.h; }

const int& Rect::x() const { return _rect.x; }
const int& Rect::y() const { return _rect.y; }
const int& Rect::width() const { return _rect.w; }
const int& Rect::height() const { return _rect.h; }

int& Rect::r() { return colorData[0]; }
int& Rect::g() { return colorData[1]; }
int& Rect::b() { return colorData[2]; }
int& Rect::opacity() { return colorData[3]; }

const int& Rect::r() const { return colorData[0]; }
const int& Rect::g() const { return colorData[1]; }
const int& Rect::b() const { return colorData[2]; }
const int& Rect::opacity() const { return colorData[3]; }