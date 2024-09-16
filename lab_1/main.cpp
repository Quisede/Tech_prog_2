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
        cout << "-------------МЕНЮ----------------\n\n" << endl;
        cout << "1 - Ввод персонажа Герой\n2 - Ввод персонажа Злодей\n3 - Ввод персонажа Монстр\n";
        cout << "4 - Удалить персонажа\n";
        cout << "5 - Сохранить в файл\n";
        cout << "6 - Выгрузить из файла в файла\n";
        cout << "7 - Найти персонажа\n";
        cout << "8 - Изменить данные персонажа\n";
        cout << "9 - Показать все содержимое контейнера\n";
        cout << "10 - Завершить программу\n";
        cout << ">>> ";
        cin >> choice;

        switch (choice) {
        case 1: {
            system("cls");
            // Создаем нового героя
            Positive_Heroes* positive_hero = new Positive_Heroes();
            positive_hero->inputData();
            keeper.addHero(positive_hero);
            system("cls");
            break; // Выход из switch
        }
        case 2: {
            system("cls");
            // Создаем нового злодея
            Villains* villains = new Villains();
            villains->inputData();
            keeper.addHero(villains);
            system("cls");
            break; // Выход из switch
        }
        case 3: {
            system("cls");
            // Создаем нового монстра
            Monsters* monster = new Monsters();
            monster->inputData();
            keeper.addHero(monster);
            system("cls");
            break; // Выход из switch
        }
        case 4: {
            system("cls");
            keeper.removeHero();
            break;
        }
        case 5: {
            system("cls");
            string filename;
            cout << "Введите желаемое название файла" << endl;
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
            cout << "Введите название файла" << endl;
            cin >> filename;
            system("cls");
            keeper.loadFromFile(filename.c_str());
            system("pause");
            system("cls");
            break;
        }
        case 7: {
            system("cls");
            cout << "Введите имя персонажа" << endl;
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
            cout << "Введите имя персонажа, данные которого вы хотите изменить" << endl;
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
            break; // Выход из switch
        case 10:
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
