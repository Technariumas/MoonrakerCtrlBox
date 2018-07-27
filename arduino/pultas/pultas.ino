#include <ResponsiveAnalogRead.h>
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
#define VOLTMETER A0



//initial indicator values
int fader1 = 0;
int fader2 = 0;
int fader3 = 0;
int compass = 0;
int voltm = 0;

int fader_low = 0;
int fader_high = 166;

int voltm_low = 0;
int voltm_high = 127;


int blinkRate = 300;
int ledState = LOW;

String state = "OFF";//TODO -- replace
int on_state = LOW;
unsigned long previousMillis = 0;
unsigned long currentMillis = 0;
ResponsiveAnalogRead fader1_pot(FADER1, true, 0.05);
ResponsiveAnalogRead fader2_pot(FADER2, true, 0.05);
ResponsiveAnalogRead fader3_pot(FADER3, true, 0.05);
ResponsiveAnalogRead voltm_pot(VOLTMETER, true);
ResponsiveAnalogRead comp_pot(COMPASS, true);
void setup() {
debouncer.attach(STATE_SWITCH, INPUT);
debouncerCue.attach(CUE_SWITCH, INPUT);
debouncer.interval(50);
debouncerCue.interval(50);
pinMode(STATE_ON, OUTPUT); 
pinMode(STATE_CUE, OUTPUT); 
pinMode(CUE1, OUTPUT); 
pinMode(CUE2, OUTPUT); 
pinMode(CUE3, OUTPUT); 

//Serial command list
sCmd.setDefaultHandler(unrecognized); 
sCmd.addCommand("OFF", turnOff);
sCmd.addCommand("ON", turnOn);
//sCmd.addCommand("CUE_WAITING", cue_standby);
Serial.begin(9600);
}

void all_leds_off() {
  digitalWrite(STATE_ON, LOW);
  digitalWrite(STATE_CUE, LOW);
  digitalWrite(CUE1, LOW);
  digitalWrite(CUE2, LOW);
  digitalWrite(CUE3, LOW);
}

void turnOff() {
  //all LEDs off
  all_leds_off();
  state = "OFF";
  //Serial.println("OFF state");
  }

void turnOn() {
  state = "ON";
  //Serial.println("ON state");
  digitalWrite(STATE_ON, HIGH);
  }

void switch_state() {
    if (state == "ON") {
      //Serial.println("TOGGLE to CUE mode");
      cue_standby();
    }
  }
  
void cue_standby() {
  state = "CUE";
  Serial.println("CUE_WAITING");
  digitalWrite(STATE_ON, LOW);
  digitalWrite(STATE_CUE, HIGH);
  }

void cue_next() {
  if (state == "CUE") {
    Serial.println("SWITCH_CUE");
    state = "CUE1_RED_LED_OFF";
    }
  else if (state == "CUE1_RED_LED_OFF") {
    Serial.println("SWITCH_CUE");
    state = "CUE1_GREEN_LED_ON";
    digitalWrite(CUE1, HIGH);
    //digitalWrite(CUE2, HIGH);
    }
  else if (state == "CUE1_GREEN_LED_ON") {
    Serial.println("SWITCH_CUE");
    state = "CUE2_RED_LED_OFF";
    digitalWrite(CUE1, LOW);
    }
  else if (state == "CUE2_RED_LED_OFF") {
    Serial.println("SWITCH_CUE");
    state = "CUE2_GREEN_LED_ON";
    digitalWrite(CUE2, HIGH);
    }
  else if (state == "CUE2_GREEN_LED_ON") {
    Serial.println("SWITCH_CUE");
    state = "CUE3_RED_LED_OFF";
    digitalWrite(CUE2, LOW);
    //digitalWrite(CUE2, HIGH);
    }
  else if (state == "CUE3_RED_LED_OFF") {
    Serial.println("SWITCH_CUE");
    state = "CUE3_GREEN_LED_ON";
    digitalWrite(CUE3, HIGH);
    }
  else if (state == "CUE3_GREEN_LED_ON") {
    Serial.println("SWITCH_CUE");
    state = "IDLE";
    digitalWrite(CUE3, LOW);
    }
  }



void loop() {
   
  sCmd.readSerial();
  
  if (state != "OFF") {
  fader1_pot.update();
  if(fader1_pot.hasChanged()) {
    updateF1();
    }
  fader2_pot.update();
  if(fader2_pot.hasChanged()) {
    updateF2();
    }
  fader3_pot.update();
  if(fader3_pot.hasChanged()) {
    updateF3();
    }  
 voltm_pot.update();
  if(voltm_pot.hasChanged()) {
    updateVoltm();
    }  
 comp_pot.update();
  if(comp_pot.hasChanged()) {
    updateCompass();
    }  
  }
  //updateCompass();

  debouncer.update();
  if ( debouncer.fell() ) {
    Serial.println(state);
    switch_state();
    }
  debouncerCue.update();
  if ( debouncerCue.fell() ) {
    Serial.println(state);
    cue_next();
    }
 if (state == "CUE1_RED_LED_OFF") {
  currentMillis = millis();
  if (currentMillis - previousMillis >= blinkRate) {
    previousMillis = currentMillis;
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
           }
    digitalWrite(CUE1, ledState);
    }      
  }
 if (state == "CUE2_RED_LED_OFF") {
  currentMillis = millis();
  if (currentMillis - previousMillis >= blinkRate) {
    previousMillis = currentMillis;
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
           }
    digitalWrite(CUE2, ledState);
    }      
  }
 if (state == "CUE3_RED_LED_OFF") {
  currentMillis = millis();
  if (currentMillis - previousMillis >= blinkRate) {
    previousMillis = currentMillis;
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
           }
    digitalWrite(CUE3, ledState);
    }      
  }    
}

// ****************** Analogue controls ********

void updateF1() {
  int f1 = fader1_pot.getValue();
  //Serial.println("Raw ServoPot1 value: ");
  //Serial.println(f1);

  fader1 = map(f1, 0, 1022, fader_low, 162);
  Serial.print("SERVO1 ");
  Serial.println(fader1);
  }  

void updateF2() {
  int f2 = fader2_pot.getValue();
  //Serial.println("Raw ServoPot2 value: ");
  //Serial.println(f2);

  fader2 = map(f2, 0, 1022, fader_low, 160);
  Serial.print("SERVO2 ");
  Serial.println(fader2);
  } 

void updateF3() {
  int f3 = fader3_pot.getValue();
  //Serial.println("Raw ServoPot3 value: ");
  //Serial.println(f3);
  fader3 = map(f3, 0, 1022, fader_low, 175);
  Serial.print("SERVO3 ");
  Serial.println(fader3);
  } 

void updateVoltm() {
  int v = voltm_pot.getValue();
  //Serial.println("Raw voltm value: ");
  //Serial.println(v);

  voltm = map(v, 0, 1022, 127, 0);
  Serial.print("VOLTM  ");
  Serial.println(voltm);
  } 

void updateCompass() {
  int c = comp_pot.getValue();
  Serial.println("Raw compass value: ");
  Serial.println(c);
  compass = map(c, 0, 1023, 270, 0);
  Serial.print("COMPASS ");
  Serial.println(compass);
  } 



void unrecognized(const char *command) {
  Serial.println("Unrecognized command: ");
  Serial.println(command);
  Serial.println("EOC");
}

