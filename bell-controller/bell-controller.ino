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

// Set ideal pwm level
int off = 0;
int pwm = 255;
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
int t0 =  185;
int t1 =  185;
int t2 =  185;
int t3 =  185;
int t4 =  185;
int t5 =  185;
int t6 =  185;
int t7 =  185;
int t8 =  185;
int t9 =  185;
int t10 = 185;
int t11 = 185;
int t12 = 185;
int t13 = 185;
int t14 = 185;

// Set the rest interval (*15)
int t0rest =  365; 
int t1rest =  365; 
int t2rest =  365; 
int t3rest =  365; 
int t4rest =  365; 
int t5rest =  365; 
int t6rest =  365; 
int t7rest =  365; 
int t8rest =  365; 
int t9rest =  365; 
int t10rest = 365; 
int t11rest = 365; 
int t12rest = 365; 
int t13rest = 365; 
int t14rest = 365; 

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
int counter0 =  0;
int counter1 =  0;
int counter2 =  0;
int counter3 =  0;
int counter4 =  0;
int counter5 =  0;
int counter6 =  0;
int counter7 =  0;
int counter8 =  0;
int counter9 =  0;
int counter10 = 0;
int counter11 = 0;
int counter12 = 0;
int counter13 = 0;
int counter14 = 0;

// how many times to do pattern before it reevaluates itself (way arbitrary)
int unit = 23;

// installation time multiplier
int installationgp = 20;  // grand pause (*trest)
int installationrest = 6; // pause (*trest)

void setup()
{
  // don't need to decalre input pins
  //pinMode(modePin, INPUT);
  //pinMode(toggle0Pin, INPUT);

  // don't know why I had this in here
  //analogWrite(motor0,motor0State);

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
  motorcontrol(metro0, motor0, motor0State, t0, t0rest, toggle0Pin, toggle0State, counter0);
  motorcontrol(metro1, motor1, motor1State, t1, t1rest, toggle1Pin, toggle1State, counter1);
  motorcontrol(metro2, motor2, motor2State, t2, t2rest, toggle2Pin, toggle2State, counter2);
  motorcontrol(metro3, motor3, motor3State, t3, t3rest, toggle3Pin, toggle3State, counter3);
  motorcontrol(metro4, motor4, motor4State, t4, t4rest, toggle4Pin, toggle4State, counter4);
  motorcontrol(metro5, motor5, motor5State, t5, t5rest, toggle5Pin, toggle5State, counter5);
  motorcontrol(metro6, motor6, motor6State, t6, t6rest, toggle6Pin, toggle6State, counter6);
  motorcontrol(metro7, motor7, motor7State, t7, t7rest, toggle7Pin, toggle7State, counter7);
  motorcontrol(metro8, motor8, motor8State, t8, t8rest, toggle8Pin, toggle8State, counter8);
  motorcontrol(metro9, motor9, motor9State, t9, t9rest, toggle9Pin, toggle9State, counter9);
  motorcontrol(metro10, motor10, motor10State, t10, t10rest, toggle10Pin, toggle10State, counter10);
  motorcontrol(metro11, motor11, motor11State, t11, t11rest, toggle11Pin, toggle11State, counter11);
  motorcontrol(metro12, motor12, motor12State, t12, t12rest, toggle12Pin, toggle12State, counter12);
  motorcontrol(metro13, motor13, motor13State, t13, t13rest, toggle13Pin, toggle13State, counter13);
  motorcontrol(metro14, motor14, motor14State, t14, t14rest, toggle14Pin, toggle14State, counter14);
  
}

//////////////////////////////////
//////// Custom Functions ////////
//////////////////////////////////

// what's left:
// -- potentiometer control of pwm value
// -- set t and trest times for all motors
// -- make installation part more fun

//  motorcontrol(metro0, motor0, motor0State, t0, t0rest, toggle0Pin, toggle0State, counter0);
void motorcontrol(Metro& metro, int motor, int &motorState, int t, int trest, int togglePin, int toggleState, int counter) {
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
      // INSTALLATION MODE (performance mode off)
      
      pwm = 90;
      
      if( counter % unit == 0 ) {
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
      counter = counter+1;
       
    } // end mode check
  } // end metro check
  
} // end of motorcontrol function
