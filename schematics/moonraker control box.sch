EESchema Schematic File Version 4
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Motor:Motor_Servo_Hitec SERVO
U 1 1 5B47995A
P 1600 3300
F 0 "SERVO" V 2050 3450 50  0000 R TNN
F 1 "TORM" V 1950 3300 50  0000 C TNN
F 2 "" H 1600 3110 50  0001 C CNN
F 3 "http://forums.parallax.com/uploads/attachments/46831/74481.png" H 1600 3110 50  0001 C CNN
	1    1600 3300
	0    -1   -1   0   
$EndComp
$Comp
L Motor:Motor_Servo_Hitec SERVO
U 1 1 5B479B64
P 2100 3300
F 0 "SERVO" V 2600 3400 50  0000 R CNN
F 1 "AKUM" V 2500 3350 50  0000 R CNN
F 2 "" H 2100 3110 50  0001 C CNN
F 3 "http://forums.parallax.com/uploads/attachments/46831/74481.png" H 2100 3110 50  0001 C CNN
	1    2100 3300
	0    -1   -1   0   
$EndComp
$Comp
L Motor:Motor_Servo_Hitec SERVO
U 1 1 5B479B8F
P 2600 3300
F 0 "SERVO" V 3100 3400 50  0000 R CNN
F 1 "DVIG" V 3000 3350 50  0000 R BNN
F 2 "" H 2600 3110 50  0001 C CNN
F 3 "http://forums.parallax.com/uploads/attachments/46831/74481.png" H 2600 3110 50  0001 C CNN
	1    2600 3300
	0    -1   -1   0   
$EndComp
$Comp
L Switch:SW_DPST_x2 on/0ff
U 1 1 5B47A05D
P 2050 1750
F 0 "on/0ff" H 2050 1985 50  0000 C CNN
F 1 "SW_DPST_x2" H 2050 1894 50  0000 C CNN
F 2 "" H 2050 1750 50  0001 C CNN
F 3 "" H 2050 1750 50  0001 C CNN
	1    2050 1750
	1    0    0    -1  
$EndComp
$Comp
L Device:LED green
U 1 1 5B47A243
P 2050 1200
F 0 "green" H 2041 1416 50  0000 C CNN
F 1 "LED" H 2041 1325 50  0000 C CNN
F 2 "" H 2050 1200 50  0001 C CNN
F 3 "~" H 2050 1200 50  0001 C CNN
	1    2050 1200
	1    0    0    -1  
$EndComp
$Comp
L Device:LED red
U 1 1 5B47A397
P 4650 3550
F 0 "red" H 4641 3766 50  0000 C CNN
F 1 "LED" H 4641 3675 50  0000 C CNN
F 2 "" H 4650 3550 50  0001 C CNN
F 3 "~" H 4650 3550 50  0001 C CNN
	1    4650 3550
	1    0    0    -1  
$EndComp
$Comp
L Device:LED red?
U 1 1 5B47A542
P 4650 3200
F 0 "red?" H 4641 3416 50  0000 C CNN
F 1 "LED" H 4641 3325 50  0000 C CNN
F 2 "" H 4650 3200 50  0001 C CNN
F 3 "~" H 4650 3200 50  0001 C CNN
	1    4650 3200
	1    0    0    -1  
$EndComp
$Comp
L Device:LED red?
U 1 1 5B47A5A0
P 4650 2800
F 0 "red?" H 4641 3016 50  0000 C CNN
F 1 "LED" H 4641 2925 50  0000 C CNN
F 2 "" H 4650 2800 50  0001 C CNN
F 3 "~" H 4650 2800 50  0001 C CNN
	1    4650 2800
	1    0    0    -1  
$EndComp
$Comp
L Device:LED red?
U 1 1 5B47A62D
P 7200 3100
F 0 "red?" H 7191 3316 50  0000 C CNN
F 1 "LED" H 7191 3225 50  0000 C CNN
F 2 "" H 7200 3100 50  0001 C CNN
F 3 "~" H 7200 3100 50  0001 C CNN
	1    7200 3100
	1    0    0    -1  
$EndComp
$Comp
L Device:LED red?
U 1 1 5B47A666
P 7200 2600
F 0 "red?" H 7191 2816 50  0000 C CNN
F 1 "LED" H 7191 2725 50  0000 C CNN
F 2 "" H 7200 2600 50  0001 C CNN
F 3 "~" H 7200 2600 50  0001 C CNN
	1    7200 2600
	1    0    0    -1  
