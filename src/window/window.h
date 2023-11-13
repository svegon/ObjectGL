//
// Created by otoma on 9/2/2023.
//
#include <cstdint>
#include <utility>

#ifndef OBJECTGL_WINDOW_H
#define OBJECTGL_WINDOW_H

#ifdef OBJECTGL_ON_OPENGL
#include <GLFW/glfw3.h>
#endif

#include "../buffer/frame_buffer.h"
#include "../device/monitor.h"

typedef unsigned int window_s;

namespace objectgl {
    class Window {
    private:
#ifdef OBJECTGL_ON_OPENGL
        GLFWwindow* handle;
#endif
    public:
        Window();

        Window(const Monitor&);

        Window(const Window&);

        ~Window();

        window_s get_width();

        window_s get_height();

        std::pair<window_s, window_s> get_size();

        void render(FrameBuffer);

        void clear(float, float, float);
    };
}

#endif //OBJECTGL_WINDOW_H
