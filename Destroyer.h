#pragma once
#include <string>
#include "Ship.h"

class Destroyer : public Ship {
public:
	static const std::string ShipType;
	Destroyer();
	std::string getShipType();
};

