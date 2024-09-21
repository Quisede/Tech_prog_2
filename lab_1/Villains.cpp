#include "Villains.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//������������ � �����������
Villains::Villains() : 
    Heroes(), wearponType(""), crime(""), location(""), skills("") {}

Villains::Villains(string& n, string& w, string& c, string& l, string& s) :
    Heroes(), wearponType(w), crime(c), location(l), skills(s) {}

Villains::Villains(const Villains& copy) :
    Heroes(copy), // ������������� �������� ������
    wearponType(copy.wearponType), // �������� ��� ������
    crime(copy.crime), // �������� ������������
    location(copy.location), // �������� �������
    skills(copy.skills) {} // �������� ������

Villains::~Villains() {}

//�������

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

//�������

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

    cout << "������� ��� ������: ";
    string inputName;
    getline(cin, inputName);
    setName(inputName);

    cout << "������� ��� ������: ";
    string inputWT;
    getline(cin, inputWT);
    setWearponType(inputWT);

    cout << "������� ������������: ";
    string inputCrime;
    getline(cin, inputCrime);
    setCrime(inputCrime);

    cout << "������� �������: ";
    string inputLocation;
    getline(cin, inputLocation);
    setLocation(inputLocation);

    cout << "������� ������: ";
    string inputSkills;
    getline(cin, inputSkills);
    setSkills(inputSkills);
}

void Villains::printInfo() const {
    cout << "������" << endl;
    cout << "���: " << getName() << endl;
    cout << "��� ������: " << getWearponType() << endl;
    cout << "������������: " << getCrime() << endl;
    cout << "�������: " << getLocation() << endl;
    cout << "������: " << getSkills() << endl;
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
    getline(file, name);          // ��������� ������ ���, ������� �������
    getline(file, wearponType);   // ��������� ��� ������
    getline(file, crime);         // ��������� ������������
    getline(file, location);      // ��������� ��������������
    getline(file, skills);        // ��������� ������
}

void Villains::changeSpec() {
    int answer = 0;
    cin.ignore();
    cout << "��� �� ������ ��������?\n1 - ���\n2 - ��� ������\n3 - ������������\n4 - �������\n5 - ������" << endl;
    cin >> answer;
    system("cls");
    if (answer == 1) {
        cout << "������� ����� ���" << endl;
        string new_name;
        cin >> new_name;
        name = new_name;
        cout << "������ ������� ��������" << endl;
    }
    else if (answer == 2) {
        cout << "������� ����� ��� ������" << endl;
        string new_WT;
        cin >> new_WT;
        wearponType = new_WT;
        cout << "������ ������� ��������" << endl;

    }
    else if (answer == 3) {
        cout << "������� ����� ������������" << endl;
        string new_C;
        cin >> new_C;
        wearponType = new_C;
        cout << "������ ������� ��������" << endl;

    }
    else if (answer == 4) {
        cout << "������� ����� �������" << endl;
        string new_L;
        cin >> new_L;
        wearponType = new_L;
        cout << "������ ������� ��������" << endl;

    }
    else if (answer == 5) {
        cout << "������� ����� �����" << endl;
        string new_Skill;
        cin >> new_Skill;
        skills = new_Skill;
        cout << "������ ������� ��������" << endl;
    }
    else {
        cout << "�������� ��������, ���������� �����" << endl;
    }
}