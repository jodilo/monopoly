#ifndef AUDIO_H
#define AUDIO_H

#include "SDL/SDL_mixer.h"

// game audio
Mix_Music *music = NULL;

  // Sound Effects
Mix_Chunk *roll = NULL;
Mix_Chunk *gamePause = NULL;
Mix_Chunk *purchase = NULL;
Mix_Chunk *trade = NULL;
Mix_Chunk *penalty = NULL;


inline void gameMusic(){
  
  if (Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
    std::cout << "ERROR OPENING AUDIO LIBRARY" << std::endl;

  // load music 
  music = Mix_LoadMUS( "data/monopoly.wav" );
  roll = Mix_LoadWAV( "data/roll.wav" );
  // Play the music
  Mix_PlayMusic(music, -1);

  
}

inline void closeMusic(){
  Mix_FreeChunk( roll );
  Mix_FreeChunk( gamePause );
  Mix_FreeChunk( purchase );
  Mix_FreeChunk( trade );
  
  Mix_FreeMusic( music );

  Mix_CloseAudio();
}


#endif
