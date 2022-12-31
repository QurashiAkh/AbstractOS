#include "framebuffer.c"

void kmain()
{
    char buffer[] = "Welcome to AbstractOS!";

    // Decrementing it by 1 so the cursor doesn't put another space after it
    // Too lazy to put that in the fb_write function
    fb_write(buffer, sizeof(buffer) - 1);
}
