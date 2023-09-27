#pragma once

#include "game.hpp"
#include "systemhal.hpp"

class GameRunner {
protected:
    static inline void reset(Game& game) {
        game.reset();
    }

    static void loop(Game& game) {
        float dt;
        while (SystemHAL::requestAnimationFrame(&dt))
            game.step(dt);
    }

    static inline int begin() {
        return SystemHAL::init();
    }

    static inline int end() {
        return SystemHAL::free();
    }
public:
    GameRunner() = delete;

    static void run(Game& game_ref) {
        // TODO: Check return values
        begin();
        reset(game_ref);
        loop(game_ref);
        end();
    }
};
