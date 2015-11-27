/*
 file: Ball.h
 
 **/


#ifndef Ball_H
#define Ball_H

#include "Window.h"
#include "Entity.h"

class Ball: public Entity
{
private:
  // defined object constants
  static const int m_DEFAULT_BALL_XPOS = 1080 / 3;
  static const int m_DEFAULT_BALL_YPOS = 720 / 2;
  const int m_DEFAULT_BALL_WIDTH = 15;
  const int m_DEFAULT_BALL_HEIGHT = 15;
  const int m_DEFAULY_BALL_XVELOCITY = 5;
  const int m_DEFAULY_BALL_YVELOCITY = 5;
  
  SDL_Rect m_Space;
  
public:
  
  // constructor
  Ball(int xVelocity, int yVelocity);
  
  // destructor
  virtual ~Ball();
  
  void handleEvents(SDL_Event event);  // takes action on any incoming events
  void move();  // moves the ball
  void render();  // renders the ball
  void wallCollision(); // checks for collision with wall
  void playerCollision(const SDL_Rect& playerSpace);  // checks for collision with player
  void computerPlayerCollision(const SDL_Rect& computerPlayerSpace);  // checks for collision with computer player
  void resetSpot(); // resets the ball after a player has scored
  inline int getBallXVelocity() const {return m_xVelocity;} // retrieves the x-velocity of the ball
  inline int getBallYVelocity() const {return m_yVelocity;} // retrieves the y-velocity of the ball
  inline SDL_Rect getSpace() const {return m_Space;}  // returns the boxed space of the ball
  
};

#endif  // Ball_H