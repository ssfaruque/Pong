/*
 file: ComputerPlayer.h
 
 **/

#ifndef ComputerPlayer_H
#define ComputerPlayer_H

#include "Entity.h"

class Ball;

class ComputerPlayer: public Entity
{
private:
  const int m_DEFAULT_COMPUTERPLAYER_WIDTH = 20;
  const int m_DEFAULT_COMPUTERPLAYER_HEIGHT = 75;
  const int m_DEFAULY_COMPUTERPLAYER_XVELOCITY = 0;
  const int m_DEFAULY_COMPUTERPLAYER_YVELOCITY = 2;
  
  SDL_Rect m_Space;
  
public:
  
  // constructor
  ComputerPlayer(int xVelocity, int yVelocity);
  
  //destructor
  ~ComputerPlayer();
  
  virtual void handleEvents(SDL_Event event);  // takes action on any incoming events
  virtual void render();  // renders the entity
  bool isAboveBall(const Ball& ball); // moves with respect to the midpoint of the ball
  void move(Ball& ball);  //moves the computer player with ball motion
  inline SDL_Rect getSpace() const  {return m_Space;};  // retrieves the boxed area the computer player is in
  
};

#endif  // ComputerPlayer_H