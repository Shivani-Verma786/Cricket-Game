#include <string>

class Player {
public:
	Player();  //Default constructor declaration under public section of Player class  //

	//  define all the attributes under public section //
	std::string name; //since, in header file we cannot use any "using" directives statement. that's why we used "std::" //
	int id;
	int runsScored;
	int ballsPlayed;
	int ballsBowled;
	int runsGiven;
	int wicketsTaken;
};

