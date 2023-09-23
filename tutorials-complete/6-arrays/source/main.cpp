#include <nds.h> 
#include <stdio.h>
#include <nf_lib.h> 
#include <filesystem.h>
#include <vector>


// We will use this to indentify the palette of the sprite and the sprite itself
const int PALLETTE_ID = 0;
const int SPRITE_RAM_SLOT = 0;


struct Fire {
    int x;
    int y;
};

// The vector will contain all the fires on the screen
const auto fires = std::vector<Fire>();




int main()
{
    // Initialize 2D engine in the bottom screen
    NF_Set2D(1, 0);

    // The following code is the same as in the previous tutorials ------------

    // Initialize NitroFS and set it as the root folder of the filesystem
    nitroFSInit(nullptr);
    NF_SetRootFolder("NITROFS");

    // This function needs to be called before loading any sprites
    NF_InitSpriteBuffers();
    // Initialize sprite system in the bottom screen
    NF_InitSpriteSys(1);


    // Load the sprite's palette from filesystem to RAM...
    NF_LoadSpritePal("fire", PALLETTE_ID);
    // ... and transfer it to VRAM of the bottom screen.
    NF_VramSpritePal(1, PALLETTE_ID, PALLETTE_ID);
    // If you want to use the same palette for multiple sprites, you only need to do this once.

    // Load the sprite's graphics from filesystem to RAM...
    NF_LoadSpriteGfx("fire", 0, 32, 32);
    // ... and transfer it to VRAM of the bottom screen
    NF_VramSpriteGfx(1, 0, 0, true);


    // --------------------------------


    

    // Finally create the sprite on the center of the screen
    // NF_CreateSprite(1, 0, 0, PALLETTE_ID, x, y);


    
    while (true)
    {
        // Read the touch screen
        touchPosition touch;
        touchRead(&touch);

        
        // If the user touched the screen...
        if (touch.px != 0 && touch.py != 0)  {
            // ... move the sprite to the position of the touch screen
            NF_MoveSprite(1, 0, touch.px - 16, touch.py - 16);
        }

        // Update the sprites on the screen: 
        // copy data from the shadow Object Attribute Memory used by NFLib 
        // to the real OAM of libnds.
        NF_SpriteOamSet(1);
        // Wait for the screen refresh
        swiWaitForVBlank();
        oamUpdate(&oamSub);
    }
}

