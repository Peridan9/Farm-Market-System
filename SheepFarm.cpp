/*
 * SheepFarm.cpp
 *
 *  Created on: Jan 9, 2022
 *      Author: ise
 */


#include "SheepFarm.h"
int i;

SheepFarm::SheepFarm(){
	for(i=0;i<3;i++){ // adding 3 animals
		try{
			Sheep* tmp = new Sheep();
			this->AnimalsList.push_back(tmp);
		}
		catch(bad_alloc&){
			exit(1);
		}
	}
}
void SheepFarm::printFarm(){
	cout << "Farm Id: " << this->ID << ", type: Sheep farm, Money: " << this->Money << ", Animals: " << this->AnimalsList.size() << " sheep, Products: Milk[";
	cout << this->Milk << "], Wool[" << this->Wool << "], Eggs[" << this->Eggs << "]" << endl;
}

void SheepFarm::buyProducts(Farm &seller){
	int productcount=0;
	while(this->Money >= 3 && seller.Milk > 0){
		this->Milk++;
		seller.Milk--;
		this->Money -= 3;
		seller.Money += 3;
		productcount++;
	}
	if(productcount > 0){
		cout << "Sheep farm(" << this->ID << ") bought " << productcount << " milk for " << productcount*3 << " dollars from Cow farm(" << seller.ID << ")" << endl;
	}

}

void SheepFarm::buyAnimals(){
	int animalcounterl=0;
	while(this->Money >= 5){
		try{
			Sheep* tmp = new Sheep();
			this->AnimalsList.push_back(tmp);
			this->Money -= tmp->cost;
		}
		catch(bad_alloc&){
			exit(1);
		}
		animalcounterl++;
	}
	if(animalcounterl > 0){
		cout << "Sheep farm(" << this->ID << ") bought " << animalcounterl << " sheeps for " << animalcounterl*5 << " dollars" << endl;
	}

}

void SheepFarm::sellProducts(){
	for(Farm* &p : this->Subscribers){
		if(this->Wool < 1){
			break;
		}
		p->buyProducts(*this);
	}

}

void SheepFarm::Subscribe(Farm &client){
	client.SubSheep(this);
}
void SheepFarm::SubChicken(Farm* sub){
	this->Subscribers.push_back(sub);
	cout << "Sheep farm(" << this->ID << ") Added Chicken farm(" << sub->ID << ") to his client list" << endl;
}
void SheepFarm::SubSheep(Farm* sub){};

void SheepFarm::SubCow(Farm* sub){
	sub->Subscribers.push_back(this);
	cout << "Cow farm(" << sub->ID << ") Added Sheep farm(" << this->ID << ") to his client list" << endl;
}

void SheepFarm::Produce(){
	int counter = 0;
	for(counter=0;counter<this->AnimalsList.size();counter++){
		this->Wool += this->AnimalsList[counter]->age;
	}
}
void SheepFarm::CheckAnimals(){
	int counter = 0;
	for(counter=0;counter<this->AnimalsList.size();counter++){
		this->AnimalsList[counter]->age++;
		if(this->AnimalsList[counter]->age == this->AnimalsList[counter]->ageofdeath){
			delete this->AnimalsList[0];
			this->AnimalsList.erase(this->AnimalsList.begin() + 0);
			counter--;
			continue;
		}
	}
}

SheepFarm::~SheepFarm(){
	for(Animal* p : this->AnimalsList){
		delete p;
	}
}

