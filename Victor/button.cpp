#include "button.h"

button::button( int x, int y, int w, int h){
  // set the button attribuets
  box.x = x;
  box.y = y;
  box.w = w;
  box.h = h;

}

void button::handle(){
  // mouse offsets
  int x = 0, y = 0;

  // If the mouse moves
  if( event.type == SDL_MOUSEMOTION ){
    // get offsets
    x = event.motion.x;
    y = event.motion.y;
  }

  // if mouse button pressed
  if (event.type == SDL_MOUSEBUTTONDOWN ){
    // If left mouse button
    if (event.button.button == SDL_BUTTON_LEFT ){
    // get offsets
    x = event.button.x;
    y = event.button.y;
    }
  }

  // If a mouse button was realeased 
  if (event.type == SDL_MOUSEBUTTONUP ){
    // If left mouse button released
    if (event.button.button == SDL_BUTTON_LEFT ){
      // Get mouse offsets
      x = event.button.x;
      y = event.button.y;
    }
  }   
}

/*
void button::show(){
  // show button
  blit(box.x, box.y, screen, clip);
}
*/
