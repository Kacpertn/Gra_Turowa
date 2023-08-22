#include "gameround.hpp"
#include "creatures.hpp"
/**
 * function responsible for making the round go, selecting the enemy team according to difficulty level
 * while loop that makes the game play unless player or enemy creatures are dead.
 * it lets the user choose what action he wants to make and makes the enemy do certain actions with a certain probability
 * @param team player's team
 * @param difficulty difficulty chosen by starting the game
 * @param game_round which round is being played now (out of 4)
 */
auto gameround::game_round(std::vector<creatures::creature>& team,int difficulty,int game_round)->void {
    auto enemy_team = std::vector<creatures::creature>();
    player::enemy_team_select(enemy_team, difficulty);
    auto enemy_dead=false;
    auto which_player=int(0);
    auto which_enemy=int(0);
    while(enemy_dead==false) {
        auto& main_enemy =enemy_team.at(which_enemy);
        auto& main_player = team.at(which_player);
        system("CLS");
        std::cout << "Your Team:\n";
        for (auto a: team) {
            a.show_stats();
        }
        std::cout << "Enemy Team:\n";
        for (auto a: enemy_team) {
            a.show_stats();
        }
        std::cout << "\n";
        std::cout << "Your chosen creature: \n";
        main_player.show_stats();
        std::cout << "\n";
        std::cout << "Enemy's chosen creature: \n";
        main_enemy.show_stats();
        std::cout << "\n";
        auto choice = char();
        std::cout << "\n";
        std::cout << "What do you want to do?\n";
        std::cout << "1. Attack\n";
        std::cout << "2. Special attack\n";
        std::cout << "3. Change current creature\n";
        std::cout << "4. Level Up\n";
        std::cin >> choice;
        while(choice!='1'&&choice!='2'&&choice!='3'&&choice!='4') {
                std::cout << "Choose a proper action.\n";
            auto choice2=char();
            std::cin >> choice2;
            choice=choice2;
        }
        if(choice=='1') {
            creatures::attack(main_player, main_enemy);
            auto all_dead = true;
            if(main_enemy.health_points==0) {
                for (auto i = 0; i < 3 + difficulty; i++) {
                    if (enemy_team.at(i).health_points != 0) {
                        which_enemy = i;
                        all_dead = false;
                    }
                }
                if (all_dead == true) {
                    enemy_dead = true;
                }
            }
        }
        else if(choice=='2') {
            creatures::special_attack(main_player,main_enemy);
                auto all_dead = true;
                if (main_enemy.health_points == 0) {
                    for (auto i = 0; i < 3 + difficulty; i++) {
                        if (enemy_team.at(i).health_points != 0) {
                            which_enemy = i;
                            all_dead = false;
                        }
                    }
                    if (all_dead == true) {
                        enemy_dead = true;
                    }

            }
        }
        else if(choice=='3') {
            which_player=change_creature(which_player, team);
        }
        else if(choice=='4') {
            creatures::level_up(main_player);
        }

        srand( time( NULL ) );

        auto auto_choice =int(rand() %10);
        if(auto_choice<=5||auto_choice<=6&&(main_enemy.ult_ready==false)) {
            creatures::attack(main_enemy, main_player);
            auto all_dead = true;
            if(main_player.health_points==0) {
                for (auto i = 0; i < 6; i++) {
                    if (team.at(i).health_points != 0) {
                        which_player = i;
                        all_dead = false;
                    }
                }
                if (all_dead == true) {
                    game_over();

                }
            }
        }
        else if(auto_choice<=6) {
            creatures::special_attack(main_enemy, main_player);
            auto all_dead = true;
            if(main_player.health_points==0) {
                for (auto i = 0; i < 3 + difficulty; i++) {
                    if (team.at(i).health_points != 0) {
                        which_player = i;
                        all_dead = false;
                    }
                }
                if (all_dead == true) {
                    game_over();
                }
            }
        }
        else if(auto_choice<=10) {
            auto to_what = rand()%(2+difficulty);
            if(enemy_team.at(to_what).health_points>0){
                which_enemy=to_what;
            }
        }
    }
}
    /**
     * function responsible for changing the currently chosen character by returning to which element in vector team or enemy_team main_player or main_enemy, should point
     * @param which current creature
     * @param team team in which the creature should be chosen
     * @return new current creautre
     */
    auto gameround::change_creature(int which,std::vector<creatures::creature>& team)->int{
        auto counter=int(1);
        std::cout<<"Choose the creature to switch to:\n";
        for(auto e: team){
            std::cout << counter <<" ";
            e.show_stats();
            counter++;

        }
        auto choice =int();
        std::cin >> choice;
        while(team.at(choice).health_points==0){
            std::cout<<"Select a creature that is alive.\n";
            std::cin>> choice;
        }
        return choice-1;

    }

    /**
     * function generating a game over screen allowing the player to press a certain button to quit the game
     */
        auto gameround::game_over()->void{
            while (true) {
                system("CLS");
                std::cout << "\n\n";
                std::cout << "Turn-based game";
                for (auto i = 0; i < 12; i++) {
                    std::cout << "\n";
                }
                std::cout << "You Lost. Press Q to exit";
                for (auto i = 0; i < 13; i++) {
                    std::cout << "\n";
                }
                auto choice = char();
                std::cin >> choice;
                if (choice == 'Q' || choice == 'q') {
                    exit(0);
                }
            }
        }

