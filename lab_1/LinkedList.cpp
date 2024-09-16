#include "LinkedList.h"
#include "Monsters.h"
#include "Positive_Heroes.h"
#include "Villains.h"
#include <iostream>

using namespace std;

void List::add(Heroes* hero) {
    Node* newNode = new Node{hero};
    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    ++size;
}

void List::print() const{
    Node* current = head;
    while (current != nullptr) {
        current->hero->printInfo(); // Вызов виртуального метода
        current = current->next;
    }
}

Node& List::operator[](int id) {
    Node* current = head;
    int count = 0;

    while (current != nullptr) {
        if (count == id) {
            return *current;
        }
        current = current->next;
        count++;
    }
}

void List::printTypeHero(int type) const {
    Node* current = head;
    while (current != nullptr) {
        //определяем тип
        if (dynamic_cast<Positive_Heroes*>(current->hero) && type == 1) {
            //cout << "Тип персонажа: Герой\n";
            current->hero->printInfo(); // Вызов виртуального метода
         
        }
        else if (dynamic_cast<Villains*>(current->hero) && type == 2) {
            //cout << "Тип персонажа: Злодей\n";
            current->hero->printInfo(); // Вызов виртуального метода
            
        }
        else if (dynamic_cast<Monsters*>(current->hero) && type == 3) {
            //cout << "Тип персонажа: Монстр\n";
            current->hero->printInfo(); // Вызов виртуального метода
            
        }
        current = current->next;
    }
}