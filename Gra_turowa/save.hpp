#pragma once
#include <vector>
#include "creatures.hpp"
#include <fstream>
namespace save{
    auto make_save(std::vector<creatures::creature> team,int game_round,int difficulty)->void;
    auto read_save(std::vector<creatures::creature> &team,int &game_round,int &difficulty)->void;
}