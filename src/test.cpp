//
// Created by otoma on 9/9/2023.
//
#include <windows.h>
#include "objectgl.h"

using namespace objectgl;
using namespace std;

int main() {
    Window window;
    FrameBuffer framebuffer;

    window.clear(1, 0, 1);

    while (true) {
        window.render(framebuffer);
    }
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, PSTR, int) {
    return main();
}
