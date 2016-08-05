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
float turningSpeed = 0.2;
float rotateSpeed = 0.7;

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

void Car_4wd::goFwd(int speed) {
//	Serial.print("h*");
	MOTOR_FL.goFwd(speed);
	MOTOR_FR.goFwd(speed);
	MOTOR_RL.goFwd(speed);
	MOTOR_RR.goFwd(speed);
}

void Car_4wd::goReverse(int speed) {
//	Serial.print("h*");
	MOTOR_FL.goBack(speed);
	MOTOR_FR.goBack(speed);
	MOTOR_RL.goBack(speed);
	MOTOR_RR.goBack(speed);
}

void Car_4wd::fwdRight(int speed) {
//	Serial.print("h*");
	MOTOR_FL.goFwd(255);
//	MOTOR_FR.go_back(speed / 2);
	MOTOR_FR.goFwd(speed * turningSpeed);
	MOTOR_RL.goFwd(255);
//	MOTOR_RR.go_back(speed / 2);
	MOTOR_RR.goFwd(speed * turningSpeed);
}

void Car_4wd::fwdLeft(int speed) {
//	Serial.print("h*");
//	MOTOR_FL.go_back(speed / 2);
//	MOTOR_FL.go_back(speed * 0.6);
	MOTOR_FL.goFwd(speed * turningSpeed);
	MOTOR_FR.goFwd(255);
//	MOTOR_RL.go_back(speed / 2);
//	MOTOR_RL.go_back(speed * 0.6);
	MOTOR_RL.goFwd(speed * turningSpeed);
	MOTOR_RR.goFwd(255);
}

void Car_4wd::backRight(int speed) {
//	Serial.print("h*");
	MOTOR_FL.goBack(255);
//	MOTOR_FR.go_back(speed / 2);
	MOTOR_FR.goBack(speed * turningSpeed);
	MOTOR_RL.goBack(255);
//	MOTOR_RR.go_back(speed / 2);
	MOTOR_RR.goBack(speed * turningSpeed);
}

void Car_4wd::backLeft(int speed) {
//	Serial.print("h*");
//	MOTOR_FL.go_back(speed / 2);
//	MOTOR_FL.go_back(speed * 0.6);
	MOTOR_FL.goBack(speed * turningSpeed);
	MOTOR_FR.goBack(255);
//	MOTOR_RL.go_back(speed / 2);
//	MOTOR_RL.go_back(speed * 0.6);
	MOTOR_RL.goBack(speed * turningSpeed);
	MOTOR_RR.goBack(255);
}

void Car_4wd::right(int speed) {
//	Serial.print("h*");
	MOTOR_FL.goFwd(speed);
	MOTOR_FR.goBack(speed * rotateSpeed);
//	MOTOR_FR.goFwd(speed * 0.5);
	MOTOR_RL.goFwd(speed);
	MOTOR_RR.goBack(speed * rotateSpeed);
//	MOTOR_RR.goFwd(speed * 0.5);
//	delay(50);
//	stop();
}

void Car_4wd::left(int speed) {
//	Serial.print("h*");
//	MOTOR_FL.go_back(speed / 2);
//	MOTOR_FL.go_back(speed * 0.6);
	MOTOR_FL.goBack(speed * rotateSpeed);
	MOTOR_FR.goFwd(speed);
//	MOTOR_RL.go_back(speed / 2);
//	MOTOR_RL.go_back(speed * 0.6);
	MOTOR_RL.goBack(speed * rotateSpeed);
	MOTOR_RR.goFwd(speed);
//	delay(50);
//	stop();
}

void Car_4wd::stop() {
//	Serial.print("h*");
	MOTOR_FL.stop();
	MOTOR_FR.stop();
	MOTOR_RL.stop();
	MOTOR_RR.stop();
}
