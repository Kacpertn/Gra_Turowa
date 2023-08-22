#pragma once
#include "creatures.hpp"
#include <vector>
#include <iostream>

namespace player {

    auto team_add(int choice,std::vector<creatures::creature>& team) -> void;
    auto choose_team(std::vector<creatures::creature>& team) -> void;
    auto enemy_team_select(std::vector<creatures::creature>& enemy_team, int difficulty) -> void;
}
