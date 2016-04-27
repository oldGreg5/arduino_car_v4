/*
 * Car4wd.cpp
 *
 *  Created on: 17 kwi 2016
 *      Author: oldGr
 */

#include "Car4wd.h"
#include "Motor.h"
#include "Arduino.h"

static Motor MOTOR_FL;
static Motor MOTOR_FR;
static Motor MOTOR_RL;
static Motor MOTOR_RR;

Car_4wd::Car_4wd(Motor motors[]) {
//	Serial.print("h*");
	MOTOR_FL = Motor(motors[0]);
	MOTOR_FR = Motor(motors[1]);
	MOTOR_RL = Motor(motors[2]);
	MOTOR_RR = Motor(motors[3]);
//	Serial.println("111111111111");
//	Serial.print(Motor(FL).printPins());
//	Serial.print(Motor(FR).printPins());
//	Serial.print(Motor(RL).printPins());
//	Serial.print(Motor(RR).printPins());

//	Serial.print(MOTOR_FL.printPins());
//	Serial.print(MOTOR_FR.printPins());
//	Serial.print(MOTOR_RL.printPins());
//	Serial.print(MOTOR_RR.printPins());

//	MOTOR_FL = FL;
//	MOTOR_FR = FR;
//	MOTOR_RL = RL;
//	MOTOR_RR = RR;
}

Car_4wd::~Car_4wd() {
	// TODO Auto-generated destructor stub
}

void Car_4wd::go_forward(int speed) {
//	Serial.print("h*");
	MOTOR_FL.go_fwd(speed);
	MOTOR_FR.go_fwd(speed);
	MOTOR_RL.go_fwd(speed);
	MOTOR_RR.go_fwd(speed);
}

void Car_4wd::go_right(int speed) {
//	Serial.print("h*");
	MOTOR_FL.go_fwd(speed);
	MOTOR_FR.go_back(speed / 2);
	MOTOR_RL.go_fwd(speed);
	MOTOR_RR.go_back(speed / 2);
}

void Car_4wd::go_left(int speed) {
//	Serial.print("h*");
	MOTOR_FL.go_back(speed / 2);
	MOTOR_FR.go_fwd(speed);
	MOTOR_RL.go_back(speed / 2);
	MOTOR_RR.go_fwd(speed);
}
