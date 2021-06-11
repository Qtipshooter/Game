// Handler.cpp
// Quinton Graham
// Handles a window and it's renderer along with holding information
// about the window
#include <string>
#include <iostream>

#include "Handler.hpp"

    /* ------ Constructors ------ */

Handler::Handler()
{
    window_x = DEFAULT_WINDOW_SIZE;
    window_y = DEFAULT_WINDOW_SIZE;
    window = SDL_CreateWindow("Title", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        window_x, window_y, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);
    render_color = DEFAULT_COLOR;
    SDL_SetRenderDrawColor(renderer, render_color.r, render_color.g, render_color.b, render_color.a);

}

Handler::Handler(std::string title, unsigned int x, unsigned int y, bool resizable, SDL_Color color)
{
    window_x = x;
    window_y = y;

    int flags{ 0 };
    if (resizable)
        flags = SDL_WINDOW_RESIZABLE;

    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        window_x, window_y, flags);

    renderer = SDL_CreateRenderer(window, -1, 0);

    render_color = color;
    SDL_SetRenderDrawColor(renderer, render_color.r, render_color.g, render_color.b, render_color.a);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

/* ------ Deconstructor ------ */
Handler::~Handler()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

/* ------ External Functions ------ */

/* ------ Informative ------ */
bool Handler::isInsideWindow(int x, int y)
{
    if (x < 0 || y < 0)
    {
        return false;
    }
    if ((unsigned int)x >= window_x || (unsigned int)y >= window_y)
    {
        return false;
    }

    return true;
}

SDL_Point Handler::getPointOfScreenPercentage(double x, double y)
{
    int new_x{}, new_y{};

    //make sure that x and y percentages are greater than 0
    if (x < 0) new_x = -1;
    else new_x = (int)(x / 100) * window_x;

    // Otherwise, divide by 100 (convert to percentage), then return the new point
    if (y < 0) new_y = -1;
    else new_y = (int) (y / 100) * window_y;

    return SDL_Point{ new_x, new_y };
}

/* ------ Basic Drawing ------ */

void Handler::drawBox(SDL_Rect rect, unsigned int border_thickness, SDL_Color border_color, SDL_Color background_color)
{
    // Store current draw color
    SDL_Color previous_draw_color = render_color;

    // Calculate the number of points for the outside border and inner box.
    unsigned int number_of_outside_points{ (2 * border_thickness * (rect.w + rect.h)) + (border_thickness * border_thickness * 4) };
    unsigned int number_of_inside_points{ (unsigned int)rect.w * rect.h };

    // Make arrays for the number of points of each
    SDL_Point* inner_points = new SDL_Point[number_of_inside_points];
    SDL_Point* outer_points = new SDL_Point[number_of_outside_points];

    // For the area of the outside border, put each point into its respective array
    // Values used in the loop definition
    int x_start_value{ rect.x - (int)border_thickness };
    int x_end_value{ rect.x + rect.w + (int)border_thickness };
    int y_start_value{ rect.y - (int)border_thickness };
    int y_end_value{ rect.y + rect.h + (int)border_thickness };

    //loop through each point in the space, if in the rectangle, add to 
    //inner space, otherwise add to outer space.  Discard if not in the window
    //and lower the number of points for that set
    int current_point_inner{ 0 };
    int current_point_outer{ 0 };
    for (int x_value = x_start_value; x_value < x_end_value; x_value++)
    {
        for (int y_value = y_start_value; y_value < y_end_value; y_value++)
        {
            //if inside the inner rectangle
            if (x_value >= rect.x && x_value < rect.x + rect.w && y_value >= rect.y && y_value < rect.y + rect.h)
            {
                // If inside the window, add the point to the array of points
                // Otherwise, remove a point from the total number of points
                if (isInsideWindow(x_value, y_value))
                {
                    inner_points[current_point_inner] = SDL_Point{ x_value, y_value };
                    current_point_inner++;
                }
                else
                {
                    number_of_inside_points--;
                }
            }
            //else, is part of the border
            else
            {
                // If inside the window, add the point to the array of points
                // Otherwise, remove a point from the total number of points
                if (isInsideWindow(x_value, y_value))
                {
                    outer_points[current_point_outer] = SDL_Point{ x_value, y_value };
                    current_point_outer++;
                }
                else
                {
                    number_of_outside_points--;
                }
            }
        }
    }

    // Set to border draw color, then draw outside color
    SDL_SetRenderDrawColor(renderer, border_color.r, border_color.g, border_color.b, border_color.a);
    SDL_RenderDrawPoints(renderer, outer_points, number_of_outside_points);

    // Set to background draw color, then drow inside color
    SDL_SetRenderDrawColor(renderer, background_color.r, background_color.g, background_color.b, background_color.a);
    SDL_RenderDrawPoints(renderer, inner_points, number_of_inside_points);

    // Present the drawing to the screen
    SDL_RenderPresent(renderer);

    // Reset drawing color to color previously used
    SDL_SetRenderDrawColor(renderer, previous_draw_color.r, previous_draw_color.g, previous_draw_color.b, previous_draw_color.a);

    delete[] inner_points;
    delete[] outer_points;
}

/* ------ Internal Functions ------ */