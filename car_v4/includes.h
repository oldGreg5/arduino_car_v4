/*
 * includes.h
 *
 *  Created on: 17 kwi 2016
 *      Author: oldGr
 */
#include "IRremote.h"
#include "IRremoteInt.h"

#ifndef INCLUDES_H_
#define INCLUDES_H_

const int IR_REMOTE = A5;

int MOTOR_RR[] = { 2, 4, 10 };
int MOTOR_FL[] = { 13, 12, 5 };
//int MOTOR_RL[] = { 5, 7, 6 };
int MOTOR_RL[] = { 8, 3, 9 };
int MOTOR_FR[] = { 11, 7, 6 };

//int MOTOR_FL[] = { 13, 12, 11 };
////int MOTOR_FL[] = { 13, 12, 11 };
//int MOTOR_RL[] = { 5, 7, 6 };
//int MOTOR_RR[] = { 8, 10, 9 };
//int MOTOR_FR[] = { 2, 4, 3 };

IRrecv irRecv(IR_REMOTE);
decode_results results;
int lastCorrectIrInput = 100;

int decodeIrSignal(String hexCode) {
	hexCode.toUpperCase();
	if (hexCode == "FD28D7" || hexCode == "CBD2CCFD" || hexCode == "758C9D82")
		return 0; //left
	if (hexCode == "FD6897" || hexCode == "85E09D61" || hexCode == "53801EE8")
		return 1; //right
	if (hexCode == "FD8877" || hexCode == "6F5974BD" || hexCode == "C26BF044")
		return 2; //up
	if (hexCode == "FD9867" || hexCode == "57E346E1" || hexCode == "C4FFB646")
		return 3; //down
//	if (hexCode == "6BDD79E6" || hexCode == "6CC8C5EA" || hexCode == "FD30CF")
//		return 4; //play song

	Serial.println(hexCode);
	return 666;
}

#endif /* INCLUDES_H_ */
