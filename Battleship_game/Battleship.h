#pragma once
class Battleship
{
private:
	int x;
	int y;
	char** map;
	char** mapE;
	int n;
	int sum, sum1;
public:
	int getX() { return this->x; }
	int getY() { return this->y; }
	int getN() { return this->n; }
	int getSum() { return this->sum; }
	int getSum1() { return this->sum1; }
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	void setN(int n) { this->n = n; }
	void setSum(int sum) { this->sum = sum; }
	void setSum1(int sum1) { this->sum1 = sum1; }
	Battleship();
	void printMap();
	void printMapEnemy();
	void placingShips();
	void hittingTarget();
	void hittingTargetEnemy();
	~Battleship();
};
