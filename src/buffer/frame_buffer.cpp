//
// Created by otoma on 9/3/2023.
//

#ifndef __gl_h
#include "glad.h"
#endif

#include "../window/window.h"
#include "frame_buffer.h"

# ifdef OBJECTGL_ON_OPENGL

objectgl::FrameBuffer::FrameBuffer() {
    glGenFramebuffers(1, &handle);
}

objectgl::FrameBuffer::~FrameBuffer() {
    glDeleteFramebuffers(1, &handle);
}

void objectgl::FrameBuffer::clear() {
    glBindFramebuffer(GL_FRAMEBUFFER, handle);
    glClear(-1); // clear all
}

#endif
