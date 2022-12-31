#include "io.h"

char *fb = (char *) 0x000B8000;

/* The I/O ports */
#define FB_COMMAND_PORT         0x3D4
#define FB_DATA_PORT            0x3D5

/* The I/O port commands */
#define FB_HIGH_BYTE_COMMAND    14
#define FB_LOW_BYTE_COMMAND     15

/** fb_move_cursor:
 *  Moves the cursor of the framebuffer to the given position
 *
 *  @param pos The new position of the cursor
 */
void fb_move_cursor(unsigned short pos)
{
    outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
    outb(FB_DATA_PORT,    ((pos >> 8) & 0x00FF));
    outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
    outb(FB_DATA_PORT,    pos & 0x00FF);
}

/** fb_write_cell:
 *  Writes a character with the given foreground and background to position i
 *  in the framebuffer.
 *
 *  @param i  The location in the framebuffer
 *  @param c  The character
 *  @param fg The foreground color
 *  @param bg The background color
 */
void fb_write_cell(unsigned int i, char c, unsigned char fg, unsigned char bg)
{
    fb[i] = c;
    fb[i + 1] = ((bg & 0x0F) << 4) | (fg & 0x0F);
}

#define FB_WHITE 15
#define FB_BLACK 0

/** fb_write:
 *  Writes the contents of the buffer by the length to the Screen.
 *
 *  @param buf The buffer written
 *  @param len The length of the buffer
 */
int fb_write(char *buf, unsigned int len){
    	unsigned int i;
    	for(i = 0; i<len; i++){
	    		fb_write_cell(i*2, *(buf+i), FB_WHITE, FB_BLACK);
	    		fb_move_cursor(len);
	    	}
    	return i;
}
