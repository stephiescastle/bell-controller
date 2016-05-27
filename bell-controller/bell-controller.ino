#include <Metro.h> // Include Metro library

// define mode switch (installation vs performance modes)
const int modePin = 53;
int modeState = HIGH;

// define sensor mode switch
const int sensormodePin = 52;
int sensormodeState = HIGH;

// define sensor
const int sensorPin = A0;    
int sensorValue = 0; 
int sensorMapped = 0; 

// define motors and LEDs (*15)
const int motor0 = 13; //define led pin

//define toggles (*15)
const int toggle0Pin = 22;
int toggle0State = HIGH;

// define ideal pwm level
int off = 0;
int pwm = 255;
int on = 255;

// Create variables to hold the motor-LED states
int motor0State = pwm;

// Set the active interval
int t0 = 185;
int t1 = 300;

// Set the rest interval. Make the differences between these proportional to their active interval
int t0rest = 365; 

// instatiate metro object
Metro metro0 = Metro(t0); 
//Metro metro1 = Metro(t1); 

//////// all installation stuff ////////
////////////////////////////////////////

// counter variables (*15)
int counter0 = 0;
// how many times to do pattern before it reevaluates itself.
int unit = 23;

//product factors for isntallation
int installationgp = 20;
int installationrest = 6;

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


//////// Functions Land ////////
////////////////////////////////

// what's left to build:
// -- potentiometer control of pwm value

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
      
    } else {
      // installation mode (performance mode off)
      
      pwm = 90;
      
      if( counter0 % unit == 0 ) { // modulo needs to be double the number wanted
        int rand0 = random(0,2);
        if (rand0 == 0) {
          motorState=off;
          metro.interval(trest*installationgp);
        } else if (rand0 == 1) {
          motorState=pwm;
          metro.interval(trest*installationgp);       
        }      
        analogWrite(motor,motorState);     
      } 
      else {
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
  
}

// NO FUNCTION KEEP THIS CLEAN
//void loop() {
//
//  if (metro0.check() == 1) { // check if the metro has passed its interval
//    
//     modeState = digitalRead(modePin);
//    
//    if( modeState == HIGH ) {
//      // Performance Mode ON
//      
//      pwm = 255;
//      sensormodeState = digitalRead(sensormodePin);
//      sensorValue = analogRead(sensorPin);
//      toggle0State = digitalRead(toggle0Pin);  
//         
//      if( toggle0State == LOW ) {
//        state0=off;
//        analogWrite(LED0,state0);
//      } 
//      
//      if( toggle0State == HIGH ) {
//        if(sensorValue > 0) {
//          if(sensormodeState == HIGH ) {
//          // sensor on fast mode
//            // make it go faster
//            sensorMapped = map(sensorValue, 0, 1000, 1, 12);
//            if (state0==pwm)  { 
//              state0=off;
//              metro0.interval(t0rest/sensorMapped); // rest between chirps
//            } else {
//              state0=pwm;
//              metro0.interval(t0); // original chirp speed
//            }
//            analogWrite(LED0,state0);
//          } else {
//            // sensor on slow mode
//            // make it go slower
//            sensorMapped = map(sensorValue, 0, 1000, 1, 6);
//            if (state0==pwm)  { 
//              state0=off;
//              metro0.interval(t0rest*sensorMapped); // rest between chirps
//            } else {
//              state0=pwm;
//              metro0.interval(t0); // original chirp speed
//            }
//            analogWrite(LED0,state0);            
//          }
//        } else {      
//          if (state0==pwm)  { 
//            state0=off;
//            metro0.interval(t0rest); // rest between chirps
//          } else {
//            state0=pwm;
//            metro0.interval(t0); // original chirp speed
//          }
//          analogWrite(LED0,state0);
//        }
//      } // end button state high
//      
//    } else {
//      // installation mode (performance mode off)
//      
//      pwm = 90;
//      
//      if( counter0 % unit == 0 ) { // modulo needs to be double the number wanted
//        int rand0 = random(0,2);
//        if (rand0 == 0) {
//          state0=off;
//          metro0.interval(t0rest*installationgp);
//        } else if (rand0 == 1) {
//          state0=pwm;
//          metro0.interval(t0rest*installationgp);       
//        }      
//        analogWrite(LED0,state0);     
//      } 
//      else {
//        if (state0 > off)  { 
//          state0=off;
//          metro0.interval(t0rest*installationrest); // rest between chirps
//        } else {
//          state0=on;
//          metro0.interval(t0); // original chirp speed
//        }
//        analogWrite(LED0,state0);
//      }
//      counter0 = counter0+1;
//       
//    } // end mode check
//  } // end metro check
//  
//}
