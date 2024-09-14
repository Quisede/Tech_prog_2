#include "Positive_Heroes.h"
#include "Heroes.h"
#include <iostream>
#include <string>
using namespace std;


//������������ � �����������
Positive_Heroes::Positive_Heroes() :
    Heroes(), wearponType(""), skills("") {}

Positive_Heroes::Positive_Heroes(const string& n, const string& w, const string& s) :
    Heroes(n), wearponType(w), skills(s) {}
/*
Positive_Heroes::Positive_Heroes(const Positive_Heroes& copy) :
    name(copy.name), wearponType(copy.wearponType), skills(copy.skills) {}
*/

Positive_Heroes::~Positive_Heroes() {}

//�������
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

//�������
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

//�������
void Positive_Heroes :: inputData() {
    
    cout << "������� ��� �����: ";
    string inputName;
    cin >> inputName;
    setName(inputName); 
   
    cout << "������� ��� ������: ";
    string inputWType;
    cin >> inputWType;
    setWearponType(inputWType);

    cout << "������� ������ �����: ";
    string skills;
    cin >> skills;
    setSkills(skills);
}

void Positive_Heroes::print() {
    cout << "�����:" << endl;
    //cout << "���: " << getName() << endl;
    cout << "��� ������: " << getWearponType() << endl;
    cout << "������: " << getSkills() << endl;
}


void Positive_Heroes::printInfo() const {
    cout << "�����" << endl;
    cout << "Name: " << getName() << endl;
    cout << "WearponType: " << getWearponType() << endl;
    cout << "Skills: " << getSkills() << endl;
}