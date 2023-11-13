//
// Created by otoma on 9/3/2023.
//

#ifndef OBJECTGL_FRAMEBUFFER_H
#define OBJECTGL_FRAMEBUFFER_H

#ifdef OBJECTGL_ON_OPENGL
#include "GLFW/glfw3.h"
#endif

#include "../window/window.h"

namespace objectgl {
    class FrameBuffer final {
    private:
#   ifdef OBJECTGL_ON_OPENGL
        GLuint handle;
#   endif
    public:
        FrameBuffer();

        ~FrameBuffer();

        void clear();

        friend class Window;
    };
}


#endif //OBJECTGL_FRAMEBUFFER_H
