/*
 * SheepFarm.h
 *
 *  Created on: Jan 9, 2022
 *      Author: ise
 */

#ifndef SHEEPFARM_H_
#define SHEEPFARM_H_
#include "Farm.h"
#include "Sheep.h"


class SheepFarm:public Farm
{
	vector<Sheep*> AnimalsList;

public:
	SheepFarm();
	SheepFarm(const SheepFarm &farm);
	virtual void buyProducts(Farm &seller);
	virtual void buyAnimals();
	virtual void printFarm();
	virtual void sellProducts();
	virtual void Subscribe(Farm &client);
	virtual void SubChicken(Farm* sub);
	virtual void SubSheep(Farm* sub);
	virtual void SubCow(Farm* sub);
	virtual void Produce();
	virtual void CheckAnimals();
	virtual ~SheepFarm();
};



#endif /* SHEEPFARM_H_ */
