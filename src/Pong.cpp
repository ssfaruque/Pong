/*
 file: Pong.cpp
 
 **/

#include "Ball.h"
#include "Player.h"
#include "ComputerPlayer.h"
#include "Score.h"


int main()
{
  
  Window window("Pong");
  Ball ball(14,14);
  Player player(0, 10);
  ComputerPlayer computerPlayer(0,10);
  Score scoreBoard;
  
  SDL_Event event;
  
  while(window.isOpen())
  {
    window.clearScreen();
    
    while(SDL_PollEvent(&event) > 0)
    {
      window.handleEvents(event);
      ball.handleEvents(event);
      player.handleEvents(event);
      computerPlayer.handleEvents(event);
      scoreBoard.handleScoreEvents(event);
      
    }
    
    if(ball.getSpace().x < 0)
    {
      //  player scores
      scoreBoard.update(1);
      SDL_Delay(1000);
      ball.resetSpot();
    }
    
    else if(ball.getSpace().x + ball.getSpace().w > Window::getWidth())
    {
      // computer player scores
      scoreBoard.update(2);
      SDL_Delay(1000);
      ball.resetSpot();
    }
    
    ball.move();
    ball.wallCollision();
    ball.playerCollision(player.getSpace());
    ball.computerPlayerCollision(computerPlayer.getSpace());
    
    player.move();
    computerPlayer.move(ball);
    
    scoreBoard.render();
    ball.render();
    player.render();
    computerPlayer.render();
    
    window.update();
  }
  
  return 0;
}

