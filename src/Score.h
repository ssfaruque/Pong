/*
 file: Score.h
 
 **/

#ifndef Score_H
#define Score_H

#include "SDL2_ttf/SDL_ttf.h"

class Score
{
private:
  unsigned int m_PlayerScore;
  unsigned int m_ComputerPlayerScore;
  SDL_Rect m_TextRect;
  TTF_Font* m_font;
  SDL_Color m_TextColor;
  SDL_Renderer* m_Renderer;
  
public:
  
  // Constructor
  Score();
  
  // Destructor
  ~Score();
  
  // updates the score when someone scores a point
  void update(int playerNumber);
  
  // renders the scores to the screen
  void render() const;
  
  // handles the score events
  void handleScoreEvents(SDL_Event event);
  
  // resets the scores for both players
  inline void reset() { m_PlayerScore = 0; m_ComputerPlayerScore = 0; }
  
};

#endif  // Score_H