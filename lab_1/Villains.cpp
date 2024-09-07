#include "Villains.h"
#include <iostream>
#include <string>

Villains::Villains() {
    strcpy(name, "");
    strcpy(wearponType, "");
    strcpy(crime, "");
    strcpy(location, "");
    strcpy(skills, "");
}

Villains::Villains(char* n, char* w, char* c, char* l, char* s) {
    strcpy(name, n);
    strcpy(wearponType, w);
    strcpy(crime, c);
    strcpy(location, l);
    strcpy(skills, s);
}

Villains::Villains(const Villains& copy) {
    strcpy(name, copy.name);
    strcpy(wearponType, copy.wearponType);
    strcpy(crime, copy.crime);
    strcpy(location, copy.location);
    strcpy(skills, copy.skills);
}


Villains::~Villains() {
}

void Villains::setName(char* n) {
    strncpy(name, n, sizeof(name) - 1);
    name[sizeof(name) - 1] = '\0';
}

void Villains::setWearponType(char* n) {
    strncpy(wearponType, n, sizeof(wearponType) - 1);
    wearponType[sizeof(wearponType) - 1] = '\0';
}

void Villains::setCrime(char* c) {
    strncpy(crime, c, sizeof(crime) - 1);
    crime[sizeof(crime) - 1] = '\0';
}

void Villains::setLocation(char* l) {
    strncpy(location, l, sizeof(location) - 1);
    location[sizeof(location) - 1] = '\0';
}

void Villains::setSkills(char* n) {
    strncpy(skills, n, sizeof(skills) - 1);
    skills[sizeof(skills) - 1] = '\0';
}

const char* Villains::getName() const {
    return name;
}

const char* Villains::getWearponType() const {
    return wearponType;
}

const char* Villains::getCrime() const {
    return crime;
}

const char* Villains::getLocation() const {
    return location;
}

const char* Villains::getSkills() const {
    return skills;
}