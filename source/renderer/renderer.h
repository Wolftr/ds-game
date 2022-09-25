#ifndef RENDERER_H
#define RENDERER_H
#include <nf_lib.h>
#include "source/math/vector2.h"

// Screen
#define TOP_SCREEN 0
#define BOTTOM_SCREEN 1

class Renderer {
    static const char* getBackgroundName(u8 screen, u8 layer);
public:
    Renderer();
    ~Renderer();
    void setSpritePosition(u8 screen, u8 id);
    void changeSpriteLayer(u8 screen, u8 id, u8 layer);
    void setBackground(const char* file, u16 width, u16 height, u8 screen, u8 layer);
    void deleteBackground(u8 screen, u8 layer);
    void deleteAllBackgrounds();
    void render();
};
#endif