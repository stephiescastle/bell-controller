#include <Metro.h> // Include Metro library
#define LED0  13 //define led pin


//define mode switch
int modePin = 53;
int modeState = HIGH;

//define sensor mode switch
int sensormodePin = 52;
int sensormodeState = HIGH;

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

// all installation stuff

// counters
int counter0 = 0;
// how many times to do pattern before it reevaluates itself.
int unit = 23;

//product factors for isntallation
int installationgp = 20;
int installationrest = 6;

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
    
     modeState = digitalRead(modePin);
    //modeState = LOW;
    if( modeState == HIGH ) {
      // Performance Mode ON
      
      pwm = 255;
      sensormodeState = digitalRead(sensormodePin);
      sensorValue0 = analogRead(sensorPin);
      button0State = digitalRead(button0Pin);  
         
      if( button0State == LOW ) {
        state0=off;
        analogWrite(LED0,state0);
      } 
      
      if( button0State == HIGH ) {
        if(sensorValue0 > 0) {
          if(sensormodeState == HIGH ) {
          // sensor on fast mode
            // make it go faster
            sensorMapped0 = map(sensorValue0, 0, 1000, 1, 12);
            if (state0==pwm)  { 
              state0=off;
              metro0.interval(t0rest/sensorMapped0); // rest between chirps
            } else {
              state0=pwm;
              metro0.interval(t0); // original chirp speed
            }
            analogWrite(LED0,state0);
          } else {
            // sensor on slow mode
            // make it go slower
            sensorMapped0 = map(sensorValue0, 0, 1000, 1, 6);
            if (state0==pwm)  { 
              state0=off;
              metro0.interval(t0rest*sensorMapped0); // rest between chirps
            } else {
              state0=pwm;
              metro0.interval(t0); // original chirp speed
            }
            analogWrite(LED0,state0);            
          }
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
      
    } else {
      // installation mode (performance mode off)
      
      pwm = 90;
      
      if( counter0 % unit == 0 ) { // modulo needs to be double the number wanted
        int rand0 = random(0,2);
        if (rand0 == 0) {
          state0=off;
          metro0.interval(t0rest*installationgp);
        } else if (rand0 == 1) {
          state0=pwm;
          metro0.interval(t0rest*installationgp);       
        }      
        analogWrite(LED0,state0);     
      } 
      else {
        if (state0 > off)  { 
          state0=off;
          metro0.interval(t0rest*installationrest); // rest between chirps
        } else {
          state0=on;
          metro0.interval(t0); // original chirp speed
        }
        analogWrite(LED0,state0);
      }
      counter0 = counter0+1;
       
    } // end mode check
  } // end metro check
}
