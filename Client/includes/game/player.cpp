#include "player.h"
#include "object_command.h"
#include "moving_object.h"

namespace game
{

#define MAX_COMMAND_COUNT 100

Player::Player()
{
    type_          = PLAYER;
    x_             = 0;
    y_             = 0;
}

void Player::notify(Object_command command)
{
    command_mutex_.lock();
    //add command
    commands_.insert(command);

    command_mutex_.unlock();
}

void Player::update()
{
    command_mutex_.lock();



    command_mutex_.unlock();


}

int Player::get_x()
{
    return x_;
}

int Player::get_y()
{
    return y_;
}

void Player::set_position(int set_x, int set_y)
{
    x_ = set_x;
    y_ = set_y;
}

void Player::notify_collision(Moving_object * other)
{
    // TODO Collision with moving objects handling
}

void Player::notify_collision(Static_object * other)
{
    // TODO Collision with static objects handling
}

void Player::show()
{

}

}
