/*
 file: Player.h
 
 **/


#ifndef Player_H
#define Player_H

#include "Entity.h"

class Player: public Entity
{
private:
  const int m_DEFAULT_PLAYER_WIDTH = 20;
  const int m_DEFAULT_PLAYER_HEIGHT = 75;
  const int m_DEFAULY_PLAYER_XVELOCITY = 0;
  const int m_DEFAULY_PLAYER_YVELOCITY = 2;
  int m_StoredVelocity;
  
  SDL_Rect m_Space;
  
public:
  
  // constructor
  Player(int xVelocity, int yVelocity);
  
  // destructor
  ~Player();
  
  virtual void handleEvents(SDL_Event event);  // takes action on any incoming events
  virtual void move();  // moves the player
  virtual void render();  // renders the player
  inline SDL_Rect getSpace() const  {return m_Space;};  // retrieves the boxed area the player is in
  
};

#endif  // Player_H