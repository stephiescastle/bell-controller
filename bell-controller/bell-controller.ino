#include <Metro.h> // Include Metro library
#include <math.h> // for logarithmic scaling

// Define mode switch (installation vs performance modes)
const int modePin = 53;
int modeState = HIGH;

// Define sensor mode switch
const int sensormodePin = 52;
int sensormodeState = HIGH;

// Define sensor
const int sensorPin = A0;    
unsigned long sensorValue = 0; 
float sensorMapped = 0; 
// scaled according to this help topic:
// http://forum.arduino.cc/index.php?topic=145443.0

// Define knobs (left to right)
const int knob0Pin = A2;    
unsigned long knob0Value = 0; 
float knob0Mapped = 0; 

const int knob1Pin = A3;    
unsigned long knob1Value = 0; 
float knob1Mapped = 0; 

const int knob2Pin = A1;    
unsigned long knob2Value = 0; 
float knob2Mapped = 0; 


// Set ideal pwm level
int off = 0;
int pwm = 255;
int pwmgp = 55;
int on = 255;

// Define motors pins (*15)
const int motor0 =  13;
const int motor1 =  12;
const int motor2 =  11;
const int motor3 =  10;
const int motor4 =   9;
const int motor5 =   8;
const int motor6 =   7;
const int motor7 =   6;
const int motor8 =   5;
const int motor9 =   4;
const int motor10 =  3;
const int motor11 =  2;
const int motor12 = 44;
const int motor13 = 45;
const int motor14 = 46;
// Define motor states (*15)
int motor0State =  pwm;
int motor1State =  pwm;
int motor2State =  pwm;
int motor3State =  pwm;
int motor4State =  pwm;
int motor5State =  pwm;
int motor6State =  pwm;
int motor7State =  pwm;
int motor8State =  pwm;
int motor9State =  pwm;
int motor10State = pwm;
int motor11State = pwm;
int motor12State = pwm;
int motor13State = pwm;
int motor14State = pwm;


// Define toggles (*15)
const int toggle0Pin =  22;
const int toggle1Pin =  23;
const int toggle2Pin =  24;
const int toggle3Pin =  25;
const int toggle4Pin =  26;
const int toggle5Pin =  27;
const int toggle6Pin =  28;
const int toggle7Pin =  29;
const int toggle8Pin =  30;
const int toggle9Pin =  31;
const int toggle10Pin = 32;
const int toggle11Pin = 33;
const int toggle12Pin = 34;
const int toggle13Pin = 35;
const int toggle14Pin = 36;
// Define toggle states (*15)
int toggle0State =  HIGH;
int toggle1State =  HIGH;
int toggle2State =  HIGH;
int toggle3State =  HIGH;
int toggle4State =  HIGH;
int toggle5State =  HIGH;
int toggle6State =  HIGH;
int toggle7State =  HIGH;
int toggle8State =  HIGH;
int toggle9State =  HIGH;
int toggle10State = HIGH;
int toggle11State = HIGH;
int toggle12State = HIGH;
int toggle13State = HIGH;
int toggle14State = HIGH;

// Set the active interval (*15)
float t0 =  285;
float t1 =  290;
float t2 =  295;
float t3 =  185;
float t4 =  190;
float t5 =  195;
float t6 =  385;
float t7 =  390;
float t8 =  395;
float t9 =  125;
float t10 = 130;
float t11 = 135;
float t12 = 325;
float t13 = 330;
float t14 = 335;

// Set the rest interval (*15)
float t0rest =  215; 
float t1rest =  220; 
float t2rest =  225; 
float t3rest =  125; 
float t4rest =  130; 
float t5rest =  135; 
float t6rest =  145; 
float t7rest =  150; 
float t8rest =  155; 
float t9rest =  95; 
float t10rest = 100; 
float t11rest = 105; 
float t12rest = 85; 
float t13rest = 90; 
float t14rest = 95; 

// Instatiate metro object  (*15)
Metro metro0 =  Metro(t0); 
Metro metro1 =  Metro(t1); 
Metro metro2 =  Metro(t2); 
Metro metro3 =  Metro(t3); 
Metro metro4 =  Metro(t4); 
Metro metro5 =  Metro(t5); 
Metro metro6 =  Metro(t6); 
Metro metro7 =  Metro(t7); 
Metro metro8 =  Metro(t8); 
Metro metro9 =  Metro(t9); 
Metro metro10 = Metro(t10); 
Metro metro11 = Metro(t11); 
Metro metro12 = Metro(t12); 
Metro metro13 = Metro(t13); 
Metro metro14 = Metro(t14); 

