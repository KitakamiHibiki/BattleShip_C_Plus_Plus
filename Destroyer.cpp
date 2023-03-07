#include "Destroyer.h"

const std::string Destroyer::ShipType = "destroyer";

Destroyer::Destroyer() :Ship(2) {}

std::string Destroyer::getShipType() {
	return Destroyer::ShipType;
}
