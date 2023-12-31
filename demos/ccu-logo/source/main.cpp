#include <nds.h>
#include <stdio.h> // NOLINT(modernize-deprecated-headers)
#include <nf_lib.h>
#include <filesystem.h>






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
    NF_InitTiledBgSys(0);

    NF_CreateTiledBg(0, 0, "green");


    while (true)
    {
        // Wait for the screen refresh
        swiWaitForVBlank();

        scanKeys();
        u16 buttons = keysDown();

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
