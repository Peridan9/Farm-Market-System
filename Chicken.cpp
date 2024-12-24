/*
 * Chicken.cpp
 *
 *  Created on: Jan 11, 2022
 *      Author: ise
 */

#include "Chicken.h"

int Chicken::ChickenPrice = 3;

Chicken::Chicken(){
	this->cost = ChickenPrice;
	this->ageofdeath = 3;
}

Chicken::~Chicken(){

}


