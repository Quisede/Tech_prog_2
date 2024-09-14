#pragma once
#include "Heroes.h"
#include "LinkedList.h"
#include <iostream>
#include <string>
using namespace std;

//����� ������
class Villains : public Heroes
{
private:
    string wearponType; //��� ������
    string crime; //������������
    string location; //����� ��������
    string skills; //������
public:
    Villains();//����������� �� ���������
    Villains(string& n, string& w, string& c, string& l, string& s);//����������� � �����������
    Villains(const Villains& copy);//����������� �����������
    ~Villains();//����������

    //�������
    void setWearponType(string& w);
    void setCrime(string& c);
    void setLocation(string& l);
    void setSkills(string& s);

    //������� 
    string getWearponType() const;
    string getCrime() const;
    string getLocation() const;
    string getSkills() const;

    //�������
    void inputData();//���� ������ �������������
    void print();//����� ������ �� �����
    void printInfo() const; //����� ������ �� �����
};