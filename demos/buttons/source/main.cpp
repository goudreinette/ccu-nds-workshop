#include <nds.h>
#include <stdio.h>
#include <nf_lib.h>
#include <filesystem.h>


// The palette is the same for every sprite
const int PALLETTE_ID = 0;


// To keep track of the different sprites
enum SpriteID {
    UP, DOWN, LEFT, RIGHT,
    L, R, 
    A, B, X, Y,
    START, SELECT,
};


struct ButtonSprite {
    const char* file;
    SpriteID spriteId;
    int x, y;
    int width, height;
    KEYPAD_BITS key;
};


ButtonSprite buttonSprites[] = {
    ButtonSprite {
        file: "up", 
        spriteId: UP, 
        x: 48, 
        y: 65, 
        width: 16, 
        height: 16,
        key: KEY_UP
    },
    ButtonSprite {
        file: "down", 
        spriteId: DOWN, 
        x: 48, 
        y: 97, 
        width: 16, 
        height: 16,
        key: KEY_DOWN
    },
    ButtonSprite {
        file: "left",
        spriteId: LEFT,
        x: 32, 
        y: 81,
        width: 16,
        height: 16,
        key: KEY_LEFT
    },
    ButtonSprite {
        file: "right",
        spriteId: RIGHT,
        x: 64, 
        y: 81,
        width: 16,
        height: 16,
        key: KEY_RIGHT
    },
    ButtonSprite {
        file: "l",
        spriteId: L,
        x: 32, 
        y: 24,
        width: 32,
        height: 16,
        key: KEY_L
    },
    ButtonSprite {
        file: "r",
        spriteId: R,
        x: 192, 
        y: 23,
        width: 32,
        height: 16,
        key: KEY_R
    },
    ButtonSprite {
        file: "a",
        spriteId: A,
        x: 208, 
        y: 81,
        width: 16,
        height: 16,
        key: KEY_A
    },
    ButtonSprite {
        file: "b",
        spriteId: B,
        x: 192, 
        y: 97,
        width: 16,
        height: 16,
        key: KEY_B
    },
    ButtonSprite {
        file: "x",
        spriteId: X,
        x: 192, 
        y: 65,
        width: 16,
        height: 16,
        key: KEY_X
    },
    ButtonSprite {
        file: "y",
        spriteId: Y,
        x: 176, 
        y: 81,
        width: 16,
        height: 16,
        key: KEY_Y
    },
    ButtonSprite {
        file: "start",
        spriteId: START,
        x: 176, 
        y: 136,
        width: 16,
        height: 16,
        key: KEY_START
    },
    ButtonSprite {
        file: "select",
        spriteId: SELECT,
        x: 176, 
        y: 152,
        width: 16,
        height: 16,
        key: KEY_SELECT
    }
};



int main(int argc, char **argv)
{
    // Initialize 2D engine in both screens and use mode 5
    NF_Set2D(0, 5);
    NF_Set2D(1, 5);

    consoleDemoInit();
    printf("\n Loading buttons demo... \n\n");
    swiWaitForVBlank();

    // Initialize NitroFS and set it as the root folder of the filesystem
    nitroFSInit(nullptr);
    NF_SetRootFolder("NITROFS");

    // Initialize the background and sprites engine on the bottom screen
    NF_InitTiledBgBuffers();
    NF_InitTiledBgSys(1);
    NF_InitSpriteBuffers();
    NF_InitSpriteSys(1);

    // Load and create the background
    NF_LoadTiledBg("background", "background", 256, 256);
    NF_CreateTiledBg(1, 0, "background");

    // Load the Palette and transfer it to VRAM
    NF_LoadSpritePal("up", PALLETTE_ID);
    NF_VramSpritePal(1, PALLETTE_ID, PALLETTE_ID);


    // Load the button sprites
    for (int i = 0; i < sizeof(buttonSprites) / sizeof(ButtonSprite); i++) {
        ButtonSprite buttonSprite = buttonSprites[i];
        NF_LoadSpriteGfx(buttonSprite.file, buttonSprite.spriteId, buttonSprite.width, buttonSprite.height);
        // Transfer our sprite to VRAM
        NF_VramSpriteGfx(1, buttonSprite.spriteId, buttonSprite.spriteId, true);
        // Create the sprites
        NF_CreateSprite(1, buttonSprite.spriteId, buttonSprite.spriteId, PALLETTE_ID, buttonSprite.x, buttonSprite.y);
    }


    while (true)
    {
        scanKeys();
        u16 buttons = keysHeld();

        // Turn the button sprites on or off when you press them
        for (int i = 0; i < sizeof(buttonSprites) / sizeof(ButtonSprite); i++) {
            ButtonSprite buttonSprite = buttonSprites[i];
            NF_ShowSprite(1, buttonSprite.spriteId, buttons & buttonSprite.key);
        }

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

