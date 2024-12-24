/*
 * Farm.h
 *
 *  Created on: Jan 9, 2022
 *      Author: ise
 */

#ifndef FARM_H_
#define FARM_H_
#include <iostream>
#include <vector>
#include "Animal.h"
using namespace std;

class Farm{
	static int farmID;
	// info
	int ID;
	int Money;
	//products
	int Milk;
	int Wool;
	int Eggs;
	vector<Farm*> Subscribers;
public:
	Farm();
	Farm(const Farm &cfarm);
	virtual void buyProducts(Farm &seller)=0;
	virtual void buyAnimals()=0;
	virtual void printFarm()=0;
	virtual void sellProducts()=0;
	virtual void Subscribe(Farm &client)=0;
	virtual void SubChicken(Farm* sub)=0;
	virtual void SubSheep(Farm* sub)=0;
	virtual void SubCow(Farm* sub)=0;
	virtual void Produce()=0;
	virtual void CheckAnimals()=0;
	virtual ~Farm();
	friend class SheepFarm;
	friend class CowFarm;
	friend class ChickenFarm;
	friend class Market;

};




#endif /* FARM_H_ */
