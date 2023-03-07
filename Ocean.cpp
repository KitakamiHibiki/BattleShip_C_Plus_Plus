#include <iostream>
#include "Ocean.h"
#include "Battleship.h"
#include "Cruiser.h"
#include "Destroyer.h"
#include "EmptySea.h"
#include "Submarine.h"

Ocean::Ocean() {
	for (int a = 0; a < 10; a += 1) {
		for (int b = 0; b < 10; b += 1) {
			this->Ships[a][b] = new EmptySea();
		}
	}
	this->shotsFired = 0;
	this->hitCount = 0;
	this->shipsSunk = 0;
	this->whichShip = 0;
}

void Ocean::placeAllShipsRandomly() {
	this->whichShip += 1;
	int BowRow, BowColumn;
	bool Horizontal;
	Ship* newShip;
	if (this->whichShip < 2) {
		newShip = new Battleship();
	}
	else if (this->whichShip < 4) {
		newShip = new Cruiser();
	}
	else if (this->whichShip < 7) {
		newShip = new Destroyer();
	}
	else if (this->whichShip < 11) {
		newShip = new Submarine();
	}
	else
		return;
	do {
		BowColumn = this->rd() % 10;
		BowRow = this->rd() % 10;
		Horizontal = this->rd() % 2;
	} while (!newShip->okToPlaceShipAt(BowRow, BowColumn, Horizontal, this));
	newShip->setBowRow(BowRow);
	newShip->setBowColumn(BowColumn);
	newShip->setHorizontal(Horizontal);
	newShip->placeShipAt(BowRow, BowColumn, Horizontal, this);
	if (this->whichShip < 11)
		this->placeAllShipsRandomly();
}

bool Ocean::isOccupied(int row, int column) {
	if (this->Ships[row][column]->getShipType() == "Empty") {
		return false;
	}
	return true;
}

bool Ocean::shootAt(int row, int column) {
	this->shotsFired += 1;
	if (this->Ships[row][column]->shootAt(row, column)) {
		this->hitCount += 1;
		if (this->Ships[row][column]->isSunk()) {
			this->shipsSunk += 1;
		}
		return true;
	}
	return false;
}

int Ocean::getShotsFired() {
	return this->shotsFired;
}

int Ocean::getHitCount() {
	return this->hitCount;
}

int Ocean::getShipsSunk() {
	return this->shipsSunk;
}

bool Ocean::isGameOver() {
	if (this->getShipsSunk() == 10)
		return true;
	return false;
}

ships* Ocean::getShipArray() {
	return this->Ships;
}

void Ocean::print() {
	for (int x = 0; x < 11; x++) {
		for (int y = 0; y < 11; y++) {
			if (x == 0) {
				std::cout << "  0 1 2 3 4 5 6 7 8 9";
				break;
			}
			if (y == 0) {
				std::cout << (x - 1) << " ";
				y += 1;
			}
			if (this->Ships[x - 1][y - 1]->getShipType() != "Empty") {
				if (this->Ships[x - 1][y - 1]->isHorizontal()) {
					if (this->Ships[x - 1][y - 1]->getHit()[this->Ships[x - 1][y - 1]->getBowColumn() - y + 1]) {
						std::cout << this->Ships[x - 1][y - 1]->toString() << " ";
					}
					else {
						std::cout << ". ";
					}
				}
				else {
					if (this->Ships[x - 1][y - 1]->getHit()[this->Ships[x - 1][y - 1]->getBowRow() - x + 1]) {
						std::cout << (*(this->Ships[x - 1][y - 1])).toString() << " ";
					}
					else {
						std::cout << ". ";
					}
				}
			}
			else {
				std::cout << this->Ships[x - 1][y - 1]->toString() << " ";
			}
		}
		std::cout << std::endl;
	}
}
