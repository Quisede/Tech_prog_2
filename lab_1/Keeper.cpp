#include "Keeper.h"
#include <iostream>
using namespace std;

//Keeper::Keeper() : head(nullptr), size(0) {}
/*
Keeper::~Keeper() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current->hero;  // Удаление объекта героя
        delete current;        // Удаление узла
        current = next;
    }
}
*/
void Keeper::addHero(Heroes* hero) {
    heroesList.add(hero);
}
/*
void Keeper::printlist() {
    Node* current = head;
    while (current != NULL)
    {
        cout << current->hero<< endl;
        current = current->next;
    }
}
*/

void Keeper::printHeroes() const {
    heroesList.print(); // Печать информации о всех героях
}

void Keeper::clearHeroes() {
    Node* current = heroesList.getHead();
    while (current != nullptr) {
        Node* next = current->next;
        delete current->hero;
        delete current;
        current = next;
    }
    heroesList = List(); // Сброс списка
}