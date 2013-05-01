#include "Game.h"
#include <cstdlib>
#include <ctime>
#include <vector>
#include "menu.h"
#include "audio.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"

using namespace std;

Game::Game(int numPlayers)
{
  
  SDL_Surface *sdlText = NULL;
  TTF_Font *font = TTF_OpenFont("usr/share/fonts/paktype/PakTypeNaqsh.ttf",28);
  SDL_Color textColor = {255,255,255};
  SDL_Color bColor = {0,0,0};
  string text;
  const char *output;
  text= "Welcome to Monopoly!";
  output = text.c_str();
  sdlText= TTF_RenderText_Shaded(font,output,textColor,bColor);
  sdl.apply_surface(0,0,sdlText,screen);
  
	for(int j = 0; j < numPlayers; j++)
	{
		players.push_back(Player(j));
	}

	int i = 0;
	string temp;

	while(i < numPlayers)
	{
		cout << "Player " << (i+1) << " what is your name? ";
		cin >> temp;
	
		players[i].setName(temp);

		i++;
	}

	curPlayer=100; //really big to ensure it resets on first call
	gameBoard;
	//cout << "gameBoard\n";
	sdl;
	//cout << "sdl\n";
	screen = NULL;

	preRollImage = sdl.load_files( "JLo/preRoll.png" );
	//cout << "someimages\n";
	postRollImage = sdl.load_files( "JLo/postRoll.png" ); // loads image w option buttons
	//cout << "images\n";
		
	tile[1] = sdl.load_files("JLo/Properties/PasquerillaEast.png");
	tile[3] = sdl.load_files("JLo/Properties/PasquerillaWest.png");
	tile[5] = sdl.load_files("JLo/Properties/ColemanMorseCenter.png");
	tile[6] = sdl.load_files("JLo/Properties/SeigfriedHall.png");
	tile[8] = sdl.load_files("JLo/Properties/LewisHall.png");
	tile[9] = sdl.load_files("JLo/Properties/CarrolHall.png");
	tile[11] = sdl.load_files("JLo/Properties/FisherHall.png");
	tile[12] = sdl.load_files("JLo/Properties/NorthDiningHall.png");
	tile[13] = sdl.load_files("JLo/Properties/DillonHall.png");
	tile[14] = sdl.load_files("JLo/Properties/AlumniHall.png");
	tile[15] = sdl.load_files("JLo/Properties/Debartolo.png");
	tile[16] = sdl.load_files("JLo/Properties/BadinHall.png");
	tile[18] = sdl.load_files("JLo/Properties/HowardHall.png");
	tile[19] = sdl.load_files("JLo/Properties/LyonsHall.png");
	tile[21] = sdl.load_files("JLo/Properties/RyanHall.png");
	tile[23] = sdl.load_files("JLo/Properties/McGlinnHall.png");
	tile[24] = sdl.load_files("JLo/Properties/WelshFamily.png");
	tile[25] = sdl.load_files("JLo/Properties/Lafortune.png");
	tile[26] = sdl.load_files("JLo/Properties/ONeillHall.png");
	tile[27] = sdl.load_files("JLo/Properties/KeoughHall.png");
	tile[28] = sdl.load_files("JLo/Properties/SouthDiningHall.png");
	tile[29] = sdl.load_files("JLo/Properties/DuncanHall.png");
	tile[31] = sdl.load_files("JLo/Properties/ComptonIceArena.png");
	tile[32] = sdl.load_files("JLo/Properties/JACC.png");
	tile[34] = sdl.load_files("JLo/Properties/NotreDameStadium.png");
	tile[35] = sdl.load_files("JLo/Properties/Hesburgh.png");
	tile[37] = sdl.load_files("JLo/Properties/MainBuilding.png");
	tile[39] = sdl.load_files("JLo/Properties/NotreDameStadium.png");

	SAOcard[0] = sdl.load_files("JLo/SAO/BengalBouts.png");
	SAOcard[1] = sdl.load_files("JLo/SAO/BarakaBouts.png");
        SAOcard[2] = sdl.load_files("JLo/SAO/MBBall.png");
        SAOcard[3] = sdl.load_files("JLo/SAO/DomeDate.png");
        SAOcard[4] = sdl.load_files("JLo/SAO/Football.png");
        SAOcard[5] = sdl.load_files("JLo/SAO/RectorGotYourBack.png");
        SAOcard[6] = sdl.load_files("JLo/SAO/BedBugs.png");
        SAOcard[7] = sdl.load_files("JLo/SAO/TaxiFare.png");
        SAOcard[8] = sdl.load_files("JLo/SAO/EddyStreet.png");
        SAOcard[9] = sdl.load_files("JLo/SAO/PayDay.png");
	SAOcard[10] = sdl.load_files("JLo/SAO/FootballSeasonPass.png");
        SAOcard[11] = sdl.load_files("JLo/SAO/ClubDues.png");
        SAOcard[12] = sdl.load_files("JLo/SAO/TriviaNight.png");


	SUBcard[0] = sdl.load_files("JLo/SUB/Raffle.png");
	SUBcard[1] = sdl.load_files("JLo/SUB/SUBMovie.png");
	SUBcard[2] = sdl.load_files("JLo/SUB/DPAC.png");
	SUBcard[3] = sdl.load_files("JLo/SUB/Legends.png");
	SUBcard[4] = sdl.load_files("JLo/SUB/Reckers.png");
	SUBcard[5] = sdl.load_files("JLo/SUB/Grotto.png");
	SUBcard[6] = sdl.load_files("JLo/SUB/GetOutofJail.png");
	SUBcard[7] = sdl.load_files("JLo/SUB/Chicago.png");
	SUBcard[8] = sdl.load_files("JLo/SUB/BarTab.png");
	SUBcard[9] = sdl.load_files("JLo/SUB/BandStipend.png");
	SUBcard[10] = sdl.load_files("JLo/SUB/Tow.png");
	SUBcard[11] = sdl.load_files("JLo/SUB/WasteFreeWednesday.png");
	SUBcard[12] = sdl.load_files("JLo/SUB/Squirrel.png");
	SUBcard[13] = sdl.load_files("JLo/SUB/Prospy.png");
}

