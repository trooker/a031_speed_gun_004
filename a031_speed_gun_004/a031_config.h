/*Copyright © 1988-2020 by Abbott Analytical Products. All Rights Reserved.
 * ultrasonic speed gun
 * m007_ultrasonic_speed_gun_xxx
 * Header file used to centralize libraries used by project
 */




#ifndef A031_CONFIG_H_
#define A031_CONFIG_H_




#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include "rgb_lcd.h"
//#include "aaputility.h"





//------------------------------------------------------------------------------
// CONSTANTS
//------------------------------------------------------------------------------
// supported control boards
//#define DEBUG 1

/****************************************************************************************
* digital i/o pin assignment
*
* this uses the undocumented feature of Arduino - pins 14-19 correspond to analog 0-5
****************************************************************************************/






#define VERSION        (1)  // firmware version


//------------------------------------------------------------------------------
// METHODS
//------------------------------------------------------------------------------
// no extern void need definiton
extern void setupBuzzer();
extern void soundBuzz1();   // happy birthday
extern void soundBuzz2();   //twinkle twinkle little star





#endif /* A031_CONFIG_H_ */
