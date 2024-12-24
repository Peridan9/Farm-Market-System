/*
 * FarmExceptions.h
 *
 *  Created on: Jan 12, 2022
 *      Author: ise
 */

#ifndef FARMEXCEPTIONS_H_
#define FARMEXCEPTIONS_H_
#include <iostream>
#include <exception>
using namespace std;

class CowException:public exception{
public:
	virtual const char* what() const throw(){
		return "Insert valid number of cow farms";
	}
};

class SheepException:public exception{
public:
	virtual const char* what() const throw(){
		return "Insert valid number of sheep farms";
	}
};

class ChickenException:public exception{
public:
	virtual const char* what() const throw(){
		return "Insert valid number of chicken farms";
	}
};




#endif /* FARMEXCEPTIONS_H_ */
