#include "Cruiser.h"

const std::string Cruiser::ShipType = "cruiser";

Cruiser::Cruiser() :Ship(3) {}

std::string Cruiser::getShipType() {
	return Cruiser::ShipType;
}
