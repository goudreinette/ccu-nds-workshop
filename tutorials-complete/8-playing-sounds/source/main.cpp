// Tutorial: 8 - Playing Sounds
#include <stdio.h>
#include <nds.h>
#include <filesystem.h>

#include <nf_lib.h>



int main() 
{
    // Initialize NitroFS and set it as the root folder of the filesystem
    nitroFSInit(NULL);
    NF_SetRootFolder("NITROFS");

    NF_Set2D(0, 0); // Set 2D mode

    NF_InitBitmapBgSys(0, 1);
    
    NF_Init16bitsBgBuffers(); // Initialize background buffers
    NF_InitAffineBgSys(0); // Initialize background system


    NF_Load16bitsBg("background", 0); // Load background


    NF_CreateAffineBg(0, 3, "background", true); // Create background layer


    // Initialize DS audio hardware. 
    // Should be called prior to attempting sound playback
    soundEnable();

    // Initialize all buffers and variables to load sound files.
    NF_InitRawSoundBuffers();

    // Load audio files from NitroFS
    NF_LoadRawSound("sfx/vine-boom", 0, 22050, 0);
    NF_LoadRawSound("sfx/sample", 1, 11025, 0);

    while (1)
    {
        scanKeys(); // Read keypad
        u16 newpress = keysDown(); // Keys just pressed

        touchPosition touch;
        touchRead(&touch);


         if (newpress & KEY_TOUCH) {
            if (touch.px > SCREEN_WIDTH / 2) {
                NF_PlayRawSound(0, 127, 127, false, 0);
            } else {
                NF_PlayRawSound(1, 127, 127, false, 0);
            }
         }

        // Wait for the screen refresh
        swiWaitForVBlank();
    }
}