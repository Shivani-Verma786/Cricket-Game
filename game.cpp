#include "game.h"							// here directly include <iostream> //
using namespace std;

/* Start First step for "Default constructor definition and  initializing attributes ................................ */

Game::Game()								//Default constructor definition of Game //
{
	/* ..............initializing attributes. */
	playersPerTeam = 4;
	maxBalls = 6;
	totalPlayers = 11;

	players[0] = "Virat";
	players[1] = "Rohit";
	players[2] = "Dhawan";
	players[3] = "Pant";
	players[4] = "Dhoni";
	players[5] = "Sachin";
	players[6] = "Jadeja";
	players[7] = "Hardik";
	players[8] = "Bumrah";
	players[9] = "Kapil";
	players[10] = "Ishant";

	isFirstInnings = false;
	teamA.name = "Team-A";
	teamB.name = "Team-B";
}

/* Start Second Step where we will show "WELCOME - MESSAGE"........................................................... */

void Game::welcome() 
{

	cout << "                                                        " << endl;
	cout << "                   _____________________________________" << endl;
	cout << "                  |                                     |" << endl;
	cout << "                  |************** CRIC-IN **************|" << endl;
	cout << "                  |                                     |" << endl;
	cout << "                  |   Welcome to Virtual Cricket Game   |" << endl;
	cout << "                  |*************************************|" << endl;
	cout << "                  |_____________________________________|" << endl;
	cout << endl << endl;
	cout << "             __________________________________________________" << endl;
	cout << "            |                                                  |" << endl;
	cout << "            |******************INSTRUCTION ********************|" << endl;
	cout << "            |                                                  |" << endl;
	cout << "            | 1. Create 2 teams (Team-A and Team-B with 4      |" << endl;
	cout << "            |    players each) from a given pool of 11 players.|" << endl;
	cout << "            | 2. Lead the toss and decide the choice of play.  |" << endl;
	cout << "            | 3. Each innings will be of 6 balls.              |" << endl;
	cout << "            |**************************************************|" << endl;
	cout << "            |__________________________________________________|" << endl;
}

/* Start Third Step for Show all players name......................................................................... */

void Game::showAllPlayers()
{

	cout << endl;
	cout << "                    _____________________________________" << endl;
	cout << "                   |                                     |" << endl;
	cout << "                   |~~~~~~~~~ Pool of Players ~~~~~~~~~~~|" << endl;
	cout << "                   |_____________________________________|" << endl;
	cout << endl << endl;

	for (int i = 0; i < totalPlayers; i++)
	{
		cout << "\t\t\t\t  [" << i << "] " << players[i] << endl;
	}
}

/*Start Fourth Step where we will take integer input for select players............................................... */

int Game::takeIntegerInput()
{

	int n;

	while (!(cin >> n)) //this condition will be show "false" ....for start second inning//
	{

		cin.clear();  //it's clear previous input //
		cin.ignore(numeric_limits<streamsize>::max(), '\n');  //for invalid input  //
		cout << "Invalid input! Please try again with valid input: ";
	}

	return n;
}

/*Start Fifth Step to Store all the validate selected players in an array index after checking id or the index value....*/

bool Game::validateSelectedPlayer(int index)
{

	int n;
	vector<Player> players; //To store all the players objects. //

	players = teamA.players;
	n = players.size();
	for (int i = 0; i < n; i++) {
		if (players[i].id == index) {
			return false;
		}
	}

	players = teamB.players;//in case of "teamB" if id or index will match then again immediately it returns "false" //
	n = players.size();
	for (int i = 0; i < n; i++) {
		if (players[i].id == index) {
			return false;
		}
	}

	return true;
}

//Start Sixth Step which shows us that By mistake, if we select a player index twice......//

