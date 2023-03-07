#pragma once
#include <string>
#include "Ship.h"

class Battleship :public Ship {
public:
	static const std::string ShipType;
	Battleship();
	std::string getShipType();
};

