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
    Heroes* heroSearch = nullptr;

    while (choice != 10) {
        cout << "-------------����----------------\n\n" << endl;
        cout << "1 - ���� ��������� �����\n2 - ���� ��������� ������\n3 - ���� ��������� ������\n";
        cout << "4 - ������� ���������\n";
        cout << "5 - ��������� � ����\n";
        cout << "6 - ��������� �� ����� � �����\n";
        cout << "7 - ����� ���������\n";
        cout << "8 - �������� ������ ���������\n";
        cout << "9 - �������� ��� ���������� ����������\n";
        cout << "10 - ��������� ���������\n";
        cout << ">>> ";
        cin >> choice;

        switch (choice) {
        case 1: {
            system("cls");
            // ������� ������ �����
            Positive_Heroes* positive_hero = new Positive_Heroes();
            positive_hero->inputData();
            keeper.addHero(positive_hero);
            system("cls");
            break; // ����� �� switch
        }
        case 2: {
            system("cls");
            // ������� ������ ������
            Villains* villains = new Villains();
            villains->inputData();
            keeper.addHero(villains);
            system("cls");
            break; // ����� �� switch
        }
        case 3: {
            system("cls");
            // ������� ������ �������
            Monsters* monster = new Monsters();
            monster->inputData();
            keeper.addHero(monster);
            system("cls");
            break; // ����� �� switch
        }
        case 4: {
            system("cls");
            keeper.removeHero();
            break;
        }
        case 5: {
            system("cls");
            string filename;
            cout << "������� �������� �������� �����" << endl;
            cin >> filename;
            system("cls");
            keeper.saveToFile(filename.c_str());
            system("pause");
            system("cls");
            break;
        }
        case 6: {
            system("cls");
            string filename;
            cout << "������� �������� �����" << endl;
            cin >> filename;
            system("cls");
            keeper.loadFromFile(filename.c_str());
            system("pause");
            system("cls");
            break;
        }
        case 7: {
            system("cls");
            cout << "������� ��� ���������" << endl;
            string nameSearch;
            cin >> nameSearch;
            system("cls");
            heroSearch = keeper.searchName(nameSearch);
            if (heroSearch == nullptr) {
                cout << "ERROR" << endl;
                system("pause");
                system("cls");
                break;
            }
            else {
                heroSearch->printInfo();
                system("pause");
                system("cls");
                break;
            }
        }
        case 8: {
            system("cls");
            cout << "������� ��� ���������, ������ �������� �� ������ ��������" << endl;
            string nameSearch;
            cin >> nameSearch;
            heroSearch = keeper.searchName(nameSearch);
            if (heroSearch == nullptr) {
                cout << "ERROR" << endl;
                break;
            }
            heroSearch->printInfo();
            
            heroSearch->changeSpec();

            system("pause");
            system("cls");

            break;
        }
        case 9:
            system("cls");
            keeper.printHeroes();
            system("pause");
            system("cls");
            break; // ����� �� switch
        case 10:
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
