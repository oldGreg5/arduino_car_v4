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
//Motor motors[4] = { };
//Motor FL = Motor(MOTOR_FL);
//Motor FR = Motor(MOTOR_FR);
//Motor RL = Motor(MOTOR_RL);
//Motor RR = Motor(MOTOR_RR);

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

//	Serial.println();
//	Serial.print(Motor(MOTOR_FL).printPins());
//	Serial.print(Motor(MOTOR_FR).printPins());
//	Serial.print(Motor(MOTOR_RL).printPins());
//	Serial.print(Motor(MOTOR_RR).printPins());

//	Serial.println();
//	Serial.print(motors[0].printPins());
//	Serial.print(motors[1].printPins());
//	Serial.print(motors[2].printPins());
//	Serial.print(motors[3].printPins());

//	Serial.println();
//	Serial.print(FL.printPins());
//	Serial.print(FR.printPins());
//	Serial.print(RL.printPins());
//	Serial.print(RR.printPins());

//	car.go_left(100);
//	Motor motor_FL = Motor(MOTOR_FL);
//	Motor motor_FR = Motor(MOTOR_FR);
//	Motor motor_RL = Motor(MOTOR_RL);
//	Motor motor_RR = Motor(MOTOR_RR);

}

void loop() {
	int decodedSignal = 99;
//	lastIrInput = 0;
	//something recived from IR

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
			//last action was turning or cold start
//			if (lastCorrectIrInput == 0 || lastCorrectIrInput == 1) {
////				turningStatic = true;
//				//turning was static or cold start
//				if (turningStatic) {
//					if (decodedSignal == 0) {
//						Serial.println("| Left");
//						car.left(turnSpeed);
//					} else {
//						Serial.println("| Right");
//						car.right(turnSpeed);
//					}
//				}
//				//last action was fwd or reverse
//			} else if (lastCorrectIrInput == 2 || lastCorrectIrInput == 3) {
//				turningStatic = false;
//				if (lastCorrectIrInput == 2) {
//					if (decodedSignal == 0) {
//						Serial.println("| forward Left");
//						car.fwdLeft(turnSpeed);
//					} else {
//						Serial.println("| forward Right");
//						car.fwdRight(turnSpeed);
//					}
//				} else {
//					if (decodedSignal == 0) {
//						Serial.println("| reverse Left");
//						car.backLeft(turnSpeed);
//					} else {
//						Serial.println("| reverse Right");
//						car.backRight(turnSpeed);
//					}
//				}
//			}
			irRecv.resume(); // Receive the next value
			return;
		}

		//new input is fwd or reverse
//		if (decodedSignal == 2 || decodedSignal == 3) {
//			newAction = true;
//		}

//		if (newAction) {
//			car.stop();
//			switch (decodedSignal) {
//			case 0:
//				if (turningStatic) {
//					Serial.println("| Left");
//					car.left(turnSpeed);
//				} else {
//					if (lastCorrectIrInput == 2) {
//						Serial.println("| forward Left");
//						car.fwdLeft(turnSpeed);
//					} else {
//						Serial.println("| reverse Left");
//						car.fwdLeft(turnSpeed);
//					}
//				}
//				break;
//			case 1:
//				if (turningStatic) {
//					Serial.println("| Right");
//					car.right(turnSpeed);
//				} else {
//					if (lastCorrectIrInput == 2) {
//						Serial.println("| forward Right");
//						car.fwdRight(turnSpeed);
//					} else {
//						Serial.println("| reverse Right");
//						car.fwdRight(turnSpeed);
//					}
//				}
//				break;
//			case 2:
//				Serial.println("| Forward");
//				car.goFwd(fwdSpeed);
//				turningStatic = false;
//				break;
//			case 3:
//				Serial.println("| Backward");
//				car.goReverse(backSpeed);
//				turningStatic = false;
//				break;
//				//	        case 4:
//				//	          Serial.print("| song");
//				//	          playSong();
//			default:
//				;
//				//		car.stop();
//				//		Serial.print(" | " + String(decCode, HEX));
//			}
//		}
		irRecv.resume(); // Receive the next value
	}
//	lastCorrectIrInput = decodedSignal;
//	Motor motor = Motor(MOTOR_FR);
//	motor.go_fwd(115);
//	car.go_forward(255);
//	car.go_backward(255);
//	car.go_left(255);
//	car.go_right(255);
//	for (int i = 0; i < 4; i++) {
//		Serial.print(i);
//		Serial.print(motors[i].printPins());
//	}
//	Serial.print(motors[4].printPins());
//	Serial.print(MOTOR_RL[0]);
//	delay(2000);
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

}
