#include "map.h"
#include <fstream>
#include <map>
#include <vector>

namespace game
{

void Map::init_map(std::string init_filename)
{

    filename_ = init_filename;

}

void Map::init_background(std::string init_filename)
{
    background_ = new gui::Background(init_filename.c_str());
}

void Map::init_music(std::string init_filename)
{
    music_.init(init_filename);
}

}
