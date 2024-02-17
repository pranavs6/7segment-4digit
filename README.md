# 7segment-4digit
Last updated : 02-17-2024

This is a quick project of mine that I made with a couple of arduinos and some led strip pieces that act as each segment of the 4 digits.

https://github.com/pranavs6/7segment-4digit/assets/119113218/29c62199-5684-4d6f-8925-c3e0b63dd284


Parts :

  1. 2x Arduino - I have used a Nano and an Uno for 2 digits each. Also you can use a 74HC595 - 8 bit shift register to act as a multiplexer taking in 3 data lines
     from the arduino serially to give out 8 data output lines. This means you can use a single arduino to multiplex its lines to run all the 4 digits from a
     single source.
     
  2. 7x led strip for each digit + 1 strip for the blinker.
     
  3. BC547 transistors for each of the strip to get the signal data from the arduino and power in from the main 12v supply line, while isolating the 12v and 5v
     lines of the supply and arduino.
     
  4. 5v and 12v power supplies.

  5. Odds and ends such as a wooden board, wires, doodads.

The input : 
    -Initially, I hooked up the 0,1 - RX/TX lines of the Arduinos to a Raspberry Pi 3 to facilitate a serial connection through which, live time from the Pi is fed
    to the boards whose digits correspond with those displayed.
    -Now, I have a DS1370 RTC module that holds time by means of an all time running setup, I just need to setup the initial time value and feed it to the Arduinos.
    -One snag I have, is that, the DS1307 module gives data in an I2C pinout, that needs pins A4, A5 - SDA/SCL pinouts, which I have hooked up at data lines for the
    led units. Now, I am planning to use another spare Arduino to generate serial data and feed it to the two master Arduinos

    
