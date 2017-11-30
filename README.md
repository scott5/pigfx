# PiGFX 
## Raspberry Pi graphics card / ANSI terminal emulator

This is a fork of https://github.com/fbergama/pigfx
with some changes to work better as a terminal for the Altair emulator
and in general. The changes are:
- line and column numbers in ESC[H command start at 1 (not 0)
- fixed issue with cursor rendering after clear screen
- support ESC[K to clear current line after cursor
- support ESC[mNN where NN=30-38 or 40-48 to change colors
- support keyboard repeat function
- keep some empty space at top and bottom of screen
- enabled internal pull-up resistor on RX line to avoid receiving garbage
  when RX line is not connected
- use 9600 baud instead of 115200
- on my Raspberry Pi A the timing calculation in src/uart.s was off by
  a factor of 16, so I changed that (see comment in src/uart.s),
  so this may now not work on a Pi Zero.

For instructions on how to install this on the Raspberry pi, refer
to the original project: https://github.com/fbergama/pigfx


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
