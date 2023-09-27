#pragma once

#include "../engine/game.hpp"


class UltimateFlashSonic : public Game {
public:
    void reset() override;
    bool step(float dt) override;
};
