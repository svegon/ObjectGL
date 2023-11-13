//
// Created by otoma on 9/3/2023.
//
#include "../window/window.h"

#ifdef OBJECTGL_ON_OPENGL
#include "GLFW/glfw3.h"
#endif

#ifndef OBJECTGL_MONITOR_H
#define OBJECTGL_MONITOR_H

namespace objectgl {
    class Monitor {
    private:
#ifdef OBJECTGL_ON_OPENGL
        GLFWmonitor* handle;
#endif

    friend class Window;
    };
}

#endif //OBJECTGL_MONITOR_H
