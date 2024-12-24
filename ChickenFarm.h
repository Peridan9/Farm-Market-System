/*
 * ChickenFarm.h
 *
 *  Created on: Jan 11, 2022
 *      Author: ise
 */

#ifndef CHICKENFARM_H_
#define CHICKENFARM_H_

#include "Farm.h"
#include "Chicken.h"


class ChickenFarm:public Farm
{
	vector<Chicken*> AnimalsList;

public:
	ChickenFarm();
	ChickenFarm(const ChickenFarm &farm);
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
	virtual ~ChickenFarm();
};




#endif /* CHICKENFARM_H_ */
