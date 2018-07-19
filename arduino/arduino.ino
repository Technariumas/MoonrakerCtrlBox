
#include <Bounce2.h>
#include <SerialCommand.h>
#include <Servo.h>

Bounce debouncer = Bounce();
SerialCommand sCmd;
Servo servo1;
Servo servo2;
Servo servo3;
Servo compass;

int servoPos1 = 0;    //initial slider position
int servoPos2 = 0;
int servoPos3 = 0;
int compass_pos = 0;
int volt_pos = 0;

//Slider and dial controls

#define COMPASS_PIN 8
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
unsigned long previousMillis = 0;        
const long updateInt = 300; 

void setup() {
  //Input pins
  debouncer.attach(MAIN_SWITCH,INPUT);
  debouncer.interval(25);

  //Output pins
  pinMode(SERVO1, OUTPUT);
  servo1.attach(SERVO1); 
  pinMode(SERVO2, OUTPUT); 
  servo2.attach(SERVO2);
  pinMode(SERVO3, OUTPUT);
  servo3.attach(SERVO3); 
  pinMode(COMPASS_PIN, OUTPUT); 
  pinMode(DIR_PIN, OUTPUT);
    
  pinMode(GREEN1, OUTPUT); 
  pinMode(GREEN2, OUTPUT); 
  pinMode(GREEN3, OUTPUT); 
  pinMode(RED1, OUTPUT); 
  pinMode(RED2, OUTPUT); 
  pinMode(RED3, OUTPUT);
  pinMode(BACKLIGHT, OUTPUT);
  pinMode(VOLTMETER, OUTPUT);
  pinMode(PASSIVE_LEDS, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  //Serial command list
  sCmd.setDefaultHandler(unrecognized); 
  sCmd.addCommand("CUE", setCue); 
  sCmd.addCommand("OFF", turnOff);
  sCmd.addCommand("VOLT", updateVoltmeter);
  sCmd.addCommand("SERVO1", updateServo1);
  sCmd.addCommand("SERVO2", updateServo2);
  sCmd.addCommand("SERVO3", updateServo3); 
  sCmd.addCommand("COMPASS", updateCompass);      
  sCmd.addCommand("SWITCH_CUE", switch_on_cue);
  Serial.begin(115200);
}



void updateServo1() {
      if (state != "OFF") {
        int s;
        char *arg;
        arg = sCmd.next();
        if (arg != NULL) {
         s = atoi(arg);   
         servoPos1 = map(s, 0, 1023, 2, 170);
         servo1.write(servoPos1);
      }
      else {Serial.println("NO SERVO1 ARG");}
    }  
}

void updateServo2() {
      if (state != "OFF") {
        int s;
        char *arg;
        arg = sCmd.next();
        if (arg != NULL) {
         s = atoi(arg);   
         servoPos2 = map(s, 0, 1023, 2, 170);
         servo2.write(servoPos2);
      }
      else {Serial.println("NO SERVO2 ARG");}
    }  
}

void updateServo3() {
      if (state != "OFF") {
        int s;
        char *arg;
        arg = sCmd.next();
        if (arg != NULL) {
         s = atoi(arg);   
         servoPos3 = map(s, 0, 1023, 2, 170);
         servo3.write(servoPos3);
      }
      else {Serial.println("NO SERVO3 ARG");}
    }  
}

void updateCompass() {
      if (state != "OFF") {
        int s;
        char *arg;
        arg = sCmd.next();
        if (arg != NULL) {
         s = atoi(arg);   
         compass_pos = map(s, 0, 1023, -170, 170);
         compass.write(compass_pos);
      }
      else {Serial.println("NO COMPASS ARG");}
    }  
}

void updateVoltmeter() {
  if (state != "OFF") {
      int v;
      char *arg;
      arg = sCmd.next();
      if (arg != NULL) {
        v = atoi(arg);    // Converts a char string to an 
        volt_pos = map(v, 0, 1023, 2, 253);
        analogWrite(VOLTMETER, volt_pos);
        Serial.println(volt_pos);
      }
      else {Serial.println("NO ARG");}
    }  
  }

void setCue() {
  if (state == "ON") {
    state = "CUE_WAITING";
    }
}

void turnOff() {
    state = "OFF";
}

void active_leds_off() {
  digitalWrite(GREEN1, LOW);
  digitalWrite(GREEN2, LOW);
  digitalWrite(GREEN3, LOW);
  digitalWrite(RED1, LOW);
  digitalWrite(RED2, LOW);
  digitalWrite(RED3, LOW);
  }

void indicators_off() {
   servo1.write(0);
   servo2.write(0);
   servo3.write(0);
   compass.write(0);
   analogWrite(VOLTMETER, 0);
  }

void indicators_on() {
  servo1.write(servoPos1);
  servo2.write(servoPos2);
  servo3.write(servoPos3);
  compass.write(compass_pos);
  analogWrite(VOLTMETER, volt_pos);
  }
    

void red_leds_on() {
  digitalWrite(RED1, HIGH);
  digitalWrite(RED2, HIGH);
  digitalWrite(RED3, HIGH);
  }


void toggle_main_switch() {
    on_state = !on_state;
    if (on_state == LOW) {
      indicators_off();
      state = "OFF";
      digitalWrite(BACKLIGHT, LOW); //power LEDs and backlight off
      digitalWrite(PASSIVE_LEDS, LOW);
      active_leds_off();
      }
    if (on_state == HIGH) {
      state = "ON";
      red_leds_on();
      digitalWrite(BACKLIGHT, HIGH); //power LEDs and backlight on
      digitalWrite(PASSIVE_LEDS, HIGH);
      indicators_on();
      }
    }

void blink_LEDS() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on 
  delay(500);                       // wait for half a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off 
  delay(500);
  }

void update_state() {
      unsigned long currentMillis = millis();
      if (currentMillis - previousMillis >= updateInt) {
          previousMillis = currentMillis;
          Serial.println(state);
  }
}



void loop() {
  sCmd.readSerial();
  debouncer.update();
  if ( debouncer.fell() ) {
    toggle_main_switch();
    }
  if (state == "OFF") {
    update_state();
    }
  if (state == "ON") {
    update_state();
    }
  if (state == "CUE_WAITING") {
      update_state();
  }
  if (state == "CUE_1_RED_OFF") {
      update_state();
      digitalWrite(RED1, LOW);
      }    
  if (state == "CUE_1_GREEN_ON") {
    update_state();
    digitalWrite(GREEN1, HIGH); 
    } 
    if (state == "CUE_2_RED_OFF") {
      update_state();
      digitalWrite(RED2, LOW);
      }    
  if (state == "CUE_2_GREEN_ON") {
    update_state();
    digitalWrite(GREEN2, HIGH); 
    } 
  if (state == "CUE_3_RED_OFF") {
      update_state();
      digitalWrite(RED3, LOW);
      }    
  if (state == "CUE_3_GREEN_ON") {
    update_state();
    digitalWrite(GREEN3, HIGH); 
    }
  if (state == "IDLE") {
   update_state();
    }     
}

void unrecognized(const char *command) {
  Serial.println("What?");
}


void switch_on_cue() {
  if (state == "CUE_WAITING") {
      state = "CUE_1_RED_OFF";
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
  else if (state == "CUE_3_GREEN_ON") {
    state = "IDLE";   
    }
  }  
  

