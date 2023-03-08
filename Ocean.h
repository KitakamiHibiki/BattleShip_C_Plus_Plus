#pragma once
#include <random>
#include "Ship.h"

using ships = Ship*[10];

class Ocean {
public:
	Ocean();
	void placeAllShipsRandomly();
	bool isOccupied(int row, int column);
	bool shootAt(int row, int column);
	int getShotsFired();
	int getHitCount();
	int getShipsSunk();
	bool isGameOver();
	ships* getShipArray();
	void print();
protected:
	ships Ships[10];
	int shotsFired;
	int hitCount;
	int shipsSunk;
	int whichShip;
	std::random_device rd;
};
