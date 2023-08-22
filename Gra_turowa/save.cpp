#include "save.hpp"
/**
 * function responsible for saving objects to a .txt file and saving amount of rounds played and game difficulty
 * @param team team to be saved
 * @param game_round amount of rounds played to be saved
 * @param difficulty difficulty chosen to be saved
 */
auto save::make_save(std::vector<creatures::creature> team,int game_round,int difficulty)->void{
    auto path = std::string("save.txt");
    auto file = std::fstream(path,std::ios::out|std::ios::trunc);
    for(auto a:team){
        auto special_power_string=std::string();
        if(a.special_power==creatures::special_power_type::water){
            special_power_string="water";
        }
        else if(a.special_power==creatures::special_power_type::earth){
            special_power_string="earth";
        }
        else if(a.special_power==creatures::special_power_type::air){
            special_power_string="air";
        }
        else if(a.special_power==creatures::special_power_type::fire){
            special_power_string="fire";
        }
        else if(a.special_power==creatures::special_power_type::ice){
            special_power_string="ice";
        }
        else if(a.special_power==creatures::special_power_type::steel){
            special_power_string="steel";
        }
        file  << a.name << " " << a.health_points << " " << a.strength << " " << a.agility << " " << special_power_string << " " << a.exp << " " << a.level << " "<<  a.ult_ready << "\n";
    }
    file << game_round << " " << difficulty;
}
/**
 * function responsible for reading and making objects of team members, simply loading the saved stats of creatures
 * @param team team to which everything is saved
 * @param game_round number, telling after how many rounds the game has been saved
 * @param difficulty difficulty chosen
 * @return
 */
auto save::read_save(std::vector<creatures::creature> &team,int &game_round,int &difficulty)->void{
    auto path = std::string("save.txt");
    auto file = std::fstream(path,std::ios::in);
    auto string =std::string();
    for(int i=0;i<6;i++){
        auto name=std::string();
        auto health_points=int();
        auto strength=int();
        auto agility=int();
        auto special_power_string=std::string();
        auto special_power=creatures::special_power_type();
        auto exp=int();
        auto level=int();
        auto ult_ready=bool();
        file >> name >> health_points >> strength >> agility >> special_power_string >> exp >> level >> ult_ready ;
        if(special_power_string=="water"){
            special_power=creatures::special_power_type::water;
        }
        else if(special_power_string=="earth"){
            special_power=creatures::special_power_type::earth;
        }
        else if(special_power_string=="air"){
            special_power=creatures::special_power_type::air;
        }
        else if(special_power_string=="fire"){
            special_power=creatures::special_power_type::fire;
        }
        else if(special_power_string=="ice"){
            special_power=creatures::special_power_type::ice;
        }
        else if(special_power_string=="steel"){
            special_power=creatures::special_power_type::steel;
        }
        auto creature = creatures::creature(name,health_points,strength,agility,special_power,exp,level,ult_ready);
        team.push_back(creature);
    }
    file >> game_round >> difficulty;
}