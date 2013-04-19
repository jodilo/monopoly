#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Tile.h"
#include "Board.h"
#include "Property.h"

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

using namespace std;

class Game
{
	public:
		Game();
		~Game();
		void turn(SDL_Event &event);
		void playerTurn(Player*, SDL_Event &event);
		int rollDie(Player*);
		void buildCheck(Player*);
		void build(Player*);
		int getPlayers();
		int getCurrentPlayer();
		int getPlayerLocation(int);
		void trade(Player*);
		void gameOver();

	private:
		char getResponse(SDL_Event &event);
		int numPlayers;
		int curPlayer;
		vector<Player> players;
		Board gameBoard;
};
#endif
