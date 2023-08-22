#include "effectiveness.hpp"
#include "creatures.hpp"
/**
 * function responsible for checking effectiveness of attacker special power type compared to enemy's
 * @param attacker creature which effectiveness is checked
 * @param enemy creature with which effectiveness is checked
 */
auto effectiveness::effectiveness(creatures::creature& attacker, creatures::creature& enemy)-> int{
    using namespace creatures;
        switch (attacker.special_power) {
            case special_power_type::water: {
                switch (enemy.special_power) {
                    case special_power_type::water: {
                        return 0;
                    }
                    case special_power_type::earth: {
                        return 2;
                    }
                    case special_power_type::air: {
                        return 1;
                    }
                    case special_power_type::fire: {
                        return 2;
                    }
                    case special_power_type::ice: {
                        return 1;
                    }
                    case special_power_type::steel: {
                        return 1;
                    }
                }
                break;
            }
            case special_power_type::earth: {
                switch (enemy.special_power) {
                    case special_power_type::water: {
                        return 1;
                    }
                    case special_power_type::earth: {
                        return 1;
                    }
                    case special_power_type::air: {
                        return 0;
                    }
                    case special_power_type::fire: {
                        return 2;
                    }
                    case special_power_type::ice: {
                        return 2;
                    }
                    case special_power_type::steel: {
                        return 2;
                    }
                }
                break;
            }
            case special_power_type::air: {
                switch (enemy.special_power) {
                    case special_power_type::water: {
                        return 1;
                    }
                    case special_power_type::earth: {
                        return 0;
                    }
                    case special_power_type::air: {
                        return 1;
                    }
                    case special_power_type::fire: {
                        return 1;
                    }
                    case special_power_type::ice: {
                        return 2;
                    }
                    case special_power_type::steel: {
                        return 0;
                    }
                }
                break;
            }
            case special_power_type::fire: {
                switch (enemy.special_power) {
                    case special_power_type::water: {
                        return 0;
                    }
                    case special_power_type::earth: {
                        return 0;
                    }
                    case special_power_type::air: {
                        return 1;
                    }
                    case special_power_type::fire: {
                        return 1;
                    }
                    case special_power_type::ice: {
                        return 2;
                    }
                    case special_power_type::steel: {
                        return 2;
                    }
                }
                break;

            }
            case special_power_type::ice: {
                switch (enemy.special_power) {
                    case special_power_type::water: {
                        return 0;
                    }
                    case special_power_type::earth: {
                        return 2;
                    }
                    case special_power_type::air: {
                        return 1;
                    }
                    case special_power_type::fire: {
                        return 0;
                    }
                    case special_power_type::ice: {
                        return 0;
                    }
                    case special_power_type::steel: {
                        return 1;
                    }
                }
                break;

            }
            case special_power_type::steel: {
                switch (enemy.special_power) {
                    case special_power_type::water: {
                        return 2;
                    }
                    case special_power_type::earth: {
                        return 1;
                    }
                    case special_power_type::air: {
                        return 2;
                    }
                    case special_power_type::fire: {
                        return 0;
                    }
                    case special_power_type::ice: {
                        return 1;
                    }
                    case special_power_type::steel: {
                        return 0;
                    }
                }
                break;
            }

        }
    return 1;
}