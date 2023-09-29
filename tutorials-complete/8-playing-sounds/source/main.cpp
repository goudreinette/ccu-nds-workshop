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

    // Initialize DS audio hardware. 
    // Should be called prior to attempting sound playback
    soundEnable();

    // Initialize all buffers and variables to load sound files.
    NF_InitRawSoundBuffers();

    // Load audio files from NitroFS
    NF_LoadRawSound("sfx/vine-boom", 0, 22050, 0);

    while (1)
    {
        scanKeys(); // Read keypad
        u16 newpress = keysDown(); // Keys just pressed

        touchPosition touch;
        touchRead(&touch);

        if (newpress & KEY_TOUCH) {
            NF_PlayRawSound(0, 127, 127, false, 0);
        }

        // Wait for the screen refresh
        swiWaitForVBlank();
    }
}