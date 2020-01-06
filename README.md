## Easy-SDL2
A wrapper class for the SDL2 graphics library to make it more approachable for beginner and intermediate developers

THIS DOCUMENT IS A WORK IN PROGRESS AND IS SUBJECT TO CHANGE AS MORE FEATURES ARE IMPLEMENTED
THIS IS A VERY EARLY VERSION OF THE PRODUCT

- Windows:
  - Creation:
    - To create a window you can call one of two constructors with the given parameters

    Window(string title, int width, int height)
    Window(string title, int width, int height, int x, int y)

    - Example:
    Window testWin("Test", 400, 400);

    - If no x and y values are passed, the window will be centered.
    - To make a window slightly off center, adjust the window position using the setPos member function immediately after construction

  - Destruction:
    - Destruction is handled, you may delete windows as any other stack variable

  - Member Functions:
  - Size and Position
    - void setPos(int x, int y)  
      - Sets the position of the window (origin at the top left)
  		- Pass SDL_WINDOWPOS_CENTERED as x or y to be centered on that axis
  	- void getPos(int* x, int* y)
      - Fills parameters with X and Y coords of window
      - Pass NULL as either argument if you only need one
  	- void hide()
      - Hides the window
  	- void show()
      - Displays the window
  	- int* BackgroundColor()
      - returns a pointer to an array of size 4 containing r, g, b, and opacity of background

  	- Drawing
    - IMPORTANT NOTE: For drawing, when an object is drawn it is placed into a buffer.
    - When the refresh method is called, all previous drawings are cleared and everything in the buffer is rendered to the window
  	- void clear()
      - clears the window
  	- void drawFullRect(Rect &rect)
      - Draws a Rect
  	- void drawLineRect(Rect& rect)
      - Draws an outline of a Rect
  	- void refresh()
      - Presents everything you have drawn
      - Put at the end of your loop


- Rectangles (Rects):
  - Creation:
    - NOTE: All r, g, b, and opacity values must be between 0 and 255
    - Rect()
      - Creates a Rect with a width and height of 0 and a color of black that is fully non- opaque
  	- Rect(int x, int y, int height, int width)
      - Creates a Rect with the given width and height and a color of black that is fully non- opaque
  	- Rect(int x, int y, int height, int width, int r, int g, int b)
      - Creates a Rect with the given width, height, and color that is fully non- opaque
  	- Rect(int x, int y, int height, int width, int r, int g, int b, int o)
      - Creates a Rect with the given width, height, color, and opacity

  - Destruction:
    - Destruction is handled, you may delete Rects as any other stack variable

  - Member Functions:
    - bool collidesWith(Rect& rect)
      - returns true if two rects are inside of each other or touching, false if not

    - All of the following methods return an integer reference to their respective values
    - Usage is very similar to the vector at function and is as follows:
    - Keep in mind these all are methods, not public data, so don't forget your parentheses
      rect1.x() = 5;
      int val = rect1.x();

    	- size and position
    	- int& x()
    	- int& y()
    	- int& width()
    	- int& height()

    	- colors
    	- int& r()
    	- int& g()
    	- int& b()
    	- int& opacity()



---V 1.0---
