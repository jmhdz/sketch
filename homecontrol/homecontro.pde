/*
serial recieve 1 - toggle garage door
serial recieve 2 - turn lights on
serial recieve 3 - turn lights off
serial recieve 4 - toggle lights
serial send 0 - garage door open
serial send 1 - garage door closed
serial send 2 - lights on
serial send 3 - lights off
*/
int garagePin = 3; //pin tied to garage door
int lightPin = 4; //pin for on/off 
int statusPin = 8; //input from garage door
int inputNumber = 0; //declare for serial input
int buttonState = 0; //variable for button state
int buttonDelay = 0; //variable for debounce of button
int oldbuttonState = 0; //variable for old button state
int lightState = 0; //set the state of the lights to off

//setup pin mode and serial data
void setup() {
    pinMode(garagePin, OUTPUT);
    pinMode(lightPin, OUTPUT);
    pinMode(statusPin, INPUT);   
    Serial.begin(9600);                       //set 9600 baud
}
void loop() {                                 //just loop forever
    if (Serial.available() > 0) {             // look for any number greater than 0
        inputNumber = Serial.read();          //store that number
    }

    if (inputNumber == 1) {                   // toggle the garage door
        digitalWrite(garagePin, HIGH);
        delay(1000);                          //delay to make sure garage door opener sees the change
        digitalWrite(garagePin, LOW);
        inputNumber = 0;
    }

    if (inputNumber == 2) {                   //turn on the lights
        digitalWrite(lightPin, HIGH);
        inputNumber = 0;
    }
    
     if (inputNumber == 3) {                  //turn off the lights
        digitalWrite(lightPin, LOW);
        inputNumber = 0;
    }
     
     if (inputNumber == 4) {                 //toggle lights on or off depending on current state and send change via serial
       lightState = digitalRead(lightPin);
       if (lightState == LOW) {
         digitalWrite(lightPin, HIGH);      
         Serial.println("2");
         inputNumber = 0;
       }
        else {
         digitalWrite(lightPin, LOW);
         Serial.println("3");
         inputNumber = 0;
        }
      }

//code for the status of the garage door
  
    buttonState = digitalRead(statusPin);     //read status of button
    delay(10);                                //10 mils wait
    buttonDelay = digitalRead(statusPin);     //read it again
    if (buttonState == buttonDelay) {         //make sure they are the same (debounce)
      if (buttonState != oldbuttonState) {    //compare old button state to new to avoid flooding serial port with useless data
       if (buttonState == HIGH) {
         Serial.println("0");                 //send a 0 via serial to computer to indicate the garage door is open
       }
       else {
         Serial.println("1");                 //send a 1 via serial to computer to indicate the garage door is closed
       }
      }
     oldbuttonState = buttonState;            //save button state for the next loop
    }
}
