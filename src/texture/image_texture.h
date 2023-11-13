//
// Created by otoma on 9/3/2023.
//
#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#endif

#ifndef OBJECTGL_IMAGE_TEXTURE_H
#define OBJECTGL_IMAGE_TEXTURE_H

#include <filesystem>

#include "stb_image.h"

#include "texture.h"
#include "../window/window.h"

namespace objectgl {
    class ImageTexture : Texture2D {
    private:
        window_s width;
        window_s height;
#   ifdef OBJECTGL_ON_OPENGL
        GLenum format;
#   endif
    public:
        ImageTexture(std::filesystem::path);

#   ifdef OBJECTGL_ON_OPENGL
        ImageTexture(window_s width, window_s height, GLenum format, void* image);

        ImageTexture(GLint wrap, GLint min_filter, GLint mag_filter, window_s width,
                     window_s height, GLenum format, void* image);

        [[nodiscard]] GLenum get_format() const;
#   endif

        [[nodiscard]] window_s get_width() const;

        [[nodiscard]] window_s get_height() const;

        [[nodiscard]] std::pair<window_s, window_s> get_size() const;
    };
}

#endif //OBJECTGL_IMAGE_TEXTURE_H
