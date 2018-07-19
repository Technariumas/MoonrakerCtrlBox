#include <Stepper.h>
#include <SerialCommand.h>
#include <Bounce2.h>

Bounce debouncer = Bounce();

//Slider and dial controls

#define STEP_PIN 8
#define DIR_PIN 9
#define SERVO1 A0
#define SERVO2 A1
#define SERVO3 A2

//Six control LEDs

#define GREEN1 2
#define GREEN2 3
#define GREEN3 4
#define RED1 5
#define RED2 6
#define RED3 7

//Backlight, passive LEDs, voltmeter, MS

#define BACKLIGHT 10
#define VOLTMETER 11
#define MAIN_SWITCH 12
#define PASSIVE_LEDS 13

int on_state = LOW;
String state = "OFF";

void setup() {
  //Input pins
  debouncer.attach(MAIN_SWITCH,INPUT);
  debouncer.interval(25);

  //Output pins
  pinMode(SERVO1, OUTPUT); 
  pinMode(SERVO2, OUTPUT); 
  pinMode(SERVO3, OUTPUT); 
  pinMode(GREEN1, OUTPUT); 
  pinMode(GREEN2, OUTPUT); 
  pinMode(GREEN3, OUTPUT); 
  pinMode(RED1, OUTPUT); 
  pinMode(RED2, OUTPUT); 
  pinMode(RED3, OUTPUT);
  pinMode(STEP_PIN, OUTPUT); 
  pinMode(DIR_PIN, OUTPUT);  
  pinMode(BACKLIGHT, OUTPUT);
  pinMode(VOLTMETER, OUTPUT);
  pinMode(PASSIVE_LEDS, OUTPUT);
 
  SerialCommand sCmd;
  Serial.begin(9600);

}

void loop() {
  sCmd.readSerial(); 
  debouncer.update();
  if ( debouncer.fell() ) { 
    toggle_main_switch();
    }
  if (state != "OFF") {
    digitalWrite(BACKLIGHT, HIGH); //power LEDs and backlight on
    digitalWrite(PASSIVE_LEDS, HIGH);
   //update_voltmeter();
   //update_indicators(); 
    }  
  }
  if (state == "OFF") {
    digitalWrite(BACKLIGHT, LOW); //power LEDs and backlight off
    digitalWrite(PASSIVE_LEDS, LOW);
    analogWrite(VOLTMETER, LOW);
    active_leds_off();
    //indicators_off();
    //msg state;
    }
  if (state == "ON") {
    red_leds_on();
    //msg state;
    }
  if (state == "CUE_WAITING") {
      //if msg_cue_button: state -- CUE_1_RED_OFF
  if (state == "CUE_1_RED_OFF") {
      Serial.println(state);
      digitalWrite(RED1, LOW);
      state = "CUE_1_GREEN_ON";
      }    
  if (state == "CUE_1_GREEN_ON") {
    Serial.println(state);
    digitalWrite(GREEN1, HIGH); 
    state = "CUE_2_RED_OFF"   
    } 
    if (state == "CUE_2_RED_OFF") {
      Serial.println(state);
      digitalWrite(RED2, LOW);
      state = "CUE_2_GREEN_ON";
      }    
  if (state == "CUE_2_GREEN_ON") {
    Serial.println(state);
    digitalWrite(GREEN2, HIGH); 
    state = "CUE_3_RED_OFF"   
    } 
  if (state == "CUE_3_RED_OFF") {
      Serial.println(state);
      digitalWrite(RED3, LOW);
      state = "CUE_3_GREEN_ON";
      }    
  if (state == "CUE_2_GREEN_ON") {
    Serial.println(state);
    digitalWrite(GREEN3, HIGH); 
    state = "IDLE";   
    }
  if (state == "IDLE") {
    Serial.println(state);
    }     
}


void active_leds_off() {
  digitalWrite(GREEN1, LOW);
  digitalWrite(GREEN2, LOW);
  digitalWrite(GREEN3, LOW);
  digitalWrite(RED1, LOW);
  digitalWrite(RED2, LOW);
  digitalWrite(RED3, LOW);
  }

//void updateVoltmeter() {
  //voltmeter_range = //msg value
  //v_out = map(msg_value, 15, 1023, 253, 32);
  //analogWrite(VOLTMETER, v_out); 
  //}

void red_leds_on() {
  digitalWrite(RED1, HIGH);
  digitalWrite(RED2, HIGH);
  digitalWrite(RED3, HIGH);
  }

void toggle_main_switch() {
      on_state = !on_state;
    if (on_state == LOW) {
      state = "OFF";
      }
    if (on_state == HIGH) {
      state = "ON";
      }
    Serial.println("Main switch toggled");
    }
  

