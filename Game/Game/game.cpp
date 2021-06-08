// game.cpp
// Quinton Graham
// <<Quinten's name here>>
// This is the main file for the game.

//When writing a new include, indicate the reason it is being included in a comment
//example is behind iostream

#include <iostream>			//Used for basic character printing
#define SDL_MAIN_HANDLED	//Used to avoid SDL taking control of main

#include "Handler.hpp"		//Used to handle the game window

// Test Function Prototypes
int graham_test_main(int argsc, char* argsv[]);
int butts_test_main(int argsc, char* argsv[]);
// Test Function Prototypes

int main(int argsc, char * argsv[])
{
	/* During the testing phase, Quinton will use the graham_test_main function
	 * and Quinten will use the butts_test_main function
	 * This will allow us to not have to modify each others code just for testing
	 * Uncomment whoever is currently testing
	 */

	return graham_test_main(argsc, argsv);

	//return butts_test_main(argsc, argsv);

	return 0;
}

int graham_test_main(int argsc, char* argsv[])
{
	Handler game = Handler("Game", DEFAULT_WINDOW_SIZE, DEFAULT_WINDOW_SIZE);


	return 0;
}

int butts_test_main(int argsc, char* argsv[])
{
	return 0;
}