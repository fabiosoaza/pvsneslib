/*---------------------------------------------------------------------------------


	Simple test of pal/ntsc console demo (from makefile) 
	-- alekmaul


---------------------------------------------------------------------------------*/
#include <snes.h>

extern char snesfont;

//---------------------------------------------------------------------------------
int main(void) {
    // Initialize SNES 
	consoleInit();
    
    // Initialize text console with our font
	consoleInitText(0, 0, &snesfont);

	// Now Put in 16 color mode and disable Bgs except current
	setMode(BG_MODE1,0);  bgSetDisable(1);  bgSetDisable(2);

	// Draw a wonderfull text :P
	consoleDrawText(10,10,"Hello World !");
    if (snes_50hz==1) {
        consoleDrawText(5,14,"YOU USE A PAL CONSOLE");
    }
    else {
        consoleDrawText(5,14,"YOU USE A NTSC CONSOLE");
    }

	// Wait for nothing :P
	setScreenOn();  
	
	while(1) {
		WaitForVBlank();
	}
	return 0;
}