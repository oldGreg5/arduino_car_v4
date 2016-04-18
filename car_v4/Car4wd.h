/*
 * Car4wd.h
 *
 *  Created on: 17 kwi 2016
 *      Author: oldGr
 */

#include "Motor.h"

#ifndef CAR4WD_H_
#define CAR4WD_H_

class Car_4wd {
public:
	Car_4wd(Motor motors[]);
	virtual ~Car_4wd();
	void go_forward(int speed);
	void go_backward(int speed);
	void go_left(int speed);
	void go_right(int speed);
};

#endif /* CAR4WD_H_ */
