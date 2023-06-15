#include <SoftwareSerial.h>

const int ledPin = 13;
String phoneNumber = "0937123456789";

SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
  mySerial.begin(9600);

  delay(2000);

  CallToNumber();
  //SendSMS();
  //ReadSMS();
}

void loop() {
  delay(700);
  digitalWrite(ledPin, !digitalRead(ledPin));
}




void CallToNumber() {
  mySerial.println("ATD" + phoneNumber + ";"); // Replace "1234567890" with the phone number you want to call
  delay(10000); // Wait for 8 seconds
  mySerial.println("ATH"); // Hang up the call
  delay(2000);
}

void SendSMS() {
  mySerial.println("AT+CMGF=1"); // Set the SMS mode to text mode
  delay(1000);
  mySerial.println("AT+CSCS=\"UCS2\"");
  delay(500);
  mySerial.println("AT+CSMP=17,167,0,8");
  delay(500);
  mySerial.println("AT+CMGS=\"" + convertToUCS2String(phoneNumber) + "\""); // Replace "1234567890" with the recipient's phone number https://convertcodes.com/utf16-encode-decode-convert-string/
  delay(500);
  mySerial.print(convertToUCS2String("Hello"));
  delay(500);
  mySerial.write(26); // Send the Ctrl+Z character to indicate the end of the message
  delay(2000);
}


void ReadSMS() {
  mySerial.println("AT+CMGF=1"); // Set the SMS mode to text mode
  delay(100);
  //  mySerial.println("AT+CMGD=1,4");
  //  delay(100);
  mySerial.println("AT+CMGR=1") ;
  delay(2000);
}
