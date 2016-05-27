#include <Metro.h> // Include Metro library

// Define mode switch (installation vs performance modes)
const int modePin = 53;
int modeState = HIGH;

// Define sensor mode switch
const int sensormodePin = 52;
int sensormodeState = HIGH;

// Define sensor
const int sensorPin = A0;    
int sensorValue = 0; 
int sensorMapped = 0; 

// Define motors pins (*15)
const int motor0 = 13;

// Define toggles (*15)
const int toggle0Pin = 22;
int toggle0State = HIGH;

// Hold the motor states (*15)
int motor0State = pwm;

// Set the active interval (*15)
int t0 = 185;
int t1 = 300;

// Set the rest interval (*15)
// Make the differences between these proportional to their active interval
int t0rest = 365; 

// Instatiate metro object  (*15)
Metro metro0 = Metro(t0); 
//Metro metro1 = Metro(t1); 

// Set ideal pwm level
int off = 0;
int pwm = 255;
int on = 255;

///////////////////////////////////////
//////// installation settings ////////
///////////////////////////////////////

// counter variables (*15)
int counter0 = 0;

// how many times to do pattern before it reevaluates itself (way arbitrary)
int unit = 23;

// installation time multiplier
int installationgp = 20;  // grand pause (*trest)
int installationrest = 6; // pause (*trest)

void setup()
{
  pinMode(modePin, INPUT);
  
  pinMode(motor0,OUTPUT);
  analogWrite(motor0,motor0State);
  pinMode(toggle0Pin, INPUT);
}

void loop() {
  motorcontrol(metro0, motor0, motor0State, t0, t0rest, toggle0Pin, toggle0State);  
}

//////////////////////////////////
//////// Custom Functions ////////
//////////////////////////////////

// what's left:
// -- potentiometer control of pwm value
// -- set t and trest times for all motors
// -- make installation part more fun

//  motorcontrol(metro0, motor0, motor0State, t0, t0rest, toggle0Pin, toggle0State);
void motorcontrol(Metro& metro, int motor, int &motorState, int t, int trest, int togglePin, int toggleState) {
  if (metro.check() == 1) { // check if the metro has passed its interval
    
     modeState = digitalRead(modePin);
    
    if( modeState == HIGH ) { // Performance Mode ON
      
      pwm = 255; // full strength
      
      sensormodeState = digitalRead(sensormodePin);
      sensorValue = analogRead(sensorPin);
      toggleState = digitalRead(togglePin);  
         
      if( toggleState == LOW ) {
        motorState=off;
        analogWrite(motor,motorState);
      } 
      
      if( toggleState == HIGH ) {
        if(sensorValue > 0) {
          if(sensormodeState == HIGH ) {
          // sensor on fast mode
            // make it go faster
            sensorMapped = map(sensorValue, 0, 1000, 1, 12);
            if (motorState==pwm)  { 
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
            sensorMapped = map(sensorValue, 0, 1000, 1, 6);
            if (motorState==pwm)  { 
              motorState=off;
              metro.interval(trest*sensorMapped); // rest between chirps
            } else {
              motorState=pwm;
              metro.interval(t); // original chirp speed
            }
            analogWrite(motor,motorState);            
          } // end if sensor in use
        } else { // no sensor
          if (motorState==pwm)  { 
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
      // installation mode (performance mode off)
      
      pwm = 90;
      
      if( counter0 % unit == 0 ) {
        // do something special
        int rand0 = random(0,2);
        if (rand0 == 0) {
          motorState=off;
          metro.interval(trest*installationgp); // big ass pause
        } else if (rand0 == 1) {
          motorState=pwm;
          metro.interval(trest*installationgp); // big ass sustain      
        }      
        analogWrite(motor,motorState);     
      } 
      else {
        // do something normal -- occasional chirps
        // make this fancier
        if (motorState > off)  { 
          motorState=off;
          metro.interval(trest*installationrest); // rest between chirps
        } else {
          motorState=on;
          metro.interval(t); // original chirp speed
        }
        analogWrite(motor,motorState);
      }
      counter0 = counter0+1;
       
    } // end mode check
  } // end metro check
  
} // end of motorcontrol function
