/*
 * CowFarm.h
 *
 *  Created on: Jan 11, 2022
 *      Author: ise
 */

#ifndef COWFARM_H_
#define COWFARM_H_
#include "Farm.h"
#include "Cow.h"


class CowFarm:public Farm
{
	vector<Cow*> AnimalsList;

public:
	CowFarm();
	CowFarm(const CowFarm &farm);
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
	virtual ~CowFarm();
};






#endif /* COWFARM_H_ */
