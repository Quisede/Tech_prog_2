#pragma once
#include "Heroes.h"
#include "LinkedList.h"
#include <iostream>
#include <string>
using namespace std;

//����� �������
class Monsters : public Heroes
{
private:
    string description;//��������

public:
    Monsters();//����������� �� ���������
    Monsters(const string& n, const string& d); // ����������� � �����������
    Monsters(const Monsters& copy);//����������� �����������
    ~Monsters();//����������

    //�������
    //void setName(string& n);
    void setDescription(string& d);

    //�������
    //string getName() const;
    string getDescription() const;

    //�������
    void inputData();//���� ������ �������������
    void printInfo() const; //����� ������ �� �����
};

