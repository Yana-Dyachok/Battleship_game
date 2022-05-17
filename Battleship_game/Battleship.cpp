#include "Battleship.h"
#include <iostream>
#include <ctime>
#include <conio.h>
using namespace std;
Battleship::Battleship() {
    this->x = 0;
    this->y = 0;
    this->sum = 0;
    this->n = n = 10;
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
}


void Battleship::hittingTarget() {
    while (sum > 0) {
        printMap();
        cout << "Enter coordinates x and y:" << endl;
        cin >> x;
        cin >> y;
        if (this->map[this->x - 1][this->y - 1] == 'A') {
            cout << "You hit the target" << endl;
            this->map[this->x - 1][this->y - 1] = '#';
            sum--;
        }
        else {
            this->map[this->x - 1][this->y - 1] = '*';
            cout << "You missed" << endl;
        }
        system("cls");
    }
    cout << "You win!!!" << endl;
}


void Battleship::placingShips() {
    for (int i = 0; i < 5; i++)
    {
        x = rand() % n;
        y = rand() % n;
        this->map[x][y] = 'A';
        sum++;//��������� �������
    }
}
 

Battleship::~Battleship() {
    for (int i = 0; i < n; i++)
        {
         delete[]this->map[i];
        }
         delete[]this->map;
 }


 void Battleship::printMap() {// ������� ������ ��������� ����
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