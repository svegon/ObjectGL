//
// Created by otoma on 9/2/2023.
//
#include "stdexcept"

#include "window.h"

#ifdef OBJECTGL_ON_OPENGL
objectgl::Window::Window() {
    if (!glfwInit()) {
        throw std::runtime_error("Couldn't initialize GLFW");
    }

    glfwDefaultWindowHints();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    handle = glfwCreateWindow(0, 0, "", nullptr, nullptr);

    if (handle == nullptr) {
        throw std::runtime_error("Failed to allocate GLFW window.");
    }
}

objectgl::Window::Window(const objectgl::Monitor &monitor) {
    if (!glfwInit()) {
        throw std::runtime_error("Couldn't initialize GLFW");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    handle = glfwCreateWindow(0, 0, "", monitor.handle, nullptr);

    if (handle == nullptr) {
        throw std::runtime_error("Failed to allocate GLFW window.");
    }
    // todo add event handlers
}

objectgl::Window::Window(const objectgl::Window &window) {
    //todo
}

objectgl::Window::~Window() {
    glfwDestroyWindow(handle);
}

window_s objectgl::Window::get_width() {
    window_s width;
    glfwGetWindowSize(handle, reinterpret_cast<int *>(&width), nullptr);
    return width;
}

window_s objectgl::Window::get_height() {
    window_s height;
    glfwGetWindowSize(handle, nullptr, reinterpret_cast<int *>(&height));
    return height;
}

std::pair<window_s, window_s> objectgl::Window::get_size() {
    std::pair<window_s, window_s> size;
    glfwGetWindowSize(handle, reinterpret_cast<int *>(&size.first),
                      reinterpret_cast<int *>(&size.second));
    return size;
}

void objectgl::Window::render(objectgl::FrameBuffer frame_buffer) {
    glfwMakeContextCurrent(handle);

}

void objectgl::Window::clear(float r, float g, float b) {
    glfwMakeContextCurrent(handle);
    glClearColor(r, g, b, 1);
}

#endif
