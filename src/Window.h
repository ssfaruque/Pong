/*
 file: Window.h
 
 **/


#ifndef Window_H
#define Window_H

#include "SDL2/SDL.h"

class Window
{
private:
  static const unsigned int m_WINDOW_WIDTH = 1080;
  static const unsigned int m_WINDOW_HEIGHT = 720;
  const char* m_WindowName;
  SDL_Window* m_MainWindow;
  static SDL_Renderer* m_Renderer;
  SDL_Event m_WindowEvent;
  bool m_WindowOpen;
  
private:
  bool init();  // initializes all of the systems
  
public:
  
  // default constructor
  Window(const char* windowName);
  
  // destructor
  ~Window();
  
  static inline SDL_Renderer* getRenderer() {return Window::m_Renderer;} // retrieves the renderer
  static inline int getWidth() {return m_WINDOW_WIDTH;}  // retrievs window width
  static inline int getHeight() {return m_WINDOW_HEIGHT;} // retrieves window height
  void clearScreen() const; // clears the window screen
  void update() const;  // updates the window screen
  void handleEvents(SDL_Event event);  // takes action on any incoming events
  inline bool isOpen() const  {return m_WindowOpen;}  // returns the state of the window
  
};

#endif  // Window_H