#include "player.h"

namespace game
{

Player::Player()
{
    type_          = PLAYER;
    newest_        = nullptr;
    oldest_        = nullptr;
    x_             = 0;
    y_             = 0;
}

void Player::notify(Object_command * command)
{
    command_mutex_.lock();



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

}
