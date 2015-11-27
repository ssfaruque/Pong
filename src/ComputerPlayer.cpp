/*
 file: ComputerPlayer.cpp
 
 **/

#include "ComputerPlayer.h"
#include "Window.h"
#include "Ball.h"


ComputerPlayer::ComputerPlayer(int xVelocity, int yVelocity): Entity(xVelocity, yVelocity)
{
  m_Space = {m_DEFAULT_COMPUTERPLAYER_WIDTH, Window::getHeight() / 2, m_DEFAULT_COMPUTERPLAYER_WIDTH, m_DEFAULT_COMPUTERPLAYER_HEIGHT};
}

ComputerPlayer::~ComputerPlayer()
{}



void ComputerPlayer::handleEvents(SDL_Event event)
{
  if(event.key.keysym.sym == SDLK_r)
  {
    m_Space.x = m_DEFAULT_COMPUTERPLAYER_WIDTH;
    m_Space.y = Window::getHeight() / 2;
  }
}


void ComputerPlayer::render()
{
  SDL_SetRenderDrawColor(m_Renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  SDL_RenderFillRect(m_Renderer, &m_Space);
}


bool ComputerPlayer::isAboveBall(const Ball& ball)
{
  SDL_Rect ballSpace = ball.getSpace();
  
  // if ball is heading towards the computer player
  if(ball.getBallXVelocity() < 0)
  {
    const int YmidPointComputerPlayer = m_Space.y + m_Space.h / 2;
    const int YmidPointBall = ballSpace.y + ballSpace.h / 2;
    
    // computer player below ball
    if(YmidPointComputerPlayer <= YmidPointBall)
    {
      if(ballSpace.x < Window::getWidth() / 2)
        m_Space.y += (m_yVelocity + 3);
      
      else
        m_Space.y += m_yVelocity;
      
      return 0;
    }
    
    // computer player above ball
    else
    {
      if(ballSpace.x < Window::getWidth() / 2)
        m_Space.y -= (m_yVelocity + 3);
      
      else
        m_Space.y -= m_yVelocity;
      
      return 1;
    }
  }
  
  // ball not heading back
  else
  {
    return -1;
  }
}


void ComputerPlayer::move(Ball& ball)
{
  // if computer player out of bounds of the wall y-axis
  if(m_Space.y < 0)
    m_Space.y = 0;
  
  if(m_Space.y + m_Space.h > Window::getHeight())
    m_Space.y = Window::getHeight() - m_Space.h;
  
  if(isAboveBall(ball) == 1)
  {
    // ball moves once
    // more likely to lose the point
  }
  
  else if(isAboveBall(ball) == 0)
  {
    // ball moves twice
    // more likely to hit the ball
  }
}


