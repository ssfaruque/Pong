/*
 file: Entity.cpp
 
 **/


#include <iostream>
#include "Entity.h"
#include "Window.h"

Entity::Entity(int xVelocity, int yVelocity):
m_xVelocity(xVelocity), m_yVelocity(yVelocity)
{
  m_Renderer = Window::getRenderer();
  if(m_Renderer == NULL)
    std::cout << "Renderer failed to load from window class " << std::endl;
}

Entity::~Entity()
{}