void Game::selectPlayers()
{

	cout << endl;
	cout << "            ------------------------------------------------" << endl;
	cout << "            |========== Create Team-A and Team-B ==========|" << endl;
	cout << "            ------------------------------------------------" << endl;

	for (int i = 0; i < playersPerTeam; i++)
	{

		// Add player to team A  //

	teamASelection:
		cout << endl;

		//if the entered index value is invalid then these two statements (line number 139-140) should be again executed.//
		//that's why we used goto statement (teamASelection:)//
		cout << endl << "Select player " << i + 1 << " of Team A - ";
		int playerIndexTeamA = takeIntegerInput();

		//if part -> if the user entered invalid index value then this message will be print..//
		if (playerIndexTeamA < 0 || playerIndexTeamA > 10)
		{
			cout << endl << "Please select from the given players" << endl;
			//after check if condition the flow of execution will be transfer to the goto level (line number -> 133) //
			goto teamASelection;    // defined the goto statement..// 
		}

		//Else if part -> Iam calling "validateSelectedPlayer" function to check if the player can be added// 
		//the team or not and for that i am passing the index of the player being demanded in the integer user input//
		//(in case validation fails it returns "True"..due to the use of "NOT operator" ......................//
		//now check the content of "validateSelectedPlayer" function. (line no -> ......................//
		else if (!validateSelectedPlayer(playerIndexTeamA))
		{
			cout << endl << "Player has been already selected. Please select other player" << endl;
			goto teamASelection;
		}

		//Else part -> If the user has entered a valid index value to Let's add the player to the team//
		else
		{
			Player teamAPlayer;
			teamAPlayer.id = playerIndexTeamA;
			teamAPlayer.name = players[playerIndexTeamA];
			teamA.players.push_back(teamAPlayer);
		}

		// Add player to team B  //
		//Like the teamA, condition will also be checked in teamB. //

	teamBSelection:

		cout << endl << "Select player " << i + 1 << " of Team B - ";
		int playerIndexTeamB = takeIntegerInput();

		if (playerIndexTeamB < 0 || playerIndexTeamB > 10)
		{
			cout << endl << "Please select from the given players" << endl;
			goto teamBSelection;
		}
		else if (!validateSelectedPlayer(playerIndexTeamB))
		{
			cout << endl << "Player has been already selected. Please select other player" << endl;
			goto teamBSelection;
		}
		else
		{
			Player teamBPlayer;
			teamBPlayer.name = players[playerIndexTeamB];
			teamB.players.push_back(teamBPlayer);
		}
	}
}

/*Start Seventh step which will Show players name of each team.........................................................*/

void Game::showTeamPlayers()
{
	vector<Player> teamAPlayers = teamA.players;  //retriving all the added players of teamA //
	vector<Player> teamBPlayers = teamB.players;  //retriving all the added players of teamB //

	cout << endl << endl;
	cout << "--------------------------\t\t--------------------------" << endl;
	cout << "|=======  Team-A  =======|\t\t|=======  Team-B  =======|" << endl;
	cout << "--------------------------\t\t--------------------------" << endl;

	//Using for loop, which displays all the players of each team //
	for (int i = 0; i < playersPerTeam; i++) {
		cout << "|\t" << "[" << i << "] " << teamAPlayers[i].name << "\t |"
			<< "\t\t"
			<< "|\t" << "[" << i << "] " << teamBPlayers[i].name << "\t |" << endl;
	}
	cout << "--------------------------\t\t--------------------------" << endl << endl;
}

// 8th Step -> In toss function we use random function and switch case statement to add the toss functionality.........//

void Game::toss()
{
	cout << endl;
	cout << "                    _____________________________________" << endl;
	cout << "                   |                                     |" << endl;
	cout << "                   |============ Let's Toss  ============|" << endl;
	cout << "                   |_____________________________________|" << endl << endl;

	cout << "                              Tossing the coin..." << endl << endl;

	srand(time(NULL));
	int randomValue = rand() % 2;	/* By using random function we can generate either 0 or 1.
									if 0 comes then "teamA" wins the toss and if 1 comes then "teamB" wins the toss*/

	switch (randomValue) {
	case 0:
		cout << "                          Team-A won the toss" << endl << endl;
		tossChoice(teamA); //if teamA win the toss then it call the "tossChoice" function and pass "teamA"as a parameter//
		break;
	case 1:
		cout << "                          Team-B won the toss" << endl << endl;
		tossChoice(teamB); //if teamB win the toss then it call the "tossChoice" function and pass "teamB"as a parameter//
		break;
	}
}

