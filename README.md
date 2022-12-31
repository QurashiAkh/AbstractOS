![AbstractOS](logo.jpg)

# AbstractOS

A Minimal, extremely Abstract x86 Operating System written in C & a tiny bit of Assembly.  
Refer to *"The little book about OS development"* by Erik Helin & Adam Renberg.

!["Welcome to AbstractOS!"](demo.gif)

I spent 11 hours trying to get it to write something into the Framebuffer.  
I mean.. It does nothing besides greeting you with the *"Welcome to AbstractOS!"* Message.  
Better than dying while acknowledging that you didn't take a shot at making your own Operating System!

## Setup

The whole System is under the `src/` Directory, so if you want to to build it on your own you should install these Dependencies:  
```sudo apt-get install build-essential nasm xorriso grub-pc-bin bochs bochs-sdl```  
Navigate to the `src/` Directory and `make` the System.  

If you don't want to do that, but rather just testing, you can download the `AbstractOS.iso` File from the Releases Tab in this Repo. You can burn it into a USB or a CD and run it on a Machine, or just put it in a VM.
