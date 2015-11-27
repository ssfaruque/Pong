/*
 file: Entity.h
 
**/

#ifndef Entity_H
#define Entity_H

#include "SDL2/SDL.h"

class Entity
{
protected:
  int m_xVelocity;
  int m_yVelocity;
  SDL_Renderer* m_Renderer;
  
public:
  
  // constructor
  Entity(int xVelocity, int yVelocity);
  
  // destructor
  virtual ~Entity();
  
  virtual void handleEvents(SDL_Event event) = 0;  // takes action on any incoming events
  virtual void render() = 0;  // renders the entity
};

#endif  // Entity_H