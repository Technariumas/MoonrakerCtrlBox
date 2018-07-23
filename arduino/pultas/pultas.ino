
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

int fader_low = 3;
int fader_high = 170;

int blinkRate = 300;
int ledState = LOW;

String state = "ON";//TODO -- replace
int on_state = LOW;
unsigned long previousMillis = 0;
unsigned long currentMillis = 0;

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
sCmd.addCommand("OFF", turnOff);
sCmd.addCommand("ON", turnOn);
sCmd.addCommand("CUE_WAITING", cue_standby);

Serial.begin(115200);
turnOn();
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
  }

void turnOn() {
  state = "ON";
  Serial.println("ON");
  digitalWrite(STATE_ON, HIGH);
  Serial.println("LED ON");  
  }

void switch_state() {
    if (state == "ON") {
      Serial.println("TOGGLE to CUE mode");
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
    Serial.println("CUE1_RED_LED_OFF");
    state = "CUE1_RED_LED_OFF";
    }
  else if (state == "CUE1_RED_LED_OFF") {
    Serial.println("CUE1_GREEN_LED_ON");
    state = "CUE1_GREEN_LED_ON";
    digitalWrite(CUE1, HIGH);
    //digitalWrite(CUE2, HIGH);
    }
  else if (state == "CUE1_GREEN_LED_ON") {
    Serial.println("CUE2_RED_LED_OFF");
    state = "CUE2_RED_LED_OFF";
    digitalWrite(CUE1, LOW);
    }
  else if (state == "CUE2_RED_LED_OFF") {
    Serial.println("CUE2_GREEN_LED_ON");
    state = "CUE2_GREEN_LED_ON";
    digitalWrite(CUE2, HIGH);
    }
  else if (state == "CUE2_GREEN_LED_ON") {
    Serial.println("CUE3_RED_LED_OFF");
    state = "CUE3_RED_LED_OFF";
    digitalWrite(CUE2, LOW);
    //digitalWrite(CUE2, HIGH);
    }
  else if (state == "CUE3_RED_LED_OFF") {
    Serial.println("CUE3_GREEN_LED_ON");
    state = "CUE3_GREEN_LED_ON";
    digitalWrite(CUE3, HIGH);
    }
  else if (state == "CUE3_GREEN_LED_ON") {
    Serial.println("IDLE");
    state = "IDLE";
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
  int f1 = analogRead(FADER1);
  old_fader1 = fader1;
  fader1 = map(f1, 0, 864, fader_high, fader_low);
  if (fader1 != old_fader1) {
    Serial.print("SERVO1 ");
    Serial.println(fader1);
    }
  }  

void updateF2() {
  int f2 = analogRead(FADER2);
  old_fader2 = fader2;
  fader2 = map(f2, 0, 864, fader_high, fader_low);
  if (fader2 != old_fader2) {
    Serial.print("SERVO2 ");
    Serial.println(fader2);
    }
  } 

void updateF3() {
  int f3 = analogRead(FADER3);
  old_fader3 = fader3;
  fader3 = map(f3, 0, 864, fader_high, fader_low);
  if (fader3 != old_fader3) {
    Serial.print("SERVO3 ");
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

