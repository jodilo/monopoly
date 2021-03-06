
#include "Player.h"
using namespace std;

Player::Player()
{
	totalMoney = 1500;
	inJail = 0;
	position = 0;
	index = 0;
}

Player::Player(int locVector)
{
	totalMoney = 1500;
	inJail = 0;
	timeJail = 0;
	position = 0;
	index = locVector;
}

Player::~Player()
{
}

int Player::getMoney()
{
	return totalMoney;
}

int Player::getJail()
{
	return inJail;
}

int Player::getTimeJail()
{
	return timeJail;
}

void Player::addTimeJail()
{
	if(timeJail == 3)
	{
		timeJail = 0;
		inJail = 0;
		return;
	}
	else timeJail++;
}

void Player::setPosition(int location)
{
	position = location;
}


deque<string> Player::getTiles()
{
	return tilesOwned;
}

deque<string> Player::getHouseTiles()
{
	return buildHouses;
}

deque<string> Player::getHotelTiles()
{
	return buildHotels;
}

void Player::goToJail()
{
	inJail = 1;
	timeJail = 0;
	position = 10;
}

void Player::addTile(string newTile)
{
	tilesOwned.push_back(newTile);
}

void Player::addHouseTiles(string newTile)
{
	buildHouses.push_back(newTile);
}

void Player::addHotelTiles(string newTile)
{
	buildHotels.push_back(newTile);
}

void Player::buildTiles(Board b)
{
	tilesOwned.clear();
	for (int i = 0; i < 40; i++){
		if (b.accessSpace(i)->getOwner() == index){
			tilesOwned.push_back(b.accessSpace(i)->getTitle());
		}
	}
	
}

void Player::clearDeques()
{
	buildHouses.clear();
	buildHotels.clear();
}

int Player::notOwnTile(string name){

	for (int i = 0; i < tilesOwned.size(); i++){
		if (name == tilesOwned[i]) return 0;
	}
	return 1;

}

void Player::printTiles()
{
	cout << "Here are the tiles you own: " << endl;
	for(int i = 0; i < tilesOwned.size(); i++)
	{
		cout << tilesOwned[i] << ", ";
	}
	cout << endl;
	cout << "Here are the tiles you can build houses on: " << endl;
	for(int i = 0; i < buildHouses.size(); i++)
	{
		cout << buildHouses[i] << ", ";
	}
	cout << endl;
	cout << "Here are the tiles you can build hotels on: " << endl;
	for(int i = 0; i < buildHotels.size(); i++)
	{
		cout << buildHotels[i] << ", ";
	}
	cout << endl;

}

void Player::setName(string playerName)
{
	name = playerName;
}

string Player::getName()
{
	return name;
}

int Player::getIndex()
{
	return index;
}

void Player::setGamePiece(int choice)
{
	piece = choice;
}

void Player::changeInMoney(int amount)
{
	totalMoney += amount;	//any loss of money can be applied as a negative amount
}

void Player::advance(int spaces)
{
	int newPos;
	newPos = position;
	newPos += spaces;
	if(newPos > 39)
	{
		position = newPos - 40;
		changeInMoney(200);
		cout << "You collect 200 dollars!" << endl;
	}
	else 
	{
		if(newPos < 0)
		{
			position = 40 + newPos;
		}
		else position += spaces;
	}
}

int Player::getPosition()
{
	return position;
}

void Player::changeGOOJ(bool status)
{
	GOOJ = status;
}

void Player::payOffResLife()
{
	inJail = 0;
	timeJail = 0;
	changeInMoney(-50);
}

void Player::setJail(bool status)
{
	if(status == 0)
	{
		timeJail = 0;
	}
	inJail = status;
}

bool Player::getGOOJ()
{
	return GOOJ;
}
