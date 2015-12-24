#include "player.h"
#include "object_command.h"
#include "../video/camera.h"
#include "../utility/configuration.h"
#include "../utility/functions.h"
#include "../physics/nongravity_object_physics.h"

namespace game
{


Player::Player()
{
    type_          = PLAYER;
    utility::Configuration player_config("config/player.cfg");
    x_             = atoi(player_config.find_string("x").c_str());
    y_             = atoi(player_config.find_string("y").c_str());
    std::vector<string> points = player_config.find_strings("point");
    std::shared_ptr<physics::Polygon> polygon = std::make_shared<physics::Polygon>(physics::Polygon());
    for(unsigned int a = 0; a < points.size(); a++)
    {
        SDL_Point a_point;
        std::vector<int> xy = utility::get_numbers_from_string(points[a]);
        if(xy.size() != 2)
        {
            printf("Warning! Point in creation of player is of wrong values\n");
            continue;
        }
        a_point.x = xy[0];
        a_point.y = xy[1];
        polygon.get()->add_point(a_point);
    }
    polygon.get()->set(x_,y_);
    physics_component_ = std::make_shared<physics::Nongravity_object_physics>(std::move(physics::Nongravity_object_physics(x_, y_)));
    physics_component_.get()->init(this,polygon);

}

void Player::notify(Object_command command)
{
    // mutex here is due to physics engine being in separate thread
    command_mutex_.lock();
    //add command
    commands_.insert(std::move(command));

    command_mutex_.unlock();
}

void Player::update()
{
    // process commands from physics engine et cetera
    command_mutex_.lock();

    auto current_command = commands_.end();
    if(current_command != commands_.begin())
    {
        current_command--;
    }
    while(current_command != commands_.begin())
    {
        (*current_command).execute(this);
        current_command--;
    }
    commands_.clear();

    command_mutex_.unlock();

    // make "smooth" transition of camera to player position
    int new_camera_x = (x_ + video::Camera::get_position().x) / 2 ;
    int new_camera_y = (y_ + video::Camera::get_position().y) / 2 ;
    video::Camera::set_position(new_camera_x , new_camera_y);



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
