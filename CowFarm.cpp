/*
 * CowFarm.cpp
 *
 *  Created on: Jan 11, 2022
 *      Author: ise
 */

#include "CowFarm.h"
int m;

CowFarm::CowFarm(){
	for(m=0;m<3;m++){ // adding 3 animals
		try{
			Cow* tmp = new Cow();
			this->AnimalsList.push_back(tmp);
		}
		catch(bad_alloc&){
			exit(1);
		}
	}
}
void CowFarm::printFarm(){
	cout << "Farm Id: " << this->ID << ", type: Cow farm, Money: " << this->Money << ", Animals: " << this->AnimalsList.size() << " cows, Products: Milk[";
	cout << this->Milk << "], Wool[" << this->Wool << "], Eggs[" << this->Eggs << "]" << endl;
}

void CowFarm::buyProducts(Farm &seller){ // how to fix
	int productcount=0;
	while(this->Money >= 1 && seller.Eggs > 0){
		this->Eggs++;
		seller.Eggs--;
		this->Money -= 1;
		seller.Money += 1;
		productcount++;
	}
	if(productcount > 0){
		cout << "Cow farm(" << this->ID << ") bought " << productcount << " eggs for " << productcount*1 << " dollars from Chicken farm(" << seller.ID << ")" << endl;
	}
}

void CowFarm::buyAnimals(){
	int animalcounterl=0;
	while(this->Money >= 10){
		try{
			Cow* tmp = new Cow();
			this->AnimalsList.push_back(tmp);
			this->Money -= tmp->cost;
		}
		catch(bad_alloc&){
			exit(1);
		}
		animalcounterl++;
	}
	if(animalcounterl > 0){
		cout << "Cow farm(" << this->ID << ") bought " << animalcounterl << " cows for " << animalcounterl*10 << " dollars" << endl;
	}

}

void CowFarm::sellProducts(){
	for(Farm* &p : this->Subscribers){
		//Farm &f = *this;
		p->buyProducts(*this);
	}

}

void CowFarm::Subscribe(Farm &client){
	client.SubCow(this);
}
void CowFarm::SubChicken(Farm* sub){
	sub->Subscribers.push_back(this);
	cout << "Chicken farm(" << sub->ID << ") Added Cow farm(" << this->ID << ") to his client list" << endl;
}
void CowFarm::SubSheep(Farm* sub){;
this->Subscribers.push_back(sub);
cout << "Cow farm(" << this->ID << ") Added Sheep farm(" << sub->ID << ") to his client list" << endl;
}
void CowFarm::SubCow(Farm* sub){

}

void CowFarm::Produce(){
	int counter = 0;
	for(counter=0;counter<this->AnimalsList.size();counter++){
		this->Milk += this->AnimalsList[counter]->age;
	}
}

void CowFarm::CheckAnimals(){
	int counter = 0;
	for(counter=0;counter<this->AnimalsList.size();counter++){
		this->AnimalsList[counter]->age++;
		if(this->AnimalsList[counter]->age == this->AnimalsList[counter]->ageofdeath){
			delete this->AnimalsList[counter];
			this->AnimalsList.erase(this->AnimalsList.begin() + 0);
			counter--;
			continue;
		}
	}
}

CowFarm::~CowFarm(){
	//	for(Farm* p : this->Subscribers){
	//		delete p;
	//		p=NULL;
	//	}
	for(Animal* p : this->AnimalsList){
		delete p;
	}
}


