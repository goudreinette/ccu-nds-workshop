#include <nds.h>
#include <stdio.h>
#include <nf_lib.h>
#include <filesystem.h>


enum Sprites
{
    UP, DOWN, LEFT, RIGHT,
    L, R, 
    A, B, X, Y,
    START, SELECT,
};


int main(int argc, char **argv)
{
    // Initialize 2D engine in both screens and use mode 0
    NF_Set2D(0, 5);
    NF_Set2D(1, 5);

    consoleDemoInit();
    printf("\n Loading buttons demo... \n\n");
    swiWaitForVBlank();

    // Initialize NitroFS and set it as the root folder of the filesystem
    nitroFSInit(nullptr);
    NF_SetRootFolder("NITROFS");

    NF_InitTiledBgBuffers();
    NF_InitTiledBgSys(1);

    // Create the buttons background
    NF_LoadTiledBg("background", "background", 256, 256);
    NF_CreateTiledBg(1, 0, "background");

    // Load the button sprites
    NF_LoadSpriteGfx("buttons", 0, 16, 16);

    while (true)
    {
        // Wait for the screen refresh
        swiWaitForVBlank();

        scanKeys();
        u16 buttons = keysDown();


        // Turn the button sprites on or off 


        if (buttons & KEY_UP) {

        }
        if (buttons & KEY_RIGHT) {

        }
        if (buttons & KEY_DOWN) {

        }
        if (buttons & KEY_LEFT) {

        }
        
    }

    // If this is reached, the program will return to the loader if the loader
    // supports it.
    return 0;
}
