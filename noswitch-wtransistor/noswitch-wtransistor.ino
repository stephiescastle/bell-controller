#include <Metro.h> // Include Metro library
#define LED0 13 // Define a LED pin
#define LED1 12 // Define another LED pin
#define LED2 11 // Define another LED pin
#define LED3 10 
#define LED4  9 
#define LED5  8
#define LED6  7 
#define LED7  6 
#define LED8  5
#define LED9  4 
#define LED10 3 
#define LED11 2
#define LED12 44 // extra pwm pins
#define LED13 45 // extra pwm pins
#define LED14 46 // extra pwm pins

// define ideal pwm level
int off = 0;
int pwm = 255;
int on = 255;

// Create variables to hold the LED states
int state0 = pwm;
int state1 = pwm;
int state2 = pwm;
int state3 = pwm;
int state4 = pwm;
int state5 = pwm;
int state6 = pwm;
int state7 = pwm;
int state8 = pwm;
int state9 = pwm;
int state10 = pwm;
int state11 = pwm;
int state12 = pwm;
int state13 = pwm;
int state14 = pwm;

// Instantiate a metro object and set the active interval
int t0 = 185;
int t1 = 190;
int t2 = 195;
int t3 = 186;
int t4 = 191;
int t5 = 196;
int t6 = 187;
int t7 = 192;
int t8 = 197;
int t9 = 188;
int t10 = 193;
int t11 = 198;
int t12 = 189;
int t13 = 194;
int t14 = 199;

// rest interval. make the differences between these proportional to their active interval
int t0rest = 365; 
int t1rest = 370;
int t2rest = 375;
int t3rest = 363; 
int t4rest = 370;
int t5rest = 373;
int t6rest = 366; 
int t7rest = 370;
int t8rest = 376;
int t9rest = 362; 
int t10rest = 370;
int t11rest = 372;
int t12rest = 367; 
int t13rest = 370;
int t14rest = 377;

Metro metro0 = Metro(t0); 
Metro metro1 = Metro(t1); 
Metro metro2 = Metro(t2); 
Metro metro3 = Metro(t3); 
Metro metro4 = Metro(t4); 
Metro metro5 = Metro(t5); 
Metro metro6 = Metro(t6); 
Metro metro7 = Metro(t7); 
Metro metro8 = Metro(t8); 
Metro metro9 = Metro(t9); 
Metro metro10 = Metro(t10); 
Metro metro11 = Metro(t11); 
Metro metro12 = Metro(t12); 
Metro metro13 = Metro(t13); 
Metro metro14 = Metro(t14); 

void setup()
{
  pinMode(LED0,OUTPUT);
  analogWrite(LED0,state0);
  
  pinMode(LED1,OUTPUT);
  analogWrite(LED1,state1);
  
  pinMode(LED2,OUTPUT);
  analogWrite(LED2,state2);

  pinMode(LED3,OUTPUT);
  analogWrite(LED3,state3);
  
  pinMode(LED4,OUTPUT);
  analogWrite(LED4,state4);
  
  pinMode(LED5,OUTPUT);
  analogWrite(LED5,state5);
  
  pinMode(LED6,OUTPUT);
  analogWrite(LED6,state6);
  
  pinMode(LED7,OUTPUT);
  analogWrite(LED7,state7);
  
  pinMode(LED8,OUTPUT);
  analogWrite(LED8,state8);
  
  pinMode(LED9,OUTPUT);
  analogWrite(LED9,state9);
  
  pinMode(LED10,OUTPUT);
  analogWrite(LED10,state10);
  
  pinMode(LED11,OUTPUT);
  analogWrite(LED11,state11);
    
  pinMode(LED12,OUTPUT);
  analogWrite(LED12,state12);
  
  pinMode(LED13,OUTPUT);
  analogWrite(LED13,state13);
  
  pinMode(LED14,OUTPUT);
  analogWrite(LED14,state14);
  
}

