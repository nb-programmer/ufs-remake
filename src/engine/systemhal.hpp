#pragma once

namespace SystemHAL {
    extern int init();
    extern int free();
    extern bool requestAnimationFrame(float *dt);
}
