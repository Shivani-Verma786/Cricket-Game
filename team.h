#include <vector>
#include "player.h"		// <string>


class Team {
public:
	Team();  //default constructor declaration //

	//  defining all the attributes under public section //
	std::string name;   //for store team name //
	int totalRunsScored;  
	int wicketsLost;
	int totalBallsBowled;
	std::vector<Player> players;
};


