#include "Villains.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//конструкторы и деструкторы
Villains::Villains() : 
    Heroes(), wearponType(""), crime(""), location(""), skills("") {}

Villains::Villains(string& n, string& w, string& c, string& l, string& s) :
    Heroes(), wearponType(w), crime(c), location(l), skills(s) {}

Villains::Villains(const Villains& copy) :
    Heroes(copy), // Инициализация базового класса
    wearponType(copy.wearponType), // Копируем тип оружия
    crime(copy.crime), // Копируем преступление
    location(copy.location), // Копируем локацию
    skills(copy.skills) {} // Копируем навыки

Villains::~Villains() {}

//сеттеры

void Villains::setWearponType(string& w) {
    wearponType = w;
}

void Villains::setCrime(string& c) {
    crime = c;
}

void Villains::setLocation(string& l) {
    location = l;
}

void Villains::setSkills(string& s) {
    skills = s;
}

//геттеры

string Villains::getWearponType() const {
    return wearponType;
}

string Villains::getCrime() const {
    return crime;
}

string Villains::getLocation() const {
    return location;
}

string Villains::getSkills() const {
    return skills;
}

void Villains::inputData() {
    cin.ignore();

    cout << "Введите имя Злодея: ";
    string inputName;
    getline(cin, inputName);
    setName(inputName);

    cout << "Введите тип оружия: ";
    string inputWT;
    getline(cin, inputWT);
    setWearponType(inputWT);

    cout << "Введите преступления: ";
    string inputCrime;
    getline(cin, inputCrime);
    setCrime(inputCrime);

    cout << "Введите локацию: ";
    string inputLocation;
    getline(cin, inputLocation);
    setLocation(inputLocation);

    cout << "Введите скиллы: ";
    string inputSkills;
    getline(cin, inputSkills);
    setSkills(inputSkills);
}

void Villains::printInfo() const {
    cout << "Злодей" << endl;
    cout << "Имя: " << getName() << endl;
    cout << "Тип оружия: " << getWearponType() << endl;
    cout << "Преступления: " << getCrime() << endl;
    cout << "Локации: " << getLocation() << endl;
    cout << "Скиллы: " << getSkills() << endl;
    cout << "\n";
}

void Villains::saveToFile(ofstream& file) const {
    file << "Villains" << endl;
    Heroes::saveToFile(file);
    file << getWearponType() << endl;
    file << getCrime() << endl;
    file << getLocation() << endl;
    file << getSkills() << endl;
}

void Villains::loadFromFile(ifstream& file) {
    getline(file, name);
    getline(file, name);          // Считываем полное имя, включая пробелы
    getline(file, wearponType);   // Считываем тип оружия
    getline(file, crime);         // Считываем преступление
    getline(file, location);      // Считываем местоположение
    getline(file, skills);        // Считываем навыки
}

void Villains::changeSpec() {
    int answer = 0;
    cin.ignore();
    cout << "Что вы хотите изменить?\n1 - Имя\n2 - Тип оружия\n3 - Преступления\n4 - Локации\n5 - Скиллы" << endl;
    cin >> answer;
    system("cls");
    if (answer == 1) {
        cout << "Введите новое имя" << endl;
        string new_name;
        cin >> new_name;
        name = new_name;
        cout << "Данные успешно изменены" << endl;
    }
    else if (answer == 2) {
        cout << "Введите новый тип оружия" << endl;
        string new_WT;
        cin >> new_WT;
        wearponType = new_WT;
        cout << "Данные успешно изменены" << endl;

    }
    else if (answer == 3) {
        cout << "Введите новые преступления" << endl;
        string new_C;
        cin >> new_C;
        wearponType = new_C;
        cout << "Данные успешно изменены" << endl;

    }
    else if (answer == 4) {
        cout << "Введите новые локации" << endl;
        string new_L;
        cin >> new_L;
        wearponType = new_L;
        cout << "Данные успешно изменены" << endl;

    }
    else if (answer == 5) {
        cout << "Введите новый скилл" << endl;
        string new_Skill;
        cin >> new_Skill;
        skills = new_Skill;
        cout << "Данные успешно изменены" << endl;
    }
    else {
        cout << "Неверное значение, попробуйте снова" << endl;
    }
}