// 9th Step -> In this coding section, the winner twam will decide whether they will bat first or bowling?...........//

void Game::tossChoice(Team tossWinnerTeam)
{

	cout << "Enter 1 to bat or 2 to bowl first. " << endl
		<< "1. Bat" << endl
		<< "2. Bowl " << endl << endl << "your choice =  ";

	int tossInput = takeIntegerInput();

	cin.ignore(numeric_limits<streamsize>::max(), '\n');  //used for clear buffer input memory //

	switch (tossInput) {
	case 1:
		cout << endl << tossWinnerTeam.name << " won the toss and elected to bat first" << endl << endl;

		if (tossWinnerTeam.name.compare("Team-A") == 0)  //if teamA is the toss winner and if they elects to bat first//
														//then make the "battingTeam" pointer point to the "teamA" object//
														//and "bowingTeam" pointer point to the "teamB" object//
		{
			battingTeam = &teamA;
			bowlingTeam = &teamB;
		}
		else 
		{	/* else Team-B is the toss winner and if they elects to bat first then make the "battingTeam" pointer point
			  to the "teamB" object and "bowingTeam" pointer point to the "teamA" object */
						 
			battingTeam = &teamB;
			bowlingTeam = &teamA;
		}

		break;
		case 2:
	        cout << endl << tossWinnerTeam.name << " won the toss and choose to bowl first" << endl << endl;

			if (tossWinnerTeam.name.compare("Team-A") == 0) /*Similarly in 2nd case, if teamA is the toss winner and if they
															elects to bowling first then make the "bowlingTeam" pointer point to
														 the "teamA" object and "battingTeam" pointer point to the "teamB" object*/
			{
				 bowlingTeam = &teamA;
				 battingTeam = &teamB;
		    }
			else	/*if teamB is the toss winner and if they elects to bowling first then make the "bowlingTeam" pointer
					 point to the "teamB" object and "battingTeam" pointer point to the "teamA" object */
			{
				bowlingTeam = &teamB;
				battingTeam = &teamA;
			}															
			break;
		default:
			cout << endl << "Invalid input. Please try again:" << endl << endl;
			tossChoice(tossWinnerTeam);
																																															  
	}
}

// 10th Step -> For first inning we will initialize the batsman and bowler//

