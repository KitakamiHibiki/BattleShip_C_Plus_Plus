#pragma once
#include <string>
#include "Ship.h"

class Submarine :public Ship {
public:
	static const std::string ShipType;
	Submarine();
	std::string getShipType();
};