Game::~Game()
{
}

int Game::rollDie(Player* current)
{
	int firstRoll;
	int secondRoll;
	int move;
	
	srand(time(NULL));
	firstRoll = rand()%6 + 1;
	secondRoll = rand()%6 + 1;

	move = firstRoll + secondRoll;

	cout << current->getName() << ", you rolled a " << move << endl;

	current->advance(move);
	return move;
}

void Game::turn()
{
	curPlayer = curPlayer++;
	if (curPlayer >= players.size()) curPlayer = 0;
	playerTurn(&players[curPlayer]);
	cout << endl << endl;
}

void Game::playerTurn(Player* current)
{
	char response;

	gameBoard.checkDecks();			//checks SAO and SUB decks to make sure they aren't empty. If so rebuilds the deck
	gameBoard.checkGroupsProp();		//checks the properties to see if an entire group is owned by a player
	gameBoard.updateRentRR();		//updates the rent of the railroads based on how many a player owns
	gameBoard.updateEffects(0);		//rolls through entire board and updates effects of properties
	buildCheck(current);			//updates the deque of property titles player can build a house on
	jailTime(current);			//checks for any behavior involving jail

	response = 'z'; //random initialize

	while (response != 'r'){

		sdl.apply_surface(150, 500, preRollImage, screen);

		cout << current->getName() << " it is your turn" << endl;
		cout << "Your current money is: $" << current->getMoney() << endl;
		current->printTiles();

		cout << "What would you like to do? (R)oll, (P)lay, (T)rade: \n";	//all 3 options presented, although trade currently does not function properly

		response = sdl.getResponse();
		
		switch(response)
		{
			case 'r':
				playerPostRoll(current);
				break;

			case 'b':
				build(current);
			break;
			case 'm':
				mortgage(current);
			break;
			case 'q':
				return;
			case 'v':
				//view;
			break;

		}
	}

}

