#include "LinkedList.h"
#include "Monsters.h"
#include "Positive_Heroes.h"
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
        current->hero->printInfo(); // Âûחמג גטנעףאכüםמדמ לועמהא
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