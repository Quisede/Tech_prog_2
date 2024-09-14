#include "Monsters.h"
#include "Heroes.h"
#include <iostream>
#include <string>
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
    cout << "Name: " << getName() << endl;
    cout << "Description: " << getDescription() << endl;
}