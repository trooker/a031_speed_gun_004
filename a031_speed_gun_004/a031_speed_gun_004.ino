/* Copyright © 1988-2020 by Abbott Analytical Products. All Rights Reserved.
 *
 * ultrasonic speed gun
 * Materials:
 * 256 mega Arduion + mBlock Me Ultrasonic Sensor v3.0
 * Grove Starter Kit: Base Shield, Backlight RGB LCD, Button, LED, Buzzer
 * Dynacom K Jack Cat3 6p6c connector
 * Parts/tools on-hand
 * 004
 * 020201_tr Finalize
 * 003
 * 200129_tr minor housekeeping
 * 200124_tr removed aapUtility since Tristate type not used
 * 200122_tr behavior test good.
 *           Reset to Fina
 *           Reset to One Cycle to Fina
 *           Reset to Three Cycles to Fina
 * 002
 * 200121_tr cleanup behavior: adjust tones.
 * 200120_tr digikey datasheet download
 *         adafruit
 *         https://www.digikey.com/product-detail/en/adafruit-industries-llc/3942/1528-2711-ND/9658069?utm_adgroup=Ultrasonic%20Receivers%2C%20Transmitters&utm_source=google&utm_medium=cpc&utm_campaign=Shopping_Sensors%2C%20Transducers_NEW&utm_term=&utm_content=Ultrasonic%20Receivers%2C%20Transmitters&gclid=EAIaIQobChMIhrDah86T5wIVAZ-fCh1kBASCEAQYAiABEgJNmfD_BwE
 * 200117_tr retrofit ultrasonic sensor
 * 200116_Resolved the buzzer playing of tunes
 * 200113 added a031_buzzer, tune libraries
 * 200109 moved project to Slober
 * 200108 To hijack the mBlock sensor the OUTPUT/INPUT mode (ping/sense) of the
 *        SIG must be switched for the mBlock ultrasonic sensor.
 * 200107 need to leverage the rgb_lcd into its own abbott library
 *   compiles without the unit8_t issue of a200104...
 * 200106
 *   began adjusting for 256 mega and LCD
 *   used code snippets and parts from a200104_2136_I2c_gas_detector-btnwrks.ino
 *
 *
 * Borrowed from David A. Mellis/Tom Igoe Ping))) Sensor
 * opt/makeblock/mBlock/resources/tools/arduino-server/tools/arduino/examples/06.Sensors/Ping
 *   Using  Uno board and mBlock Me Ultrasonic Sensor V3.0
 * Borrowed from  M Ladd Radar Gun
 * https://www.instructables.com/id/Radar-Gun/
 *    using 256Mega board and HC-SR04 Sensor
 *  sold as radar but actually just ultrasonic pinging
 *  with very limited range.
 *
 * Mellis/Igoe Ping))) Sensor used
 * VCC connection of the sensor attached to +5V
 * GND connection of the sensor attached to ground
 * pingPin connection of the sensor attached to digital pin 7
 *    and switch OUTPUT/INPUT to trigger/receive.
 *    See image of mBlock sensor
 *
 * Ladd Radar Gun used the circuit:
 * VCC connection of the sensor attached to +5V
 * GND connection of the sensor attached to ground
 * TRIG connection of the sensor attached to digital pin 2
 * ECHO connection of the sensor attached to digital pin 4
 *    See image of HC-SR04 sensor
 *
 *
 *
 */


#include "a031_config.h"



bool debugLCD; // =  false; //true;

rgb_lcd lcd;


int doneFlag = -1;       // think tristate
                         // -1 don't care
                         // 0 showSetup() completed
                         // 1
int triggerFlg = -1;     // think tristate
                         // -1 don't care reset and ready for trigger
                         // 0 btn triggered
                         // 1 utlrasonic cycled to mph
int resetFlag = -1;      // think tristate
                         // -1 don't care reset and ready for trigger
                         // 0 btn triggered
                          // 1 utlrasonic cycled to mph
int loopknt = 0;         // count loop cycles
bool loopdebug = false;   // controls serial printing of debug info:  true is doit
int workknt = 0;         // count cycle through work
int wait4loop = 100;
int endOn = wait4loop;         // 200;         // end work loop after
int closeLoopOn = wait4loop;   // end arduino looping after 200 cycles
String readString = "";
double mydelay = 1;      //seconds of delay through zdelay
double breath_delay = 1;  //breath delay.
String stamp = "1421";   //time stamp for verifciation of build
int buzz1Knt = 1;        //
int buzz2Knt = 1;        //
int buzz3Knt = 1;        //siren
int buzzOff  = 2;



