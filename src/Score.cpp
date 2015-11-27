/*
 file: Score.cpp
 
 **/

#include "Score.h"
#include "Window.h"
#include <iostream>
#include <sstream>


Score::Score(): m_PlayerScore(0), m_ComputerPlayerScore(0)
{
  // initialize SDL_ttf
  if(TTF_Init() != 0)
  {
    std::cout << "SDL ttf failed to initialize " << TTF_GetError() << std::endl;
  }
  
  m_font = TTF_OpenFont("../fonts/OpenSans-Regular.ttf", 15);
  if(m_font == nullptr)
  {
    std::cout << "Failed to load SDL font" << std::endl << TTF_GetError();
  }
  m_TextColor = {0xFF, 0xFF, 0xFF};
  m_TextRect = { 400, 0, 1080 / 4, 100 };
  m_Renderer = Window::getRenderer();
}


Score::~Score()
{
  TTF_CloseFont(m_font);
  TTF_Quit();
}


void Score::update(int playerNumber)
{
  // updates the player score
  if(playerNumber == 1)
  {
    ++m_PlayerScore;
  }
  
  // updates the computer player score
  else if(playerNumber == 2)
  {
    ++m_ComputerPlayerScore;
  }
}


void Score::render() const
{
  std::stringstream score("");
  score << m_ComputerPlayerScore << "   |   " << m_PlayerScore;
  SDL_Surface* textSurface = TTF_RenderText_Solid(m_font, score.str().c_str(), m_TextColor);
  SDL_Texture* textTexture = SDL_CreateTextureFromSurface(m_Renderer, textSurface);
  SDL_FreeSurface(textSurface);
  SDL_RenderCopy(m_Renderer, textTexture, nullptr, &m_TextRect);
  
}


// handles the score events
void Score::handleScoreEvents(SDL_Event event)
{
  if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_r)
  {
    reset();
  }
}


