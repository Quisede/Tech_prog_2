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
    //корректная работа с русским языком
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Keeper keeper;//создаем объект Кипер 
    int choice = 0;
    Heroes* heroSearch = nullptr;//указатель для поиска персонажа

    //реализация меню
    while (choice != 10) {
        cout << "-------------МЕНЮ----------------\n\n" << endl;
        cout << "1 - Ввод персонажа Герой\n2 - Ввод персонажа Злодей\n3 - Ввод персонажа Монстр\n";
        cout << "4 - Удалить персонажа\n";
        cout << "5 - Сохранить в файл\n";
        cout << "6 - Загрузить из файла\n";
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
            positive_hero->inputData();//ввод данных пользователем вручную
            keeper.addHero(positive_hero);//добавление нового героя в контейнер Кипера
            system("cls");
            break; // Выход из switch
        }
        case 2: {
            system("cls");
            // Создаем нового злодея
            Villains* villains = new Villains();
            villains->inputData();//ввод данных пользователем вручную
            keeper.addHero(villains);//добавление нового героя в контейнер Кипера
            system("cls");
            break; // Выход из switch
        }
        case 3: {
            system("cls");
            // Создаем нового монстра
            Monsters* monster = new Monsters();
            monster->inputData();//ввод данных пользователем вручную
            keeper.addHero(monster);//добавление нового героя в контейнер Кипера
            system("cls");
            break; // Выход из switch
        }
        case 4: {
            //удаление героя
            system("cls");
            keeper.removeHero();//вызов функции в Кипере для удаления данных удаляемого героя в контейнере
            break;
        }
        case 5: {
            //сохранение текущих данных контейнера в файл
            system("cls");
            string filename;
            cout << "Введите желаемое название файла" << endl;
            cin >> filename;
            system("cls");
            keeper.saveToFile(filename.c_str());//вызов функции в Кипере для сохранения данных в файл, с_str преобразует строку в char* для корректной работы функции
            system("pause");
            system("cls");
            break;
        }
        case 6: {
            //загрузка данных из файла
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
            //поиск персонажа
            cin.ignore();
            system("cls");
            cout << "Введите имя персонажа" << endl;
            string nameSearch;
            getline(cin, nameSearch);
            system("cls");
            heroSearch = keeper.searchName(nameSearch);//вызов функции поиска по имени в Кипере
            //если вернулся нуль, то значит ничего не нашли
            if (heroSearch == nullptr) {
                cout << "ERROR" << endl;
                system("pause");
                system("cls");
                break;
            }
            //иначе берем возвращенный из функции поиска указатель и отправляем его на печать данных
            else {
                heroSearch->printInfo();
                system("pause");
                system("cls");
                break;
            }
        }
        case 8: {
            //изменение данных персонажей
            cin.ignore();
            system("cls");
            cout << "Введите имя персонажа, данные которого вы хотите изменить" << endl;
            string nameSearch;
            getline(cin, nameSearch);
            //сначала ищем персонажа по имени
            heroSearch = keeper.searchName(nameSearch);
            system("cls");
            if (heroSearch == nullptr) {
                cout << "ERROR" << endl;
                break;
            }
            //печатаем информацию о найденном персонаже
            heroSearch->printInfo();
            //вызываем функцию изменения данных для кокретного типа персонажа
            heroSearch->changeSpec();

            system("pause");
            system("cls");

            break;
        }
        case 9:
            //печать всего контейнера
            system("cls");
            keeper.printHeroes();//функция в Кипере, которая прогоняет весь список и выводит всю информацию
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
