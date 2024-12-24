/*
 * Animal.h
 *
 *  Created on: Jan 9, 2022
 *      Author: ise
 */

#ifndef ANIMAL_H_
#define ANIMAL_H_

class Animal{
	int age;
	int cost;
	int ageofdeath;
public:
	Animal();
	virtual ~Animal();
	friend class Sheep;
	friend class Cow;
	friend class Chicken;
	friend class SheepFarm;
	friend class CowFarm;
	friend class ChickenFarm;

};



#endif /* ANIMAL_H_ */
