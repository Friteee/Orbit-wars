#ifndef PHYSICS_ENGINE_H_INCLUDED
#define PHYSICS_ENGINE_H_INCLUDED

#include "polygon.h"
#include "../game/static_object.h"
#include <vector>
#include <mutex>
#include <list>
#include <thread>
#include <atomic>

namespace physics
{

class Physics_component;

/** \class physics::Physics_engine
 *
 * \brief Class used for collision detection and physical objects updates
 *
 * One uses add_static_polygon to add static objects for collision detection,
 * add_moving_polygon to add moving objects for collision detection and detected collision handling,
 * delete_static_polygon to delete a static object
 * delete_moving_polygon to delete a moving object
 * run to handle collisions and run physics calculations
 * reset to delete every physics object (both static and moving) from collision detection
 */

class Physics_engine
{

public:

    ~Physics_engine();
    void add_static_object(game::Static_object * added);
    void add_moving_object(Physics_component * added);
    void delete_static_object(game::Static_object * deleted);
    void delete_moving_object(Physics_component * deleted);
    void run(unsigned int ticks_per_s);
    void reset();

private:
    void check_addition();
    void update_moving();
    void update_objects();
    void check_collision();
    void thread();

    class Static_command
    {
    public:
        game::Static_object * get();
        void set(game::Static_object * added);
    private:
        game::Static_object * object_;
    };

    class Moving_command
    {
    public:
        Physics_component * get();
        void set(Physics_component * added);
    private:
        Physics_component * object_;
    };

    std::vector<game::Static_object *> static_objects_;
    std::vector<Physics_component *>   moving_objects_;
    std::mutex                         objects_change_;
    std::list <Static_command>         static_addition_;
    std::list <Moving_command>         moving_addition_;
    std::list <Static_command>         static_deletion_;
    std::list <Moving_command>         moving_deletion_;
    std::thread                      * engine_;
    std::atomic_bool                   stop_;
    unsigned int                       ticks_per_second_;





};



}

#endif // PHYSICS_ENGINE_H_INCLUDED
