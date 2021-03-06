#ifndef TILE_TYPE_H_INCLUDED
#define TILE_TYPE_H_INCLUDED

#include <string>
#include <SDL.h>
#include "../video/texture.h"

namespace game
{

/** \brief Basic information about tile
 *
 *  Kinda similar to flyweight pattern
 */


class Object_type
{
public:
    Object_type();
    bool get_invincibility();
    void set_invincibility( bool set_invincible );
    void init_texture     ( std::string filename , SDL_Rect boundaries);
    void blit             ( SDL_Point location );
    void set_id           ( unsigned int init_id);
    void set_width        ( unsigned int width);
    void set_height       ( unsigned int height);
    unsigned int width();
    unsigned int height();
    virtual void update() {}
    unsigned int get_id ()
    {
        return id_;
    }
private:
    video::Texture texture_;
    bool           invincible_;
    unsigned int   id_;
    unsigned int   width_, height_;
};

}

#endif // TILE_TYPE_H_INCLUDED