//Red LCD Background
const int colorRr = 255;
const int colorGr = 0;
const int colorBr = 0;



//Silver LCD background  assumued delault
const int colorR = 192;
const int colorG = 192;
const int colorB = 192;



//mbot id for grove shield components
const int sigId_led    = 3;     //Port 3 LED   OUTPUT
const int sigId_btn    = 6;     //Port 7 btn   INPUT
const int sigId_buz    = 5;     //Port 6 buzzer OUTPUT
const int trigPin      = 4;     //ultrasonic sensor trigger  OUTPUT/INPUT
//const int echoPin      = 2;   //utlrasonic sensor ping echo INPUT


void showSetup()
{
  Serial.println("Top of setup for LCD");
    // set up the LCD's number of columns and rows:
      readString = "Setup fina: " + stamp;
      lcd.begin(16, 2);
      Serial.println(readString);
      showDisplaywDelay(readString,mydelay);
     // Serial.println("doneFlag = " + String(doneFlag));

      Serial.println(readString);
      readString = "";  // re-initialize
      doneFlag++;       //0: lcd is setup

}

void showDisplayDebug(String msg)
{
   if (debugLCD == true )
   {
	  showDisplaywDelay(msg,5);   // show in lcd for 5 seconds
   }
}


void showDisplaywDelay(String msg, double wait)
{
  showDisplay(msg);
  zdelay(wait);
}

void showDisplay(String msgStr)
{
    // clear the screen
    lcd.clear();
    lcd.setCursor(0, 0);
    if ((doneFlag < 1) and (workknt < 51))
    {
      lcd.print(msgStr);
      msgStr = "";
    }
}

void showMills()
{
    Serial.println("Show mills");
    // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
    lcd.setCursor(0, 1);
    // print the number of seconds since reset:
    lcd.print(millis()/1000);
    zdelay(mydelay);
}

void showDone()
{
  if (doneFlag == 0)
  {
	    Serial.println("Fina. Reset");
        lcd.setRGB(colorRr, colorGr, colorBr);
        showDisplay("Fina.  Reset");
        zdelay(mydelay);
        doneFlag++;            //may need ot shut-off if no message sent to LCD
  } //doneFlag == 0
  else if (doneFlag == 2)  //turn-off lcd
  {
      lcd.setRGB(0, 0, 0);
      lcd.noDisplay();
  }
  doneFlag++;
}

void zdelay(double seconds)
{
  delay(seconds*1000);
}

 void  allstop()
 {
    digitalWrite((sigId_led+0),LOW);   //LED
    digitalWrite((sigId_btn+0),HIGH);  //btn
    digitalWrite((sigId_buz+0),LOW);   //buzzer
 }


long distanceOverTime(long first,long second){
 return ((first-second)/.1)*.0223693629;//taking cm/s to mph
}

long microsecondsToInches(long microseconds)
{
  // Both borrowed sources use this factor.  See them for original source reference
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  // Both borrowed sources use this factor.  See them for original source reference
  return microseconds / 29 / 2;
}

long holder;//store the cm from last time through loop.
long temp;//used to store the speed value after changes
int counter;

