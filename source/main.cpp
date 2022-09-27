#include <stdio.h>
#include <time.h>
#include <nds.h>
#include <nf_lib.h>
#include "renderer/renderer.h"
#include "math/vector2.h"
#include "vlf_input.h"
#include "vlf_rand.h"

int main(int argc, char **argv) {
	// Initialize the random function
	vlf_rand::setSeed((long int)time(NULL));

	// Initialize the console
	consoleDemoInit();
	consoleClear();

	// Initialize Nitro File System
	NF_SetRootFolder("NITROFS");

	// Initialize the renderer
	Renderer renderer = Renderer();
	renderer.setBackground("bg/screen1", 256, 256, BOTTOM_SCREEN, 1);

	while(1) {
		// Input
		scanKeys();
		touchRead(&vlf_input::touch);
		
		// Update
		
		
		// Render
		NF_SpriteOamSet(TOP_SCREEN); 
		NF_SpriteOamSet(BOTTOM_SCREEN); 
		
		swiWaitForVBlank();
		
		oamUpdate(&oamMain);
		oamUpdate(&oamSub);
	}

	return 0;
}

// Force all cpp files to be included in the build even when not referenced anywhere else
#include "math/vector2.cpp"
#include "renderer/renderer.cpp"