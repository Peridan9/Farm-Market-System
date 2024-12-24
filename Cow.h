/*
 * Cow.h
 *
 *  Created on: Jan 11, 2022
 *      Author: ise
 */

#ifndef COW_H_
#define COW_H_
#include "Animal.h"

class Cow:public Animal{
	static int CowPrice;
public:
	Cow();
	~Cow();
};




#endif /* COW_H_ */
