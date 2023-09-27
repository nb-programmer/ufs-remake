#pragma once

class Game {
public:
    virtual void reset() = 0;
    virtual bool step(float dt) = 0;
};
