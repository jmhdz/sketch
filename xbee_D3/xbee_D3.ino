/*
                                                 

7E 00 10 17 01 00 13 A2 00 40 CA 06 67 FF FE 02 44 33 05 40  D3high

7E 00 10 17 01 00 13 A2 00 40 CA 06 67 FF FE 02 44 33 04 41  D3low



*Please note that the command D4 (bytes 17 and 18) is issued as 44 and 34. 
34 is the hex equivalent of the ASCII character 4. 
The setting for D4 (byte 19) is issued as 04 and 05. 
This is the hex equivalent of decimal 4 and 5 respectively.
*/


int led = 13;                           //  set pin 13 as led

void setup() {                          //  start setup
pinMode(led, OUTPUT);                   //  set led as output
Serial.begin(9600);                     //  Start serial comm
}

void loop() {
  digitalWrite(led, HIGH);               // turn on led
  setRemoteState(0x05);
  delay(5000);
  digitalWrite(led, LOW);
  setRemoteState(0x04);
  delay(5000);
}

void setRemoteState(char value) {
  Serial.write(0x7E);                      //  start byte
  Serial.write((byte)0x00);                //  high part of lenght (always zero);
  Serial.write(0x10);                      //  low part of lenght (the number of bytes that follow)
  Serial.write(0x17);                      //  0X17 is a remote AT command
  Serial.write((byte)0x01);                //  frame id set to zero for no replay
  
                                           //  ID or recipient, or use 0xFFFF for broadcast
  Serial.write((byte)0x00);
  Serial.write((byte)0x13);
  Serial.write((byte)0xA2);
  Serial.write((byte)0x00);
  Serial.write((byte)0x40);
  Serial.write((byte)0xCA);
  Serial.write((byte)0x06);
  Serial.write((byte)0x67);
                       //  0xFF for broadcast
  
  //16 bits of recipient or 0xFFFE
  
  Serial.write(0xFF);
  Serial.write(0xFE);
  
  Serial.write(0x02);                        //  0x02 to apply changes immediatly
  
  //command name in ASCII characters
  Serial.write(0x44);
  Serial.write(0x33);
  
  //command data in as many bytes as needed
  Serial.write(value);
  
  //checksum is all bytes after lenght
  long sum = 0x17 + 0x01 + 0x00 + 0x13 + 0xA2 + 0x00 + 0x40 + 0xCA + 0x06 + 0x67 + 0xFF + 0xFE + 0x02 + 0x44 + 0x33 + value;
  Serial.write ( 0xFF - ( sum & 0xFF));      // calculate the checksum

}

