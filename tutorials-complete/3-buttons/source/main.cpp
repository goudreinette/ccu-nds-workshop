#include <nds.h> 
#include <stdio.h>
#include <nf_lib.h> // Include NFlib, which we will use to work with sprites
#include <filesystem.h> // Include filesystem, needed to load files from NitroFS



int main()
{
    consoleDemoInit();

    printf("Press buttons to see them \nprinted on the screen\n");

    
    while (true)
    {
        scanKeys();
        int buttons = keysDown();

        if (buttons & KEY_A) {
            printf("A pressed\n");
        }
        if (buttons & KEY_B) {
            printf("B pressed\n");
        }
        if (buttons & KEY_X) {
            printf("X pressed\n");
        }
        if (buttons & KEY_Y) {
            printf("Y pressed\n");
        }
        if (buttons & KEY_L) {
            printf("L pressed\n");
        }
        if (buttons & KEY_R) {
            printf("R pressed\n");
        }
        if (buttons & KEY_START) {
            printf("START pressed\n");
        }
        if (buttons & KEY_SELECT) {
            printf("SELECT pressed\n");
        }
        if (buttons & KEY_UP) {
            printf("UP pressed\n");
        }
        if (buttons & KEY_DOWN) {
            printf("DOWN pressed\n");
        }
        if (buttons & KEY_LEFT) {
            printf("LEFT pressed\n");
        }
        if (buttons & KEY_RIGHT) {
            printf("RIGHT pressed\n");
        }

       
        // Wait for the screen refresh
        swiWaitForVBlank();
    }
}

