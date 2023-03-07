#include "Battleship.h"

const std::string Battleship::ShipType = "battleship";

Battleship::Battleship() :Ship(4) {}

std::string Battleship::getShipType() {
	return Battleship::ShipType;
}
