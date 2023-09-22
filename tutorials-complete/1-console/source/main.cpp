#include <nds.h>
#include <stdio.h>
#include <filesystem.h>




int main()
{
    // Initialize the console to a default state for prototyping.
    // This function sets the console to use sub display using MODE_0_2D and BG0.
    consoleDemoInit();
    printf("Hello, world!... \n\n");

    int frame = 0;

    // The main loop of the program.
    // This loop runs forever, as long as the program is not terminated.
    while (true)
    {
        // Print a message to the screen.
        // The \x1b[0;1H sequence moves the cursor to the second line, just below "Hello, world!".
        // Without this sequence, the text would keep scrolling down the screen.
        printf("\x1b[1;0HFrame: %d\n", frame);

        // Wait for the screen refresh
        swiWaitForVBlank();

        // Increment the frame counter
        frame++;
    }

    // If this is reached, the program will return to the loader if the loader
    // supports it.
    return 0;
}

