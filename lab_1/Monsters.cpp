#include "Monsters.h"
#include <iostream>
#include <string>

Monsters::Monsters() {
    strcpy(name, "");
    strcpy(description, "");
}

Monsters::Monsters(char* n, char* d) {
    strcpy(name, n);
    strcpy(description, d);
}

Monsters::Monsters(const Monsters& copy) {
    strcpy(name, copy.name);
    strcpy(description, copy.description);
}


Monsters::~Monsters() {
}

void Monsters::setName(char* n) {
    strncpy(name, n, sizeof(name) - 1);
    name[sizeof(name) - 1] = '\0';
}

void Monsters::setDescription(char* d) {
    strncpy(description, d, sizeof(description) - 1);
    description[sizeof(description) - 1] = '\0';
}

const char* Monsters::getName() const {
    return name;
}

const char* Monsters::getDescription() const {
    return description;
}
