#include <nds.h>
#include <stdio.h>
#include <nf_lib.h>
#include <filesystem.h>


// The palette is the same for every sprite
const int PALLETTE_ID = 0;


// To keep track of the different sprites
enum SpriteID {
    FireSparksID
};


struct FireSparks {
    const char* file;
    SpriteID spriteId;
    int x, y;
    int width, height;
};


FireSparks fireSparks = {
    file: "cat-space",
    spriteId: FireSparksID,
    x: 0,
    y: 0,
    width: 64,
    height: 64
};


int main(int argc, char **argv)
{
    // Initialize 2D engine in both screens and use mode 5
    NF_Set2D(0, 5);
    NF_Set2D(1, 5);

    // Initialize the console on the top screen
    consoleInit(NULL, 0, BgType_Text4bpp, BgSize_T_256x256, 31, 0, true, true);
    printf("\n Loading buttons demo... \n\n");

    // Initialize NitroFS and set it as the root folder of the filesystem
    nitroFSInit(nullptr);
    NF_SetRootFolder("NITROFS");

    // Initialize the background and sprites engine on the bottom screen
    NF_InitSpriteBuffers();
    NF_InitSpriteSys(1);

    // Load the Palette and transfer it to VRAM
    NF_LoadSpritePal("cat-space", PALLETTE_ID);
    NF_VramSpritePal(1, PALLETTE_ID, PALLETTE_ID);


    // Load the button sprites
    NF_LoadSpriteGfx(fireSparks.file, fireSparks.spriteId, fireSparks.width, fireSparks.height);
    // Transfer our sprite to VRAM
    NF_VramSpriteGfx(1, fireSparks.spriteId, fireSparks.spriteId, true);
    // Create the sprites
    NF_CreateSprite(1, fireSparks.spriteId, fireSparks.spriteId, PALLETTE_ID, fireSparks.x, fireSparks.y);
    
    // Keep track of the current animation frame
    int fire_frame = 0;

    while (true)
    {
        fire_frame++;

        // Print "frame number x of 19" on the bottom screen
        printf("\x1b[1;1Hframe number %d of 8    ", fire_frame);

        // Update the sprite frame
        NF_SpriteFrame(1, FireSparksID, fire_frame / 10 % 8);
      
        // Update the sprites on the screen
        NF_SpriteOamSet(1);
        // Wait for the screen refresh
        swiWaitForVBlank();
        oamUpdate(&oamMain);
        oamUpdate(&oamSub);
    }

    // If this is reached, the program will return to the loader if the loader
    // supports it.
    return 0;
}

