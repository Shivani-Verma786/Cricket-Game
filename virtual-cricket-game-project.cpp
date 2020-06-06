#include "game.h"        // here directly include <iostream> //
using namespace std;


int main()
{

	Game game;															  //Since welcome msg inside the Game class.//

	game.welcome();                                                       //calling the "welcome" function//

	//.....start coding for press enter key to continue ....//
	cout << "\n\n                           Press Enter to continue";
	getchar();
	//.....................end the code................... //


	game.showAllPlayers();                                                //calling the "showAllPlayers" function//

	cout << "\n\n                           Press Enter to continue";
	getchar();

	game.selectPlayers();                                                 //calling the "selectPlayers" function//
	game.showTeamPlayers();                                               //calling the "showTeamPlayers" function//
	
	cin.ignore(numeric_limits<streamsize>::max(), '\n');  /*for clear buffer memory*/

	cout << "\n\n                           Press Enter to toss";
	getchar();

	game.toss();   //calling the "toss" function//
	game.startFirstInnings();  //calling "startFirstInnings" function//

	game.startSecondInnings();//calling "startSecondInnings" function//

	game.matchDetail();  //calling "matchDetail" function//


	return 0;
}