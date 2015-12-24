#ifndef NONGRAVITY_OBJECT_PHYSICS_H_INCLUDED
#define NONGRAVITY_OBJECT_PHYSICS_H_INCLUDED

#include "physics_component.h"
#include <memory>
#include <SDL.h>

namespace physics
{

class Nongravity_object_physics : public Physics_component
{
public:
    Nongravity_object_physics(SDL_Point init_location );

    Nongravity_object_physics(int x, int y);

    ~Nongravity_object_physics();

    virtual void update(unsigned int time) override;

    virtual void update_object() override;

    virtual void notify_static(unsigned int point , game::Static_object * object)override;

    virtual void notify_moving(Physics_component* moving) override;

    virtual SDL_Point get_interpolated_location(unsigned int time) override;

    void set_horizontal_acceleration(float init_acceleration);

    void set_vertical_acceleration(float init_acceleration);

    void set_friction(float friction);

private:
    float horizontal_acceleration_, vertical_acceleration_;
    float x_ , y_;
    float previous_x_ , previous_y_;
    float x_speed_, y_speed_;
    float friction_;

};

}

#endif // NONGRAVITY_OBJECT_PHYSICS_H_INCLUDED
