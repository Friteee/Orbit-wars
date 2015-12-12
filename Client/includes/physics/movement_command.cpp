#include "movement_command.h"
#include "../game/moving_object.h"

namespace physics
{

Movement_command::Movement_command(game::Moving_object * object, int init_x , int init_y)
{
    x_ = init_x;
    y_ = init_y;
    x_before_ = object->get_x();
    y_before_ = object->get_y();
}

void Movement_command::redo(game::Moving_object * object)
{
    object->set_position(x_before_ , y_before_);
}

void Movement_command::execute(game::Moving_object * object)
{
    object->set_position(x_ , y_);
}

}