$EndComp
$Comp
L Device:LED green
U 1 1 5B47A696
P 5250 3550
F 0 "green" H 5241 3766 50  0000 C CNN
F 1 "LED" H 5241 3675 50  0000 C CNN
F 2 "" H 5250 3550 50  0001 C CNN
F 3 "~" H 5250 3550 50  0001 C CNN
	1    5250 3550
	1    0    0    -1  
$EndComp
$Comp
L Device:LED green?
U 1 1 5B47A6FB
P 5250 3150
F 0 "green?" H 5241 3366 50  0000 C CNN
F 1 "LED" H 5241 3275 50  0000 C CNN
F 2 "" H 5250 3150 50  0001 C CNN
F 3 "~" H 5250 3150 50  0001 C CNN
	1    5250 3150
	1    0    0    -1  
$EndComp
$Comp
L Device:LED red?
U 1 1 5B47A760
P 5250 2750
F 0 "red?" H 5241 2966 50  0000 C CNN
F 1 "LED" H 5241 2875 50  0000 C CNN
F 2 "" H 5250 2750 50  0001 C CNN
F 3 "~" H 5250 2750 50  0001 C CNN
	1    5250 2750
	1    0    0    -1  
$EndComp
$Comp
L Device:LED red?
U 1 1 5B47A78D
P 7750 3650
F 0 "red?" H 7741 3866 50  0000 C CNN
F 1 "LED" H 7741 3775 50  0000 C CNN
F 2 "" H 7750 3650 50  0001 C CNN
F 3 "~" H 7750 3650 50  0001 C CNN
	1    7750 3650
	1    0    0    -1  
$EndComp
$Comp
L Device:LED red?
U 1 1 5B47A7B9
P 7750 3050
F 0 "red?" H 7741 3266 50  0000 C CNN
F 1 "LED" H 7741 3175 50  0000 C CNN
F 2 "" H 7750 3050 50  0001 C CNN
F 3 "~" H 7750 3050 50  0001 C CNN
	1    7750 3050
	1    0    0    -1  
$EndComp
$Comp
L Device:LED red?
U 1 1 5B47A7E4
P 7750 2550
F 0 "red?" H 7741 2766 50  0000 C CNN
F 1 "LED" H 7741 2675 50  0000 C CNN
F 2 "" H 7750 2550 50  0001 C CNN
F 3 "~" H 7750 2550 50  0001 C CNN
	1    7750 2550
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_DPST_x2 on/0ff?
U 1 1 5B47B37E
P 5950 3600
F 0 "on/0ff?" H 5950 3835 50  0000 C CNN
F 1 "SW_DPST_x2" H 5950 3744 50  0000 C CNN
F 2 "" H 5950 3600 50  0001 C CNN
F 3 "" H 5950 3600 50  0001 C CNN
	1    5950 3600
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_DPST_x2 on/0ff?
U 1 1 5B47B472
P 5950 3150
F 0 "on/0ff?" H 5950 3385 50  0000 C CNN
F 1 "SW_DPST_x2" H 5950 3294 50  0000 C CNN
F 2 "" H 5950 3150 50  0001 C CNN
F 3 "" H 5950 3150 50  0001 C CNN
	1    5950 3150
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_DPST_x2 on/0ff?
U 1 1 5B47B56C
P 5950 2700
F 0 "on/0ff?" H 5950 2935 50  0000 C CNN
F 1 "SW_DPST_x2" H 5950 2844 50  0000 C CNN
F 2 "" H 5950 2700 50  0001 C CNN
F 3 "" H 5950 2700 50  0001 C CNN
	1    5950 2700
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_DPDT_x2 SW?
U 1 1 5B47B974
P 8300 2600
F 0 "SW?" H 8300 2885 50  0000 C CNN
F 1 "SW_DPDT_x2" H 8300 2794 50  0000 C CNN
F 2 "" H 8300 2600 50  0001 C CNN
F 3 "" H 8300 2600 50  0001 C CNN
	1    8300 2600
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_DPDT_x2 SW?
U 1 1 5B47BB6A
P 8300 3100
F 0 "SW?" H 8300 3385 50  0000 C CNN
F 1 "SW_DPDT_x2" H 8300 3294 50  0000 C CNN
F 2 "" H 8300 3100 50  0001 C CNN
F 3 "" H 8300 3100 50  0001 C CNN
	1    8300 3100
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_DPDT_x2 SW?
U 1 1 5B47BD38
P 8300 3650
F 0 "SW?" H 8300 3935 50  0000 C CNN
F 1 "SW_DPDT_x2" H 8300 3844 50  0000 C CNN
F 2 "" H 8300 3650 50  0001 C CNN
F 3 "" H 8300 3650 50  0001 C CNN
	1    8300 3650
	1    0    0    -1  
