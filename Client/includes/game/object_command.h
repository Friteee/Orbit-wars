#ifndef OBJECT_COMMAND_H_INCLUDED
#define OBJECT_COMMAND_H_INCLUDED

namespace game
{

class Moving_object;


/** \brief Implementation of command on object
 *
 */
class Command_implementation
{
public:
    virtual void execute(Moving_object * object) = 0;
    virtual void redo   (Moving_object * object) = 0;
};

/** \brief Class for command, executed on object
 *
 *  Every derived class should implement execute, redo
 *  and initialize time stamp in constructor as SDL_GetTicks().
 *  They should be deleted by the object itself
 */

class Object_command
{
public:
    Object_command();
    Object_command(unsigned int timestamp);
    void execute(Moving_object * object);
    void redo   (Moving_object * object);
    unsigned int get_time()
    {
        return timestamp_;
    }
    void set_timestamp( unsigned int set_time)
    {
        timestamp_ = set_time;
    }
protected:
    unsigned int timestamp_;
    Command_implementation * implementation_;
};

}

#endif // OBJECT_COMMAND_H_INCLUDED