void loop()
{
      
  if (metro0.check() == 1) { // check if the metro has passed its interval . 
      
      if (state0==pwm)  { 
        state0=off;
        metro0.interval(t0rest); // rest between chirps
      } else {
        state0=pwm;
        metro0.interval(t0); // original chirp speed
      }
      analogWrite(LED0,state0);
  }
  
   if (metro1.check() == 1) { // check if the metro has passed its interval .
      if (state1==pwm)  { 
        state1=off;
        metro1.interval(t1rest); // rest between chirps
      } else {
        state1=pwm;
        metro1.interval(t1); // original chirp speed
      }
      analogWrite(LED1,state1);
  }
  if (metro2.check() == 1) { // check if the metro has passed its interval .
      if (state2==pwm)  { 
        state2=off;
        metro2.interval(t2rest); // rest between chirps
      } else {
        state2=pwm;
        metro2.interval(t2); // original chirp speed
      }
      analogWrite(LED2,state2);
  }

  if (metro3.check() == 1) { // check if the metro has passed its interval . 
      if (state3==pwm)  { 
        state3=off;
        metro3.interval(t3rest); // rest between chirps
      } else {
        state3=pwm;
        metro3.interval(t3); // original chirp speed
      }
      analogWrite(LED3,state3);
  }
  
   if (metro4.check() == 1) { // check if the metro has passed its interval .
      if (state4==pwm)  { 
        state4=off;
        metro4.interval(t4rest); // rest between chirps
      } else {
        state4=pwm;
        metro4.interval(t4); // original chirp speed
      }
      analogWrite(LED4,state4);
  }
  if (metro5.check() == 1) { // check if the metro has passed its interval .
      if (state5==pwm)  { 
        state5=off;
        metro5.interval(t5rest); // rest between chirps
      } else {
        state5=pwm;
        metro5.interval(t5); // original chirp speed
      }
      analogWrite(LED5,state5);
  }

  if (metro6.check() == 1) { // check if the metro has passed its interval . 
      if (state6==pwm)  { 
        state6=off;
        metro6.interval(t6rest); // rest between chirps
      } else {
        state6=pwm;
        metro6.interval(t6); // original chirp speed
      }
      analogWrite(LED6,state6);
  }
  
   if (metro7.check() == 1) { // check if the metro has passed its interval .
      if (state7==pwm)  { 
        state7=off;
        metro7.interval(t7rest); // rest between chirps
      } else {
        state7=pwm;
        metro7.interval(t7); // original chirp speed
      }
      analogWrite(LED7,state7);
  }
  if (metro8.check() == 1) { // check if the metro has passed its interval .
      if (state8==pwm)  { 
        state8=off;
        metro8.interval(t8rest); // rest between chirps
      } else {
        state8=pwm;
        metro8.interval(t8); // original chirp speed
      }
      analogWrite(LED8,state8);
  }

  if (metro9.check() == 1) { // check if the metro has passed its interval . 
      if (state9==pwm)  { 
        state9=off;
        metro9.interval(t9rest); // rest between chirps
      } else {
        state9=pwm;
        metro9.interval(t9); // original chirp speed
      }
      analogWrite(LED9,state9);
  }
  
   if (metro10.check() == 1) { // check if the metro has passed its interval .
      if (state10==pwm)  { 
        state10=off;
        metro10.interval(t10rest); // rest between chirps
      } else {
        state10=pwm;
        metro10.interval(t10); // original chirp speed
      }
      analogWrite(LED10,state10);
  }
  if (metro11.check() == 1) { // check if the metro has passed its interval .
      if (state11==pwm)  { 
        state11=off;
        metro11.interval(t11rest); // rest between chirps
      } else {
        state11=pwm;
        metro11.interval(t11); // original chirp speed
      }
      analogWrite(LED11,state11);
  }

  if (metro12.check() == 1) { // check if the metro has passed its interval . 
      if (state12==pwm)  { 
        state12=off;
        metro12.interval(t12rest); // rest between chirps
      } else {
        state12=pwm;
        metro12.interval(t12); // original chirp speed
      }
      analogWrite(LED12,state12);
  }
  
   if (metro13.check() == 1) { // check if the metro has passed its interval .
      if (state13==pwm)  { 
        state13=off;
        metro13.interval(t13rest); // rest between chirps
      } else {
        state13=pwm;
        metro13.interval(t13); // original chirp speed
      }
      analogWrite(LED13,state13);
  }
  if (metro14.check() == 1) { // check if the metro has passed its interval .
      if (state14==pwm)  { 
        state14=off;
        metro14.interval(t14rest); // rest between chirps
      } else {
        state14=pwm;
        metro14.interval(t14); // original chirp speed
      }
      analogWrite(LED14,state14);
  }
  
}
