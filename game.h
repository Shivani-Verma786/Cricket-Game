#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "team.h" // "player.h", <string>, <vector>


class Game {
public:
	Game();								//the attributes of this constructor initialized in "game.cpp" file //
	//  define all the attributes under public section //
	int playersPerTeam;
	int maxBalls;
	int totalPlayers;
	std::string players[11];

	bool isFirstInnings;				/*this attribute will help us to know that which inning is currently going on.
									    if the first inning is going on then this attribute will be "true" 
									    else if the second inning is going on then it will be "false". */

	Team teamA, teamB;					//Team objects //
	Team* battingTeam, * bowlingTeam;   //Team Pointers//
	Player* batsman, * bowler;			//Pointers for type Player//

	void welcome();                     //declared "welcome" function//
	void showAllPlayers();				//declared "showAllPlayers" function//
	int takeIntegerInput();				//declared "takeIntegerInput" function//
	void selectPlayers();				//declared "selectPlayers" function//

	bool validateSelectedPlayer(int);	//declared "validateSelectedPlayer" function...................................//
			//This function (line no. 30) will accept index of the player as a papameter which needs to be validated..//
			//If the validation succeeds this function will return "True" otherwise it will return "False".............//

	void showTeamPlayers();				//declared "showTeamPlayers" function//
	void toss();						//declared "toss" function//

	void tossChoice(Team);				//declared "tossChoice" function//..this function will accept "Team" as a parameter//
										//and this Team object will actually represent the winning team object//
	
	void startFirstInnings();			//declared "startFirstInnings" function//
	void initializePlayers();			//declared "initializePlayers" function//
	void playInnings();					//declared "playInnings" function//
	void bat();							//declared "bat" function//
	bool validateInningsScore();		//declared "validateInningsScore" function//
	void showGameScorecard();			//declared "showGameScorecard" function//
	void startSecondInnings();			//declared "startSecondInnings" function//
	void matchDetail();			//declared "showMatchSummary" function//
	
};

