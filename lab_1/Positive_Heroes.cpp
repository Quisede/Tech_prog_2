#include "Positive_Heroes.h"
#include <iostream>
#include <string>

Positive_Heroes::Positive_Heroes() {
    strcpy(name, "");        
    strcpy(wearponType, ""); 
    strcpy(skills, "");      
}

Positive_Heroes::Positive_Heroes(char* n, char* w, char* s) {
    strcpy(name, n);
    strcpy(wearponType, w);
    strcpy(skills, s);
}

Positive_Heroes::Positive_Heroes(const Positive_Heroes& copy) {
    strcpy(name, copy.name);
    strcpy(wearponType, copy.wearponType);
    strcpy(skills, copy.skills);
}


Positive_Heroes::~Positive_Heroes() {
}

void Positive_Heroes::setName(char* n) {
    strncpy(name, n, sizeof(name) - 1);
    name[sizeof(name) - 1] = '\0';
}

void Positive_Heroes::setWearponType(char* n) {
    strncpy(wearponType, n, sizeof(wearponType) - 1);
    wearponType[sizeof(wearponType) - 1] = '\0';
}

void Positive_Heroes::setSkills(char* n) {
    strncpy(skills, n, sizeof(skills) - 1);
    skills[sizeof(skills) - 1] = '\0';
}

const char* Positive_Heroes::getName() const {
    return name;
}

const char* Positive_Heroes::getWearponType() const {
    return wearponType;
}

const char* Positive_Heroes::getSkills() const {
    return skills;
}