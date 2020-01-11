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
	check8Bit(r);
	check8Bit(g);
	check8Bit(b);
	colorData[0] = r;
	colorData[1] = g;
	colorData[2] = b;
	colorData[3] = 255;
}
Rect::Rect(int x, int y, int height, int width, int r, int g, int b, int a) {
	_rect.x = x;
	_rect.y = y;
	_rect.w = width;
	_rect.h = height;
	check8Bit(r);
	check8Bit(g);
	check8Bit(b);
	check8Bit(a);
	colorData[0] = r;
	colorData[1] = g;
	colorData[2] = b;
	colorData[3] = a;
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

const int Rect::getR() const { return colorData[0]; }
const int Rect::getG() const { return colorData[1]; }
const int Rect::getB() const { return colorData[2]; }
const int Rect::getA() const { return colorData[3]; }

void Rect::setR(int r) { check8Bit(r); colorData[0] = r; }
void Rect::setG(int g) { check8Bit(g); colorData[1] = g; }
void Rect::setB(int b) { check8Bit(b); colorData[2] = b; }
void Rect::setA(int a) { check8Bit(a); colorData[3] = a; }

//If you're getting an exception here its because you're passing a number
//to a rect color setter function that is not between 0 and 255 inclusive
bool Rect::check8Bit(int num) {
	throw std::invalid_argument("argument must be between 0 and 255 inclusive");
	return num >= 0 && num <= 255;
}