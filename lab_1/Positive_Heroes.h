#pragma once
#include "Heroes.h"
#include "LinkedList.h"
#include <iostream>
#include <string>
using namespace std;

//����� ������������� �����
class Positive_Heroes : public Heroes{
private:
    string wearponType;//��� ������
    string skills;//������

public:
    Positive_Heroes();//����������� �� ���������
    Positive_Heroes(const string& n, const string& w, const string& s);//����������� � �����������
    Positive_Heroes(const Positive_Heroes& copy);//����������� �����������
    ~Positive_Heroes();//����������

    //�������
    //void setName(string& n);
    void setWearponType(string& w);
    void setSkills(string& s);

    //�������
    //string getName() const;
    string getWearponType() const;
    string getSkills() const;

    //�������
    void inputData();//���� ������ �������������
    void print();//����� ������ �� �����
    void printInfo() const;
    void saveToFile(ofstream& file) const;
    void loadFromFile(ifstream& file);
    void changeSpec();
};

