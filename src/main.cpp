#include <Arduino.h>
#define PIN_RS485_RX 15
#define PIN_RS485_TX 14
const int DE_RE_PIN_ch3 = 4;

unsigned long lastPing24 = 0;
unsigned long lastPing58 = 0;
unsigned long pingInterval = 50;  // 50 ms interval for each sensor

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Serial2.begin(115200, SERIAL_8N1, PIN_RS485_RX, PIN_RS485_TX);
  Serial3.begin(115200);
  delay(500);

  Serial.println("RS485-Test");
  delay(500);
}

void Ping_24() {
  if (millis() - lastPing24 >= pingInterval) {
    lastPing24 = millis();
    Serial3.write(0x24);
    delay(10);  // Small delay to allow data to arrive
    if (Serial3.available() >= 2) {
      byte lowByte = Serial3.read();
      byte highByte = Serial3.read();
      Serial.print("Received from 24: Low Byte: 0x");
      Serial.print(lowByte, HEX);
      Serial.print(", High Byte: 0x");
      Serial.println(highByte, HEX);
    } else {
      Serial.println("No data received from Sensor 24");
    }
    while (Serial3.available()) Serial3.read();  // Clear buffer
  }
}

void Ping_58() {
  if (millis() - lastPing58 >= pingInterval) {
    lastPing58 = millis();
    Serial3.write(0x58);
    delay(10);  // Small delay to allow data to arrive
    if (Serial3.available() >= 2) {
      byte lowByte = Serial3.read();
      byte highByte = Serial3.read();
      Serial.print("Received from 58: Low Byte: 0x");
      Serial.print(lowByte, HEX);
      Serial.print(", High Byte: 0x");
      Serial.println(highByte, HEX);
    } else {
      Serial.println("No data received from Sensor 58");
    }
    while (Serial3.available()) Serial3.read();  // Clear buffer
  }
}

void loop() {
  Ping_24();
  Ping_58();
}


/*
#include <Arduino.h>
#define PIN_RS485_RX 15
#define PIN_RS485_TX 14
const int DE_RE_PIN_ch3 = 4;
unsigned long Ping_ch3_last_24 = 0;
unsigned long Ping_ch3_last_58 = 0;
unsigned long Ping_ch3_Interval = 4;


void setup() {
  Serial.begin (115200);
  delay (1000);

  // Serial2.begin (115200, SERIAL_8N1, PIN_RS485_RX, PIN_RS485_TX);
  Serial3.begin (115200);
  delay (1000);

  Serial.println ("RS485-Test");

  delay (1000);
}
void Ping_24(){
    if (millis() - Ping_ch3_last_24 >= Ping_ch3_Interval) {  
    Ping_ch3_last_24 = millis();  
    Serial3.write(0x24);
    if (Serial3.available()<=2) {
      byte incomingByte_LOW = Serial3.read();
      byte incomingByte_HIGH = Serial3.read();
      Serial.print("3 Rec24: 0x");
      Serial.print(incomingByte_LOW, HEX);
      Serial.print( " , 0x");
      Serial.println(incomingByte_HIGH, HEX);
    } else {
      Serial.println("3 No data received from Sensor 24");
      if (Serial3.peek() != -1) {
        Serial.print("3 24 Error byte: ");
        Serial.println(Serial3.peek(), HEX);
      }
    }
  }
}
void Ping_58(){
    if (millis() - Ping_ch3_last_58 >= Ping_ch3_Interval) {  
    Ping_ch3_last_58 = millis();  
    Serial3.write(0x58);
    if (Serial3.available()<=2) {
      byte incomingByte_LOW = Serial3.read();
      byte incomingByte_HIGH = Serial3.read();
      Serial.print("3 Rec58: 0x");
      Serial.print(incomingByte_LOW, HEX);
      Serial.print( " , 0x");
      Serial.println(incomingByte_HIGH, HEX);
    } else {
      Serial.println("3 No data received from Sensor58");
      if (Serial3.peek() != -1) {
        Serial.print("3 58 Error byte: ");
        Serial.println(Serial3.peek(), HEX);
      }
    }
  }
}
void loop() { 

}
*/

/*#include <Arduino.h>
const int DE_RE_PIN_ch1 = 4;
unsigned long Ping_ch1_last = 0;
unsigned long Ping_ch1_Interval = 4;

const int DE_RE_PIN_ch2 = 6;
unsigned long Ping_ch2_last = 0;
unsigned long Ping_ch2_Interval = 4;

void setup() {
  
  pinMode(DE_RE_PIN_ch1, OUTPUT);
  digitalWrite(DE_RE_PIN_ch1, LOW);
  Serial1.begin(2000000);

  pinMode(DE_RE_PIN_ch2, OUTPUT);
  digitalWrite(DE_RE_PIN_ch2, LOW);
  Serial2.begin(115200,SERIAL_8N1);

  Serial.begin(115200);  
}

void loop() { 


  
    if (millis() - Ping_ch2_last >= Ping_ch2_Interval) {  
    Ping_ch2_last = millis();  
    digitalWrite(DE_RE_PIN_ch2, HIGH); 
   Serial2.flush();  // Flush the buffer
    Serial2.write(0x24);
    digitalWrite(DE_RE_PIN_ch2, LOW);  
    delay(2);  // Increase the delay to give the sensor more time to respond
    
    if (Serial2.available()) {
      byte incomingByte = Serial2.read();
      Serial.print("2 Received: 0x");
      Serial.println(incomingByte, HEX);
    } else {
      Serial.println("2 No data received from Sensor A");
      if (Serial2.peek() != -1) {
        Serial.print("2 Error byte: ");
        Serial.println(Serial2.peek(), HEX);
      }
    }
  }


  return;
  if (millis() - Ping_ch1_last >= Ping_ch1_Interval) {  
    Ping_ch1_last = millis();  
    digitalWrite(DE_RE_PIN_ch1, HIGH); 
    Serial1.flush();  // Flush the buffer
    Serial1.write(0x18);
    digitalWrite(DE_RE_PIN_ch1, LOW);  
    delay(1);  // Increase the delay to give the sensor more time to respond
    
    if (Serial1.available()) {
      byte incomingByte = Serial1.read();
      Serial.print("1 Received: 0x");
      Serial.println(incomingByte, HEX);
    } else {
      Serial.println("1 No data received from Sensor A");
      if (Serial1.peek() != -1) {
        Serial.print("1 Error byte: ");
        Serial.println(Serial1.peek(), HEX);
      }
    }
  }

}
*/