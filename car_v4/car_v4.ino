#include "Arduino.h"
#include "Motor.h"
#include "includes.h"
#include "Car4wd.h"
#include "IRremote.h"
#include "IRremoteInt.h"
//define pins for motor driver {PIN1,PIN2,PWM}
//const int MOTOR_RR1 = 2;
//int MOTOR_RR[] = { 2, 4, 3 };
//int MOTOR_FR[] = { 5, 7, 6 };
//int MOTOR_RL[] = { 8, 10, 9 };
//int MOTOR_FL[] = { 13, 12, 11 };
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
const int SPD = 100;

Motor motors[] = { Motor(MOTOR_FL), Motor(MOTOR_FR), Motor(MOTOR_RL), Motor(
		MOTOR_RR) };

Car_4wd car = Car_4wd(motors);
int fwdSpeed = 190;
int backSpeed = 150;
int turnSpeed = 180;
//boolean turningStatic = true;

void setup() {
	Serial.begin(9600);      // open the serial port at 9600 bps
	irRecv.enableIRIn(); // Start the receiver
}

void loop() {
	int decodedSignal = 99;

	if (irRecv.decode(&results)) {
//		Serial.print("dupa");
		long int decCode = results.value;
		String hexString = String(decCode, HEX);
		//        Serial.println(hexString);
		decodedSignal = decodeIrSignal(hexString);

		Serial.print(lastCorrectIrInput);
		Serial.print("|");
		Serial.println(decodedSignal);

//		boolean newAction = false;

		if (decodedSignal == 666) {
			lastCorrectIrInput = 100;
			car.stop();
			irRecv.resume(); // Receive the next value
			return;
		}

		//cold start
		if (lastCorrectIrInput == 100) {
			switch (decodedSignal) {
			case 0:
				Serial.println("| Left");
				car.left(turnSpeed);
//				turningStatic = true;
				break;
			case 1:
				Serial.println("| Right");
				car.right(turnSpeed);
//				turningStatic = true;
				break;
			case 2:
				Serial.println("| Forward");
				car.goFwd(fwdSpeed);
//				turningStatic = false;
				lastCorrectIrInput = decodedSignal;
				break;
			case 3:
				Serial.println("| Reverse");
				car.goReverse(backSpeed);
//				turningStatic = false;
				lastCorrectIrInput = decodedSignal;
				break;
				//	        case 4:
				//	          Serial.print("| song");
				//	          playSong();
				//		car.stop();
				//		Serial.print(" | " + String(decCode, HEX));
			}
			irRecv.resume(); // Receive the next value
			return;
		}

		//new input is fwd or reverse
		if (decodedSignal == 2 || decodedSignal == 3) {
//			if (lastCorrectIrInput == 0 || lastCorrectIrInput == 1) {
			if (decodedSignal == 2) {
				Serial.println("| Forward");
				car.goFwd(fwdSpeed);
//				turningStatic = false;
			} else {
				Serial.println("| Reverse");
				car.goReverse(backSpeed);
//				turningStatic = false;
			}
//			}
			lastCorrectIrInput = decodedSignal;
			irRecv.resume(); // Receive the next value
			return;
		}

		//new input is turning
		if (decodedSignal == 0 || decodedSignal == 1) {
			//last was fwd or reverse
			if (lastCorrectIrInput == 2 || lastCorrectIrInput == 3) {
//				turningStatic = false;
				if (lastCorrectIrInput == 2) {
					if (decodedSignal == 0) {
						Serial.println("| forward Left");
						car.fwdLeft(fwdSpeed);
					} else {
						Serial.println("| forward Right");
						car.fwdRight(fwdSpeed);
					}
				} else {
					if (decodedSignal == 0) {
						Serial.println("| reverse Left");
						car.backLeft(backSpeed);
					} else {
						Serial.println("| reverse Right");
						car.backRight(backSpeed);
					}
				}
			} else {
				lastCorrectIrInput = 100;
				//				turningStatic = true;
				//turning was static or cold start
//				if (turningStatic) {
				if (decodedSignal == 0) {
					Serial.println("| Left");
					car.left(turnSpeed);
				} else {
					Serial.println("| Right");
					car.right(turnSpeed);
				}
//				}
				//last action was fwd or reverse
			}
			irRecv.resume(); // Receive the next value
			return;
		}
		irRecv.resume(); // Receive the next value
	}
}
