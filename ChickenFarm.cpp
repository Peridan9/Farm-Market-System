/*
 * ChickenFarm.cpp
 *
 *  Created on: Jan 11, 2022
 *      Author: ise
 */

#include "ChickenFarm.h"
int c;

ChickenFarm::ChickenFarm(){
	for(c=0;c<3;c++){ // adding 3 animals
		try{
			Chicken* tmp = new Chicken();
			this->AnimalsList.push_back(tmp);
		}
		catch(bad_alloc&){
			exit(1);
		}
	}
}
void ChickenFarm::printFarm(){
	cout << "Farm Id: " << this->ID << ", type: Chicken Farm, Money: " << this->Money << ", Animals: " << this->AnimalsList.size() << " chickens, Products: Milk[";
	cout << this->Milk << "], Wool[" << this->Wool << "], Eggs[" << this->Eggs << "]" << endl;
}

void ChickenFarm::buyProducts(Farm &seller){ // how to fix
	int productcount=0;
	while(this->Money >= 2 && seller.Wool > 0){
		this->Wool++;
		seller.Wool--;
		this->Money -= 2;
		seller.Money += 2;
		productcount++;
	}
	if(productcount > 0){
		cout << "Chicken farm(" << this->ID << ") bought " << productcount << " wool for " << productcount*2 << " dollars from Sheep farm(" << seller.ID << ")\n";
	}
}

void ChickenFarm::buyAnimals(){
	int animalcounterl=0;
	while(this->Money >= 3){
		try{
			Chicken* tmp = new Chicken();
			this->AnimalsList.push_back(tmp);
			this->Money -= tmp->cost;
		}
		catch(bad_alloc&){
			exit(1);
		}
		animalcounterl++;
	}
	if(animalcounterl > 0){
		cout << "Chicken farm(" << this->ID << ") bought " << animalcounterl << " chickens for " << animalcounterl*3 << " dollars\n";
	}
}

void ChickenFarm::sellProducts(){
	for(Farm* &p : this->Subscribers){
		//Farm &f = *this;
		p->buyProducts(*this);
	}
}

void ChickenFarm::Subscribe(Farm &client){
	client.SubChicken(this);
}
void ChickenFarm::SubChicken(Farm* sub){

}
void ChickenFarm::SubSheep(Farm* sub){;
sub->Subscribers.push_back(this);
cout << "Sheep farm(" << sub->ID << ") Added Chicken farm(" << this->ID << ") to his client list" << endl;
}
void ChickenFarm::SubCow(Farm* sub){
	this->Subscribers.push_back(sub);
	cout << "Chicken farm(" << this->ID << ") Added Cow farm(" << sub->ID << ") to his client list" << endl;
}

void ChickenFarm::Produce(){
	int counter = 0;
	for(counter=0;counter<this->AnimalsList.size();counter++){
		this->Eggs += this->AnimalsList[counter]->age;
	}
}

void ChickenFarm::CheckAnimals(){
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


ChickenFarm::~ChickenFarm(){
//	for(Farm* p : this->Subscribers){
//		delete p;
//		p=NULL;
//	}
	for(Animal* p : this->AnimalsList){
		delete p;
	}
}


