
/* Garage Timer
This sketch is meant to continuously monitor the status of the 
garage door. If it is opened, the sketch will wait 5 minutes to 
see if the garage door is still open. If it is still open, the relay 
will be activated in order to close the garage door. A red LED
(open_door_led) will also be lit if the Arduino has had to close
the garage door.
*/

#include <Time.h>

const long oneSecond = 1000;
const long oneMinute = oneSecond * 60;
int lock_pin = 6;    // safety pin 
int status_pin = 8;  // open (LOW) or closed (HIGH)
int ledLock = 13;   // Lock status pin
int operate_pin = 7;  // relay to open/close door
int open_door_led = 9; // LED to indicate door was left open today.

int door_count = 0; // Keep track of how many times the door has been left open.

int door = HIGH;

void setup() 
{
  Serial.begin(9600);
  pinMode(status_pin, INPUT);

  pinMode(operate_pin, OUTPUT);
  pinMode(open_door_led, OUTPUT);
  pinMode(lock_pin, INPUT);
  pinMode(ledLock, OUTPUT);
  
}

void loop()
{
  door = digitalRead(status_pin);
  
  
  if(door == HIGH) // Door is closed.  Nothing to see here!
  {
    Serial.println("The door is closed.");
    delay(2000);
    while(digitalRead(lock_pin)== LOW)
  {
   digitalWrite(ledLock, LOW);
   delay(3000);
   digitalWrite(ledLock, HIGH);
   delay(1000);
  }
    }
  else  // door is open
  {
  Serial.println("The door is open.  t-5min");
    delay(5 * oneMinute);  // giving you a chance to close door on your own.
    while(digitalRead(lock_pin) == LOW)
    {
    digitalWrite(ledLock, LOW);
    delay(3000);
    digitalWrite(ledLock, HIGH);
    delay(1000);
    }
    delay(3000);
    door = digitalRead(status_pin);
    if(door == HIGH)
    {
      Serial.println("Good, you closed the door.  Whew!");
    }
    else
    {
      Serial.println("Looks like you forgot to close the garage door. Closing the door now.");
      digitalWrite(operate_pin, HIGH);  // Closing the door
      delay(170);
      digitalWrite(operate_pin, LOW); // Stop closing door
      door_count = door_count + 1;
      digitalWrite(open_door_led, HIGH);
      delay(45 * oneSecond);
      Serial.println("The door should be shut now.");
      Serial.print("The door has been left open ");
      Serial.print(door_count);
      Serial.println(" time(s).");
      delay(4000);
      door = digitalRead(status_pin);
      if(door == LOW)
      {
        blockedOn();
      }
      else
      {
        loop();
      }
    }
  }
}

void blockedOn()
{
  door = digitalRead(status_pin);
  if(door == LOW)
  {
    Serial.println("Door is blocked");
  }
  while(digitalRead(status_pin) == LOW)
  {
    digitalWrite(ledLock, LOW);
   delay(90);
   digitalWrite(ledLock, HIGH);
   delay(90);
  }
  digitalWrite(operate_pin, LOW);
}
