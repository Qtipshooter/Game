// Handler.hpp
// Quinton Graham
// Defines the class Handler as a class to handle a window
// and related components and information.  Also provides functions
// to work with the window and draw on the screen.

#ifndef HANDLER_H_
#define HANDLER_H_

#include <SDL2/SDL.h>       // Window and Renderer objects, along with interactions and other datatypes
#include <SDL2/SDL_ttf.h>   // True Type Font and and its functions to draw words

//definitions used for this class
#define DEFAULT_WINDOW_SIZE 400
#define DEFAULT_COLOR SDL_Color{0xff, 0xff, 0xff, 0xff}


class Handler
{
public:

    //variables
    SDL_Window * window;        //A pointer to the window being handled
    SDL_Renderer * renderer;    //A pointer to the renderer for the window
    unsigned int window_x;      //The width of the window
    unsigned int window_y;      //The height of the window
    SDL_Color render_color;     //The current drawing color of the renderer

    /* ------ Constructors ------ */

    /**Default Constructor
     * Creates a window with a size of 400 x 400 and
     * a title of "Title" that is not resizable
     */
    Handler();

    /**Full Constructor
     * Constructs the window with a background color
     * @param title - the title of the window created
     * @param x - the width of the window created
     * @param y - the height of the window created
     * @OPparam resizable - true if the window is resizable afterward
     * @OPparam color - background color of the screen and initial color of the renderer
     */
    Handler(std::string title, unsigned int x, unsigned int y, bool resizable = false, SDL_Color color = DEFAULT_COLOR);

    /**Copy Constructor
     * Forbidden to use
     */
    Handler(const Handler &copy) = delete;

    /**Copy Assignment Operator
     * Forbidden to use
     */
    Handler& operator= (const Handler &copy) = delete;

    /**Destructor
     * Destroys the renderer, window, and deletes the
     * object in the process
     */
    ~Handler();

    /* ------ External Functions ------ */

    /* ------ Informative ------ */
    /**IsInsideWindow
     * Returns whether a point is in the window handled by this object
     * @param x - x cordinate of the point to check
     * @param y - y cordinate of the point to check
     * @return - bool true if point is inside the window, false otherwise
     */
    bool isInsideWindow(int x, int y);

    /**GetPointOfScreenPercentage
     * Returns a point that is x% through the width of the screen
     * and y% through the hieght of the screen
     * @param x - percentage through the width of the screen
     * @param y - percentage through the hieght of the screen
     * @return - SDL_Point that contains the cordinates of the
     * point at the percentages requested, or a point pointing to
     * -1, -1 if the x or y value was negative
     */
    SDL_Point getPointOfScreenPercentage(double x, double y);

    /* ------ Basic Drawing ------ */
    /**DrawBox
     * Draws a box at a given location location with an internal
     * width and height given by the user and a border in `border` pixels
     * that is of a given color
     * @param rect - an SDL_Rect that represents the internal rectangle to be shown
     * @OPparam border_thickness - the thickness of the border to the box created
     * @OPparam border_color - the color of the border
     * @OPparam background_color - the color of the border
     */
    void drawBox(SDL_Rect rect, unsigned int border_thickness = 4, SDL_Color border_color = SDL_Color{ 0x00, 0x00, 0x00, 0xff },
        SDL_Color background_color = SDL_Color{ 0xff, 0xff, 0xff, 0xff });

    /* ------ Internal Functiions ------ */
private:

};

#endif