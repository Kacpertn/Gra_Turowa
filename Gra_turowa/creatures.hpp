#pragma once
#include <string>
namespace creatures {
    enum class special_power_type {
        water, earth, air, fire, ice, steel
    };
    struct creature {
        std::string name;
        int health_points;
        int strength;
        int agility;
        special_power_type special_power;
        int exp;
        int level;
        bool ult_ready;
        virtual auto show_stats() -> void;
        creature(std::string name, int health_points, int strength, int agility, special_power_type special_power,
                 int exp, int level, bool ult_ready);
    };

    struct oved : creature {
        oved();
    };

    struct meelis : creature {
        meelis();
    };

    struct boyka : creature {
        boyka();
    };

    struct yevgraf : creature {
        yevgraf();
    };

    struct siddharta : creature {
        siddharta();
    };

    struct fester : creature {
        fester();
    };

    struct skoler : creature {
        skoler();
    };

    struct cillia : creature {
        cillia();
    };

    struct linnea : creature {
        linnea();
    };

    struct varius : creature {
        varius();
    };

    struct arin : creature {
        arin();
    };

    struct odran : creature {
        odran();
    };

    struct maura : creature {
        maura();
    };

    struct vante : creature {
        vante();
    };

    struct methabel : creature {
        methabel();
    };

    auto attack(creature &player, creature &enemy) -> void;

    auto level_up(creature &creature) -> void;

    auto special_attack(creature& attacker, creature& enemy)-> void;
}