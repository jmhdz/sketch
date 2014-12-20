	

    //simple button GET server code to control servo and arduino pin 5
    //for use with IDE 1.0
    //open serial monitor to see what the arduino receives
    //use the \ slash to escape the " in the html
    //for use with W5100 based ethernet shields
    //Powering a servo from the arduino usually DOES NOT WORK.
    //note that the below bug fix may be required
    // http://code.google.com/p/arduino/issues/detail?id=605
     
    #include <SPI.h>
    #include <Ethernet.h>
     
    #include <Servo.h>
    Servo myservo;  // create servo object to control a servo
    int relay = 7;
    int light = 11;
    const long oneSecond = 1000;
    const long oneMinute = oneSecond * 60;
    int lock_pin = 6;    // safety pin 
    int status_pin = 8;  // open (LOW) or closed (HIGH)
    int ledLock = 13;   // Lock status pin
    int operate_pin = 7;  // relay to open/close door
    int open_door_led = 9; // LED to indicate door was left open today.
    long interval = 300000;
    long oldtime = 0;
    int door_count = 0; // Keep track of how many times the door has been left open.

    int door = HIGH;
    
    byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; //physical mac address
    byte ip[] = { 192, 168, 11, 3 }; // ip in lan
    EthernetServer server(80); //server port
     
    String readString;
     
    //////////////////////
     
    void setup(){
     
      pinMode(light, OUTPUT); //pin selected to control
      pinMode(relay, OUTPUT); // relay pin
      //start Ethernet
      Ethernet.begin(mac, ip);
      server.begin();
      //the pin for the servo co
      //enable serial data print
      Serial.begin(9600);
      Serial.println("server LED test 1.0"); // so I can keep track of what is loaded
    }
     
    void loop(){
      unsigned long time = millis ();
      // Create a client connection
      EthernetClient client = server.available();
      if (client) {
        while (client.connected()) {
          if (client.available()) {
            char c = client.read();
     
            //read char by char HTTP request
            if (readString.length() < 100) {
     
              //store characters to string
              readString += c;
              //Serial.print(c);
            }
     
            //if HTTP request has ended
            if (c == '\n') {
     
              ///////////////
              Serial.println(readString); //print to serial monitor for debuging
     
              client.println("HTTP/1.1 200 OK"); //send new page
              client.println("Content-Type: text/html");
              client.println();
     
              client.println("<HTML>");
              client.println("<HEAD>");
              client.println("<meta name='apple-mobile-web-app-capable' content='yes' />");
              client.println("<meta name='apple-mobile-web-app-status-bar-style' content='black-translucent' />");
              client.println("<link rel='stylesheet' type='text/css' href='http://randomnerdtutorials.com/ethernetcss.css' />");
              client.println("<TITLE>Home Garage</TITLE>");
              client.println("</HEAD>");
              client.println("<BODY>");
              client.println("<H1>Garage</H1>");
              client.println("<hr />");
              client.println("<br />");
             
              client.println("<a href=\"/?lighton\"\">Turn On Light</a>");
              client.println("<a href=\"/?lightoff\"\">Turn Off Light</a>");        
              client.println("<a href=\"/?garage\"\">Garage Door</a><br />");
              
              client.println("</BODY>");
              client.println("</HTML>");
     
              delay(1);
              //stopping client
              client.stop();
     
              ///////////////////// control arduino pin
              if(readString.indexOf("?lighton") >0)//checks for on
              {
                digitalWrite(light, HIGH);    // set pin 4 high
                Serial.println("Led On");
               client.stop();
              }
              else{
              if(readString.indexOf("?lightoff") >0)//checks for off
              {
                digitalWrite(light, LOW);    // set pin 4 low
                Serial.println("Led Off");
                client.stop();
              }
               else{
                if(readString.indexOf("?garage") >0)//check for garage
                {
                  digitalWrite(relay, HIGH);
                  delay (500);
                  digitalWrite(relay, LOW);
                  Serial.println("Garage");
                  client.stop();
                }
              
              }
              }
              
             
              //clearing string for next read
              readString="";
              client.stop();
     
            }
          }
        }
      }
        door = digitalRead(status_pin);
  
  
  if(door == HIGH) // Door is closed.  Nothing to see here!
  {
    Serial.println("The door is closed.");
    Serial.println(time);  //print elapsed time
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
      // giving you a chance to close door on your own.
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
      if(time - oldtime > interval) {
    // save the last time you blinked the LED 
    oldtime = time;
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

