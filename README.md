# PiGFX 
## Raspberry Pi graphics card / ANSI terminal emulator

This is a fork of https://github.com/fbergama/pigfx
with some changes to work better as a terminal for the Altair emulator
and in general. The changes are:
- baud rate can be configured without rebuilding by modifying config.txt file
- line and column numbers in ESC[H command start at 1 (not 0)
- fixed issue with cursor rendering after clear screen
- fixed issue with ESC[0K (clear current line after cursor)
- support ESC[K to clear current line after cursor
- support ESC[NNm where NN=30-38 or 40-48 to change colors
- support keyboard repeat function
- keep some empty space at top and bottom of screen
- enabled internal pull-up resistor on RX line to avoid receiving garbage
  when RX line is not connected

I have tested this on a first generation Raspberry Pi A and B and a Raspberry Pi Zero.
It should also work on an A+ and B+. I don't know about later generations and don't 
have any to test with.

The Pi's HDMI output as well as Composite output work but the Composite signal
is a bit blurry because of the relatively high resolution used. The Pi does not
have a VGA output but non-expensive converters exist, such as this:
https://www.ebay.com/itm/361521797200

A USB keyboard is required since the Pi does not have a PS/2 keyboard connector. 
Converters exist for that too although I have not tried any.

To install, simply copy the content of the "bin" directory into the
root directory of an empty, FAT32 formatted SD card and plug the card
into the Raspberry Pi.

The serial port is on the following pins:
- TX (out) : GPIO14 (pin 8 of the 2-row GPIO connector)
- RX (in)  : GPIO15 (pin 10 of the 2-row GPIO connector)

Note that Raspberry Pi pins are 3.3V (not 5V tolerant).

The default baud rate is 115200 8N1. The rate (but not the 8N1
parameters) can be modified in the config.txt file.

For more detailed instructions refer to the original project: 
https://github.com/fbergama/pigfx

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
