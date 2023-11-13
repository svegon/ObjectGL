//
// Created by otoma on 9/3/2023.
//
#ifdef OBJECTGL_ON_OPENGL
#include "glad.h"
#endif

#ifndef OBJECTGL_TEXTURE_H
#define OBJECTGL_TEXTURE_H

namespace objectgl {
    class Texture {
    private:

    protected:
        Texture();
    public:
        virtual ~Texture();
    };

    class Texture2D : Texture {
    private:

#   ifdef OBJECTGL_ON_OPENGL
        GLuint handle;
#   endif

    protected:
        Texture2D();

#   ifdef OBJECTGL_ON_OPENGL
        Texture2D(GLint wrap, GLint min_filter, GLint mag_filter);
#   endif

    public:
        virtual ~Texture2D();

#   ifdef OBJECTGL_ON_OPENGL
        void bind();

        void unbind();
#   endif
    };
}

#endif //OBJECTGL_TEXTURE_H
