#include "Keeper.h"
#include "Monsters.h"
#include "LinkedList.h"
#include "Heroes.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <stdio.h>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Keeper keeper;
    int choice = 0;

    while (choice != 9) {
        cout << "-------------����----------------\n\n" << endl;
        cout << "�������� ���������: \n1)�����\n2)������\n3)������\n" << endl;
        cout << "8 - �������� ��� ���������� ����������\n";
        cout << "9 - ��������� ���������\n";
        cin >> choice;

        switch (choice) {
        case 1: {
            system("cls");
            // ������� ������ �����
            Positive_Heroes* positive_hero = new Positive_Heroes();
            positive_hero->inputData();
            keeper.addHero(positive_hero);
            break; // ����� �� switch
        }
        case 2: {
            system("cls");
            // ������� ������ ������
            Villains* villains = new Villains();
            villains->inputData();
            keeper.addHero(villains);
            break; // ����� �� switch
        }
        case 3: {
            system("cls");
            // ������� ������ �������
            Monsters* monster = new Monsters();
            monster->inputData();
            keeper.addHero(monster);
            break; // ����� �� switch
        }
        case 8:
            system("cls");
            keeper.printHeroes();
            break; // ����� �� switch
        case 9:
            // ����� �� ���������
            break;
        default:
            cout << "�������� �����. ����������, ���������� �����." << endl;
            break;
        }
    }

    // ������� ������
    keeper.clearHeroes();

    return 0;
}
