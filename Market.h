/*
 * Market.h
 *
 *  Created on: Jan 9, 2022
 *      Author: ise
 */

#ifndef MARKET_H_
#define MARKET_H_
#include "Farm.h"
#include "FarmExceptions.h"

class Market{
	static int marketyear;
	vector<Farm*> FarmsinMarket;

public:
	Market();
	int getYear();
	void nextYear();
	void fastForwardYears();
	void printMarketFarms();
	~Market();
};



#endif /* MARKET_H_ */
