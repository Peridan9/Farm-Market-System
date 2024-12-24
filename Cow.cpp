/*
 * Cow.cpp
 *
 *  Created on: Jan 11, 2022
 *      Author: ise
 */

#include "Cow.h"

int Cow::CowPrice = 10;

Cow::Cow(){
	this->cost = CowPrice;
	this->ageofdeath = 10;
}

Cow::~Cow(){

}


