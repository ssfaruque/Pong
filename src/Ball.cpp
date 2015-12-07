/*
 file: Ball.cpp
 
 **/

#include "Ball.h"

Ball::Ball(int xVelocity, int yVelocity): Entity(xVelocity, yVelocity)
{
  m_Space = {m_DEFAULT_BALL_XPOS, m_DEFAULT_BALL_YPOS, m_DEFAULT_BALL_WIDTH, m_DEFAULT_BALL_HEIGHT};
}

void Ball::handleEvents(SDL_Event event)
{
  if(event.key.keysym.sym == SDLK_r)
  {
    m_Space.x = m_DEFAULT_BALL_XPOS / 4;
    m_Space.y = m_DEFAULT_BALL_YPOS;
  }
}


void Ball::wallCollision()
{
  // if ball goes past walls on x-axis
  if(m_Space.x + m_Space.w <= 0 || m_Space.x >= Window::getWidth())
  {
    // stop the ball from moving
    //m_xVelocity = 0;
    //m_yVelocity = 0;
  }
  
  
  // if ball hits wall on y-axis
  if(m_Space.y <= 0 || m_Space.y + m_Space.h >= Window::getHeight())
  {
    // y component of velocity switches signs
    m_yVelocity = -m_yVelocity;
  }
}


void Ball::playerCollision(const SDL_Rect& playerSpace)
{
  // if ball hits the player
  if((m_Space.x + m_Space.w >= playerSpace.x && m_Space.x + m_Space.w <= playerSpace.x + playerSpace.w) && ((m_Space.y >= playerSpace.y && m_Space.y <= playerSpace.y + playerSpace.h) || (m_Space.y + m_Space.h  >= playerSpace.y && m_Space.y + m_Space.h <= playerSpace.y + playerSpace.h)))
  {
    m_xVelocity = -m_xVelocity;
  }
}


void Ball::computerPlayerCollision(const SDL_Rect& computerPlayerSpace)
{
  // if ball hits the computer player
  if((m_Space.x + m_Space.w >= computerPlayerSpace.x && m_Space.x + m_Space.w <= computerPlayerSpace.x + computerPlayerSpace.w) && ((m_Space.y >= computerPlayerSpace.y && m_Space.y <= computerPlayerSpace.y + computerPlayerSpace.h) || (m_Space.y + m_Space.h  >= computerPlayerSpace.y && m_Space.y + m_Space.h <= computerPlayerSpace.y + computerPlayerSpace.h)))
  {
    m_xVelocity = -m_xVelocity;
  }
}

void Ball::resetSpot()
{
  m_Space.x = m_DEFAULT_BALL_XPOS;
  m_Space.y = m_DEFAULT_BALL_YPOS;
}


Ball::~Ball()
{}


void Ball::move()
{
  m_Space.x += m_xVelocity;
  m_Space.y += m_yVelocity;
}


void Ball::render()
{
  SDL_SetRenderDrawColor(m_Renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  SDL_RenderFillRect(m_Renderer, &m_Space);
}










