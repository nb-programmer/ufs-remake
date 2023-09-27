/**
 * Main game shell
 */

#include "engine/runner.hpp"
#include "game/ufs.hpp"


int main() {
    UltimateFlashSonic game;
    GameRunner::run(game);
    return 0;
}
