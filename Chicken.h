/*
 * Chicken.h
 *
 *  Created on: Jan 11, 2022
 *      Author: ise
 */

#ifndef CHICKEN_H_
#define CHICKEN_H_

#include "Animal.h"

class Chicken:public Animal{
	static int ChickenPrice;
public:
	Chicken();
	~Chicken();
};




#endif /* CHICKEN_H_ */
