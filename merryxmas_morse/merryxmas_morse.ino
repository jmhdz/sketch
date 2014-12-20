/*
  Merry Christmas in Morse Code Blink
  This example code is in the public domain.
 */
  
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
 
// the setup routine runs once when you press reset:
void setup() {               
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);    
}
 
// the loop routine runs over and over again forever:
void loop() {
//M in morse code is two dashes. We define the dot and dash subroutines below.
dash();
dash();
space();
//E
dot();
space();
//R
dot();
dash();
dot();
space();
//R
dot();
dash();
dot();
space();
//Y
dash();
dot();
dash();
dash();
space();
//Space
wordspace();
//C
dash();
dot();
dash();
dot();
space();
//H
dot();
dot();
dot();
dot();
space();
//R
dot();
dash();
dot();
space();
//I
dot();
dot();
space();
//S
dot();
dot();
dot();
space();
//T
dash();
space();
//M
dash();
dash();
space();
//A
dot();
dash();
space();
//S
dot();
dot();
dot();
space();
wordspace();
   
   
   
}
 
void dot() {
  digitalWrite(led, LOW);   // turn the LED off (LOW is the voltage level)
  delay(200);               // keep the light off for 200 ms (dot)
  digitalWrite(led, HIGH);    // turn the LED on by making the voltage HIGH
  delay(600);               //pause between characters
 
 
}
 
void dash() {
  digitalWrite(led, LOW);   // turn the LED off
  delay(600);               // keep the light off for 600 ms
  digitalWrite(led, HIGH);    // turn the LED on by making the voltage high
  delay(600);
 
  }
 
void space(){             
  digitalWrite(led, HIGH); //Make sure the LED is on
  delay(1000);              //For one second to mark space between characters
}
 
void wordspace(){             
digitalWrite(led, HIGH); //make sure the LED is on
  delay(3000);           //for 3 seconds to mark space between words
}
