#include <cstdlib>
#include <iostream>
#include "creatures.hpp"
#include "effectiveness.hpp"
#include <vector>
#include <algorithm>

namespace creatures {
        /**
         * base struct from which all other 15 struct inherit
         * @param name name of the creature
         * @param health_points health points of the creature
         * @param strength strength of the creature
         * @param agility agility of the creature
         * @param special_power special power type of the creature
         * @param exp experience points the creature has accumulated
         * @param level level of the creature
         * @param ult_ready if creatures special attack is ready
         */
        creature::creature(std::string name, int health_points, int strength, int agility, special_power_type special_power, int exp, int level,bool ult_ready)
                : name(name),health_points(health_points), strength(strength), agility(agility), special_power(special_power), exp(exp),
                  level(level),ult_ready(ult_ready) {}

        /**
         * function responsible for showing creatures attributes
         */
        auto creature::show_stats() -> void {
            std::cout << name;
            for(auto i =0;i<15-name.size();i++){
                std::cout << " ";
            }
            std::cout << "| Health:" << health_points<< " Strength: " << strength <<" Agility: "<< agility << " Level: "<< level << " Exp: " << exp << "  ";
            if(ult_ready==1){
                std::cout << "Special Power Ready";
            }
            else{
                std::cout << "Special Power Not Ready Yet";
            }
            std::cout <<"\n";

        }
            /**
            * struct responsible for generating creature Oved
            */
            oved::oved()
                  : creature("Oved",250, 50, 5, special_power_type::earth, 0, 1,1) {}

            /**
             * struct responsible for generating creature Meelis
             */
            meelis::meelis()
                    : creature("Meelis",150, 30, 10, special_power_type::air, 0, 1,1) {}
            /**
             * struct responsible for generating creature Boyka
             */
            boyka::boyka()
                    : creature("Boyka",200, 30, 8, special_power_type::water, 0, 1,1) {}
            /**
             * struct responsible for generating creature Yevgraf
             */
            yevgraf::yevgraf()
                    : creature("Yevgraf",200, 30, 7, special_power_type::fire, 0, 1,1) {}
            /**
             * struct responsible for generating creature Siddharta
             */
            siddharta::siddharta()
                    : creature("Siddharta",300, 45, 5, special_power_type::earth, 0, 1,1) {}
            /**
             * struct responsible for generating creature Fester
             */
            fester::fester()
                    : creature("Fester",200, 60, 8, special_power_type::ice, 0, 1,1) {}
            /**
             * struct responsible for generating creature Skoler
             */
            skoler::skoler()
                    : creature("Skoler",400, 40, 0, special_power_type::steel, 0, 1,1) {}
            /**
             * struct responsible for generating creature Cillia
             */
            cillia::cillia()
                    : creature("Cillia",180, 40, 10, special_power_type::water, 0, 1,1) {}
            /**
             * struct responsible for generating creature Linnea
             */
            linnea::linnea()
                    : creature("Linnea",230, 55, 5, special_power_type::earth, 0, 1,1) {}
            /**
             * struct responsible for generating creature Varius
             */
            varius::varius()
                    : creature("Varius",300, 30, 7, special_power_type::ice, 0, 1,1) {}
            /**
             * struct responsible for generating creature Arin
             */
            arin::arin()
                    : creature("Arin",200, 40, 5, special_power_type::water, 0, 1,1) {}
            /**
             * struct responsible for generating creature Odran
             */
            odran::odran()
                    : creature("Odran",300, 30, 8, special_power_type::fire, 0, 1,1) {}
            /**
             * struct responsible for generating creature Maura
             */
            maura::maura()
                    : creature("Maura",150, 70, 15, special_power_type::air, 0, 1,1) {}
            /**
             * struct responsible for generating creature Vante
             */
            vante::vante()
                    : creature("Vante",200, 60, 10, special_power_type::fire, 0, 1,1) {}
            /**
             * struct responsible for generating creature Methabel
             */
            methabel::methabel()
                    : creature("Methabel",600, 20, 0, special_power_type::steel, 0, 1,1) {}

        /**
         * function responsible for dealing damage to opponents creature. The damage is equal to the strength of the attacker,so are the experience points earned,
         * there is a probability (equal to agility of the enemy being attacked) that the damage won't be dealt and the experience points (amount still equal to attackers strength) will go to the opponent
         * @param attacker creature attacking
         * @param enemy creature being attacked (opponent)
         */
        auto attack(creature& attacker ,creature& enemy)->void{
            srand( time( NULL ) );
            if(rand() %100<enemy.agility){
                enemy.exp=enemy.exp+attacker.strength;
            }
            else{
                if(enemy.health_points<attacker.strength){
                    enemy.health_points=0;
                }
                else{
                    enemy.health_points=enemy.health_points-attacker.strength;
                }
                attacker.exp=attacker.exp+attacker.strength;
            }
        };
        /**
         * Function responsible for choosing and rising the chosen parameter of the selected creature
         * @param creature creature which chosen parameter should be risen
         */
        auto ability_upgrade(creature& creature)->void{
            auto choice =char();
            std::cout<< "Choose what attribute you want to upgrade:\n ";
            std::cout<< "1: Health\n ";
            std::cout<< "2: Strength\n ";
            std::cout<< "3: Agility\n ";
            std::cin>> choice;
            switch(choice){
                case '1': {
                    creature.health_points=creature.health_points+10;
                    break;
                }
                case '2': {
                    creature.strength=creature.strength+5;
                    break;
                }
                case '3':{
                    creature.agility=creature.agility+1;
                    break;
                }
                default:{
                    ability_upgrade(creature);
                    break;
                }
            }
        }
        /**
         * function responsible for checking if creature has enough experience points for leveling up
         * also responsible for two upgrades by calling function ability_upgrade() twice
         * function deleting experience points used by level up, giving ability to use special power again and actually increasing the level
         * @param creature creature to be leveled up
         */
        auto level_up(creature& creature)->void{
            if(creature.exp>=creature.level*100){
                ability_upgrade(creature);
                ability_upgrade(creature);
                creature.show_stats();
                creature.level++;
                creature.exp=creature.exp-(100*(creature.level-1));
                creature.ult_ready=true;
            }
        }
        /**
         * function responsible for making a special attack by multiplying strength by two and by the effectiveness bonus
         * makes it unable to call the function again without leveling up
         * @param attacker creature using the special attack
         * @param enemy creature being attacked
         */
        auto special_attack(creature& attacker, creature& enemy)-> void{
            if(attacker.ult_ready==true) {
                auto multiplier = int(effectiveness::effectiveness(attacker, enemy));
                enemy.health_points = enemy.health_points-attacker.strength * multiplier * 2;
                attacker.exp = attacker.exp + attacker.strength;
                attacker.ult_ready = false;
            }
        }

    }