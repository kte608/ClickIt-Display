// Demonstrates use of the ClickIt Screen 
// This example code is in the public domain.


#include <Wire.h>

int led = LED_BUILTIN;

void setup()
{
  pinMode(led, OUTPUT);
  Wire.begin(); // join i2c bus 
}


uint16_t displayNum=0; // Number to display (letters are possible too!)
uint8_t len;
char displayBuf[10];


void incrementCounter()
{
  uint8_t i;
  digitalWrite(led, HIGH);    // briefly flash the LED
  
  
  Wire.beginTransmission(0x09);   // transmit to device 
  Wire.write(0b11110011);         // Set the decimal points and clock ":"
  itoa(displayNum,displayBuf,10); // Convert the number to ASCII characters
  
  // Pad blank spaces to the start if the number is not long enough
  len=strlen(displayBuf);
  for(i=0;i<4-len;i++)
  {
    Wire.write(0);            // Nothing pad the start.
  }        
  Wire.write(displayBuf);     // Fill in the rest of the number
  Wire.endTransmission();     // stop transmitting
  
  
  digitalWrite(led, LOW);

  displayNum++;               // Next number

  // Wrap around
  if(displayNum>9999)
  {displayNum=0;}
  delay(1000);                // Wait a second.
}

void loop()
{
  incrementCounter();
}
