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
	void goFwd(int speed);
	void goReverse(int speed);
	void left(int speed);
	void right(int speed);
	void fwdLeft(int speed);
	void fwdRight(int speed);
	void backLeft(int speed);
	void backRight(int speed);
	void stop();
};

#endif /* CAR4WD_H_ */
