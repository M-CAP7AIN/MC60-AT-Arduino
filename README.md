# Quectel MC60  AT Command

This is an example Arduino sketch that demonstrates how to use the `SoftwareSerial` library to make a call, send an SMS, and read an SMS on an Arduino board.

## Getting Started

To get started with this example, you'll need:

- An Arduino board
- A GSM module Quectel MC60
- A phone number to call and send an SMS to
- A SIM card with active cellular service

## Wiring

The GSM module should be connected to the Arduino board as follows:

- GSM module RX to Arduino pin 11 (TX)
- GSM module TX to Arduino pin 10 (RX)
- GSM module GND to Arduino GND
- GSM module VCC to Arduino 5V

## Usage

Before uploading the sketch to the Arduino board, make sure to set the `phoneNumber` variable to the phone number you want to call and send an SMS to.

After uploading the sketch to the Arduino board, open the serial monitor and set the baud rate to 9600. You should see the Arduino board flashing its onboard LED (connected to pin 13) every 700 milliseconds.

The sketch contains three functions:

### CallToNumber()

This function dials the phone number specified by `phoneNumber`, waits for 10 seconds, and then hangs up the call.

### SendSMS()

This function sends an SMS to the phone number specified by `phoneNumber`. It sets the SMS mode to text mode, converts the phone number to UCS2 format, and sends the message "Hello". After sending the message, it waits for 2 seconds.

### ReadSMS()

This function reads the first SMS in the inbox. It sets the SMS mode to text mode and uses the `AT+CMGR` command to read the message. After reading the message, it waits for 2 seconds.

You can uncomment the function calls in the `setup()` function to test each function.

## Resources

- `SoftwareSerial.h` library: https://www.arduino.cc/en/Reference/SoftwareSerial
- `AT Commands for GSM/GPRS Modems` manual: https://robu.in/wp-content/uploads/2018/12/Quectel_MC60_AT_Commands_Manual_V1.2.pdf
