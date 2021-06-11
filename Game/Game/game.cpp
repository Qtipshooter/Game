// game.cpp
// Quinton Graham
// <<Quinten's name here>>
// This is the main file for the game.

//When writing a new include, indicate the reason it is being included in a comment
//example is behind iostream

#include <iostream>			//Used for basic character printing
#define SDL_MAIN_HANDLED	//Used to avoid SDL taking control of main

#include "Handler.hpp"		//Used to handle the game window and renderer
#include "definitions.hpp"	//Used for game definitions

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
	Handler game("Game", GAME_DEFAULT_WINDOW_X, GAME_DEFAULT_WINDOW_Y, false, PINK);
	SDL_Event* event = new SDL_Event{};

	//Full box
	//game.drawBox(SDL_Rect{ TEXTBOX_FULL_X, TEXTBOX_FULL_Y, TEXTBOX_FULL_W, TEXTBOX_FULL_H }, TEXBOX_BORDER_SIZE, BLACK, LIGHTBLUE);
	// 0, 520, 1280, 200

	//Picture box (square)
	game.drawBox(TEXTBOX_SPLIT_PIC_RECT, TEXBOX_BORDER_SIZE, BLACK, YELLOW);
	// 0, 520, 200, 200

	//picture textbox
	game.drawBox(TEXTBOX_SPLIT_TEXT_RECT, TEXBOX_BORDER_SIZE, BLACK, PURPLE);
	// 200, 520, 1080, 200

	while (true)
	{
		while (SDL_PollEvent(event))
		{
			switch (event->type)
			{
			case SDL_QUIT:
				return 0;
				break;
			case SDL_MOUSEBUTTONDOWN:
				std::cout << "Mouse button pressed.\n";
				break;
			case SDL_KEYDOWN:
				switch (event->key.keysym.sym)
				{
				case SDLK_ESCAPE:
					return 0;
					break;
				default:
					break;
				}
			default:
				break;
			}
		}
	}

	return 0;
}

int butts_test_main(int argsc, char* argsv[])
{
	return 0;
}