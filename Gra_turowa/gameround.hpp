#pragma once
#include "creatures.hpp"
#include "player.hpp"
#include "effectiveness.hpp"
namespace gameround{
    auto game_round(std::vector<creatures::creature>& team,int difficulty,int round)->void;
    auto change_creature(int which,std::vector<creatures::creature>& team)->int;
    auto game_over()->void;
}