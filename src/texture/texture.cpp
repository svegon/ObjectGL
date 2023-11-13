//
// Created by otoma on 9/3/2023.
//
#include "texture.h"

objectgl::Texture::Texture() = default;

objectgl::Texture::~Texture() = default;

objectgl::Texture2D::Texture2D() : Texture2D(GL_REPEAT, GL_NEAREST_MIPMAP_NEAREST,GL_NEAREST) {}

objectgl::Texture2D::Texture2D(GLint wrap, GLint min_filter, GLint mag_filter) : Texture() {
    glGenTextures(1, &handle);
    glBindTexture(GL_TEXTURE_2D, handle);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, min_filter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, mag_filter);
}

objectgl::Texture2D::~Texture2D() {
    glDeleteTextures(1, &handle);
}

void objectgl::Texture2D::bind() {
    glBindTexture(GL_TEXTURE_2D, handle);
}

void objectgl::Texture2D::unbind() {
    glBindTexture(GL_TEXTURE_2D, NULL);
}
