//
// Created by otoma on 9/9/2023.
//
#include <stdexcept>
#include "image_texture.h"

objectgl::ImageTexture::ImageTexture(std::filesystem::path path) {
    int w, h, comps;
    GLenum f;
    unsigned char* image = stbi_load(path.string().c_str(), &w,&h, &comps, 0);

    if (image == nullptr) {
        throw std::runtime_error(std::string("invalid image path: ") + path.string());
    }

    switch (comps) {
        /**
         * theoretically we could have some single/double component images but they're too rare to make me
         * covering the cases worth it
         */
        case 3:
            f = GL_RGB8;
            break;
        case 4:
            f = GL_RGBA8;
            break;
        default:
            throw std::runtime_error(std::string("unexpected number of image's components ")
            + std::to_string(comps) + std::string(" for image ") + path.string());
    }

    this->width = w;
    this->height = h;
    this->format = f;

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, (GLsizei) w, (GLsizei) h, 0, f, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, NULL);

    stbi_image_free(image);
}

#ifdef OBJECTGL_ON_OPENGL
objectgl::ImageTexture::ImageTexture(window_s width, window_s height, GLenum format, void *image)
: ImageTexture(GL_REPEAT, GL_NEAREST_MIPMAP_NEAREST, GL_NEAREST, width, height, format, image)
{}

objectgl::ImageTexture::ImageTexture(GLint wrap, GLint min_filter, GLint mag_filter, window_s width, window_s height,
                                     GLenum format, void *image) : Texture2D(wrap, min_filter, mag_filter) {
    this->width = width;
    this->height = height;
    this->format = format;

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, (GLsizei) width, (GLsizei) height, 0, format, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, NULL);
}

window_s objectgl::ImageTexture::get_width() const {
    return width;
}

window_s objectgl::ImageTexture::get_height() const {
    return height;
}

std::pair<window_s, window_s> objectgl::ImageTexture::get_size() const {
    return std::pair<window_s, window_s>{width, height};
}

GLenum objectgl::ImageTexture::get_format() const {
    return format;
}

#endif

