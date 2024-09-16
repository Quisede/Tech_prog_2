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
        current->hero->printInfo(); // ����� ������������ ������
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
        //���������� ���
        if (dynamic_cast<Positive_Heroes*>(current->hero) && type == 1) {
            //cout << "��� ���������: �����\n";
            current->hero->printInfo(); // ����� ������������ ������
         
        }
        else if (dynamic_cast<Villains*>(current->hero) && type == 2) {
            //cout << "��� ���������: ������\n";
            current->hero->printInfo(); // ����� ������������ ������
            
        }
        else if (dynamic_cast<Monsters*>(current->hero) && type == 3) {
            //cout << "��� ���������: ������\n";
            current->hero->printInfo(); // ����� ������������ ������
            
        }
        current = current->next;
    }
}