#include "Arduino.h"
#include "Motor.h"
//define pins for motor driver {PIN1,PIN2,PWM}
//const int MOTOR_RR1 = 2;
int MOTOR_RR[] = { 2, 4, 3 };
int MOTOR_FR[] = { 5, 7, 6 };
int MOTOR_RL[] = { 8, 10, 9 };
int MOTOR_FL[] = { 13, 12, 11 };
//const int MOTOR_RR2 = 4;
//const int PWM_RR = 3;
//const int MOTOR_FR1 = 5;
//const int MOTOR_FR2 = 7;
//const int PWM_FR = 6;
//const int MOTOR_RL1 = 8;
//const int MOTOR_RL2 = 10;
//const int PWM_RL = 9;
//const int MOTOR_FL1 = 13;
//const int MOTOR_FL2 = 12;
//const int PWM_FL = 11;

int LED = 13; // Use the onboard Uno LED
const int SPD = 50;

void setup() {
	Motor motor_RR = Motor(MOTOR_RR);
	Motor motor_FR = Motor(MOTOR_FR);
	Motor motor_RL = Motor(MOTOR_RL);
	Motor motor_FL = Motor(MOTOR_FL);
	motor_RR.go_fwd(SPD);
// Add your initialization code here
}

// The loop function is called in an endless loop
void loop() {
//	analogWrite(PWM_FL, SPD); //right motor
//	digitalWrite(LED, HIGH);
//	digitalWrite(MOTOR_FL1, LOW);
//	digitalWrite(MOTOR_FL2, HIGH);
//	delay(1000);
//	digitalWrite(LED, LOW);
//	digitalWrite(MOTOR_FL1, LOW);
//	digitalWrite(MOTOR_FL2, LOW);
//	delay(1000);
//	analogWrite(PWM_RL, SPD); //right motor
//	digitalWrite(LED, HIGH);
//	digitalWrite(MOTOR_RL1, LOW);
//	digitalWrite(MOTOR_RL2, HIGH);
//	delay(1000);
//	digitalWrite(LED, LOW);
//	digitalWrite(MOTOR_RL1, LOW);
//	digitalWrite(MOTOR_RL2, LOW);
//	delay(1000);
//	analogWrite(PWM_FR, SPD); //right motor
//	digitalWrite(LED, HIGH);
//	digitalWrite(MOTOR_FR1, LOW);
//	digitalWrite(MOTOR_FR2, HIGH);
//	delay(1000);
//	digitalWrite(LED, LOW);
//	digitalWrite(MOTOR_FR1, LOW);
//	digitalWrite(MOTOR_FR2, LOW);
//	delay(1000);
//	analogWrite(PWM_RR, SPD); //right motor
//	digitalWrite(LED, HIGH);
//	digitalWrite(MOTOR_RR1, LOW);
//	digitalWrite(MOTOR_RR2, HIGH);
//	delay(1000);
//	digitalWrite(LED, LOW);
//	digitalWrite(MOTOR_RR1, LOW);
//	digitalWrite(MOTOR_RR2, LOW);
//	delay(1000);

	//Add your repeated code here
}
