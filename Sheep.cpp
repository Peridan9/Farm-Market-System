/*
 * Sheep.cpp
 *
 *  Created on: Jan 9, 2022
 *      Author: ise
 */

#include "Sheep.h"

int Sheep::SheepPrice = 5;

Sheep::Sheep(){
	this->cost = this->SheepPrice;
	this->ageofdeath = 5;
}

Sheep::~Sheep(){

}


