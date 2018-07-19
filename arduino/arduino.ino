
#include <Bounce2.h>
#include <Stepper.h>
#include <SerialCommand.h>


Bounce debouncer = Bounce();
SerialCommand sCmd;

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
#define PASSIVE_LEDS A4 //TODO: replace


int on_state = LOW;
String state = "ON";

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
  pinMode(LED_BUILTIN, OUTPUT);
  
  sCmd.setDefaultHandler(unrecognized); 
  sCmd.addCommand("CUE", setCue); 
  sCmd.addCommand("OFF", turnOff);
  sCmd.addCommand("HELLO", sayHello);  
  sCmd.addCommand("VOLT", updateVoltmeter);
  sCmd.addCommand("SWITCH_CUE", switch_on_cue);
  Serial.begin(115200);
}

void sayHello() {
  char *arg;
  arg = sCmd.next();    // Get the next argument from the SerialCommand object buffer
  if (arg != NULL) {    // As long as it existed, take it
    Serial.print("Hello ");
    Serial.println(arg);
    blink_LEDS();
  }
  else {
    Serial.println("Hello, whoever you are");
  }
}

void setCue() {
  if (state == "OFF") {
    state = "CUE";
    blink_LEDS();
    }
}

void turnOff() {
    state = "OFF";
    Serial.println(state);
}

void active_leds_off() {
  digitalWrite(GREEN1, LOW);
  digitalWrite(GREEN2, LOW);
  digitalWrite(GREEN3, LOW);
  digitalWrite(RED1, LOW);
  digitalWrite(RED2, LOW);
  digitalWrite(RED3, LOW);
  }

void updateVoltmeter() {
  if (state != "OFF") {
      int v;
      char *arg;
      arg = sCmd.next();
      if (arg != NULL) {
        v = atoi(arg);    // Converts a char string to an 
        int out = map(v, 0, 1023, 2, 253);
        analogWrite(VOLTMETER, out);
        Serial.println(out);
      }
    }  
  }

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

void blink_LEDS() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on 
  delay(500);                       // wait for half a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off 
  delay(500);
  }

void switch_on_cue() {
  if (state == "CUE_WAITING") {
      state == "CUE_1_RED_OFF";
    }
  else if (state == "CUE_1_RED_OFF") {
      state = "CUE_1_GREEN_ON";
      }    
  else if (state == "CUE_1_GREEN_ON") {
    state = "CUE_2_RED_OFF";   
    } 
   else if (state == "CUE_2_RED_OFF") {
      state = "CUE_2_GREEN_ON";
      }    
  else if (state == "CUE_2_GREEN_ON") {
    state = "CUE_3_RED_OFF";
    } 
  else if (state == "CUE_3_RED_OFF") {
      state = "CUE_3_GREEN_ON";
      }    
  else if (state == "CUE_2_GREEN_ON") {
    state = "IDLE";   
    }
  }  

void loop() {
  
  sCmd.readSerial(); 
  debouncer.update();
  if ( debouncer.fell() ) {
    toggle_main_switch();
    }
  if (state != "OFF") {
    Serial.println(state);
    digitalWrite(BACKLIGHT, HIGH); //power LEDs and backlight on
    digitalWrite(PASSIVE_LEDS, HIGH);
    //update_voltmeter();
   //update_indicators(); 
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
      red_leds_on();
  Serial.println("Waiting...");
  }
  if (state == "CUE_1_RED_OFF") {
      Serial.println(state);
      digitalWrite(RED1, LOW);
      }    
  if (state == "CUE_1_GREEN_ON") {
    Serial.println(state);
    digitalWrite(GREEN1, HIGH); 
    } 
    if (state == "CUE_2_RED_OFF") {
      Serial.println(state);
      digitalWrite(RED2, LOW);
      }    
  if (state == "CUE_2_GREEN_ON") {
    Serial.println(state);
    digitalWrite(GREEN2, HIGH); 
    } 
  if (state == "CUE_3_RED_OFF") {
      Serial.println(state);
      digitalWrite(RED3, LOW);
      }    
  if (state == "CUE_2_GREEN_ON") {
    Serial.println(state);
    digitalWrite(GREEN3, HIGH); 
    }
  if (state == "IDLE") {
    Serial.println(state);
    }     
}

void unrecognized(const char *command) {
  Serial.println("What?");
}


  

