# PiGFX 
## Raspberry Pi graphics card / ANSI terminal emulator

This is a fork of https://github.com/fbergama/pigfx
with some changes to work better as a terminal for the Altair emulator
and in general. The changes are:
- baud rate can be configured by modifying config.txt file or pressing F11 at runtime
- three different font sizes (8/14/16)
- many improvements to ANSI control sequence support
- support keyboard repeat function
- fixed issue with cursor rendering after clear screen
- keep some empty space at top and bottom of screen
- enabled internal pull-up resistor on RX line to avoid receiving garbage
  when RX line is not connected

I have tested this on a first generation Raspberry Pi A and B and a Raspberry Pi Zero.
It should also work on an A+ and B+. I don't know about later generations and don't 
have any to test with.

The Pi's HDMI output as well as Composite output work but the Composite signal
was a bit blurry when I tested it. The Pi does not have a VGA output but non-expensive 
converters exist. I have used this with good results: https://www.ebay.com/itm/361521797200

A USB keyboard is required since the Pi does not have a PS/2 keyboard connector. 
Converters exist for that too although I have not tried any.

To install, simply copy the content of the "bin" directory into the
root directory of an empty, FAT32 formatted SD card and plug the card
into the Raspberry Pi.

The serial port is on the following pins:
- TX (out) : GPIO14 (pin 8 of the 2-row GPIO connector)
- RX (in)  : GPIO15 (pin 10 of the 2-row GPIO connector)

Note that Raspberry Pi pins are 3.3V (not 5V tolerant).

For more instructions refer to the original project: 
https://github.com/fbergama/pigfx

### Changing the baud rate

The default baud rate is 115200 8N1. The default rate (but not the 8N1
parameters) can be modified in the config.txt file. 

At runtime, pressing F11 cycles through baud rates
(300, 600, 1200, 2400, 4800, 9600, 19200, 38400, 57600, 115200).
This is temporary, at the next boot the baud rate reverts to the default.

### Changing the font size

The terminal comes with three font sizes: 8x8 (CGA), 8x14 (EGA), 8x16 (VGA).
The default font size can be set by choosing the corresponding kernel-NN.img file.
For example, to choose the 8x14 font as default, rename kernel-14.img to kernel.img
on the SD card.

The default kernel.img file uses the VGA font.

At runtime, pressing F12 cycles through the three font sizes.
This is temporary, at the next boot the size reverts to the default.

### Changing the number of lines on the screen

Some software assumes a specific number of lines on screen (often 24)
and will not work properly if the actual screen differs from that.

By default the terminal will put as many lines on the screen as possible
given the selected font size (with a small border on the top and bottom).
For the CGA font that's 59 lines, EGA has 34 and the VGA font has 29 lines.

The number of lines can be changed at runtime by pressing F10. This will
cycle through, starting at the maximum number, going down to 16 and then
back to maximum.

To change the initial number of lines, change the SCREEN_LINES setting in
pigfx_config.h.in and re-compile the kernel.

-----


The MIT License (MIT)

Copyright (c) 2016 Filippo Bergamasco.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
