#include "renderer.h"
#include "source/math/vector2.cpp"
#include <sstream>
#include <string.h>

Renderer::Renderer() 
{
    // Set both screens to 2D render mode
    NF_Set2D(TOP_SCREEN, 0);
    NF_Set2D(BOTTOM_SCREEN, 0);

    // Initialize the background buffers
    NF_InitTiledBgBuffers();

    // Initialize the background system
    NF_InitTiledBgSys(TOP_SCREEN);
    NF_InitTiledBgSys(BOTTOM_SCREEN);
}

Renderer::~Renderer() 
{
    deleteAllBackgrounds();
}

const char* Renderer::getBackgroundName(u8 screen, u8 layer) {
    std::string s = "";
    s += std::to_string(screen);
    s += std::to_string(layer);
    return s.c_str();
}

void Renderer::setBackground(const char* file, u16 width, u16 height, u8 screen, u8 layer) {
    // Get the background name from the screen and layer
    const char* name = getBackgroundName(screen, layer);

    // Load the background from FAT
    NF_LoadTiledBg(file, name, width, height);

    // Create the background
    NF_CreateTiledBg(screen, layer, name);

    // Delete from RAM if the background is less than 512x512
    if (width <= 512 && height <= 512)
        NF_UnloadTiledBg(name);
}

void Renderer::deleteBackground(u8 screen, u8 layer) {
    // Get the background name from the screen and layer
    const char* name = getBackgroundName(screen, layer);

    // Delete and unload the background
    NF_DeleteTiledBg(screen, layer);
    NF_UnloadTiledBg(name);
}

void Renderer::deleteAllBackgrounds() {
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            deleteBackground(i, j);
        }
    }
}

void Renderer::render()
{

}