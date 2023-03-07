#pragma once
#include <iostream>
#include "Ship.h"
class Cruiser :public Ship {
public:
	static const std::string ShipType;
	Cruiser();
	std::string getShipType();
};

