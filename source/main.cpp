// C++
#include <stdio.h>
#include <time.h>

// NDS
#include <nds.h>

// NF
#include <nf_lib.h>

// Project


int main(int argc, char **argv) {
	consoleDemoInit();
	consoleClear();

	NF_SetRootFolder("NITROFS");

	while(1) {
		swiWaitForVBlank();
	}

	return 0;
}