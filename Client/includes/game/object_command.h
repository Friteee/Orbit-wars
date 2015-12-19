#ifndef OBJECT_COMMAND_H_INCLUDEDS
#define OBJECT_COMMAND_H_INCLUDEDS


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
    virtual ~Command_implementation(){}
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
    Object_command(Command_implementation * implementation);
    Object_command(unsigned int timestamp , Command_implementation * implementation);
    ~Object_command();
    void execute(Moving_object * object) const;
    void redo   (Moving_object * object) const;
    bool operator<(const Object_command& rhs) const;
    bool operator>(const Object_command& rhs) const;
    bool operator<=(const Object_command& rhs) const;
    bool operator>=(const Object_command& rhs) const;
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
