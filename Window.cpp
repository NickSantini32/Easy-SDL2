#include "Window.h"
#include "Rect.h"
#include "SDL.h"
#include <string>
//#include "SDL_ttf.h"
#include <iostream>

Window::Window(const std::string title, int width, int height) : Window(title, width, height, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED){	
}
Window::Window(const std::string title, int width, int height, int x, int y) : _title(title), _width(width), _height(height), _x(x), _y(y){
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cerr << "Could not init";
	}

	_window = SDL_CreateWindow(
		_title.c_str(),
		x,
		y,
		_width,
		_height,
		SDL_WINDOW_SHOWN);
	if (_x == SDL_WINDOWPOS_CENTERED || _y == SDL_WINDOWPOS_CENTERED)
		SDL_GetWindowPosition(_window, &_x, &_y);

	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_SOFTWARE);
	SDL_SetRenderDrawColor(_renderer, background[0], background[1], background[2], background[3]);
	SDL_RenderClear(_renderer);
}
Window::~Window(){
	SDL_DestroyWindow(_window);
	SDL_Quit();
}


void Window::setPos(int x, int y) {
	if (!x)
		x = _x;
	if (!y)
		y = _y;
	SDL_SetWindowPosition(_window, x, y);
	SDL_GetWindowPosition(_window, &_x, &_y);
}
const int Window::getX() const {
	return _x;
}
const int Window::getY() const {
	return _y;
}
void Window::setSize(int w, int h) {
	if (!w)
		w = _width;
	if (!h)
		h = _height;
	SDL_SetWindowSize(_window, w, h);
	_height = h;
	_width = w;
}
const int Window::getWidth() const {
	return _width;
}
const int Window::getHeight() const {
	return _height;
}
void Window::hide() {
	SDL_HideWindow(_window);
}
void Window::show() {
	SDL_ShowWindow(_window);
}

void Window::setR(int r) { check8Bit(r); background[0] = r; }
void Window::setG(int g) { check8Bit(g); background[1] = g; }
void Window::setB(int b) { check8Bit(b); background[2] = b; }
void Window::setA(int a) { check8Bit(a); background[3] = a; }

const int Window::getR() const { return background[0]; }
const int Window::getG() const { return background[1]; }
const int Window::getB() const { return background[2]; }
const int Window::getA() const { return background[3]; }

const bool Window::pollEvents() {
	return SDL_PollEvent(&_event);
	/*switch (_event.type)
	{
	case SDL_MOUSEMOTION:
	{
		mouseX = _event.motion.x;
		mouseY = _event.motion.y;
		std::cout << mouseX << std::endl;
		break;
	}
	}*/
}
const int Window::keyPressEvent() {
	if (_event.type == SDL_KEYDOWN)
		return _event.key.keysym.sym;
	else
		return -1;
}
const int Window::keyReleaseEvent() {
	if (_event.type == SDL_KEYUP)
		return _event.key.keysym.sym;
	else
		return -1;
}
const int Window::mousePressEvent() {
	if (_event.type == SDL_MOUSEBUTTONDOWN)
		return _event.button.button;
	else
		return -1;
}
const int Window::mouseReleaseEvent() {
	if (_event.type == SDL_MOUSEBUTTONUP)
		return _event.button.button;
	else
		return -1;
}
const int Window::getMouseX() const {
	return _event.motion.x;
}
const int Window::getMouseY() const {
	return _event.motion.y;
}



void Window::drawFullRect(Rect &rect){
	SDL_SetRenderDrawColor(_renderer, rect.getG(), rect.getG(), rect.getB(), rect.getA());
	SDL_RenderFillRect(_renderer, &rect._rect);
}
void Window::drawLineRect(Rect& rect) {
	SDL_SetRenderDrawColor(_renderer, rect.getR(), rect.getG(), rect.getB(), rect.getA());
	SDL_RenderDrawRect(_renderer, &rect._rect);
}


void Window::clear() {
	clearRenderer();
	present();
}
void Window::refresh() {
	present();
	clearRenderer();
}
void Window::present() {
	SDL_RenderPresent(_renderer);
}
void Window::clearRenderer() {
	SDL_SetRenderDrawColor(_renderer, background[0], background[1], background[2], background[3]);
	SDL_RenderClear(_renderer);
}


//If you're getting an exception here its because you're passing a number
//to a window color setter function that is not between 0 and 255 inclusive
bool Window::check8Bit(int num) {
	throw std::invalid_argument("argument must be between 0 and 255 inclusive");
	return num >= 0 && num <= 255;
}
