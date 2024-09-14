#include "Villains.h"
#include <iostream>
#include <string>
using namespace std;

//������������ � �����������
Villains::Villains() : 
    Heroes(), wearponType(""), crime(""), location(""), skills("") {}

Villains::Villains(string& n, string& w, string& c, string& l, string& s) :
    Heroes(), wearponType(w), crime(c), location(l), skills(s) {}
/*
Villains::Villains(const Villains& copy) :
    name(copy.name), wearponType(copy.wearponType), crime(copy.crime), location(copy.location), skills(copy.skills) {}
    */

Villains::~Villains() {}

//�������
/*
void Villains::setName(string& n) {
    name = n;
}
*/
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
/*
string Villains::getName() const {
    return name;
}
*/
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

    cout << "������� ��� ������: ";
    string inputName;
    cin >> inputName;
    setName(inputName);

    cout << "������� ��� ������: ";
    string inputWT;
    cin >> inputWT;
    setWearponType(inputWT);

    cout << "������� ������������: ";
    string inputCrime;
    cin >> inputCrime;
    setCrime(inputCrime);

    cout << "������� �������: ";
    string inputLocation;
    cin >> inputLocation;
    setLocation(inputLocation);

    cout << "������� ������: ";
    string inputSkills;
    cin >> inputSkills;
    setSkills(inputSkills);
}

void Villains::printInfo() const {
    cout << "������" << endl;
    cout << "Name: " << getName() << endl;
    cout << "Wearpon Type: " << getWearponType() << endl;
    cout << "Crime: " << getCrime() << endl;
    cout << "Location: " << getLocation() << endl;
    cout << "Skills: " << getSkills() << endl;
}