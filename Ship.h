#pragma once
#include <string>

class Ocean;

class Ship {
public:
	Ship(int length);
	int getLength();
	int getBowRow();
	int getBowColumn();
	bool* getHit();
	bool isHorizontal();
	void setBowRow(int row);
	void setBowColumn(int column);
	void setHorizontal(bool horizontal);
	virtual std::string getShipType() = 0;
	bool okToPlaceShipAt(int row, int column, bool Horizontal, Ocean* ocean);
	void placeShipAt(int row, int column, bool Horizontal, Ocean* ocean);
	virtual bool shootAt(int row, int column);
	virtual bool isSunk();
	virtual std::string toString();
protected:
	int bowRow, bowColumn, length;
	bool horizontal;
	bool* hit;
};
