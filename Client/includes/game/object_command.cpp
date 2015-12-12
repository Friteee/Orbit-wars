#include "object_command.h"
#include "SDL.h"

namespace game
{

Object_command::Object_command(Command_implementation * implementation)
{
    timestamp_ = SDL_GetTicks();
    implementation_ = implementation;
}

Object_command::Object_command(unsigned int timestamp , Command_implementation * implementation)
{
    timestamp_ = timestamp;
    implementation_ = implementation;
}

void Object_command::execute(Moving_object * object)
{
    implementation_->execute(object);
}

void Object_command::redo   (Moving_object * object)
{
    implementation_->redo(object);
}

Object_command::~Object_command()
{
    delete implementation_;
}

bool Object_command::operator<(const Object_command& rhs) const
{
    return timestamp_ < rhs.timestamp_;
}

bool Object_command::operator>(const Object_command& rhs) const
{
    return timestamp_ > rhs.timestamp_;
}

bool Object_command::operator<=(const Object_command& rhs) const
{
    return timestamp_ <= rhs.timestamp_;
}

bool Object_command::operator>=(const Object_command& rhs) const
{
    return timestamp_ >= rhs.timestamp_;
}

}
