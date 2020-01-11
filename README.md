# Easy-SDL2

A wrapper class for the SDL2 graphics library to make it more approachable for beginner and intermediate developers

How to install SDL2: Work in Progress

THIS DOCUMENT IS A WORK IN PROGRESS AND IS SUBJECT TO CHANGE AS MORE FEATURES ARE IMPLEMENTED  
THIS IS A VERY EARLY VERSION OF THE PRODUCT

If you have any questions please thoroughly read this document first  
If you cannot solve your issue or have feature suggestions you may email me at nsant026@ucr.edu

Current state of my to-do list:  
<pre><code>MAYBE
------------------------------------------------------------------------
Look Into System Include Directory As Where To Put SDL2
Add Texture for Rects
------------------------------------------------------------------------

Check greater than or equal to 0 for window and rect dimensions (and add notes about that to doc)

Add SDL2 Installation instructions

Add Window and rect copy constructors

Write destructors

Add Window Events  
	Key Inputs ✔  
	Mouse Inputs ✔  
	Text Inputs	  
	Window Movement   

Add Drawable Lines

Add Drawable Circles
	Compute Circle Collision


BEFORE COMITTING
------------------------------------------------------------------------
Make sure Documentation, cpp, and header have identical methods all in order


FINISHED
------------------------------------------------------------------------

Add Rectangle Collision ✔

Add Window Visibility ✔

Add Window Background Color ✔

Format Documentation ✔

Add Window Resizing ✔

Add checks for r g b and o vals not between 0 and 255 ✔
</code></pre>
# Now For the Documentation  

## Windows
 - __Creation:__  
     To create a window you can call one of two constructors with the given parameters  
__Window(string title, int width, int height)__  
__Window(string title, int width, int height, int x, int y)__  
    Example:
	<pre><code>Window testWin("Test", 400, 400);</code></pre>

    If no x and y values are passed, the window will be centered.  
    To make a window slightly off center, use the setPos and getPos member functions immediately after construction  

  - __Destruction:__  
    Destruction is handled, you may delete windows as any other stack variable  

  - __Member Functions:__  
    - __Size and Position__
      - __void setPos(int x, int y)__  
        Sets the position of the window (origin at the top left)  
    		Pass SDL_WINDOWPOS_CENTERED as x or y to be centered on that axis  
        Pass NULL as either argument if you only need to change one
      - __int getX()__  
	      __int getY()__          
      - __void setSize(int w, int h)__  
        Sets the size of the window  
        Pass NULL as either argument if you only want to change one  
  	 - __int getWidth()__
	   - __int getHeight()__
      - __void hide()__  
        Hides the window  
      - __void show()__  
        Displays the window
      - background color setters  
       __void setR(int r)  
       void setG(int g)  
       void setB(int b)  
       void setA(int a)__  
      (a stands for alpha/opacity)
      - background color getters  
       __int getR()  
      int getG()  
      int getB()  
      int getA()__  

    - __Input Handling__  
      - __bool pollEvents()__  
      Returns whether or not there is a window event (ie: a keypress, mouse movement, or mouse button press) and updates most recent event
      - __int keyPressEvent()__  
      Looks at the most recent event and returns the keycode of the key that was pressed. Returns -1 if the event variable is not a keydown event  
      Keep in mind that while this function does return an int, it is meant to be checked against an enum. The list of all the different enums for each key can be found in the 'SDL_Keycode Value' column on the right of this page https://wiki.libsdl.org/SDL_Keycode  
      Here is an example of usage:    
      <pre><code>switch (testWin.keyPressEvent()) {  
			case SDLK_a: {  
			     cout << "The a key was pressed" << endl;  
            }  
		}</code></pre>
	  - __int keyReleaseEvent()__  
      Identical to the method above but checks for a key up event  
    Overall input handling should be a while loop nested in your game loop. Polling events from the queue is extremely fast and does not hold up the loop it is contained in. Example:
    <pre><code>
    while (true) { //game loop
		  while (testWin.pollEvents()) { //polls events until the queue is empty
			  switch (testWin.keyPressEvent())
			  {
			  case SDLK_a: {
				  cout << "The a key was pressed" << endl;
			  }
			  }
		  }
		testWin.refresh();
	  }
    </code></pre>
      - __int mousePressEvent()__  
      Looks at the most recent event and returns the keycode of the key that was pressed. Returns -1 if the event variable is not a keydown event  
      Returns an enum just like the methods above it, but the list of mouse enums can be found here under the remarks column https://wiki.libsdl.org/SDL_MouseButtonEvent#Remarks
	  - __int mouseReleaseEvent()__  
    Identical to above, but for button release  
 	  - __int getMouseX()__  
    Returns the X of the mouse relative to the top left corner of the window the mouse is on, this is why this is an object method, not a static one
	  - __int getMouseY()__  
    Same as above but for Y  

	 Drawing  
	 __IMPORTANT NOTE: For drawing, when an object is drawn it is placed into a buffer.__
	 __When the refresh method is called, all previous drawings are cleared and everything in the buffer is rendered to the window__  
  	- __void clear()__  
      Clears the window
  	- __void drawFullRect(Rect &rect)__  
      Draws a Rect
  	- __void drawLineRect(Rect& rect)__  
      Draws an outline of a Rect
  	- __void refresh()__  
      Presents everything you have drawn
      Put at the end of your loop


## Rectangles (Rects)
  - __Creation:__  
    __NOTE: All r, g, b, and a values must be between 0 and 255__  
    - __Rect()__  
      Creates a Rect with a width and height of 0 and a color of black that is fully non- opaque
  	- __Rect(int x, int y, int height, int width)__  
      Creates a Rect with the given width and height and a color of black that is fully non- opaque
  	- __Rect(int x, int y, int height, int width, int r, int g, int b)__  
      Creates a Rect with the given width, height, and color that is fully non- opaque
  	- __Rect(int x, int y, int height, int width, int r, int g, int b, int a)__  
      Creates a Rect with the given width, height, color, and opacity

  - __Destruction:__  
    - Destruction is handled, you may delete Rects as any other stack variable

  - __Member Functions:__  
    - __bool collidesWith(Rect& rect)__  
      Returns true if two rects are inside of each other or touching, false if not

    - __Accessing and Mutating Member Variables__  
      - color setters  
     	 __void getR(int r)  
       void getG(int g)  
	     void getB(int b)  
	     void getA(int a)__  
      - color getters  
       __int setR()  
      int setG()  
      int setB()  
      int setA()__  

    All of the following methods return an integer reference to their respective values
    Usage is very similar to the vector at function and is as follows:
    Keep in mind these all are methods, not public data, so don't forget your parentheses
    Example:
    <pre><code>rect1.x() = 5;  
    int val = rect1.x();
    </code></pre>

	- size and position  
    	int& x()  
    	int& y()  
    	int& width()  
    	int& height()  





---V 1.0---
