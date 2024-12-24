/*
 * Sheep.h
 *
 *  Created on: Jan 9, 2022
 *      Author: ise
 */

#ifndef SHEEP_H_
#define SHEEP_H_
#include "Animal.h"

class Sheep:public Animal{
	static int SheepPrice;
public:
	Sheep();
	~Sheep();
	friend class SheepFarm;
};



#endif /* SHEEP_H_ */