$EndComp
$Comp
L Motor:Stepper_Motor_bipolar M?
U 1 1 5B47C051
P 7200 1400
F 0 "M?" H 7388 1523 50  0000 L CNN
F 1 "Stepper_Motor_bipolar" H 7388 1432 50  0000 L CNN
F 2 "" H 7210 1390 50  0001 C CNN
F 3 "http://www.infineon.com/dgdl/Application-Note-TLE8110EE_driving_UniPolarStepperMotor_V1.1.pdf?fileId=db3a30431be39b97011be5d0aa0a00b0" H 7210 1390 50  0001 C CNN
	1    7200 1400
	1    0    0    -1  
$EndComp
$Comp
L Device:Voltmeter_DC MES?
U 1 1 5B47C12C
P 8950 1300
F 0 "MES?" H 9103 1346 50  0000 L CNN
F 1 "Voltmeter_DC" H 9103 1255 50  0000 L CNN
F 2 "" V 8950 1400 50  0001 C CNN
F 3 "~" V 8950 1400 50  0001 C CNN
	1    8950 1300
	1    0    0    -1  
$EndComp
$Comp
L MCU_Module:Arduino_UNO_R3 A?
U 1 1 5B47C3F7
P 4000 6100
F 0 "A?" H 4000 7278 50  0000 C CNN
F 1 "Arduino_UNO_R3" H 4000 7187 50  0000 C CNN
F 2 "Module:Arduino_UNO_R3" H 4150 5050 50  0001 L CNN
F 3 "https://www.arduino.cc/en/Main/arduinoBoardUno" H 3800 7150 50  0001 C CNN
	1    4000 6100
	1    0    0    -1  
$EndComp
Wire Wire Line
	1600 3600 1600 3950
Wire Wire Line
	1600 3950 2100 3950
Wire Wire Line
	2100 3950 2100 3600
Wire Wire Line
	2100 3950 2600 3950
Wire Wire Line
	2600 3950 2600 3600
Connection ~ 2100 3950
Wire Wire Line
	1700 3600 1700 3800
Wire Wire Line
	1700 3800 2200 3800
Wire Wire Line
	2200 3800 2200 3600
Wire Wire Line
	2200 3800 2700 3800
Connection ~ 2200 3800
Wire Wire Line
	2700 3800 2700 3600
Wire Wire Line
	2250 1750 2600 1750
Wire Wire Line
	3050 1750 3050 3800
Wire Wire Line
	3050 3800 2700 3800
Connection ~ 2700 3800
Wire Wire Line
	8950 1750 8950 1500
Connection ~ 3050 1750
Wire Wire Line
	4500 2800 4500 3200
Wire Wire Line
	4500 3550 4500 3200
Connection ~ 4500 3200
Wire Wire Line
	5100 3550 5100 3150
Wire Wire Line
	5100 3150 5100 2750
Connection ~ 5100 3150
Wire Wire Line
	5100 2750 5100 1750
Connection ~ 5100 2750
Connection ~ 5100 1750
Wire Wire Line
	4500 2800 4500 1750
Wire Wire Line
	3050 1750 4500 1750
Connection ~ 4500 2800
Connection ~ 4500 1750
Wire Wire Line
	4500 1750 5100 1750
Wire Wire Line
	7600 3650 7600 3050
Wire Wire Line
	7600 2550 7600 1750
Wire Wire Line
	5100 1750 7050 1750
Connection ~ 7600 1750
Wire Wire Line
	7600 1750 8300 1750
Wire Wire Line
	7600 2550 7600 3050
Connection ~ 7600 2550
Connection ~ 7600 3050
Wire Wire Line
	7050 2600 7050 1750
Connection ~ 7050 1750
Wire Wire Line
	7050 1750 7600 1750
Wire Wire Line
	7050 2600 7050 3100
Connection ~ 7050 2600
$Comp
L Device:LED red?
U 1 1 5B47A5F7
P 7200 3650
F 0 "red?" H 7191 3866 50  0000 C CNN
F 1 "LED" H 7191 3775 50  0000 C CNN
F 2 "" H 7200 3650 50  0001 C CNN
F 3 "~" H 7200 3650 50  0001 C CNN
	1    7200 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	7050 3100 7050 3650
Connection ~ 7050 3100
Wire Wire Line
	7350 2600 7350 2150
Wire Wire Line
	7350 2150 8500 2150
Wire Wire Line
	8500 2150 8500 2500
Wire Wire Line
	7350 3100 7350 2850
Wire Wire Line
	7350 2850 8500 2850
Wire Wire Line
	8500 2850 8500 3000
Wire Wire Line
	7350 3650 7350 3350
Wire Wire Line
	7350 3350 8500 3350
Wire Wire Line
	8500 3350 8500 3550
