/*
 file: Player.cpp
 
 **/


#include "Player.h"
#include "Window.h"

Player::Player(int xVelocity, int yVelocity): Entity(xVelocity, yVelocity), m_StoredVelocity(yVelocity)
{
  m_Space = {Window::getWidth() - (2 * m_DEFAULT_PLAYER_WIDTH), Window::getHeight() / 2, m_DEFAULT_PLAYER_WIDTH, m_DEFAULT_PLAYER_HEIGHT};
  
}


Player::~Player()
{}


void Player::handleEvents(SDL_Event event)
{
  if(event.key.keysym.sym == SDLK_r)
  {
    m_Space.x = Window::getWidth() - (2 * m_DEFAULT_PLAYER_WIDTH);
    m_Space.y = Window::getHeight() / 2;
  }
}


void Player::move()
{
  // checks for keyboard input
  const Uint8* keyState = SDL_GetKeyboardState(NULL);
  if(keyState[SDL_SCANCODE_UP])
  {
    // checks for collisions with wall on y-axis
    if(m_Space.y >= 0)
    {
      m_Space.y -= m_yVelocity;
    }
  }
  
  else if(keyState[SDL_SCANCODE_DOWN])
  {
    // checks for collisions with wall on y-axis
    if(m_Space.y + m_Space.h <= Window::getHeight())
    {
      m_Space.y += m_yVelocity;
    }
  }
}


void Player::render()
{
  SDL_SetRenderDrawColor(m_Renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  SDL_RenderFillRect(m_Renderer, &m_Space);
}







