#include "object_command.h"
#include "SDL.h"
#include <cstdio>

namespace game
{

Object_command::Object_command(Command_implementation * implementation)
{
    timestamp_ = SDL_GetTicks();
    implementation_ = implementation;
    object_count_++;
}

Object_command::Object_command(unsigned int timestamp , Command_implementation * implementation)
{
    timestamp_ = timestamp;
    implementation_ = implementation;
}

Object_command::Object_command(Object_command && other)
{
    timestamp_ = other.timestamp_;
    implementation_ = other.implementation_;
    object_count_++;
    other.object_count_++;
}

void Object_command::execute(Moving_object * object) const
{
    implementation_->execute(object);
}

void Object_command::redo   (Moving_object * object) const
{
    implementation_->redo(object);
}

Object_command::~Object_command()
{
    if(object_count_ < 2)
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
