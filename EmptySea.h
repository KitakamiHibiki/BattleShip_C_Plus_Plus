#pragma once
#include "Ship.h"

class EmptySea :public Ship {
public:
	virtual std::string toString();
	static const std::string ShipType;
	EmptySea();
	std::string getShipType();
	virtual bool shootAt(int row, int column);
	virtual bool isSunk();
private:
	bool Sunk = false;
};
