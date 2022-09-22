// C++
#include <stdio.h>
#include <time.h>

// NDS
#include <nds.h>

// NF
// Makefile is not set to compile with NitroFox right now, will fix later
// #include <nf_lib.h>

// Project


int main(int argc, char **argv) {
	consoleDemoInit();
	consoleClear();

	// NF_SetRootFolder("NITROFS");

	while(1) {
		swiWaitForVBlank();
	}

	return 0; 
}