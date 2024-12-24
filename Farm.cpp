/*
 * Farm.cpp
 *
 *  Created on: Jan 9, 2022
 *      Author: ise
 */

#include "Farm.h"

int Farm::farmID = 1;

Farm::Farm(){

	this->ID = farmID;
	this->farmID++;
	this->Money = 10;
	this->Milk=0;
	this->Wool=0;
	this->Eggs=0;
}

Farm::~Farm(){

}


