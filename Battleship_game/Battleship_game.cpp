#include <iostream>
#include "Battleship.h"
using namespace std;
int main()
{
	srand(time(NULL));
	Battleship A;
	A.hittingTarget();
	A.printMap();
	A.placingShips();
}