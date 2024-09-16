#include "Monsters.h"
#include "Heroes.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//конструкторы и деструкторы
Monsters::Monsters() : Heroes(), description("") {}

Monsters::Monsters(const string& name, const string& description) : Heroes(name), description(description) {}
/*
Monsters::Monsters(const Monsters& copy) : name(copy.name), description(copy.description){}
*/
Monsters::~Monsters() {
}

//сеттеры
/*
void Monsters::setName(string& n) {
    Heroes.name = n;
}
*/
void Monsters::setDescription(string& d) {
    description = d;
}

//геттеры
/*
string Monsters::getName() const {
    return name;
}
*/
string Monsters::getDescription() const {
    return description;
}

void Monsters::inputData() {

    cout << "Введите имя Монстра: ";
    string inputName;
    cin >> inputName;
    setName(inputName);

    cout << "Введите описание монстра: ";
    string inputDescription;
    cin >> inputDescription;
    setDescription(inputDescription);
}

void Monsters::printInfo() const {
    cout << "МОНСТР" << endl;
    cout << "Имя: " << getName() << endl;
    cout << "Описание: " << getDescription() << endl;
    cout << "\n";
}

void Monsters::saveToFile(ofstream& file) const {
    file << "Monsters" << endl;
    Heroes::saveToFile(file);
    file << getDescription() << endl;
}

void Monsters::loadFromFile(ifstream& file) {
    file >> name;
    file >> description;
}

void Monsters::changeSpec() {
    int answer = 0;
    cout << "Что вы хотите изменить?\n1 - Имя\n2 - Описание" << endl;
    cin >> answer;
    if (answer == 1) {
        cout << "Введите новое имя" << endl;
        string new_name;
        cin >> new_name;
        name = new_name;
        cout << "Данные успешно изменены" << endl;
    }
    else if (answer == 2) {
        cout << "Введите новое описание" << endl;
        string new_D;
        cin >> new_D;
        description = new_D;
        cout << "Данные успешно изменены" << endl;

    }
    else {
        cout << "Неверное значение, попробуйте снова" << endl;
    }
}