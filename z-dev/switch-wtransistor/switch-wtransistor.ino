#include <Metro.h> // Include Metro library
#define LED0  5 //define led pin

//define buttons
int button0Pin = 31;
int button0State = HIGH;

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

Metro metro0 = Metro(t0); 

void setup()
{
  pinMode(LED0,OUTPUT);
  analogWrite(LED0,state0);
  pinMode(button0Pin, INPUT);
}

void loop()
{
      
  if (metro0.check() == 1) { // check if the metro has passed its interval .
    button0State = digitalRead(button0Pin);  
    
    if( button0State == LOW ) {
      state0=off;
      analogWrite(LED0,state0);
    } 
    
    if( button0State == HIGH ) {
      if (state0==pwm)  { 
        state0=off;
        metro0.interval(t0rest); // rest between chirps
      } else {
        state0=pwm;
        metro0.interval(t0); // original chirp speed
      }
      analogWrite(LED0,state0);
    }
    
  }
}
