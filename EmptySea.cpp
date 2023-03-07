#include "EmptySea.h"

const std::string EmptySea::ShipType = "Empty";

EmptySea::EmptySea() :Ship(1) {}

std::string EmptySea::getShipType() {
	return EmptySea::ShipType;
}

bool EmptySea::shootAt(int row, int column) {
	this->Sunk = true;
	return false;
}

bool EmptySea::isSunk() {
	return this->Sunk;
}

std::string EmptySea::toString() {
	if (this->isSunk()) {
		return "-";
	}
	else {
		return ".";
	}
}
