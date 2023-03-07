#include <iostream>
#include "Ocean.h"
int main() {
	Ocean* ocean = new Ocean();
	ocean->placeAllShipsRandomly();
	while (!ocean->isGameOver()) {
		try {
			ocean->print();
			std::cout << "Enter row,column: ";
			int row, column;
			std::cin >> row;
			std::cin >> column;
			ocean->shootAt(row, column);
			std::cout << "HitCount: " << ocean->getHitCount() << std::endl;
			std::cout << "ShipsSunk: " << ocean->getShipsSunk() << std::endl;
			std::cout << "ShotsFired: " << ocean->getShotsFired() << std::endl;
		}
		catch (...) {
		}
	}
	ocean->print();
	std::cout << "HitCount: " << ocean->getHitCount() << std::endl;
	std::cout << "ShipsSunk: " << ocean->getShipsSunk() << std::endl;
	std::cout << "ShotsFired: " << ocean->getShotsFired() << std::endl;
	return 0;
}