Wire Wire Line
	7900 3650 7900 3850
Wire Wire Line
	7900 3850 8500 3850
Wire Wire Line
	8500 3850 8500 3750
Wire Wire Line
	7900 2550 7900 2750
Wire Wire Line
	7900 2750 8500 2750
Wire Wire Line
	8500 2750 8500 2700
Wire Wire Line
	7900 3050 7900 3250
Wire Wire Line
	7900 3250 8500 3250
Wire Wire Line
	8500 3250 8500 3200
Wire Wire Line
	8100 2600 8100 3100
Wire Wire Line
	8100 3100 8100 3650
Connection ~ 8100 3100
Wire Wire Line
	8100 3650 8100 4150
Wire Wire Line
	8100 4150 2600 4150
Wire Wire Line
	2600 4150 2600 3950
Connection ~ 8100 3650
Connection ~ 2600 3950
$Comp
L Device:Lamp LA?
U 1 1 5B487D98
P 1600 2450
F 0 "LA?" H 1728 2496 50  0000 L CNN
F 1 "Lamp" H 1728 2405 50  0000 L CNN
F 2 "" V 1600 2550 50  0001 C CNN
F 3 "~" V 1600 2550 50  0001 C CNN
	1    1600 2450
	1    0    0    -1  
$EndComp
$Comp
L Device:Lamp LA?
U 1 1 5B487E7E
P 2100 2450
F 0 "LA?" H 2228 2496 50  0000 L CNN
F 1 "Lamp" H 2228 2405 50  0000 L CNN
F 2 "" V 2100 2550 50  0001 C CNN
F 3 "~" V 2100 2550 50  0001 C CNN
	1    2100 2450
	1    0    0    -1  
$EndComp
$Comp
L Device:Lamp LA?
U 1 1 5B487EF2
P 2600 2450
F 0 "LA?" H 2728 2496 50  0000 L CNN
F 1 "Lamp" H 2728 2405 50  0000 L CNN
F 2 "" V 2600 2550 50  0001 C CNN
F 3 "~" V 2600 2550 50  0001 C CNN
	1    2600 2450
	1    0    0    -1  
$EndComp
$Comp
L Device:Lamp LA?
U 1 1 5B487F6F
P 7200 800
F 0 "LA?" H 7328 846 50  0000 L CNN
F 1 "Lamp" H 7328 755 50  0000 L CNN
F 2 "" V 7200 900 50  0001 C CNN
F 3 "~" V 7200 900 50  0001 C CNN
	1    7200 800 
	1    0    0    -1  
$EndComp
$Comp
L Device:Lamp LA?
U 1 1 5B4881C1
P 8950 800
F 0 "LA?" H 9078 846 50  0000 L CNN
F 1 "Lamp" H 9078 755 50  0000 L CNN
F 2 "" V 8950 900 50  0001 C CNN
F 3 "~" V 8950 900 50  0001 C CNN
	1    8950 800 
	1    0    0    -1  
$EndComp
Wire Wire Line
	8950 600  7200 600 
Wire Wire Line
	8950 1000 8300 1000
Wire Wire Line
	1600 2250 2100 2250
Wire Wire Line
	2100 2250 2600 2250
Connection ~ 2100 2250
Wire Wire Line
	1600 2650 2100 2650
Wire Wire Line
	2100 2650 2600 2650
Connection ~ 2100 2650
Wire Wire Line
	2600 2250 2600 1750
Connection ~ 2600 2250
Connection ~ 2600 1750
Wire Wire Line
	2600 1750 3050 1750
Wire Wire Line
	8300 1000 8300 1750
Connection ~ 8300 1000
Wire Wire Line
	8300 1000 7200 1000
Connection ~ 8300 1750
Wire Wire Line
	8300 1750 8950 1750
Wire Wire Line
	4000 600  7200 600 
Wire Wire Line
	4000 600  4000 2650
Connection ~ 7200 600 
Wire Wire Line
	2600 2650 4000 2650
Connection ~ 2600 2650
Wire Wire Line
	1500 3600 1500 4450
Wire Wire Line
	1500 4450 4900 4450
Wire Wire Line
	4900 4450 4900 6100
Wire Wire Line
	4900 6100 4500 6100
Wire Wire Line
	4500 6200 4950 6200
Wire Wire Line
	4950 6200 4950 4400
Wire Wire Line
	4950 4400 2000 4400
Wire Wire Line
	2000 4400 2000 3600
Wire Wire Line
	2500 3600 2500 4350
Wire Wire Line
	2500 4350 5000 4350
Wire Wire Line
	5000 4350 5000 6300
Wire Wire Line
	5000 6300 4500 6300
$EndSCHEMATC