void Game::playerPostRoll(Player* current){

	int output;	//stores index value from interact function
	int playerRoll;		//stores value of player's roll

	char response;
	
	playerRoll = rollDie(current);
	gameBoard.updateEffects(playerRoll);

	SDL_Surface *disp;

	if(gameBoard.accessSpace(current->getPosition())->getTitle() == "S.U.B.")
	{
		gameBoard.accessSpace(current->getPosition())->manDeck(current, &gameBoard);
		disp = SUBcard[gameBoard.getCardNum(1)];
		cout << gameBoard.getCardNum(1) << endl;
	}
	else if (gameBoard.accessSpace(current->getPosition())->getTitle() == "S.A.O."){
		gameBoard.accessSpace(current->getPosition())->manDeck(current, &gameBoard);
                disp = SAOcard[gameBoard.getCardNum(2)];
		cout << gameBoard.getCardNum(2) << endl;
	} else {
		disp = tile[current->getPosition()];
	}
	//	cout << "right before postRollImage" << endl;	
        sdl.apply_surface(150, 150, postRollImage, screen);
        sdl.apply_surface(160, 80, disp, screen);
	output = gameBoard.accessSpace(current->getPosition())->interact(current);	//this vomit is supposed to print out the information from the tile
	if(output != -1)
	{
		gameBoard.accessSpace(current->getPosition())->payBack(&players[output]);	//this vomit awards a player money if someone lands on their property
	}

	response = 'z';
	while (response != 'o'){
		response = sdl.getResponsePostPlay();
		switch (response){
			case 'b':
				//buy
				break;
			case 'v':
				//view
				break;
			case 'm':
				mortgage(current);
				break;
			case 'q':
				return;
			case 't':
				trade(current);
				break;
		}
	}

}

void Game::buildCheck(Player* current)
{
	deque<string> props;
	props = current->getTiles();
	current->clearDeques();
	
	for(int i = 0; i < props.size(); i++)
	{
		for(int j = 0; j < 40; j++)
		{
			if(props[i] == gameBoard.accessSpace(j)->getTitle())
			{
				if(gameBoard.accessSpace(j)->getGroup() > 0 && gameBoard.accessSpace(j)->getGroup() <= 8)
				{
					if(gameBoard.accessSpace(j)->getGroupOwned() == 1)
					{
						if(gameBoard.accessSpace(j)->getHouses() < 4 && gameBoard.accessSpace(j)->getHotels() == 0)
						{
							current->addHouseTiles(props[i]);
						}
						if(gameBoard.accessSpace(j)->getHouses() == 4)
						{
							current->addHotelTiles(props[i]);
						}
					}
				}
			}
		}
	}
}	

