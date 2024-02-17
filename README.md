# 7segment-4digit

This is a quick project of mine that I made with a couple of arduinos and some led strip pieces that act as each segment of the 4 digits.

https://github.com/pranavs6/7segment-4digit/assets/119113218/29c62199-5684-4d6f-8925-c3e0b63dd284

Parts :
  1. 2x Arduino - I have used a Nano and an Uno for 2 digits each. Also you can use a 74HC595 - 8 bit shift register to act as a multiplexer taking in 3 data lines
     from the arduino serially to give out 8 data output lines. This means you can use a single arduino to multiplex its lines to runall the 4 digits from a
     single source.
  2. 7x led strip for each digit + 1 strip for the blinker.
  3. BC547 transistors for each of the strip to get the signal data from the arduino and power in from the main 12v supply line, while isolating the 12v and 5v
     lines of the supply and arduino.
  4. 5v and 12v power supplies.
