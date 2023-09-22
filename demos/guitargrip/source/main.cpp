#include <nds.h>
#include <stdio.h> // NOLINT(modernize-deprecated-headers)
#include <string>
#include <vector>
#include <filesystem.h>
#include <nf_lib.h>
#include <nds.h>


int main()
{
    // Initialize 2D engine in both screens and use mode 0
    NF_Set2D(0, 5);
    NF_Set2D(1, 5);

    consoleDemoInit();
    printf("\n Loading artificial... \n\n");
    swiWaitForVBlank();

    // Initialize NitroFS and set it as the root folder of the filesystem
    nitroFSInit(nullptr);
    NF_SetRootFolder("NITROFS");


    NF_InitTiledBgBuffers();
    NF_InitTiledBgSys(0);

    NF_LoadTiledBg("red", "red", 256, 256);
    NF_LoadTiledBg("blue", "blue", 256, 256);
    NF_LoadTiledBg("green", "green", 256, 256);
    NF_LoadTiledBg("yellow", "yellow", 256, 256);



    while (true)
    {
        // Wait for the screen refresh
        swiWaitForVBlank();

        guitarGripScanKeys();
        scanKeys();
        u16 keys = guitarGripKeysDown();
        u16 buttons = keysDown();

        if (keys & GUITARGRIP_GREEN || buttons & KEY_UP) {
            NF_CreateTiledBg(0, 0, "green");
            printf("\n GREEN pressed!");
        }
        // the rest of the keys
        if (keys & GUITARGRIP_RED || buttons & KEY_RIGHT) {
            NF_CreateTiledBg(0, 0, "red");
            printf("\n RED pressed!");
        }
        if (keys & GUITARGRIP_YELLOW || buttons & KEY_DOWN) {
            NF_CreateTiledBg(0, 0, "yellow");
            printf("\n YELLOW pressed!");
        }
        if (keys & GUITARGRIP_BLUE || buttons & KEY_LEFT) {
            NF_CreateTiledBg(0, 0, "blue");
            printf("\n BLUE pressed!");
        }
    }

    // If this is reached, the program will return to the loader if the loader
    // supports it.
    return 0;
}