///////////////////////////////////////
//////// installation settings ////////
///////////////////////////////////////

// counter variables (*15)
int counter0 =  1;
int counter1 =  1;
int counter2 =  1;
int counter3 =  1;
int counter4 =  1;
int counter5 =  1;
int counter6 =  1;
int counter7 =  1;
int counter8 =  1;
int counter9 =  1;
int counter10 = 1;
int counter11 = 1;
int counter12 = 1;
int counter13 = 1;
int counter14 = 1;

// how many times to do pattern before it reevaluates itself (way arbitrary)
int unit0 = 13;
int unit1 = 9;
int unit2 = 7;
int unit3 = 11;
int unit4 = 16;

// installation time multiplier
int installationgp = 30;  // grand pause (*trest)
int installationrest = 14; // pause (*trest)

void setup()
{
  // declare output pins
  pinMode(motor0,OUTPUT);
  pinMode(motor1,OUTPUT);
  pinMode(motor2,OUTPUT);
  pinMode(motor3,OUTPUT);
  pinMode(motor4,OUTPUT);
  pinMode(motor5,OUTPUT);
  pinMode(motor6,OUTPUT);
  pinMode(motor7,OUTPUT);
  pinMode(motor8,OUTPUT);
  pinMode(motor9,OUTPUT);
  pinMode(motor10,OUTPUT);
  pinMode(motor11,OUTPUT);
  pinMode(motor12,OUTPUT);
  pinMode(motor13,OUTPUT);
  pinMode(motor14,OUTPUT);
}

void loop() {
  motorcontrol(metro0, motor0, motor0State, t0, t0rest, toggle0Pin, toggle0State, counter0, unit0);
  motorcontrol(metro1, motor1, motor1State, t1, t1rest, toggle1Pin, toggle1State, counter1, unit0);
  motorcontrol(metro2, motor2, motor2State, t2, t2rest, toggle2Pin, toggle2State, counter2, unit0);
  motorcontrol(metro3, motor3, motor3State, t3, t3rest, toggle3Pin, toggle3State, counter3, unit1);
  motorcontrol(metro4, motor4, motor4State, t4, t4rest, toggle4Pin, toggle4State, counter4, unit1);
  motorcontrol(metro5, motor5, motor5State, t5, t5rest, toggle5Pin, toggle5State, counter5, unit1);
  motorcontrol(metro6, motor6, motor6State, t6, t6rest, toggle6Pin, toggle6State, counter6, unit2);
  motorcontrol(metro7, motor7, motor7State, t7, t7rest, toggle7Pin, toggle7State, counter7, unit2);
  motorcontrol(metro8, motor8, motor8State, t8, t8rest, toggle8Pin, toggle8State, counter8, unit2);
  motorcontrol(metro9, motor9, motor9State, t9, t9rest, toggle9Pin, toggle9State, counter9, unit3);
  motorcontrol(metro10, motor10, motor10State, t10, t10rest, toggle10Pin, toggle10State, counter10, unit3);
  motorcontrol(metro11, motor11, motor11State, t11, t11rest, toggle11Pin, toggle11State, counter11, unit3);
  motorcontrol(metro12, motor12, motor12State, t12, t12rest, toggle12Pin, toggle12State, counter12, unit4);
  motorcontrol(metro13, motor13, motor13State, t13, t13rest, toggle13Pin, toggle13State, counter13, unit4);
  motorcontrol(metro14, motor14, motor14State, t14, t14rest, toggle14Pin, toggle14State, counter14, unit4);
  
}

//////////////////////////////////
//////// Custom Functions ////////
//////////////////////////////////

// what's left:
// -- potentiometer control of pwm value
// -- set t and trest times for all motors
// -- make installation part more fun
// -- make performance part better and figure it out
// -- installation mode: maybe take out the pause vs sustain thing...

