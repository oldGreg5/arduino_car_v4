/*
 * Motor.cpp
 *
 *  Created on: 17 kwi 2016
 *      Author: oldGr
 */

#include "Motor.h"
#include <Arduino.h>

Motor::Motor() {
	// TODO Auto-generated destructor stub
}

Motor::Motor(int motor_pins[]) {

	pin1 = motor_pins[0];
	pin2 = motor_pins[1];
	pwm = motor_pins[2];
}

Motor::~Motor() {
	// TODO Auto-generated destructor stub
}

void Motor::goFwd(int speed) {
	analogWrite(pwm, speed); //set speed
	digitalWrite(pin1, LOW);
	digitalWrite(pin2, HIGH);
}

void Motor::goBack(int speed) {
	analogWrite(pwm, speed); //set speed
	digitalWrite(pin1, HIGH);
	digitalWrite(pin2, LOW);
}

void Motor::stop() {
	digitalWrite(pin1, LOW);
	digitalWrite(pin2, LOW);
}

String Motor::printPins() {
	String str;
	str = pin1;
	str += " ";
	str += pin2;
	str += " ";
	str += pwm;
	str += "\n";
	return str;
}
