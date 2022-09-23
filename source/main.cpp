#include <stdio.h>
#include <time.h>
#include <nds.h>
#include <nf_lib.h>
#include "vlf_input.h"
#include "vlf_rand.h"

int main(int argc, char **argv) {
	vlf_rand::setSeed((long int)time(NULL));

	// Initialize the console
	consoleDemoInit();
	consoleClear();

	// Initialize Nitro File System
	NF_SetRootFolder("NITROFS");

	while(1) {
		// Input
		scanKeys();
		touchRead(&vlf_input::touch);

		

		// Render
		swiWaitForVBlank();
		oamUpdate(&oamMain);
		oamUpdate(&oamSub);
	}

	return 0;
}