#include "player.hpp"
    /**
     * function responsible for actually adding chosen creatures to the team
     * @param choice which creature (1-15) has been chosen
     * @param team to which the creature needs to be added
     */
    auto player::team_add(int choice, std::vector<creatures::creature>& team) -> void {
        switch (choice) {
            case 1: {
                team.push_back(creatures::oved());
                std::cout << "Added successfully.\n";
                break;
            }
            case 2: {
                team.push_back(creatures::meelis());
                std::cout << "Added successfully.\n";
                break;
            }
            case 3: {
                team.push_back(creatures::boyka());
                std::cout << "Added successfully.\n";
                break;
            }
            case 4: {
                team.push_back(creatures::yevgraf());
                std::cout << "Added successfully.\n";
                break;
            }
            case 5: {
                team.push_back(creatures::siddharta());
                std::cout << "Added successfully.\n";
                break;
            }
            case 6: {
                team.push_back(creatures::fester());
                std::cout << "Added successfully.\n";
                break;
            }
            case 7: {
                team.push_back(creatures::skoler());
                std::cout << "Added successfully.\n";
                break;
            }
            case 8: {
                team.push_back(creatures::cillia());
                std::cout << "Added successfully.\n";
                break;
            }
            case 9: {
                team.push_back(creatures::linnea());
                std::cout << "Added successfully.\n";
                break;
            }
            case 10: {
                team.push_back(creatures::varius());
                std::cout << "Added successfully.\n";
                break;
            }
            case 11: {
                team.push_back(creatures::arin());
                std::cout << "Added successfully.\n";
                break;
            }
            case 12: {
                team.push_back(creatures::odran());
                std::cout << "Added successfully.\n";
                break;
            }
            case 13: {
                team.push_back(creatures::maura());
                std::cout << "Added successfully.\n";
                break;
            }
            case 14: {
                team.push_back(creatures::vante());
                std::cout << "Added successfully.\n";
                break;
            }
            case 15: {
                team.push_back(creatures::methabel());
                std::cout << "Added successfully.\n";
                break;
            }
            default: {
                std::cout << "Choose a creature from the list.\n";
                std::cin >> choice;
                team_add(choice,team);
                break;
            }
        }

    }
/**
 * function responsible for showing all possible creatures and their stats and letting the player choose 6
 * @param team vector to which the team members are added
 */
    auto player::choose_team(std::vector<creatures::creature>& team) -> void {
        std::cout << "Choose your team (6 creatures): \n";
        std::cout << " name,        health, strength, agility, super power\n";
        std::cout << "1. Oved       250,    50,       5,       earth\n";
        std::cout << "2. Meelis     150,    30,       10,      air\n";
        std::cout << "3. Boyka      200,    30,       8,       water\n";
        std::cout << "4. Yevgraf    200,    30,       7,       fire\n";
        std::cout << "5. Siddharta  300,    45,       5,       earth\n";
        std::cout << "6. Fester     200,    60,       8,       ice\n";
        std::cout << "7. Skoler     400,    40,       0,       steel\n";
        std::cout << "8. Cillia     180,    40,       10,      water\n";
        std::cout << "9. Linnea     230,    55,       5,       earth\n";
        std::cout << "10.Varius     300,    30,       7,       ice\n";
        std::cout << "11.Arin       200,    40,       5,       water\n";
        std::cout << "12.Odran      300,    30,       8,       fire\n";
        std::cout << "13.Maura      150,    70,       15,      air\n";
        std::cout << "14.Vante      200,    60,       10,      fire\n";
        std::cout << "15.Methabel   600,    20,       0,       steel\n";
        for(auto i =0;i<6;i++){
            auto choice = int();
            std::cin >> choice;
            team_add(choice,team);
        }
    }
    /**
     * function responsible for generating an enemy team to play against the player
     * @param enemy_team vector to which the team members are added
     * @param difficulty amount of creatures needed to base 3 according to game difficulty
     */
auto player::enemy_team_select(std::vector<creatures::creature>& enemy_team,int difficulty) -> void{
    auto choice = int();
    srand( time( NULL ) );
    for(auto i = 0;i<3+difficulty;i++){
        choice=(std::rand()%15)+1;
        player::team_add(choice,enemy_team);
    }
}