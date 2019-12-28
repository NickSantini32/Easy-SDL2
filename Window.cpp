#include "Window.h"
#include "Rect.h"
#include "SDL.h"
#include <string>
//#include "SDL_ttf.h"
#include <iostream>

Window::Window(const std::string title, int width, int height) : Window(title, width, height, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED){	
}
Window::Window(const std::string title, int width, int height, int x, int y) : _title(title), _width(width), _height(height){
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

	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_SOFTWARE);
	SDL_SetRenderDrawColor(_renderer, background[0], background[1], background[2], background[3]);
	SDL_RenderClear(_renderer);
}
Window::~Window(){
	SDL_DestroyWindow(_window);
	SDL_Quit();
}


void Window::setPos(int x, int y) {
	SDL_SetWindowPosition(_window, x, y);
}
void Window::getPos(int* x, int* y) {
	SDL_GetWindowPosition(_window, x, y);
}
void Window::show() {
	SDL_ShowWindow(_window);
}
void Window::hide() {
	SDL_HideWindow(_window);
}
int* Window::BackgroundColor() {
	return background;
}
const int* Window::BackgroundColor() const{
	return background;
}


void Window::drawFullRect(Rect &rect){
	SDL_SetRenderDrawColor(_renderer, rect.r(), rect.g(), rect.b(), rect.opacity());
	SDL_RenderFillRect(_renderer, &rect._rect);
}
void Window::drawLineRect(Rect& rect) {
	SDL_SetRenderDrawColor(_renderer, rect.r(), rect.g(), rect.b(), rect.opacity());
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



