#include <Metro.h> // Include Metro library
#define LED0  5 //define led pin


//define mode switch
int modePin = 53;
int modeState = HIGH;

//define buttons
int button0Pin = 31;
int button0State = HIGH;

// sensor stuff
int sensorPin = A0;    
int sensorValue0 = 0; 
int sensorMapped0 = 0; 

// define ideal pwm level
int off = 0;
int pwm = 255;
int on = 255;

// Create variables to hold the LED states
int state0 = pwm;

// Instantiate a metro object and set the active interval
int t0 = 185;

// rest interval. make the differences between these proportional to their active interval
int t0rest = 365; 

//product factor
int factor = 2;

Metro metro0 = Metro(t0); 

void setup()
{
  pinMode(modePin, INPUT);
  
  pinMode(LED0,OUTPUT);
  analogWrite(LED0,state0);
  pinMode(button0Pin, INPUT);
}

void loop() {

  if (metro0.check() == 1) { // check if the metro has passed its interval

    sensorValue0 = analogRead(sensorPin);
    button0State = digitalRead(button0Pin);  
       
    //sensor not activated
    if( button0State == LOW ) {
      state0=off;
      analogWrite(LED0,state0);
    } 
    
    if( button0State == HIGH ) {
      if(sensorValue0 > 0) {       
        // sensor is activated, make it go faster
        sensorMapped0 = map(sensorValue0, 0, 60, 1, 8);
        if (state0==pwm)  { 
          state0=off;
          metro0.interval(t0rest/sensorValue0); // rest between chirps
        } else {
          state0=pwm;
          metro0.interval(t0); // original chirp speed
        }
        analogWrite(LED0,state0);
      } else {      
        if (state0==pwm)  { 
          state0=off;
          metro0.interval(t0rest); // rest between chirps
        } else {
          state0=pwm;
          metro0.interval(t0); // original chirp speed
        }
        analogWrite(LED0,state0);
      }
    } // end button state high
  } // end metro check
}
