#ifndef TILE_H
#define TILE_H
#include <iostream>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

class Player;
class Board;

class Tile
{
	public:
		Tile();
		Tile(int, string, int, int, int, bool);
		~Tile();
		void setOwner(int);	//sets an owner for the tile
		int getOwner();		//returns the owner of the tile
		int getGroup();
		int getEffect();	//returns the rent cost
		string getTitle();	//returns title of Tile
		virtual int buy(Player*); //extends interact
		virtual int interact(Player*);	//will be used to interact with player based on where they land
		virtual void payBack(Player*);	//will give player money from another player landing on their property
		virtual void updateEffect(int);	//will modify the rent for a tile based on rules that differ for tile type


		virtual void setGroupOwned(bool);	//sets groupOwned variable, only used for Property inheritance
		virtual bool getGroupOwned();		//gets groupOwned variable, only used for Property inheritance
		virtual int getHouses();		//gets number of houses, only used for Property inheritance
		virtual int getHotels();		//gets number of hotels, only used for Property inheritance
		virtual void addHouses(int);		//adds houses, only used for Property inheritance
		virtual void addHotels(int);		//adds hotels, only used for Property inheritance
		virtual void implosion();		//removes all houses and hotels

		virtual void manDeck(Player*, Board*);	//will be used solely by CardSpaces

		virtual int getCost(); 		//will be used by all tiles that can be purchased
		virtual void setMortgage(bool);		//will be used by all tiles that can be purchased	
		virtual bool getMortgage();		//will be used by all tiles that can be purchased
		

	protected:
		int group;	//group tile is in, used to replace visual colors
		string title;	 //label used for tile
		int owner;	 //int representing index in vector of players as to which player owns tile. If unowned, equals -1
		int moneyEffect; //positive, negative, or zero money effect based on nature and ownership of tile
		int takeCard;	 //0 gets player no card, 1 gets sub card, 2 gets sao card
		bool update;	//tells program whether or not it must give money to the owner		
};
#endif
