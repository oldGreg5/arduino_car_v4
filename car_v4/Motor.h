/*
 * Motor.h
 *
 *  Created on: 17 kwi 2016
 *      Author: oldGr
 */

#ifndef MOTOR_H_
#define MOTOR_H_

class Motor {
public:
	Motor();
	Motor(int motor_pins[]);
	virtual ~Motor();
	void go_fwd(int speed);
};

#endif /* MOTOR_H_ */