void Game::build(Player* current)		//pretty sure getline is causing a weird print error in this function somewhere as well
{

	int select;		//player selects building choice
	int loop = 1;		//controls while loop
	int houseLoop = 1;	//controls house building loop
	int hotelLoop = 1;
	int housesAdded;
	int hotelsAdded;
	string location;	//where the user wants to build

	deque<string> houseOptions;
	deque<string> hotelOptions;

	while(loop)
	{
		houseOptions = current->getHouseTiles();
		hotelOptions = current->getHotelTiles();
		houseLoop = 1;
		hotelLoop = 1;
	
		cout << "What would you like to build? 1 for houses ($50 each), 2 for hotels ($100 each), 3 to exit";
		cin >> select;
		if(select == 1)
		{
			if(houseOptions.empty() != 1)
			{
				while(houseLoop)
				{	
					cout << "Where would you like to build a house? ";
					for(int i = 0; i < houseOptions.size(); i++)
					{
						cout << houseOptions[i] << ", ";
					}
					cout << endl;
					getline(cin, location);

					for(int i = 0; i < houseOptions.size(); i++)
					{
						if(location == houseOptions[i])
						{
							for(int j = 0; j < 40; j++)
							{
								if(location == gameBoard.accessSpace(j)->getTitle())
								{
									cout << "There are " << gameBoard.accessSpace(j)->getHouses() << " houses here. How many would you like to add? (Max 4)";
									cin >> housesAdded;
									if(current->getMoney() <= 50*housesAdded)
									{
										cout << "You can't afford that many houses!" << endl;
										houseLoop = 0;
										break;
									}
									gameBoard.accessSpace(j)->addHouses(housesAdded);
									current->changeInMoney((-50) * housesAdded);
									houseLoop = 0;
								}
							}
						}
					}
					if(houseLoop != 0)
					{
						cout << "That is not somewhere you can build a house" << endl;
					}
				}
			}
			else
			{
				cout << "You can't build houses anywhere" << endl;
			}	
		}
		if(select == 2)
		{
			if(hotelOptions.empty() != 1)
			{
				while(hotelLoop)
				{	
					cout << "Where would you like to build a hotel? ";
					for(int i = 0; i < hotelOptions.size(); i++)
					{
						cout << hotelOptions[i] << ", ";
					}
					cout << endl;
					getline(cin, location);

					for(int i = 0; i < hotelOptions.size(); i++)
					{
						if(location == hotelOptions[i])
						{
							for(int j = 0; j < 40; j++)
							{
								if(location == gameBoard.accessSpace(j)->getTitle())
								{
									cout << "There are " << gameBoard.accessSpace(j)->getHotels() << " hotels here. How many would you like to add? (Max 1)";
									cin >> hotelsAdded;
									if(current->getMoney() <= 100*hotelsAdded)
									{
										cout << "You can't afford to buy a hotel!" << endl;
										hotelLoop = 0;
										break;
									}
									gameBoard.accessSpace(j)->addHotels(hotelsAdded);
									gameBoard.accessSpace(j)->addHouses(-4);
									current->changeInMoney(-100);
									hotelLoop = 0;
								}
							}
						}
					}
					if(hotelLoop != 0)
					{
						cout << "That is not somewhere you can build a hotel" << endl;
					}
				}
			}
			else
			{
				cout << "You can't build hotels anywhere" << endl;
			}	
		}
		if(select == 3)
		{
			return;
		}
	}
}

void Game::mortgage(Player* current)
{
	string place;
	deque<string> owned;
	int moveOn;	//is set to 1 if the player picks a valid tile
	int mortgageReturn;	//amount player receives for mortgaging
	char mortgageYN;	//players final decision	
	int j;
	bool status;		//bool representing mortgaged status of selected location

	owned = current->getTiles();

	current->printTiles();
	cout << "What would you like to mortgage or unmortgage?";
	getline(cin, place);

	for(int i = 0; i < owned.size(); i++)
	{
		if(place == owned[i])
		{
			moveOn = 1;
		}
	}

	if(moveOn == 0)
	{
		cout << "Sorry! That's not a tile you own!" << endl;
		return;
	}
	else if(moveOn == 1)
	{
		for(j = 0; j < 40; j++)
		{
			if(gameBoard.accessSpace(j)->getTitle() == place)
			{
				mortgageReturn = (gameBoard.accessSpace(j)->getCost())/2;
				status = gameBoard.accessSpace(j)->getMortgage();
			}
		}
		
		if(status == 0)
		{
			cout << "Would you like to mortgage " << place << " and gain " << mortgageReturn << "? (y/n)";
			cin >> mortgageYN;
	
			if(mortgageYN == 'n') return;
			if(mortgageYN == 'y')
			{
				current->changeInMoney(mortgageReturn);
				gameBoard.accessSpace(j)->setMortgage(1);
			}
		}
		else if(status == 1 && current->getMoney() > mortgageReturn)
		{
			cout << "Would you like to unmortgage " << place << "? It will cost you " << mortgageReturn << ". (y/n)";
			cin >> mortgageYN;
	
			if(mortgageYN == 'n') return;
			if(mortgageYN == 'y')
			{
				current->changeInMoney(-mortgageReturn);
				gameBoard.accessSpace(j)->setMortgage(0);
			}
		}
		else if(status == 1 && current->getMoney() <= mortgageReturn)
		{
			cout << "This location is mortgaged, and you can't afford to unmortgage it!" << endl;
		}

	}
}

	
int Game::getPlayers(){
	return numPlayers;
}

