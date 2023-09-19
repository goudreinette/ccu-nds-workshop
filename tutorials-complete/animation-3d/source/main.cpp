#include <nds.h>
#include <stdio.h>
#include <nf_lib.h>
#include <filesystem.h>


// The palette is the same for every sprite
const int PALLETTE_ID = 0;
const int SPRITE_ID = 0;



int main(int argc, char **argv)
{
    // Initialize 2D engine in both screens and use mode 5
    NF_Set2D(0, 0);
    NF_Set2D(1, 0);

    // Initialize the console on the top screen
    consoleInit(NULL, 1, BgType_Text4bpp, BgSize_T_256x256, 31, 0, false, true);
    printf("\n Loading buttons demo... \n\n");

    // Initialize NitroFS and set it as the root folder of the filesystem
    nitroFSInit(nullptr);
    NF_SetRootFolder("NITROFS");

    // Initialize 3D engine in the top screen in mode 0
    NF_Set3D(1, 0);

    // Initialize tiled backgrounds system
    NF_InitTiledBgBuffers();    // Initialize storage buffers
    NF_InitTiledBgSys(0);       // Top screen
    NF_InitTiledBgSys(1);       // Bottom screen

    // Initialize the background and sprites engine on the bottom screen
    NF_InitSpriteBuffers();
    NF_Init3dSpriteSys();

    // Load the Palette and transfer it to VRAM
    NF_LoadSpritePal("fire-sparks", PALLETTE_ID);


    // Load the button sprites
    NF_LoadSpriteGfx("fire-sparks", SPRITE_ID, 64, 64);
    // Transfer our sprite to VRAM
    NF_Vram3dSpriteGfx(SPRITE_ID, SPRITE_ID, true);
    NF_Vram3dSpritePal(SPRITE_ID, SPRITE_ID);
    // Create the sprites
    NF_Create3dSprite(SPRITE_ID, SPRITE_ID, PALLETTE_ID, (256 / 2) - 32, 32);
    // Make it 4x as big
    NF_Scale3dSprite(SPRITE_ID, 256, 256);


    
    int fire_frame = 0;
    int fire_frame_t = 0;


    while (true)
    {
        scanKeys();
        u16 buttons = keysHeld();

        fire_frame_t++; // Slow down 4 times
        if (fire_frame_t % 2 == 0) {
            fire_frame = (fire_frame + 1) % 19; // 19 frames

            // Update the frame of the sprite
            NF_Set3dSpriteFrame(SPRITE_ID, fire_frame);
        }

        // Print "frame number x of 19" on the bottom screen
        printf("\x1b[1;1Hframe number %d of 19    ", fire_frame);

         // Draw all 3D sprites
        NF_Draw3dSprites();

        // Tell the GPU to draw the scene and wait until it's done
        glFlush(0);

        // Wait for the screen refresh
        swiWaitForVBlank();

        // Update textures of any 3D sprite with "keepframes == true"
        NF_Update3dSpritesGfx();
    }

    // If this is reached, the program will return to the loader if the loader
    // supports it.
    return 0;
}

