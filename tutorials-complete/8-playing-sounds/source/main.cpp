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
    NF_LoadRawSound("sfx/sample", 0, 11025, 0);

    // // Start background music
    // u8 sound_id = NF_PlayRawSound(1, 127, 64, true, 0);

    while (1)
    {
        scanKeys(); // Read keypad
        u16 newpress = keysDown(); // Keys just pressed

         if (newpress & KEY_R)
            NF_PlayRawSound(0, 127, 127, false, 0);

        // Wait for the screen refresh
        swiWaitForVBlank();
    }
}