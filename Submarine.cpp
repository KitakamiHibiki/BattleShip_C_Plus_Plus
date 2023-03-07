#include "Submarine.h"

const std::string Submarine::ShipType = "submarine";

Submarine::Submarine() :Ship(1) {}

std::string Submarine::getShipType() {
	return Submarine::ShipType;
}
