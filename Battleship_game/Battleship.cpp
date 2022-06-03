#include "Battleship.h"
#include <iostream>
#include <ctime>
#include <conio.h>
#include <Windows.h>
using namespace std;
Battleship::Battleship() {
    this->x = 0;
    this->y = 0;
    this->sum = 0;
    this->sum1 = 0;
    this->n = 10;
    this->map = nullptr;
    this->map = new char* [n];
    for (int i = 0; i < n; i++)
    {
        map[i] = new char[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            map[i][j] = '.';
        }
    }
    this->mapE = nullptr;
    this->mapE = new char* [n];
    for (int i = 0; i < n; i++)
    {
        mapE[i] = new char[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mapE[i][j] = '.';
        }
    }
}


void Battleship::hittingTarget() {
    std::cout << "Enter coordinates x and y:" << endl;
    cin >> this->x;
    cin >> this->y;
    if ((this->x > 10 or this->x < 1) or (this->y > 10 or this->y < 1)) {
        do {
            cout << "Wrong coordinates, try again: ";
            cin >> this->x;
            cin >> this->y;
        } while ((x > 10 or x < 1) or (y > 10 or y < 1));
    }
    if (this->map[this->x - 1][this->y - 1] == 'A') {
        cout << "You hit the target" << endl;
        this->mapE[this->x - 1][this->y - 1] = '#';
        sum--;
    }
    else {
        this->mapE[this->x - 1][this->y - 1] = '*';
        cout << "You missed" << endl;
    }
    Sleep(500);
}


void Battleship::hittingTargetEnemy() {
    std::cout << "Enemy step:" << endl;
    this->x = rand() % n;
    this->y = rand() % n;
    if (this->map[this->x][this->y] == 'A') {
        cout << "Enemy hit the target" << endl;
        this->map[this->x][this->y] = '#';
        sum--;
    }
    else {
        this->map[this->x][this->y] = '*';
        cout << "Enemy missed" << endl;
    }
}


void Battleship::placingShips() {
    for (int i = 0; i < 10; i++)
    {
        x = rand() % n;
        y = rand() % n;
        this->map[x][y] = 'A';
        sum++;//підрахунок кораблів
    }
}


Battleship::~Battleship() {
    for (int i = 0; i < n; i++)
    {
        delete[]this->map[i];
    }
    delete[]this->map;
    for (int i = 0; i < n; i++)
    {
        delete[]this->mapE[i];
    }
    delete[]this->mapE;
}


void Battleship::printMap() {// функція виводу грального поля
    cout << "   1 2 3 4 5 6 7 8 9 10" << endl;
    int y = 1;
    for (int i = 0; i < n; i++)
    {
        if (y == 10)
            cout << y << " ";
        else
            cout << y << "  ";
        y++;
        for (int j = 0; j < n; j++)
        {
            cout << mapE[i][j] << " ";
        }
        cout << "\n";
    }
}


void Battleship::printMapEnemy() {// функція виводу грального поля
    cout << "   1 2 3 4 5 6 7 8 9 10" << endl;
    int y = 1;
    for (int i = 0; i < n; i++)
    {
        if (y == 10)
            cout << y << " ";
        else
            cout << y << "  ";
        y++;
        for (int j = 0; j < n; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}
