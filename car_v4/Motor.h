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
	void goFwd(int speed);
	void goBack(int speed);
	void stop();
	String printPins();
	int pwm;
	int pin1;
	int pin2;
};

#endif /* MOTOR_H_ */
