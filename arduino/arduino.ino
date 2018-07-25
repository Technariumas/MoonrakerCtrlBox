#include <Bounce2.h>
#include <SerialCommand.h>
#include <Servo.h>
#include <ServoEaser.h>

Bounce debouncer = Bounce();
SerialCommand sCmd;

int servoFrameMillis = 20;  // minimum time between servo updates

Servo servo1; 
ServoEaser servoEaser1;
unsigned long lastMillis;

Servo servo2;
ServoEaser servoEaser2;

Servo servo3;
ServoEaser servoEaser3;

Servo compass;
ServoEaser compassEaser;

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
  servoEaser1.useMicroseconds( true ); 
  servoEaser1.begin(servo1, 20);   

  
  pinMode(SERVO2, OUTPUT); 
  servo2.attach(SERVO2);
  servoEaser2.useMicroseconds( true ); 
  servoEaser2.begin(servo2, 20);    
  
  pinMode(SERVO3, OUTPUT);
  servo3.attach(SERVO3); 
  servoEaser3.useMicroseconds( true ); 
  servoEaser3.begin(servo3, 20);
    
  pinMode(COMPASS_PIN, OUTPUT);
  compass.attach(COMPASS_PIN); 
  compassEaser.begin(compass, 20);
 
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
  //sCmd.setDefaultHandler(unrecognized); 
  sCmd.addCommand("CUE_WAITING", setCue); 
  sCmd.addCommand("SWITCH_CUE", switch_on_cue);
  sCmd.addCommand("VOLTM", updateVoltmeter);
  sCmd.addCommand("SERVO1", updateServo1);
  sCmd.addCommand("SERVO2", updateServo2);
  sCmd.addCommand("SERVO3", updateServo3); 
  sCmd.addCommand("COMPASS", updateCompass);      

  //sCmd.addCommand("OFF", turnOff);
  Serial.begin(9600);
}



void updateServo1() {
      if (state != "OFF") {
          int s;
          char *arg;
          arg = sCmd.next();
          if (arg != NULL) {
            s = atoi(arg);
            servoPos1 = s;//map(s, -14, 166, 0, 127);

            Serial.print("Servo1: ");
            Serial.println(servoPos1);
            //if (servoEaser1.hasArrived()) {  
              servoEaser1.easeTo( servoPos1, 300 );
          //}
        }
          //else {Serial.println("NO SERVO1 ARG");}
    }
}

void updateServo2() {
      if (state != "OFF") {
        //if (servoEaser2.hasArrived()) { 
        int s;
        char *arg;
        arg = sCmd.next();
        if (arg != NULL) {
        s = atoi(arg);
        servoPos2 = s;//constrain(s, -14, 166);
             
        servoEaser2.easeTo( servoPos2, 300 );
        //servo2.write(servoPos2);
        Serial.print("Servo2 : ");
        Serial.println(servoPos2);
        }
          //else {Serial.println("NO SERVO1 ARG");}
    }
}

void updateServo3() {
      if (state != "OFF") {
        //if (servoEaser3.hasArrived()) {
         int s;
          char *arg;
          arg = sCmd.next();
          if (arg != NULL) {
            s = atoi(arg);   
            //Serial.println(s);
            servoPos3 = s;//constrain(s, -14, 166);
            Serial.print("Servo3: ");
            Serial.println(servoPos3);
            servoEaser3.easeTo( servoPos3, 700 );
          //}
          //else {Serial.println("NO SERVO1 ARG");}
    }
    }
}

void updateCompass() {
      if (state != "OFF") {
        int s;
        char *arg;
        arg = sCmd.next();
        if (arg != NULL) {
         s = atoi(arg);   
         compass_pos = s;//map(s, 0, 166, 0, 360);
         Serial.print("Compass: ");
         Serial.println(compass_pos);
         compass.write(compass_pos);
      }
      else {Serial.println("NO COMPASS ARG");}
    }  
}

void updateVoltmeter() {
  if (state != "OFF") {
      Serial.println(state);
      int v;
      char *arg;
      arg = sCmd.next();
      if (arg != NULL) {
        v = atoi(arg);   
        volt_pos = map(v, 0, 127, 0, 220);
        //volt_pos = constrain(volt_pos, 0, 220);
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

void main_switch_on() {
      state = "ON";
      red_leds_on();
      digitalWrite(BACKLIGHT, HIGH); //power LEDs and backlight on
      digitalWrite(PASSIVE_LEDS, HIGH);
      indicators_on();
      Serial.println("ON");
  }

void main_switch_off() {
      indicators_off();
      state = "OFF";
      Serial.println("OFF");
      digitalWrite(BACKLIGHT, LOW); //power LEDs and backlight off
      digitalWrite(PASSIVE_LEDS, LOW);
      active_leds_off();
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
  if (state != "OFF") {
    servoEaser1.update();
    servoEaser2.update();
    servoEaser3.update();
    compassEaser.update();
    
  }
  sCmd.readSerial();
  debouncer.update();
  if ( debouncer.fell() ) {
    main_switch_on();
    }
  if ( debouncer.rose() ) {
    main_switch_off();
    }

  if (state == "OFF") {
    //update_state();
    }
  if (state == "ON") {
    //update_state();
    }
  if (state == "CUE_WAITING") {
      //update_state();
  }
  if (state == "CUE_1_RED_OFF") {
      //update_state();
      digitalWrite(RED1, LOW);
      }    
  if (state == "CUE_1_GREEN_ON") {
    //update_state();
    digitalWrite(GREEN1, HIGH); 
    } 
    if (state == "CUE_2_RED_OFF") {
      //update_state();
      digitalWrite(RED2, LOW);
      }    
  if (state == "CUE_2_GREEN_ON") {
    //update_state();
    digitalWrite(GREEN2, HIGH); 
    } 
  if (state == "CUE_3_RED_OFF") {
      //update_state();
      digitalWrite(RED3, LOW);
      }    
  if (state == "CUE_3_GREEN_ON") {
    //update_state();
    digitalWrite(GREEN3, HIGH); 
    }
  if (state == "IDLE") {
   //update_state();
    }     
}

void printCurrPos() {
    static long nextPrintTime;
    
    if( (long)(millis() - nextPrintTime) >= 0 ) {
        nextPrintTime += 200; // 100 millisecs between print statements
        Serial.print("currPos: ");
        Serial.println( servoEaser1.getCurrPos() );
    }
}

void unrecognized(const char *command) {
  Serial.println("Unrecognized command: ");
  Serial.println(command);
  Serial.println("EOC");
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
  


