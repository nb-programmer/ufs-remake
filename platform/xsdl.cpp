/**
 * Cross-platform desktop engine using SDL2
 */


#include <iostream>

namespace SystemHAL {
    int init() {
        return 0;
    }
    int free() {
        return 0;
    }
    bool requestAnimationFrame(float *dt) {
        return true;
    }
}