void Game::initializePlayers()
{
    // Choose batsman and bowler: Initialize *batsman and *bowler //
	batsman = &battingTeam->players[0];  
	bowler = &bowlingTeam->players[0];

	cout << battingTeam->name << " - " << batsman->name << " is batting " << endl;
	cout << bowlingTeam->name << " - " << bowler->name << " is bowling " << endl << endl;
}
// 11th Step -> .......................................................................................................//
void Game::playInnings() {

	for (int i = 0; i < maxBalls; i++)   //This for loop will be executed six times //
	{

		cout << "Press Enter to bowl...";  //The user needs press Enter key for each delivery//
		getchar();
		cout << "Bowling..." << endl;

		bat();   //within this function we will get the run scored by the batsman after each delivery//

		if (!validateInningsScore())
		{
			break;
		}
	}
}
//12th step ->..........................................................................................................//
void Game::bat()
{

	srand(time(NULL));
	int runsScored = rand() % 7;  //we used random function to generate runs from 0 to 6  //

	// Update batting team and batsman score ......................................................//

	 /*updating batsman pointer and access the attribute of runScored and then update the runScored by adding 
	  this(line no-336) runscored variable*/
	batsman->runsScored = batsman->runsScored + runsScored;

	//Similarly we will update the total runScored by the batting team until this delivery//
	battingTeam->totalRunsScored = battingTeam->totalRunsScored + runsScored;

	//and finally, we will update the balls played by the batsman //
	batsman->ballsPlayed = batsman->ballsPlayed + 1;

	// Update bowling team and bowler score..............................................................//

	//update the bollsBowled by the bowler//
	bowler->ballsBowled = bowler->ballsBowled + 1;

	//we will update the total ballsBowled by the bowling team until this delivery //
	bowlingTeam->totalBallsBowled = bowlingTeam->totalBallsBowled + 1;

	//the total runs given by the bowler to the batting team until this delivery //
	bowler->runsGiven = bowler->runsGiven + runsScored;

	if (runsScored != 0)  //if batsman is not out then print this statement , and call showGameScoreCard function//
	{	// if runsScored = 1, 2, 3, 4, 5, or 6
		cout << endl << bowler->name << " to " << batsman->name << " " << runsScored << " runs!" << endl << endl;
		showGameScorecard();
	}
	else
	{ 	/* else runScored = 0 and the batsman is ‘OUT’  then print this statement and then we need to update the total
		wicket lost by the batting team until this delivery also we will update the score card of the bowler
		and call showGameScoreCard function, after that update next palyer index*/
		cout << endl << bowler->name << " to " << batsman->name << " OUT!" << endl << endl;

		battingTeam->wicketsLost = battingTeam->wicketsLost + 1; //this "wicketsLost" attribute will give us the index of the next player//
		bowler->wicketsTaken = bowler->wicketsTaken + 1;

		showGameScorecard();  

		int nextPlayerIndex = battingTeam->wicketsLost;
		batsman = &battingTeam->players[nextPlayerIndex]; //updating next palyer index//
	}
}

//13th step->............................................................................................................//
void Game::startFirstInnings()
{

	cout << " || ~~~~~~~~~~~~~~~~~~~~~~~~ FIRST INNINGS STARTS ~~~~~~~~~~~~~~~~~~~~~~~~ || " << endl << endl;

	isFirstInnings = true;

	initializePlayers();
	playInnings();
}

//14th step->............................................................................................................//
void Game::startSecondInnings() 
{
	cout << endl << endl;
	cout << " || ~~~~~~~~~~~~~~~~~~~~~~~~ SECOND INNINGS STARTS ~~~~~~~~~~~~~~~~~~~~~~~~ || " << endl << endl;

	isFirstInnings = false;	
	//in the 1st inning "isFirstInnings" variable was initialized by "True". So in the second it will be just opposite//
									

	// Now we will swap battingTeam and bowlingTeam pointers//
	Team temp = *battingTeam;
	*battingTeam = *bowlingTeam;
	*bowlingTeam = temp;

	// After that we will call these function for select the the bowler and batsman for second Innings//
	initializePlayers();
	playInnings();
}

//15th step->............................................................................................................//

