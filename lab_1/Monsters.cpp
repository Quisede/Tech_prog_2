#include "Monsters.h"
#include "Heroes.h"
#include <iostream>
#include <string>
using namespace std;

//������������ � �����������
Monsters::Monsters() : Heroes(), description("") {}

Monsters::Monsters(const string& name, const string& description) : Heroes(name), description(description) {}
/*
Monsters::Monsters(const Monsters& copy) : name(copy.name), description(copy.description){}
*/
Monsters::~Monsters() {
}

//�������
/*
void Monsters::setName(string& n) {
    Heroes.name = n;
}
*/
void Monsters::setDescription(string& d) {
    description = d;
}

//�������
/*
string Monsters::getName() const {
    return name;
}
*/
string Monsters::getDescription() const {
    return description;
}

void Monsters::inputData() {

    cout << "������� ��� �������: ";
    string inputName;
    cin >> inputName;
    setName(inputName);

    cout << "������� �������� �������: ";
    string inputDescription;
    cin >> inputDescription;
    setDescription(inputDescription);
}

void Monsters::printInfo() const {
    cout << "������" << endl;
    cout << "Name: " << getName() << endl;
    cout << "Description: " << getDescription() << endl;
}