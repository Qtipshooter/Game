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
int extra_main(int argsc, char* argsv[]);
// Test Function Prototypes

int main(int argsc, char * argsv[])
{
	/* During the testing phase, Quinton will use the graham_test_main function
	 * and Quinten will use the butts_test_main function
	 * This will allow us to not have to modify each others code just for testing
	 * Uncomment whoever is currently testing
	 */

	if(graham_test_main(argsc, argsv)) 
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", SDL_GetError(), NULL);

	//return butts_test_main(argsc, argsv);

	//return extra_main(argsc, argsv);

	return 0;
}

int graham_test_main(int argsc, char* argsv[])
{
	Handler game("Game", GAME_DEFAULT_WINDOW_X, GAME_DEFAULT_WINDOW_Y, false, PINK);
	SDL_Event* event = new SDL_Event{};

	//Full box
	//game.drawBox(SDL_Rect{ TEXTBOX_FULL_X, TEXTBOX_FULL_Y, TEXTBOX_FULL_W, TEXTBOX_FULL_H }, TEXBOX_BORDER_SIZE, BLACK, LIGHTBLUE);
	// 0, 520, 1280, 200

	for (int i = 0; i < 20; i++)
	{
		int x_offset = i * 128;
		for (int j = 0; j < 20; j++)
		{
			int y_offset = j * 128;
			SDL_Color tile_color;
			if ((i + j) % 2 == 0) tile_color = WHITE;
			else tile_color = BLACK;

			game.drawBox(SDL_Rect{ x_offset, y_offset, 128, 128 }, 0, tile_color, tile_color);
		}
	}

	bool flag = true;

	int test_num = -5;

	while (flag)
	{
		while (SDL_PollEvent(event))
		{
			switch (event->type)
			{
			case SDL_QUIT:
				flag = false;
				break;
			case SDL_MOUSEBUTTONDOWN:
				std::cout << "Mouse button pressed.\n";
				//Picture box (square)
				game.drawBox(TEXTBOX_SPLIT_PIC_RECT, TEXBOX_BORDER_SIZE, BLACK, YELLOW);
				// 0, 520, 200, 200

				//picture textbox
				game.drawBox(TEXTBOX_SPLIT_TEXT_RECT, TEXBOX_BORDER_SIZE, BLACK, PURPLE);
				// 200, 520, 1080, 200
				break;
			case SDL_KEYDOWN:
				switch (event->key.keysym.sym)
				{
				case SDLK_ESCAPE:
					flag = false;
					break;
				case SDLK_r:
					SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING, "Error printing", SDL_GetError(), game.window);
					break;
				case SDLK_e:
					SDL_SetError("Test Error");
					break;
				case SDLK_t:
					SDL_ClearError();
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

int extra_main(int argc, char* argv[])
{
	return 0;
}