//  motorcontrol(metro0, motor0, motor0State, t0, t0rest, toggle0Pin, toggle0State, counter0);
void motorcontrol(Metro& metro, int motor, int &motorState, float t, float trest, int togglePin, int toggleState, int &counter, int unit) {
  if (metro.check() == 1) { // check if the metro has passed its interval

    // see if installation of performance mode
    modeState = digitalRead(modePin);

    // use third knob to control motor strength (pwm)
    knob2Value = 1023 - analogRead(knob2Pin); // invert because hooked up backwards
    knob2Value = knob2Value * knob2Value;
    knob2Value = knob2Value / 1309; // "ease in-out"
    knob2Mapped = map(knob2Value, 0, 799, 0, 255);
    pwm = knob2Mapped;    

    // use second knob to control note-off length (trest)
    knob1Value = 1023 - analogRead(knob1Pin); // invert because hooked up backwards
    knob1Value = knob1Value * knob1Value;
    knob1Value = knob1Value / 1309; // "ease in-out"
    knob1Mapped = mapf(knob1Value, 0, 1023, 1, 15);
    trest = trest*knob1Mapped;

    // to turn motors on/off in either mode
    toggleState = digitalRead(togglePin); 

    if( modeState == HIGH ) { // Performance Mode ON
      
      // use first knob to control note-on length (t)
      knob0Value = 1023 - analogRead(knob0Pin); // invert because hooked up backwards
      knob0Mapped = mapf(knob0Value, 0, 1023, 1, 8);
      t = t*knob0Mapped;

      // FSR sensor to control overall speed with fast/slow modes
      sensormodeState = digitalRead(sensormodePin);
      sensorValue = analogRead(sensorPin);
      sensorValue = sensorValue * sensorValue;
      sensorValue = sensorValue / 1309; // "ease in-out"

      // to turn motors on/off
      //toggleState = digitalRead(togglePin);  
         
      if( toggleState == LOW ) {
        motorState=off;
        analogWrite(motor,motorState);
      } 
      
      if( toggleState == HIGH ) {

        if(sensorValue > 0) {
          if(sensormodeState == HIGH ) {
          // sensor on fast mode
            // make it go faster
            sensorMapped = mapf(sensorValue, 0, 799, 1, 8);

            if (motorState != off)  { 
              motorState=off;
              metro.interval(trest/sensorMapped); // rest between chirps
            } else {
              motorState=pwm;
              metro.interval(t); // original chirp speed
            }
            analogWrite(motor,motorState);
          } else {
            // sensor on slow mode
            // make it go slower
            sensorMapped = mapf(sensorValue, 0, 799, 1, 30);
            if (motorState != off)  { 
              motorState=off;
              metro.interval(trest*sensorMapped); // rest between chirps
            } else {
              motorState=pwm;
              metro.interval(t); // original chirp speed
            }
            analogWrite(motor,motorState);            
          } // end if sensor in use
        } else { // no sensor
          if (motorState != off)  { 
            motorState=off;
            metro.interval(trest); // rest between chirps
          } else {
            motorState=pwm;
            metro.interval(t); // original chirp speed
          }
          analogWrite(motor,motorState);
        }
      } // end toggle state high
    // end performance mode
    } else {
      // INSTALLATION MODE (performance mode off)
      // installation settings
      t0 =  105;
      t1 =  110;
      t2 =  115;
      t3 =  105;
      t4 =  110;
      t5 =  115;
      t6 =  105;
      t7 =  110;
      t8 =  115;
      t9 =  105;
      t10 = 110;
      t11 = 115;
      t12 = 105;
      t13 = 110;
      t14 = 115;
      // trest determined by knob2
      
      // to turn motors on/off
      //toggleState = digitalRead(togglePin);
      if( toggleState == LOW ) {
        motorState=off;
        analogWrite(motor,motorState);
      } 
      if( toggleState == HIGH ) {
        // motor on
        if( counter % unit == 0 ) {
          // do something special
          int randomize = random(0,2);
          if (randomize == 0) { // can either do a sustain or a pause
            motorState=off;
            metro.interval(trest*installationgp); // big ass pause
          } else {
            motorState=pwmgp;
            metro.interval(trest*installationgp); // t*installationgp // big ass sustain      
          }      
          analogWrite(motor,motorState);     
        } else {
          // do something normal -- chirps
          // make this fancier
          if (motorState != off)  { 
            motorState=off;
            metro.interval(trest*installationrest); // rest between chirps
          } else {
            motorState=pwm;
            metro.interval(t); // original chirp speed
          }
          analogWrite(motor,motorState);
        }
        counter = counter+1;
      } // end togglestate check 
    } // end mode check
  } // end metro check
  
} // end of motorcontrol function

float mapf(float x, float in_min, float in_max, float out_min, float out_max) {
 return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