int Game::getCurrentPlayer(){
	return curPlayer;
}

int Game::getPlayerLocation(int player){
	return ((&players[curPlayer])->getPosition());
}

void Game::trade(Player* current)		//this function was thrown together somewhat carelessly, I'm having problems with getline
{
	string recipient;
	int recipIndex;
	int offer;
	int request;
	char answer;
	deque<string> options;
	deque<string> playerOwns;

	cout << current->getName() << ", who would you like to trade with? Please input their number" << endl;
	
	for(int i = 0; i < players.size()-1; i++)
	{
		cout << players[i].getName() << ": (" << players[i].getIndex() << ")" << endl;
	}

	cin >> recipIndex;
	cout << "Here is what " << players[recipIndex].getName() << " owns: " << endl;
	options = players[recipIndex].getTiles();
	playerOwns = current->getTiles();

	for(int i = 0; i < options.size()-1; i++)
	{
		cout << options[i] << ": " << i << endl;
	}

	cout << "What would you like to trade for? Please enter the number associated with the name";
	cin >> request;

	cout << "Here is what you can offer. Enter the number of the location you'd like to offer in return" << endl;

	for(int i = 0; i < playerOwns.size()-1; i++)
	{
		cout << playerOwns[i] << ": " << i << endl;
	}

	cout << "Your offer: ";
	cin >> offer; 

	cout << players[recipIndex].getName() << ", do you accept this trade? " << playerOwns[offer] << " for " << options[request] << "? (y/n)";
	cin >> answer;

	if(answer == 'n') return;
	else if(answer == 'y')
	{
		cout << "Congratulations! Trade completed!" << endl;
		for(int i = 0; i < 40; i++)
		{
			if(gameBoard.accessSpace(i)->getTitle() == options[request])
			{
				gameBoard.accessSpace(i)->setOwner(current->getIndex());
			}
			if(gameBoard.accessSpace(i)->getTitle() == playerOwns[offer])
			{
				gameBoard.accessSpace(i)->setOwner(recipIndex);
			}
		}
	}
}

int Game::gameOver()
{
	for(int i = 0; i < players.size(); i++)
	{
		if(players[i].getMoney() <= 0 && (players[i].getTiles()).empty())
		{
			cout << players[i].getName() << ", you have run out of money! You are eliminated from the game! Thanks for playing!" << endl;
			players.erase(players.begin()+i);
		}
		else if(players[i].getMoney() <= 0 && !((players[i].getTiles().empty())))
		{
			cout << players[i].getName() << ", you have no money, but you do have properties! You will be sent to the mortgaging screen. Not mortgaging will result in your elimination" << endl;
			mortgage(&players[i]);
			if(players[i].getMoney() <= 0)
			{
				cout << "You still have no money! You are eliminated from the game! Thanks for playing!" << endl;
				players.erase(players.begin()+i);
			}
		}
	}

	if(players.size() == 1)
	{
		cout << "Congratulations " << players[0].getName() << ", you are the only player remaining! You (and capitalism) win!" << endl;
		return 1;
	}
	else
	{
		return 0;
	}
	
}

void Game::jailTime(Player* current)
{
	char pay;

	if(current->getJail() == 1)
	{
			current->addTimeJail();
			if(current->getTimeJail() != 0)
			{
				cout << current->getName() << ", you are stuck at res life!" << endl;
				if(current->getMoney() > 50)
				{
					cout << "Would you like to pay off the service hours? (y/n)";
					pay = sdl.getResponse();
					if(pay == 'y')
					{
						current->payOffResLife();
					}
					else
					{
						cout << "You lose a turn!" << endl;
						return;
					}
				}
				else
				{
					cout << "You lose a turn!" << endl;
					return;
				}
			}
			else if(current->getTimeJail() == 0)
			{
				cout << current->getName() << ", you're out of res life!" << endl;
				current->addTimeJail();
			}
	}
}

void Game::addScreen(SDL_Surface *point){
	screen = point;
}