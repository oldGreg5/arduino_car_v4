/*
 * Motor.h
 *
 *  Created on: 17 kwi 2016
 *      Author: oldGr
 */
#include "Arduino.h"
#ifndef MOTOR_H_
#define MOTOR_H_

class Motor {
public:
	Motor();
	Motor(int motor_pins[]);
	virtual ~Motor();
	void go_fwd(int speed);
	void go_back(int speed);
	String printPins();
	int pwm;
	int pin1;
	int pin2;
};

#endif /* MOTOR_H_ */