/*validateInningsScore function will return "true" if the validation succeeds and then we need to continue with the 
next ball delievery and ..........in case if the validation fails then this function will return "false"
and then we need to END the first inning and start the second inning*/
bool Game::validateInningsScore()
{

	if (isFirstInnings)
	{

		if (battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls)
		{    /*validation fails(the innings will end if the batting team has lost all its wickets or the bowling team's
			ball delivery limit is over*/

			cout << "\t\t ||~~~~~~~~~~~~~~~~~~~~~~~~  FIRST INNINGS ENDS ~~~~~~~~~~~~~~~~~~~~~~~~ || " << endl << endl;

			cout << battingTeam->name << " " << battingTeam->totalRunsScored << " - "
				<< battingTeam->wicketsLost << " (" << bowlingTeam->totalBallsBowled
				<< ")" << endl;

			cout << bowlingTeam->name << " needs " << battingTeam->totalRunsScored + 1
				<< " runs to win the match" << endl << endl;

			return false;
		}
	}
	else
	{ // Else 2nd innings start//

		if (battingTeam->totalRunsScored > bowlingTeam->totalRunsScored) 
		{	//if the total run of batting team becomes larger than the total run of bowling team then batting team won the match//
			  

			cout << battingTeam->name << " WON THE MATCH " << endl << endl;
			return false;  
	
		}

		/*if battingTeam lost his total wicket and bowlingTeam has utilized his total 6 balls*/
		else if (battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls)
		{
			if (battingTeam->totalRunsScored < bowlingTeam->totalRunsScored) 
			{	/*if the total run of batting team becomes smaller than the total run of bowling team then 
				bowing team won the match  */

				cout << bowlingTeam->name << " WON THE MATCH " << endl << endl;
			}
			else if (battingTeam->totalBallsBowled == maxBalls || bowlingTeam->totalBallsBowled == maxBalls || battingTeam->totalRunsScored == bowlingTeam->totalRunsScored)
			{
				cout << "\t\t||~~~~~~~~~~~~~~~~~~~~~~~~ MATCH TIE ~~~~~~~~~~~~~~~~~~~~~~~~||" << endl << endl;
			}
			else
			{	//otherwise match will be draw//
				cout << "\t\t||~~~~~~~~~~~~~~~~~~~~~~~~ MATCH DRAW ~~~~~~~~~~~~~~~~~~~~~~~~||" << endl << endl;
			}
			return false;
		}
	}

	return true;
}

//16th step->............................................................................................................//

void Game::showGameScorecard()
{

	cout << "--------------------------------------------------------------------------" << endl;

	cout << "\t" << battingTeam->name << "  " << battingTeam->totalRunsScored << " - "
		<< battingTeam->wicketsLost << " (" << bowlingTeam->totalBallsBowled << ") | " << batsman->name
		<< " " << batsman->runsScored << " (" << batsman->ballsPlayed << ") \t" << bowler->name << " "
		<< bowler->ballsBowled << " - " << bowler->runsGiven << " - " << bowler->wicketsTaken << "\t" << endl;

	cout << "--------------------------------------------------------------------------" << endl << endl;
}

//17th step->............................................................................................................//

void Game::matchDetail()
{

	cout << "||~~~~~~~~~~~~~~~~~~~~~~~~ MATCH ENDS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ || " << endl << endl;

	cout << battingTeam->name << " " << battingTeam->totalRunsScored << "-" << battingTeam->wicketsLost << " (" << bowlingTeam->totalBallsBowled << ")" << endl;

	cout << "==========================================" << endl;
	cout << "| PLAYER \t BATTING \t BOWLING |" << endl;
	
	for (int j = 0; j < playersPerTeam; j++) {
		Player player = battingTeam->players[j];
		cout << "|----------------------------------------|" << endl;
		cout << "| " << "[" << j << "] " << player.name << "  \t "
			<< player.runsScored << "(" << player.ballsPlayed << ") \t\t "
			<< player.ballsBowled << "-" << player.runsGiven << "-"
			<< player.wicketsTaken << "\t |" << endl;
	}
	cout << "==========================================" << endl << endl;

	cout << bowlingTeam->name << " " << bowlingTeam->totalRunsScored << "-" << bowlingTeam->wicketsLost << " (" << battingTeam->totalBallsBowled << ")" << endl;

	cout << "==========================================" << endl;
	cout << "| PLAYER \t BATTING \t BOWLING |" << endl;

	for (int i = 0; i < playersPerTeam; i++) {
		Player player = bowlingTeam->players[i];
		cout << "|----------------------------------------|" << endl;
		cout << "| " << "[" << i << "] " << player.name << "  \t "
			<< player.runsScored << "(" << player.ballsPlayed << ") \t\t "
			<< player.ballsBowled << "-" << player.runsGiven << "-"
			<< player.wicketsTaken << "\t |" << endl;
	}
	cout << "==========================================" << endl << endl;
}

