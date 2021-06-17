// definitions.hpp
// Quinton Graham
//
// This contains basic defines that will be used throughout
// the entire program in someway or another.  This will make
// the code look cleaner and make more sense for example with color
// or sizings.

#ifndef DEFINITIONS_H_
#define DEFINITIONS_H_

// Window Size Default
#define GAME_DEFAULT_WINDOW_X	1280
#define GAME_DEFAULT_WINDOW_Y	720

// Color Definitions
#define WHITE       SDL_Color{0xff, 0xff, 0xff, 0xff}
#define BLACK       SDL_Color{0x00, 0x00, 0x00, 0xff}
#define RED         SDL_Color{0xff, 0x00, 0x00, 0xff}
#define GREEN       SDL_Color{0x00, 0xff, 0x00, 0xff}
#define BLUE        SDL_Color{0x00, 0x00, 0xff, 0xff}
#define YELLOW      SDL_Color{0xff, 0xff, 0x00, 0xff}
#define ORANGE      SDL_Color{0xff, 0xa5, 0x00, 0xff}
#define PURPLE      SDL_Color{0xee, 0x82, 0xee, 0xff}
#define PINK        SDL_Color{0xff, 0x66, 0xcc, 0xff}
#define BROWN       SDL_Color{0xa5, 0x2a, 0x2a, 0xff}
#define CYAN        SDL_Color{0x00, 0xff, 0xff, 0xff}
#define GRAY        SDL_Color{0xbe, 0xbe, 0xbe, 0xff}
#define LIGHTGREEN  SDL_Color{0x90, 0xee, 0x90, 0xff}
#define LIGHTBLUE   SDL_Color{0x99, 0xcc, 0xff, 0xff}
#define DARKRED     SDL_Color{0x99, 0x00, 0x00, 0xff}

// Pixel size of one square in roaming mode
//TODO

//Small tile size definitions 
//TODO - Complete the centering definitions
#define TILE_SMALL_SIZE		64
#define TILE_SMALL_PIXELS	4096

//Large tile size definitions
//TODO - Complete the centering definitions
#define TILE_LARGE_SIZE		128
#define TILE_LARGE_PIXELS	16384

//64 by 64 would be 4096 pixels total, 20 across, 11.25 high.
//This would be 16384 bytes minimum per square if stored as SDL_Points for each point in a single square.
//by centering the player on the screen, we would have half a box off each side, and an eighth of a box of the top and bottom.
//That would be 32 pixels on the side and 8 on the top and bottom.
//I think that 64 would work best, but will discuss before hand

//revisment, maybe 128 works a bit better.  This makes the number of pixels 16384 per box,
//meaning 65536 bytes per box if all points are stored as SDL_Points.
//this method makes there be 10 boxes across and 5.625 (5 and 5/8th) boxes vertically.
//centering this makes there be half width (64 pixels) boxes on the sides
//and .3125 (5/16th) (40 pixels) boxes on top and bottom.  This still leaves 9 boxes across
//and 5 boxes up and down with extra space on all edges

/* ------ Text Dialoug Box definitions (Picture and no Picture) ------ */
//Default Border size (which is used to determine the other textbox sizes)
#define TEXBOX_BORDER_SIZE 6

//Full textbox size
#define TEXTBOX_FULL_X				TEXBOX_BORDER_SIZE
#define TEXTBOX_FULL_Y				520 + TEXBOX_BORDER_SIZE
#define TEXTBOX_FULL_W				1280 - (TEXBOX_BORDER_SIZE * 2)
#define TEXTBOX_FULL_H				200 - (TEXBOX_BORDER_SIZE * 2)
#define TEXTBOX_FULL_RECT			SDL_Rect{TEXTBOX_FULL_X, TEXTBOX_FULL_Y, TEXTBOX_FULL_W, TEXTBOX_FULL_H}

//Split textbox text section size
#define TEXTBOX_SPLIT_TEXT_X		194 + TEXBOX_BORDER_SIZE
#define TEXTBOX_SPLIT_TEXT_Y		520 + TEXBOX_BORDER_SIZE
#define TEXTBOX_SPLIT_TEXT_W		1086 - (TEXBOX_BORDER_SIZE * 2)
#define TEXTBOX_SPLIT_TEXT_H		200 - (TEXBOX_BORDER_SIZE * 2)
#define TEXTBOX_SPLIT_TEXT_RECT		SDL_Rect{TEXTBOX_SPLIT_TEXT_X, TEXTBOX_SPLIT_TEXT_Y, TEXTBOX_SPLIT_TEXT_W, TEXTBOX_SPLIT_TEXT_H}

//Split picture size
#define TEXTBOX_SPLIT_PIC_X			TEXBOX_BORDER_SIZE
#define TEXTBOX_SPLIT_PIC_Y			520 + TEXBOX_BORDER_SIZE
#define TEXTBOX_SPLIT_PIC_W			200 - (TEXBOX_BORDER_SIZE * 2)
#define TEXTBOX_SPLIT_PIC_H			200 - (TEXBOX_BORDER_SIZE * 2)
#define TEXTBOX_SPLIT_PIC_RECT		SDL_Rect{TEXTBOX_SPLIT_PIC_X, TEXTBOX_SPLIT_PIC_Y, TEXTBOX_SPLIT_PIC_W, TEXTBOX_SPLIT_PIC_H}

// Font definitions
//TODO
//Default font
//Alternate font probably too

// Errors


#endif // !DEFINITIONS_H_
