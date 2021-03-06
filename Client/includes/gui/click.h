#ifndef CLICK_H_INCLUDED
#define CLICK_H_INCLUDED

#include <SDL.h>

namespace gui
{

/**
 * \brief Class for click handling
 *
 *  Initialize this in event handling of a program mode
 */

class Click
{
public:

    // determine if user has clicked that rectangle last frame and released the button
    bool has_clicked();

    //set last click's location
    void set_location(int x , int y);

    void get_location(int & x, int & y);

    // set click last frame
    void set_clicked(bool was_clicked);

private:

    //static to know last click location
    static SDL_Point last_click_location_;

    static bool clicked_last_frame_ ;
};

}


#endif // CLICK_H_INCLUDED
