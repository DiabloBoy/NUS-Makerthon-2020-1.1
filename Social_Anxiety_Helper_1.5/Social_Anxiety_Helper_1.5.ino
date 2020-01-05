/***************************************************
DFPlayer - A Mini MP3 Player For Arduino
 <https://www.dfrobot.com/product-1121.html>
 
 ***************************************************
 This example shows the basic function of library for DFPlayer.
 
 Created 2016-12-07
 By [Angelo qiao](Angelo.qiao@dfrobot.com)
 
 GNU Lesser General Public License.
 See <http://www.gnu.org/licenses/> for details.
 All above must be included in any redistribution
 ****************************************************/

/***********Notice and Trouble shooting***************
 1.Connection and Diagram can be found here
 <https://www.dfrobot.com/wiki/index.php/DFPlayer_Mini_SKU:DFR0299#Connection_Diagram>
 2.This code is tested on Arduino Uno, Leonardo, Mega boards.
 ****************************************************/

#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include <Wire.h>

// This version includes a Bluetooth Module

SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);

int limit = 150;
int heart_rate;
int inPin = 2;
int val = 0;

void setup()
{
  mySoftwareSerial.begin(9600);
  // Baud rate
  Serial.begin(9600);
  Wire.begin();
  
  Serial.println();

  


  
  myDFPlayer.volume(15);  //Set volume value. From 0 to 30
  
    Wire.requestFrom(0xA0 >> 1, 1);         // request 1 bytes from slave device
  
}

void loop()
{
        unsigned char c = Wire.read();   // receive heart rate value (a byte)
        //Serial.println(c, DEC);
        heart_rate = int(c);
        Serial.println(heart_rate);

      if(heart_rate > limit ) {
         Serial.print(3);
        myDFPlayer.play(1);
        
        //Pause Playback if push button is pressed
        
        for(int counter = 0 ; counter < 500; counter ++){
            delay(100);            
            val = digitalRead(inPin);
            if (val == HIGH){ 
              myDFPlayer.pause();
              break;
            }
        }
      }
   


}
