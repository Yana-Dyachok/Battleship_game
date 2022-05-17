#include <iostream>
#include "Battleship.h"
using namespace std;
int main()
{
	srand(time(NULL));
	Battleship A;
	A.placingShips();
	A.hittingTarget();
}
