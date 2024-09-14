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
        cout << "-------------МЕНЮ----------------\n\n" << endl;
        cout << "Выберите персонажа: \n1)Герой\n2)Злодей\n3)Монстр\n" << endl;
        cout << "8 - Показать все содержимое контейнера\n";
        cout << "9 - Завершить программу\n";
        cin >> choice;

        switch (choice) {
        case 1: {
            system("cls");
            // Создаем нового героя
            Positive_Heroes* positive_hero = new Positive_Heroes();
            positive_hero->inputData();
            keeper.addHero(positive_hero);
            break; // Выход из switch
        }
        case 2: {
            system("cls");
            // Создаем нового злодея
            Villains* villains = new Villains();
            villains->inputData();
            keeper.addHero(villains);
            break; // Выход из switch
        }
        case 3: {
            system("cls");
            // Создаем нового монстра
            Monsters* monster = new Monsters();
            monster->inputData();
            keeper.addHero(monster);
            break; // Выход из switch
        }
        case 8:
            system("cls");
            keeper.printHeroes();
            break; // Выход из switch
        case 9:
            // Выход из программы
            break;
        default:
            cout << "Неверный выбор. Пожалуйста, попробуйте снова." << endl;
            break;
        }
    }

    // Очистка памяти
    keeper.clearHeroes();

    return 0;
}