void rungun()
{


	  // establish variables for duration of the ping,
	  // and the distance result in inches and centimeters:
	  long duration, inches, cm;
	  long Speed;
      showDisplayDebug("pass to rungun"); //debug
      soundBuzz4(); //siren announce triggering
	  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
	  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
      lcd.setRGB(colorRr, colorGr, colorBr);
      showDisplay("ACTIVE");
      //ledBreath();
	  pinMode(trigPin+0, OUTPUT);  //Pin 2
	  digitalWrite(trigPin, LOW);
	  delayMicroseconds(2);
	  digitalWrite(trigPin, HIGH);
	  //mBlock
	  delayMicroseconds(5);

	  //HC-SR04
	  //delayMicroseconds(10);
	  digitalWrite(trigPin, LOW);

	  // Read the signal from the sensor: a HIGH pulse whose
	  // duration is the time (in microseconds) from the sending
	  // of the ping to the reception of its echo off of an object.
	  //pinMode(echoPin+0, INPUT);   //Pin 4
	  pinMode(trigPin+0, INPUT);     //Pin 4
	  //duration = pulseIn(echoPin, HIGH);
	  duration = pulseIn(trigPin, HIGH);
	  soundBuzz3(); //siren
	  Serial.println(String(duration)+ " duration, ");
	  readString = "duration: " + String(duration);
      lcd.setRGB(colorR, colorG, colorB);
	  showDisplaywDelay(readString,mydelay);

	  // convert the time into a distance
	  inches = microsecondsToInches(duration);
	  cm = microsecondsToCentimeters(duration);

	  Speed=distanceOverTime(holder,cm);
	  holder=cm;//after speed caclulation so take the cm value for another calculation
	  Speed=abs(Speed);

	  Serial.print(String(inches));
	  Serial.print(" in, ");
	  readString = "in: "+ String(inches);
	  showDisplaywDelay(readString,mydelay);
	  Serial.print(cm);
	  Serial.print(" cm, ");
	  readString = "cm: "+ String(cm);
	  showDisplaywDelay(readString,mydelay);


	  Serial.print(Speed);
	  Serial.print(" mph");
	  Serial.println();
	  readString = String(Speed) + " mph, " ;
	  showDisplaywDelay(readString,mydelay);
}



void checkBtn()
{
  if (digitalRead(sigId_btn)==HIGH)
  {
     lcd.setCursor(0, 0);
     readString = "Button Pressed";
     showDisplayDebug(readString);
     lcd.setCursor(0, 1);
     readString = "Buzz On LED Off";
     showDisplayDebug(readString);
     digitalWrite((sigId_btn+0),HIGH);
     digitalWrite((sigId_led+0),LOW);
     triggerFlg = 0;  // btn triggered to start
  } //ifpressed
  else
  {
	  digitalWrite((sigId_btn+0),LOW);
	  digitalWrite((sigId_led+0),HIGH);
	  digitalWrite((sigId_buz+0),LOW);

  }
}


void flashLCD_btn()
{
	  readString = "Waiting on Btn";
	  Serial.println(readString);
	  showDisplay(readString);

}


void loopPrn(String msg)
{
	if (loopdebug == true)
	{
		Serial.println(msg);
	}
}



void  doSomeWork()
{
 Serial.println("doSomeWork");
 flashLCD_btn();
 workknt = 0;
 resetFlag = -1;
 loopPrn(String(workknt) + " workknt");
 while (workknt < endOn)
 {
     loopPrn( String(workknt) + "  while (workknt < endOn)");
     checkBtn();
delay(100);
  if (triggerFlg ==0)
  {
     workknt = 0;
     rungun();
     triggerFlg = 1;
     flashLCD_btn();  // reset LCD for next reading
  }
  else
  {
	  //assume quit or reset
	  digitalWrite((sigId_led+0),HIGH);
	  resetFlag = 0;
	  if (workknt < endOn+1)
	 // if (workknt == 0)
	  {
		//  flashLCD_btn();
		  workknt++;
	  } //if
  } //else
 } //while
 showDone();
 loopPrn("doSomeWork() end)");
}




void setup(){
	debugLCD = false;
    Serial.begin(9600);
    pinMode((sigId_led+0),INPUT);    //LED   _
    pinMode((sigId_btn+0),INPUT);    //btn
    pinMode((sigId_buz+0),OUTPUT);   //buzzer
    allstop();
    showSetup();              //I2C LCD
    Serial.println("return from setup");
    setupBuzzer();
}




void loop()
{
if (buzz1Knt < buzzOff)
{
	soundBuzz1(); //happy birthday
    buzz1Knt++;
}
if (loopknt < closeLoopOn+1)
{
loopPrn(String(loopknt) + " loopknt");
loopPrn(String(doneFlag) + " doneFlag  ln423");
}
if ((loopknt < 1) && (doneFlag <= 2))
{
  Serial.print("");
  Serial.println("top of loop");
  doSomeWork();
}
else
if ((loopknt == closeLoopOn) && (doneFlag == 2))
  {
    showMills();
    showDone();
    if (buzz2Knt < buzzOff)
    {
 	   soundBuzz2(); //shave haircut
       buzz2Knt++;
    }
    allstop();

 }
 else if (loopknt > closeLoopOn)
 {
//  do nothing
 }
 if (loopknt < closeLoopOn+1)
  {
    loopknt++;
  }

}




