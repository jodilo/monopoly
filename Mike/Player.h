#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <deque>
#include <string>
#include "Tile.h"
#include "Board.h"
using namespace std;


class Player
{
	public: 
		Player();			//constructor
		~Player();
		Player(int);
		int getMoney();			//gets player's money total
		int getJail();			//gets player's jail status
		void setJail(bool);			//sets player's jail status
		void setGamePiece(int);		//sets players piece value
		void setName(string);		//sets player's name
		void setPosition(int);		//sets a player's position
		void addTimeJail();		//adds to player's time spent in jail
		string getName();		//gets player's name
		deque<string> getTiles();	//gets player's owned tiles
		deque<string> getHouseTiles();  //gets player's house tiles
		deque<string> getHotelTiles();  //gets player's hotel tiles
		int getIndex();			//gets player's index
		int getPosition();		//gets player's position
		int getTimeJail();		//gets player's time in jail
		void addTile(string);		//adds name of tile to list of player's owned locations
		void addHouseTiles(string);	//adds name of tile to tiles player can build houses on
		void addHotelTiles(string);	//adds name of tile to tiles player can build a hotel on
		void buildTiles(Board);		//builds the list of owned tiles
		void clearDeques();		//will empty houses and hotels deque so there is no overlap in listing where the user can build
		int notOwnTile(string);		//checks if player owns a tile
		void printTiles();		//prints names of tiles player owns
		void goToJail();		//sends player's piece to jail location and changes inJail
		void changeInMoney(int);	//can be used to add or subtract money from totalMoney		
		void advance(int);		//will change piece's position
		void payOffResLife();		//player can pay their way out of jail time
		void changeGOOJ(bool);		//will affect player's GOOJ status
		bool getGOOJ();			//get's player's GOOJ status

	private:
		int totalMoney;	//players total money
		string name;	//player may have option to provide name in future
		int piece;	//integer value representing game piece
		bool inJail;	//bool for player being in jail or not in jail
		bool GOOJ;	//bool for players get out of jail free status
		int timeJail;	//number of turns player has spent in jail

		int index;	//index in array used to store players in game class
			
		int position; 	//used for index as to player's location on board

		deque<string> tilesOwned;	//names of all the tiles the player owns
		deque<string> buildHouses;	//names of all the tiles player can build houses on
		deque<string> buildHotels;	//names of all the tiles player can build hotels on
};
#endif


//need method of implementing positions on board
