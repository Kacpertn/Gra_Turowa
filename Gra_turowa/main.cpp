#include <iostream>
#include <cstdlib>
#include <fstream>
#include "creatures.hpp"
#include "player.hpp"
#include "gameround.hpp"
#include "save.hpp"

/**
 * function responsible for generating the start screen
 */
auto start() -> void{
    std::cout << "\n\n";
    std::cout << "Turn-based game";
    for(auto i =0;i<12;i++){
        std::cout <<"\n";
    }
    std::cout << "Press [1-3] to start (1-easy, 2-medium, 3-hard) or 0 to load saved game";
    for(auto i =0;i<13;i++){
        std::cout <<"\n";
    }
    std::cout << "By Kacper Tonderys\n";
}
/**
 * generating a round won screen, it keeps showing until a certain key is pressed causing a certain action
 * @param game_round number telling which round is now being played
 */
auto win_screen(std::vector<creatures::creature> team,int game_round,int difficulty)->void {
    auto next_round = false;
    while (next_round == false) {
        system("CLS");
        std::cout << "\n\n";
        std::cout << "Turn-based game";
        for (auto i = 0; i < 12; i++) {
            std::cout << "\n";
        }
        std::cout << "Round " << game_round <<" won. Press P to start another round, S to save or Q to quit";
        for (auto i = 0; i < 13; i++) {
            std::cout << "\n";
        }
        auto choice = char();
        std::cin >> choice;
        if (choice == 'P' || choice == 'p') {
            next_round = true;
        }
        if (choice == 'S' || choice == 's') {
            save::make_save(team,game_round,difficulty);
            exit(0);
        }
        if (choice == 'Q' || choice == 'q') {
            exit(0);
        }
    }
}
/**
 * main function, responsible for creating players team and making the game go for 4 rounds. it also contains two while loops,
 * both of which make the game stay on a certain screen unless a certain button is pressed.
 * @return
 */
auto main()-> int {
    auto difficulty = int(0);
    auto team = std::vector<creatures::creature>();
    auto starting_round = int(1);
    auto end_game = false;
    while (end_game == false) {
        system("CLS");
        start();
        auto choice = char();
        std::cin >> choice;
        if (choice == '1' || choice == '2' || choice == '3') {
            difficulty = int(choice-48);
            system("CLS");
            player::choose_team(team);
            system("CLS");
            for (auto i = 1; i <= 4; i++) {
                gameround::game_round(team, difficulty, i);
                win_screen(team, i, difficulty);
                end_game = true;
            }
        }
        if (choice == '0') {
            save::read_save(team, difficulty, starting_round);
            for (auto i = starting_round + 1; i <= 4; i++) {
                gameround::game_round(team, difficulty, i);
                win_screen(team, i, difficulty);
                end_game = true;

            }
        }
    }
        system("CLS");
        while (true) {
            std::cout << "\n\n";
            std::cout << "Turn-based game";
            for (auto i = 0; i < 12; i++) {
                std::cout << "\n";
            }
            std::cout << "You won. Thanks for playing. Press Q to quit";
            for (auto i = 0; i < 13; i++) {
                std::cout << "\n";
            }
            std::cout << "By Kacper Tonderys\n";
            auto choice2 = char();
            std::cin >> choice2;
            if (choice2 == 'Q' || choice2 == 'q') {
                exit(0);
            }
        }

}