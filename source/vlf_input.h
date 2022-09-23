#ifndef VLF_INPUT_H
#define VLF_INPUT_H
#include <nf_lib.h>

namespace vlf_input {
    touchPosition touch;
    bool getKey(int keyCode) { return keysHeld() & keyCode; }
    bool getKeyDown(int keyCode) { return keysDown() & keyCode; }
    bool getKeyUp(int keyCode) { return keysUp() & keyCode; }
}
#endif