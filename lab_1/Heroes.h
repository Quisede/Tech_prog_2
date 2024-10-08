#pragma once
#include <string>
using namespace std;

class Heroes
{
protected:
    string name;//��� ���������

public:
    Heroes() : name(""){}
    Heroes(const string& name) : name(name){}
    virtual ~Heroes() {}
    
    virtual void printInfo() const = 0; // ����������� ����� ��� ������ ����������
    virtual void saveToFile(ofstream& file) const; // ����������� ����� ��� ���������� ������ � ����
    virtual void loadFromFile(ifstream& file); // ����������� ����� ��� �������� ������ �� �����
    virtual void changeSpec();

    // �������
    void setName(const string& n) { name = n; }

    // �������
    string getName() const { return name; }
};

