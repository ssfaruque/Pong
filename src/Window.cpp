/*
 file: Window.cpp
 
 **/

#include <iostream>
#include "Window.h"
#include "SDL2_image/SDL_image.h"
#include "SDL2_ttf/SDL_ttf.h"


// initializing window renderer
SDL_Renderer* Window::m_Renderer = nullptr;


//Default constructor
Window::Window(const char* windowName):
m_WindowName(windowName)
{
  // When init fails
  if(!init())
  {
    std::cout << "Initialization failed\n Terminating Program... " << std::endl;
    exit(0);
  }
  
  // When init is successful
  else
  {
  
  m_MainWindow = SDL_CreateWindow(windowName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_WINDOW_WIDTH, m_WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE);
  if(m_MainWindow == NULL)
  {
    std::cout << "Failed to create window" << SDL_GetError() << std::endl;
    m_WindowOpen = false;
  }
  
    Window::m_Renderer = SDL_CreateRenderer(m_MainWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(Window::m_Renderer == NULL)
      std::cout << "Failed to create renderer" << SDL_GetError() << std::endl;
    
    m_WindowOpen = true;
  }
}


// Destructor
Window::~Window()
{
  SDL_DestroyWindow(m_MainWindow);
  SDL_DestroyRenderer(Window::m_Renderer);
  
  SDL_Quit();
  IMG_Quit();
}


bool Window::init()
{
  // initailize SDL
  if(SDL_Init(SDL_INIT_VIDEO) != 0)
  {
    std::cout << "SDL failed to initialize " << std::endl << SDL_GetError();
    return false;
  }
  
  // initialize SDL image
  int imgFlags = IMG_INIT_JPG | IMG_INIT_PNG;
  if(!(IMG_Init(imgFlags) & imgFlags))
  {
    std::cout << "SDL image failed to initialize " << std::endl << IMG_GetError();
    return false;
  }
  
  return true;
}


void Window::clearScreen() const
{
  SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 0xFF);
  SDL_RenderClear(m_Renderer);
}


void Window::update() const
{
  SDL_RenderPresent(Window::m_Renderer);  // updates textures on screen
  //SDL_UpdateWindowSurface(m_MainWindow);  // updates surfaces on screen
}


void Window::handleEvents(SDL_Event event)
{
    if(event.type == SDL_QUIT)
    {
      m_WindowOpen = false;
    }
}












