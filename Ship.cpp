#include <iostream>
#include <vector>
#include "Ship.h"
#include "Ocean.h"

Ship::Ship(int length) {
	this->length = length;
	this->hit = new bool[length];
	for (int a = 0; a < length; a += 1) {
		this->hit[a] = false;
	}
}

int Ship::getLength() {
	return this->length;
}

int Ship::getBowRow() {
	return this->bowRow;
}

int Ship::getBowColumn() {
	return this->bowColumn;
}

bool* Ship::getHit() {
	return this->hit;
}

bool Ship::isHorizontal() {
	return this->horizontal;
}

void Ship::setBowRow(int row) {
	this->bowRow = row;
}

void Ship::setBowColumn(int column) {
	this->bowColumn = column;
}

void Ship::setHorizontal(bool horizontal) {
	this->horizontal = horizontal;
}

bool Ship::okToPlaceShipAt(int row, int column, bool Horizontal, Ocean* ocean) {
	if (Horizontal) {
		for (int a = column; a > column - this->length; a -= 1) {
			if (a < 0 || a > 9 || ocean->isOccupied(row, a)) {
				return false;
			}
		}
		for (int nRow = row + 1; nRow > row - 2; nRow -= 1) {
			for (int ncolumn = column + 1; ncolumn > column - this->length - 1; ncolumn -= 1) {
				if (!(nRow == row && ncolumn > column - this->length && ncolumn < column + 1)) {
					if (nRow > -1 && nRow < 10 && ncolumn > -1 && ncolumn < 10)
						if (ocean->isOccupied(nRow, ncolumn))
							return false;
				}
			}
		}
	}
	else {
		for (int a = row; a > row - this->length; a -= 1) {
			if (a < 0 || a > 9 || ocean->isOccupied(a, column))
				return false;
		}
		for (int ncolumn = column + 1; ncolumn > column - 2; ncolumn -= 1) {
			for (int nRow = row + 1; nRow > row - this->length - 1; nRow -= 1) {
				if (!(ncolumn == column && nRow > row - this->length && nRow < row + 1)) {
					if (nRow > -1 && nRow < 10 && ncolumn > -1 && ncolumn < 10)
						if (ocean->isOccupied(nRow, ncolumn))
							return false;
				}
			}
		}
	}
	return true;
}

void Ship::placeShipAt(int row, int column, bool Horizontal, Ocean* ocean) {
	if (this->isHorizontal()) {
		for (int a = column; a > column - this->getLength(); a -= 1) {
			ocean->getShipArray()[row][a] = this;
		}
	}
	else {
		for (int a = row; a > row - this->getLength(); a -= 1) {
			ocean->getShipArray()[a][column] = this;
		}
	}
}

bool Ship::shootAt(int row, int column) {
	if (!this->isSunk()) {
		if (this->horizontal) {
			this->hit[this->bowColumn - column] = true;
			return true;
		}
		else {
			this->hit[this->bowRow - row] = true;
			return true;
		}
	}
	return false;
}

bool Ship::isSunk() {
	for (int a = 0; a < this->length; a += 1) {
		if (!this->hit[a])
			return false;
	}
	return true;
}

std::string Ship::toString() {
	if (this->isSunk())
		return "s";
	return "x";
}
