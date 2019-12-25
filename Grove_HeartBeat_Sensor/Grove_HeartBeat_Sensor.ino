#include <Wire.h>
void setup() {
    Serial.begin(9600);
    Serial.println("heart rate sensor:");
    Wire.begin();
                }
int heart_rate;
void loop() {
    Wire.requestFrom(0xA0 >> 1, 1);    // request 1 bytes from slave device
    while(Wire.available()) {          // slave may send less than requested
        unsigned char c = Wire.read();   // receive heart rate value (a byte)
        //Serial.println(c,DEC);
        heart_rate = int(c);
        Serial.println(heart_rate);
        
        
        
        
        
        
        
       
        
        
        
        
        
    }  
    
    delay(500);
}
