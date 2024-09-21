#include "Keeper.h"
#include <iostream>
#include <fstream>
using namespace std;

//������� ��������� ����� � ������
void Keeper::addHero(Heroes* hero) {
    heroesList.add(hero);
}

//������� ������ ���������� � ���� ������
void Keeper::printHeroes() const {
    heroesList.print(); // ������ ���������� � ���� ������
}

//������� �������� ������
void Keeper::clearHeroes() {
    //������ ��������� �� �������� ������� � ��������� ���� ������, ������� ������
    Node* current = heroesList.getHead();
    while (current != nullptr) {
        Node* next = current->next;
        delete current->hero;
        delete current;
        current = next;
    }
    heroesList = List(); // ����� ������
}

//������� �������� �����
void Keeper::removeHero() {
    cout << "������ ��������� �� ������ �������?:\n1)�����\n2)������\n3)�������\n";
    int choice = 0;
    int choice_2 = 0;
    cin >> choice;

    while (choice != 4) {
        cin.ignore();
        switch (choice) {
        case 1: {
            system("cls");
            cout << "1)����� ��������� �� �����\n2)�������� ���� ����������\n3)�����\n";
            cin >> choice_2;

            system("cls");

            if (choice_2 == 1) {
                //����� �� �����
                system("cls");
                cin.ignore();
                string s;
                //����������� ���
                cout << "������� ��� ���������: ";
                getline(cin, s); 
                cout << s << endl;
                //�������� ��� ��� �� ������� �������� ��������� �� �����
                removeByName(s); // �������� ��������� �� �����
                system("pause");
                system("cls");
            }
            if (choice_2 == 2) {
                //����� ���� ����������
                if (choice == 1)
                    cout << "��� �����" << endl;
                if (choice == 2)
                    cout << "��� ������" << endl;
                if (choice == 3)
                    cout << "��� �������" << endl;
                
                system("cls");
                heroesList.printTypeHero(choice);
                system("pause");
                system("cls");
            }
            if (choice_2 == 3) {
                //����� �� ��� ����
                system("cls");
                break;
            }
            //�� ������ ������������� �����
            if (choice_2 != 1 && choice_2 != 2 && choice_2 != 3) {
                cout << "�� ����� �������� ��������, ���������� �����" << endl;
            }
            system("pause");
            break; // ����� �� switch
        }
        case 2: {
            system("cls");
            cout << "1)����� ��������� �� �����\n2)�������� ���� ����������\n3)�����\n";
            cin.ignore();
            cin >> choice_2;
            system("cls");
            if (choice_2 == 1) {
                string s;
                cout << "������� ��� ���������:\n";
                getline(cin, s);
                removeByName(s); // �������� ��������� �� �����
            }
            if (choice_2 == 2) {
                if (choice == 1)
                    cout << "��� �����" << endl;
                if (choice == 2)
                    cout << "��� ������" << endl;
                if (choice == 3)
                    cout << "��� �������" << endl;


                heroesList.printTypeHero(choice);
            }
            if (choice_2 == 3) {
                break;
            }
            if (choice_2 != 1 && choice_2 != 2 && choice_2 != 3) {
                cout << "�� ����� �������� ��������, ���������� �����" << endl;
            }
            system("pause");
            system("cls");
            break; // ����� �� switch
        }
        case 3: {
            system("cls");
            cout << "1)����� ��������� �� �����\n2)�������� ���� ����������\n3)�����\n";
            cin >> choice_2;
            system("cls");
            if (choice_2 == 1) {
                string s;
                cin.ignore();
                cout << "������� ��� ���������:\n";
                getline(cin, s);
                removeByName(s); // �������� ��������� �� �����
                //break;
            }
            if (choice_2 == 2) {
                if (choice == 1)
                    cout << "��� �����" << endl;
                if (choice == 2)
                    cout << "��� ������" << endl;
                if (choice == 3)
                    cout << "��� �������" << endl;


                heroesList.printTypeHero(choice);

            }
            if (choice_2 == 3) {
                break;
            }
            if (choice_2 != 1 && choice_2 != 2 && choice_2 != 3) {
                cout << "�� ����� �������� ��������, ���������� �����" << endl;
            }
            
            system("pause");
            system("cls");
            break; // ����� �� switch
        }
        default:
            cout << "�������� �����. ����������, ���������� �����." << endl;
            break;
        }
        break;
    }
}
//������� ������ �� �����, ���������� ��������� �� ������ ������ ������
Heroes* Keeper::searchName(string& s) {
    Node* current = heroesList.getHead();  // �������� � ������ ������
    while (current != nullptr) {
        //if (current->hero->getName() == s) {
          if (strcmp(current->hero->getName().c_str(), s.c_str()) == 0){
            return current->hero;  // ���������� ��������� �� ���������� �����
        }
        current = current->next;  // ��������� � ���������� ����
    }
    cout << "ERROR: ����� � ������ " << s << " �� ������." << endl;
    return nullptr;  // ���� ������ �� �����, ���������� nullptr
}
//�������� �� �����
void Keeper::removeByName(string& n) {
    Node* current = heroesList.getHead();//������� ����
    Node* previous = nullptr;//���������� ����

    while (current != nullptr) {
        if (current->hero->getName() == n) {
            if (previous == nullptr) {
                heroesList.setHead(current->next);
            }
            else {
                previous->next = current->next;
            }
            delete current->hero;
            delete current;
            cout << "����� " << n << " ������ �� ������.\n";
            return;
        }
        previous = current;
        current = current->next;
    }
    cout << "����� � ������ " << n << " �� ������.\n";
}
//������� ���������� � ����
void Keeper::saveToFile(const char* filename) {
    Node* current = heroesList.getHead();//������ ��������� �� �������� ������� ������

    ofstream file(filename);//��������� ���� ��� ������

    //���� ���� ��������, �� ��������� ������ �� ������ � ��������� ������ � ����
    if (file.is_open()){
        while (current != nullptr) {
            current->hero->saveToFile(file);
            current = current->next;
        }
        file.close();
        cout << "������ ������ ������� �������� � ����." << endl;
    }
    else {
        cout << "������ ��� �������� �����" << endl;
    }
}

//�������� �� �����
void Keeper::loadFromFile(const char* filename) {
    int answer = 0;
    //��������� ��� ������
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "�� ������� ������� ����" << endl;
        return;
    }

    cout << "���� ������ � ������� ������" << endl;
    cout << "��� �������� ������ �� �����, ������� ��������� ���� ������ ����� ��������. �� ������ ����������?\n1 - ��\n2 - ����� � ����" << endl;
    cin >> answer;
    if (answer == 2) {
        return;
    }
    if (answer != 1 && answer != 2) {
        cout << "�������� ��������. ���������� �����.";
        return;
    }

    //����� ��������� ������� ������ ��������� 

    clearHeroes();//������� ���������� ����� ���������

    string type;
    //� ����������� �� ���� ������� ������� ��� � ��������������� �����
    while (file >> type) {
        Heroes* hero = nullptr;

        if (type == "Positive_Heroes")
            hero = new Positive_Heroes();
        else if (type == "Villains")
            hero = new Villains();
        else if (type == "Monsters")
            hero = new Monsters();
        
        if (hero) {
            hero->loadFromFile(file);
            addHero(hero);
        }

    }

    file.close(); // ��������� ����
    system("cls");
    cout << "������ ������ ������� �������� �� �����." << endl;
}

