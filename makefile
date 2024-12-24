CPP_FARM: farmMarket.o Market.o Farm.o CowFarm.o SheepFarm.o ChickenFarm.o Animal.o Cow.o Sheep.o Chicken.o
	g++ farmMarket.o Market.o Farm.o CowFarm.o SheepFarm.o ChickenFarm.o Animal.o Cow.o Sheep.o Chicken.o -o CPP_FARM

farmMarket.o: farmMarket.cpp Market.h FarmExceptions.h
	g++ -c farmMarket.cpp
	
Market.o: Market.cpp Market.h Animal.h SheepFarm.h CowFarm.h ChickenFarm.h FarmExceptions.h
	g++ -c Market.cpp
	
Farm.o: Farm.cpp Farm.h Animal.h
	g++ -c Farm.cpp

CowFarm.o: CowFarm.cpp CowFarm.h Farm.h Animal.h Cow.h
	g++ -c CowFarm.cpp

SheepFarm.o: SheepFarm.cpp SheepFarm.h Farm.h Animal.h Sheep.h
	g++ -c SheepFarm.cpp

ChickenFarm.o: ChickenFarm.cpp ChickenFarm.h Farm.h Animal.h Chicken.h
	g++ -c ChickenFarm.cpp

Animal.o: Animal.cpp Animal.h
	g++ -c Animal.cpp

Cow.o: Cow.cpp Cow.h Animal.h
	g++ -c Cow.cpp
	
Sheep.o: Sheep.cpp Sheep.h Animal.h
	g++ -c Sheep.cpp
	
Chicken.o: Chicken.cpp Chicken.h Animal.h
	g++ -c Chicken.cpp
	
clean:
	rm -f*.o

