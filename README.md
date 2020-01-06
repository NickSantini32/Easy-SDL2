# Easy-SDL2
A wrapper class for the SDL2 graphics library to make it more approachable for beginner and intermediate developers

THIS DOCUMENT IS A WORK IN PROGRESS AND IS SUBJECT TO CHANGE AS MORE FEATURES ARE IMPLEMENTED  
THIS IS A VERY EARLY VERSION OF THE PRODUCT

## Windows
 - __Creation:__  
     To create a window you can call one of two constructors with the given parameters  

		  Window(string title, int width, int height)  
		  Window(string title, int width, int height, int x, int y)  

    __Example:__  
	>Window testWin("Test", 400, 400);  

    If no x and y values are passed, the window will be centered.  
    To make a window slightly off center, use the setPos and getPos member functions immediately after construction  

  - __Destruction:__  
    Destruction is handled, you may delete windows as any other stack variable  

  - __Member Functions:__  
  Size and Position
    - __void setPos(int x, int y)__  
      Sets the position of the window (origin at the top left)  
  		Pass SDL_WINDOWPOS_CENTERED as x or y to be centered on that axis  
  	- __void getPos(int* x, int* y)__  
      Fills parameters with X and Y coords of window  
      Pass NULL as either argument if you only need one  
  	- __void hide()__  
      Hides the window  
  	- __void show()__  
      Displays the window  
  	- __int* BackgroundColor()__  
      returns a pointer to an array of size 4 containing r, g, b, and opacity of background  

	 Drawing  
	 __IMPORTANT NOTE: For drawing, when an object is drawn it is placed into a buffer.__
	 __When the refresh method is called, all previous drawings are cleared and everything in the buffer is rendered to the window__  
  	- __void clear()__  
      clears the window
  	- __void drawFullRect(Rect &rect)__  
      Draws a Rect
  	- __void drawLineRect(Rect& rect)__  
      Draws an outline of a Rect
  	- __void refresh()__  
      Presents everything you have drawn
      Put at the end of your loop


## Rectangles (Rects)
  - __Creation:__  
    __NOTE: All r, g, b, and opacity values must be between 0 and 255__  
    - __Rect()__  
      Creates a Rect with a width and height of 0 and a color of black that is fully non- opaque
  	- __Rect(int x, int y, int height, int width)__  
      Creates a Rect with the given width and height and a color of black that is fully non- opaque
  	- __Rect(int x, int y, int height, int width, int r, int g, int b)__  
      Creates a Rect with the given width, height, and color that is fully non- opaque
  	- __Rect(int x, int y, int height, int width, int r, int g, int b, int o)__  
      Creates a Rect with the given width, height, color, and opacity

  - __Destruction:__  
    - Destruction is handled, you may delete Rects as any other stack variable

  - __Member Functions:__  
    - __bool collidesWith(Rect& rect)__  
      returns true if two rects are inside of each other or touching, false if not
      
    - __Accessing and Mutating Member Variables__  
    All of the following methods return an integer reference to their respective values
    Usage is very similar to the vector at function and is as follows:
    Keep in mind these all are methods, not public data, so don't forget your parentheses
    Example:
    	>rect1.x() = 5;  
       	>int val = rect1.x();  
    
	- size and position  
    	int& x()  
    	int& y()  
    	int& width()  
    	int& height()  

	 - colors  
    	int& r()  
    	int& g()  
    	int& b()  
    	int& opacity()  



---V 1.0---

