/*
 * Market.cpp
 *
 *  Created on: Jan 9, 2022
 *      Author: ise
 */

#include "Market.h"
#include "Animal.h"
#include "SheepFarm.h"
#include "CowFarm.h"
#include "ChickenFarm.h"


int Market::marketyear = 0;

Market::Market(){

}

int Market::getYear(){
	return Market::marketyear;
}

void Market::nextYear(){
	int i;
	int ncows;
	int nsheeps;
	int nchickens;
	for(Farm* p : this->FarmsinMarket){
		p->Produce();
	}
	cout << "----Creating new farms----" << endl;
	while(true){
		try{
			cout << "How many new cow farms will be added this year?" << endl;
			cin >> ncows;
			if(ncows < 0){
				throw CowException();
			}
			cout << "How many new sheep farms will be added this year?" << endl;
			cin >> nsheeps;
			if(nsheeps < 0){
				throw SheepException();
			}
			cout << "How many new chicken farms will be added this year?" << endl;
			cin >> nchickens;
			if(nchickens < 0){
				throw ChickenException();
			}
			break;
		}
		catch(exception& e){
			cout << e.what() << endl;
		}
	}
	cout << "----Adding new farms to market----" << endl;
	for(i=0;i<ncows;i++){
		try{
			Farm* tmp = new CowFarm();
			this->FarmsinMarket.push_back(tmp);
		}
		catch(bad_alloc&){
			exit(1);
		}
		for(Farm* p : this->FarmsinMarket){
			this->FarmsinMarket.back()->Subscribe(*p);
		}

	}
	for(i=0;i<nsheeps;i++){
		try{
			Farm* tmp = new SheepFarm();
			this->FarmsinMarket.push_back(tmp);
		}
		catch(bad_alloc&){
			exit(1);
		}
		for(Farm* p : this->FarmsinMarket){
			this->FarmsinMarket.back()->Subscribe(*p);
		}
	}
	for(i=0;i<nchickens;i++){
		try{
			Farm* tmp = new ChickenFarm();
			this->FarmsinMarket.push_back(tmp);
		}
		catch(bad_alloc&){
			exit(1);
		}
		for(Farm* p : this->FarmsinMarket){
			this->FarmsinMarket.back()->Subscribe(*p);
		}
	}
	cout << "----Begin Market----" << endl;
	//	for(Farm* &p : this->FarmsinMarket){
	//		p->sellProducts();
	//	}
	for(i=0;i<this->FarmsinMarket.size();i++){
		this->FarmsinMarket[i]->sellProducts();
	}
	cout << "----Buy Animals----" << endl;
	for(Farm* p : this->FarmsinMarket){
		p->buyAnimals();
		p->CheckAnimals();
		p->Money += 10;
	}
	this->marketyear++;

}
void Market::fastForwardYears(){
	int i;
	int yearstorun;
	cout << "How many years to fast forward?" << endl;
	cin >> yearstorun;
	for(i=0;i<yearstorun;i++){
		for(Farm* p : this->FarmsinMarket){
			p->Produce();
		}
		cout << "----Begin Market----" << endl;
		for(Farm* p : this->FarmsinMarket){
			p->sellProducts();
		}
		cout << "----Buy Animals----" << endl;
		for(Farm* p : this->FarmsinMarket){
			p->buyAnimals();
			p->CheckAnimals();
			p->Money+=10;
		}
		this->marketyear++;
	}
}

void Market::printMarketFarms(){
	cout << "----Market Farms----\n";
	for(Farm* &p : this->FarmsinMarket){
		p->printFarm();
	}
}

Market::~Market(){
	for(Farm* p : this->FarmsinMarket){
		delete p;
	}

}

