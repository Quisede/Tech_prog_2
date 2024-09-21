#include "Positive_Heroes.h"
#include "Heroes.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


//конструкторы и деструкторы
Positive_Heroes::Positive_Heroes() :
    Heroes(), wearponType(""), skills("") {}

Positive_Heroes::Positive_Heroes(const string& n, const string& w, const string& s) :
    Heroes(n), wearponType(w), skills(s) {}

Positive_Heroes::Positive_Heroes(const Positive_Heroes& copy) :
    Heroes(copy), // Инициализация базового класса с помощью конструктора копирования
    wearponType(copy.wearponType), // Копируем тип оружия
    skills(copy.skills) {} // Копируем навыки

Positive_Heroes::~Positive_Heroes() {}

//сеттеры

void Positive_Heroes::setWearponType(string& w) {
    wearponType = w;
}

void Positive_Heroes::setSkills(string& s) {
    skills = s;
}

//геттеры

string Positive_Heroes::getWearponType() const {
    return wearponType;
}

string Positive_Heroes::getSkills() const {
    return skills;
}

//функции
//ввод данных
void Positive_Heroes :: inputData() {
    cin.ignore();

    cout << "Введите имя героя: ";
    string inputName;
    getline(cin, inputName);
    setName(inputName); 
   
    cout << "Введите тип оружия: ";
    string inputWType;
    getline(cin, inputWType);
    setWearponType(inputWType);

    cout << "Введите навыки героя: ";
    string skills;
    getline(cin, skills);
    setSkills(skills);
}
//печать данных
void Positive_Heroes::print() {
    cout << "Герой:" << endl;
    //cout << "Имя: " << getName() << endl;
    cout << "Тип оружия: " << getWearponType() << endl;
    cout << "Скиллы: " << getSkills() << endl;
}


void Positive_Heroes::printInfo() const {
    cout << "ГЕРОЙ" << endl;
    cout << "Имя: " << getName() << endl;
    cout << "Тип оружия: " << getWearponType() << endl;
    cout << "Скиллы: " << getSkills() << endl;
    cout << "\n";
}

void Positive_Heroes::saveToFile(ofstream& file) const {
    file << "Positive_Heroes" << endl;
    Heroes::saveToFile(file);
    file << getWearponType() << endl;
    file << getSkills() << endl;
}

void Positive_Heroes::loadFromFile(ifstream& file) {
    getline(file, name);
    //file >> name;
    //file >> wearponType; 
    //file >> skills;
    getline(file, name);          // Считываем полное имя, включая пробелы
    getline(file, wearponType);   // Считываем тип оружия
    getline(file, skills);        // Считываем навыки
}

void Positive_Heroes::changeSpec() {
    int answer = 0;
    cin.ignore();
    cout << "Что вы хотите изменить?\n1 - Имя\n2 - Тип оружия\n3 - Скиллы" << endl;
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