
#include "nongravity_object_physics.h"
#include "../main_logic/game_logic.h"
#include "movement_command.h"

namespace physics
{

Nongravity_object_physics::Nongravity_object_physics(SDL_Point init_location)
{
    horizontal_acceleration_ = 0;
    vertical_acceleration_ = 0;
    x_ = init_location.x;
    y_ = init_location.y;
    x_speed_ = 0;
    y_speed_ = 0;
    friction_ = 0.99;
}

Nongravity_object_physics::Nongravity_object_physics(int x, int y)
{
    horizontal_acceleration_ = 0;
    vertical_acceleration_ = 0;
    x_ = x;
    y_ = y;
    x_speed_ = 0;
    y_speed_ = 0;
    friction_ = 0.99;
}

Nongravity_object_physics::~Nongravity_object_physics()
{
    if(registered)
        main_logic::Game_logic::get_engine().delete_moving_object(this);
}

void Nongravity_object_physics::update(unsigned int time)
{
    previous_x_ = x_;
    previous_y_ = y_;
    float seconds = static_cast<float>(time) / 1000;
    x_ = x_speed_ * seconds + horizontal_acceleration_ * seconds * seconds / 2;
    y_ = y_speed_ * seconds + vertical_acceleration_ * seconds * seconds / 2;
    x_speed_ += horizontal_acceleration_ * seconds;
    y_speed_ += vertical_acceleration_ * seconds;
    x_speed_ *= friction_;
    y_speed_ *= friction_;
}

void Nongravity_object_physics::notify_static(unsigned int collided_point , game::Static_object * object)
{
    if(object->get_tile_type()->get_invincibility())
    {
        return;
    }

    int x_buffer = static_cast<int>(previous_x_);
    int y_buffer = static_cast<int>(previous_y_);
    // find x and y values between previous and current ones so that this object and previous object don't collide
    physics::Polygon & objects_polygon = object->get_polygon();

    (*polygon_).set(x_buffer,y_buffer);
    int previous_buffer_x = x_buffer;
    int previous_buffer_y = y_buffer;

    while (!(*polygon_).is_colliding(objects_polygon))
    {
        previous_buffer_x = x_buffer;
        previous_buffer_y = y_buffer;
        x_buffer = (x_buffer + x_)/2;
        y_buffer = (y_buffer + y_)/2;
        if((x_buffer == x_ + 1 || x_buffer == x_ - 1) && (y_buffer == y_ + 1 || y_buffer == y_ - 1))
        {
            break;
        }
        (*polygon_).set(x_buffer,y_buffer);
    }
    (*polygon_).set(previous_buffer_x,previous_buffer_y);
}

void Nongravity_object_physics::notify_moving(Physics_component* moving)
{
    object_->notify_collision(moving->get_object());
}

SDL_Point Nongravity_object_physics::get_interpolated_location(unsigned int time)
{
    SDL_Point location;
    float seconds = float(time) / 1000;
    if(y_speed_ != 0)
    {
        location.y = static_cast<int>(y_ + y_speed_ * seconds + vertical_acceleration_ * seconds * seconds / 2);
    }
    if(x_speed_ != 0)
    {
        location.x = static_cast<int>(x_ + x_speed_ * seconds + horizontal_acceleration_ * seconds * seconds / 2);
    }
    return location;
}

void Nongravity_object_physics::set_horizontal_acceleration(float init_acceleration)
{
    horizontal_acceleration_ = init_acceleration;
}

void Nongravity_object_physics::set_vertical_acceleration(float init_acceleration)
{
    vertical_acceleration_ = init_acceleration;
}

void Nongravity_object_physics::set_friction(float friction)
{
    friction_ = friction;
}

void Nongravity_object_physics::update_object()
{
    Movement_command * impl = new Movement_command(object_ , object_->get_x() , object_->get_y());
    object_->notify(game::Object_command(impl));
}

}
