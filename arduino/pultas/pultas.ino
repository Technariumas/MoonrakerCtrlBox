
#include <Bounce2.h>
#include <SerialCommand.h>

Bounce debouncer = Bounce();
Bounce debouncerCue = Bounce();
SerialCommand sCmd;

//indicator LEDs

#define STATE_ON 2
#define STATE_CUE 3
#define CUE1 4
#define CUE2 5
#define CUE3 6

#define STATE_SWITCH 7
#define CUE_SWITCH 8

//potentiometers
#define FADER1 A4
#define FADER2 A3
#define FADER3 A2
#define COMPASS A1 
#define VOLTM A0



//initial indicator values
int fader1 = 0;
int old_fader1 = 0;
int fader2 = 0;
int old_fader2 = 0;
int fader3 = 0;
int old_fader3 = 0;
int compass = 0;
int old_compass = 0;
int voltm = 0;
int old_voltm = 0;



String state = "OFF";//TODO -- replace
int on_state = LOW;

void setup() {
debouncer.attach(STATE_SWITCH, INPUT);
debouncerCue.attach(CUE_SWITCH, INPUT);
debouncer.interval(25);
debouncerCue.interval(25);
pinMode(STATE_ON, OUTPUT); 
pinMode(STATE_CUE, OUTPUT); 
pinMode(CUE1, OUTPUT); 
pinMode(CUE2, OUTPUT); 
pinMode(CUE3, OUTPUT); 

//Serial command list
sCmd.addCommand("OFF", turnOff);
sCmd.addCommand("CUE_WAITING", cue_standby);

Serial.begin(115200);
}

void turnOff() {
  //all LEDs off
  //if on button is pressed, light led
  //all_leds_off();
  state == "OFF";
  }

void switch_state() {
    if (state == "OFF") {
       state = "ON";
       Serial.println("ON");
       digitalWrite(STATE_ON, HIGH);
    }
    if (state == "ON") {
      //Serial.println("CUE");
      state = "CUE";
      cue_standby();
      }
}
//OFF
//ON
//CUE_WAITING
//CUE_1_RED_OFF
//CUE_1_GREEN_ON
//CUE_2_RED_OFF
//CUE_2_GREEN_ON
//CUE_3_RED_OFF
//CUE_3_GREEN_ON
//IDLE

void cue_standby() {
  digitalWrite(STATE_ON, LOW);
  digitalWrite(STATE_CUE, HIGH);
  }

void cue_next() {
  if (state == "CUE") {
    state = "CUE1";
    digitalWrite(CUE1, HIGH);
    }
  if (state == "CUE1") {
    state = "CUE2";
    digitalWrite(CUE1, LOW);
    digitalWrite(CUE2, HIGH);
    }
  if (state == "CUE2") {
    state = "IDLE";
    digitalWrite(CUE2, LOW);
    digitalWrite(CUE3, HIGH);
    }
  if (state == "IDLE") {
    digitalWrite(CUE3, LOW);    
    }
  }



void loop() {
  //updateF1();
  //updateF2();
  //updateF3();
  //updateVoltm();
  //updateCompass();
  sCmd.readSerial();
  debouncer.update();
  if ( debouncer.fell() ) {
    Serial.println("state button pressed");
    Serial.println(state);
    switch_state();
    }
  debouncerCue.update();
  if ( debouncerCue.fell() ) {
    Serial.println("cue button pressed");
    Serial.println(state);
    cue_next();
    }  
}


// ****************** Analogue controls ********

void updateF1() {
  int f1 = analogRead(FADER1);
  old_fader1 = fader1;
  fader1 = map(f1, 0, 864, 32, 0);
  if (fader1 != old_fader1) {
    Serial.print("F1 ");
    Serial.println(fader1);
    }
  }  

void updateF2() {
  int f2 = analogRead(FADER2);
  old_fader2 = fader2;
  fader2 = map(f2, 0, 864, 32, 0);
  if (fader2 != old_fader2) {
    Serial.print("F2 ");
    Serial.println(fader2);
    }
  } 

void updateF3() {
  int f3 = analogRead(FADER3);
  old_fader3 = fader3;
  fader3 = map(f3, 0, 864, 32, 0);
  if (fader3 != old_fader3) {
    Serial.print("F3 ");
    Serial.println(fader3);
    }
  } 

void updateCompass() {
  int c = analogRead(COMPASS);
  old_compass = compass;
  compass = map(c, 0, 864, 32, 0);
  if (compass!= old_compass) {
    Serial.print("COMPASS ");
    Serial.println(compass);
    }
  } 

void updateVoltm() {
  int v = analogRead(VOLTM);
  old_voltm = voltm;
  voltm = map(v, 0, 864, 32, 0);
  if (voltm!= old_voltm) {
    Serial.print("VOLTM ");
    Serial.println(voltm);
    }
  } 

