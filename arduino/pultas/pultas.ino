
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
#define FADER1 A0
#define FADER2 A1
#define FADER3 A2
#define COMPASS A3 
#define VOLTM A4

//initial indicator positions
int fader1 = 0;    
int fader2 = 0;
int fader3 = 0;
int fader_compass = 0;
int fader_voltm = 0;

String state = "OFF";
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
  all_leds_off();
  state == "OFF";
  }

void switch_state() {
    if (state == "OFF") {
       state = "ON";
       digitalWrite(STATE_ON, HIGH);
    }
    if (state == "ON") {
      state = "CUE";
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

void loop() {
  sCmd.readSerial();
  debouncer.update();
  if ( debouncer.fell() ) {
    switch_state();
    }
  debouncerCue.update();
  if ( debouncerCue.fell() ) {
    cue_next();
    }  
}


