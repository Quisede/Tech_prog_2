#include "Keeper.h"
#include <iostream>
#include <fstream>
using namespace std;

//Keeper::Keeper() : head(nullptr), size(0) {}
/*
Keeper::~Keeper() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current->hero;  // Удаление объекта героя
        delete current;        // Удаление узла
        current = next;
    }
}
*/
void Keeper::addHero(Heroes* hero) {
    heroesList.add(hero);
}

void Keeper::printHeroes() const {
    heroesList.print(); // Печать информации о всех героях
}

void Keeper::clearHeroes() {
    Node* current = heroesList.getHead();
    while (current != nullptr) {
        Node* next = current->next;
        delete current->hero;
        delete current;
        current = next;
    }
    heroesList = List(); // Сброс списка
}

void Keeper::removeHero() {
    cout << "Какого персонажа вы хотите удалить?:\n1)Героя\n2)Злодея\n3)Монстра\n";
    int choice = 0;
    int choice_2 = 0;

    while (choice != 3) {
        cin >> choice;

        switch (choice) {
        case 1: {
            system("cls");
            cout << "1)Найти персонажа по имени\n2)Показать всех персонажей\n3)Выйти\n";
            cin >> choice_2;

            if (choice_2 == 1) {
                string s;
                system("cls");
                cout << "Введите имя персонажа:\n";
                cin >> s;
                removeByName(s); // Удаление персонажа по имени
                system("cls");
            }
            if (choice_2 == 2) {
                if (choice == 1)
                    cout << "ВСЕ ГЕРОИ" << endl;
                if (choice == 2)
                    cout << "ВСЕ ЗЛОДЕИ" << endl;
                if (choice == 3)
                    cout << "ВСЕ МОНСТРЫ" << endl;

                system("cls");
                heroesList.printTypeHero(choice);
                system("pause");
                system("cls");
            }
            if (choice_2 == 3) {
                system("cls");
                break;
            }
            if (choice_2 != 1 && choice_2 != 2 && choice_2 != 3) {
                cout << "Вы ввели неверное значение, попробуйте снова" << endl;
            }
            break; // Выход из switch
        }
        case 2: {
            system("cls");
            cout << "1)Найти персонажа по имени\n2)Показать всех персонажей\n3)Выйти\n";
            cin >> choice_2;
            system("cls");
            if (choice_2 == 1) {
                string s;
                cout << "Введите имя персонажа:\n";
                cin >> s;
                removeByName(s); // Удаление персонажа по имени
            }
            if (choice_2 == 2) {
                if (choice == 1)
                    cout << "ВСЕ ГЕРОИ" << endl;
                if (choice == 2)
                    cout << "ВСЕ ЗЛОДЕИ" << endl;
                if (choice == 3)
                    cout << "ВСЕ МОНСТРЫ" << endl;


                heroesList.printTypeHero(choice);
            }
            if (choice_2 == 3) {
                break;
            }
            else {
                cout << "Вы ввели неверное значение, попробуйте снова" << endl;
            }
            
            break; // Выход из switch
        }
        case 3: {
            system("cls");
            cout << "1)Найти персонажа по имени\n2)Показать всех персонажей\n3)Выйти\n";
            cin >> choice_2;

            if (choice_2 == 1) {
                string s;
                cout << "Введите имя персонажа:\n";
                cin >> s;
                removeByName(s); // Удаление персонажа по имени
            }
            if (choice_2 == 2) {
                if (choice == 1)
                    cout << "ВСЕ ГЕРОИ" << endl;
                if (choice == 2)
                    cout << "ВСЕ ЗЛОДЕИ" << endl;
                if (choice == 3)
                    cout << "ВСЕ МОНСТРЫ" << endl;


                heroesList.printTypeHero(choice);
            }
            if (choice_2 == 3) {
                break;
            }
            else {
                cout << "Вы ввели неверное значение, попробуйте снова" << endl;
            }
            
            break; // Выход из switch
        }
        default:
            cout << "Неверный выбор. Пожалуйста, попробуйте снова." << endl;
            break;
        }
    }
}

Heroes* Keeper::searchName(string& s) {/*
    Node* current = heroesList.getHead();
    while (current != nullptr) {
        if (current->hero->getName() == s) {
            return current->hero;//возвращаем указатель на найденный объект
        }
    }
    cout << "ERROR";
    return nullptr;//если ничего не нашли*/
    Node* current = heroesList.getHead();  // Начинаем с головы списка
    while (current != nullptr) {
        if (current->hero->getName() == s) {
            return current->hero;  // Возвращаем указатель на найденного героя
        }
        current = current->next;  // Переходим к следующему узлу
    }
    cout << "ERROR: Герой с именем " << s << " не найден." << endl;
    return nullptr;  // Если ничего не нашли, возвращаем nullptr
}

void Keeper::removeByName(string& n) {
    Node* current = heroesList.getHead();//екущий узел
    Node* previous = nullptr;//предыдущий узел

    while (current != nullptr) {
        if (current->hero->getName() == n) {
            if (previous == nullptr) {
                heroesList.setHead(current->next);
            }
            else {
                previous->next = current->next;
            }
            delete current->hero;
            delete current;
            cout << "Герой " << n << " удален из списка.\n";
            return;
        }
        previous = current;
        current = current->next;
    }
    cout << "Герой с именем " << n << " не найден.\n";
}

void Keeper::saveToFile(const char* filename) {
    Node* current = heroesList.getHead();

    ofstream file(filename);

    if (file.is_open()){
        while (current != nullptr) {
            current->hero->saveToFile(file);
            current = current->next;
        }
        file.close();
        cout << "Список героев успешно сохранен в файл." << endl;
    }
    else {
        cout << "Ошибка при открытии файла" << endl;
    }
}

void Keeper::loadFromFile(const char* filename) {
    int answer = 0;
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Не удалось открыть файл" << endl;
        return;
    }

    cout << "Файл найден и успешно открыт" << endl;
    cout << "При загрузке данных из файла, текущие внесенные вами данные будут отчищены. Вы хотите продолжить?\n1 - Да\n2 - Выйти в меню" << endl;
    cin >> answer;
    if (answer == 2) {
        return;
    }
    if (answer != 1 && answer != 2) {
        cout << "Неверное значение. Попробуйте снова.";
        return;
    }

    clearHeroes();//очистка контейнера перед загрузкой

    string type;
    while (file >> type) {
        Heroes* hero = nullptr;

        if (type == "Positive_Heroes")
            hero = new Positive_Heroes();
        else if (type == "Villains")
            hero = new Villains();
        else if (type == "Monsters")
            hero = new Monsters();
        
        if (hero) {
            hero->loadFromFile(file);
            addHero(hero);
        }

    }

    file.close(); // Закрываем файл
    system("cls");
    cout << "Список героев успешно загружен из файла." << endl;
}

