#include "Monsters.h"
#include "Heroes.h"
#include <iostream>
#include <string>
#include <fstream>
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
    cout << "���: " << getName() << endl;
    cout << "��������: " << getDescription() << endl;
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
    cout << "��� �� ������ ��������?\n1 - ���\n2 - ��������" << endl;
    cin >> answer;
    if (answer == 1) {
        cout << "������� ����� ���" << endl;
        string new_name;
        cin >> new_name;
        name = new_name;
        cout << "������ ������� ��������" << endl;
    }
    else if (answer == 2) {
        cout << "������� ����� ��������" << endl;
        string new_D;
        cin >> new_D;
        description = new_D;
        cout << "������ ������� ��������" << endl;

    }
    else {
        cout << "�������� ��������, ���������� �����" << endl;
    }
}