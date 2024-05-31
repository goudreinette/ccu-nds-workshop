// Tutorial: 8 - Playing Sounds
#include <stdio.h>
#include <nds.h>
#include <filesystem.h>

#include <nf_lib.h>



int main() 
{
    // Initialize 2D engine in both screens and use mode 0
    NF_Set2D(0, 5);
    NF_Set2D(1, 5);


    // Initialize NitroFS and set it as the root folder of the filesystem
    nitroFSInit(NULL);
    NF_SetRootFolder("NITROFS");

    // Initialize DS audio hardware. 
    // Should be called prior to attempting sound playback
    soundEnable();

    // Initialize all buffers and variables to load sound files.
    NF_InitRawSoundBuffers();

    // Load audio files from NitroFS
    NF_LoadRawSound("sfx/vine-boom", 0, 11025, 0);


    NF_PlayRawSound(0, 127, 64, false, 0); 


    consoleDemoInit();
    printf("\n Touch to play sound \n\n");
   

    while (1) {
        scanKeys(); // Read keypad
        u16 newpress = keysDown(); // Keys just pressed

        touchPosition touch;
        touchRead(&touch);

        if (newpress & KEY_TOUCH) {
            NF_PlayRawSound(0, 127, 64, false, 0); 
        }

        // Wait for the screen refresh
        swiWaitForVBlank();
    }
}