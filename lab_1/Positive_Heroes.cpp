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
/*
Positive_Heroes::Positive_Heroes(const Positive_Heroes& copy) :
    name(copy.name), wearponType(copy.wearponType), skills(copy.skills) {}
*/

Positive_Heroes::~Positive_Heroes() {}

//сеттеры
/*
void Positive_Heroes::setName(string& n) {
    name = n;
}
*/
void Positive_Heroes::setWearponType(string& w) {
    wearponType = w;
}

void Positive_Heroes::setSkills(string& s) {
    skills = s;
}

//геттеры
/*
string Positive_Heroes::getName() const {
    return name;
}
*/
string Positive_Heroes::getWearponType() const {
    return wearponType;
}

string Positive_Heroes::getSkills() const {
    return skills;
}

//функции
void Positive_Heroes :: inputData() {
    
    cout << "Введите имя героя: ";
    string inputName;
    cin >> inputName;
    setName(inputName); 
   
    cout << "Введите тип оружия: ";
    string inputWType;
    cin >> inputWType;
    setWearponType(inputWType);

    cout << "Введите навыки героя: ";
    string skills;
    cin >> skills;
    setSkills(skills);
}

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
    //getline(file, name);
    file >> name;
    file >> wearponType; 
    file >> skills;
}

void Positive_Heroes::changeSpec() {
    int answer = 0;
    cout << "Что вы хотите изменить?\n1 - Имя\n2 - Тип оружия\n3 - Скиллы" << endl;
    cin >> answer;
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