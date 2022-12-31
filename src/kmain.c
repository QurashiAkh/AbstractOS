#include "drivers/frame_buffer.c"
#include "drivers/serial_port.c"
#include "segmentation/memory_segments.h"

void kmain()
{
    char buffer[] = "Welcome to AbstractOS!";

    // Decrementing it by 1 so the cursor doesn't put another space after it
    // Too lazy to put that in the fb_write function
    fb_write(buffer, sizeof(buffer) - 1);

    
    // Serial Port logging
    serial_configure(SERIAL_COM1_BASE, Baud_115200);
    serial_write(SERIAL_COM1_BASE, buffer, sizeof(buffer));
}
