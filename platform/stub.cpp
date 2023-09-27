
#include <iostream>

#define __IN__
#define __OUT__

namespace SystemHAL {
    int init() {
        return 0;
    }

    int free() {
        return 0;
    }

    bool requestAnimationFrame(__OUT__ float *dt) {
        return true;
    }
}

namespace GameHAL {
    typedef struct {
        unsigned int width;
        unsigned int height;
    } Dimensions;

    using Viewport = Dimensions;

    void getViewport(__OUT__ Viewport *dim) {

    }

    void setViewport(__IN__ Viewport &dim) {

    }
}
