#pragma once
#include "Heroes.h"
class Monsters :
    public Heroes
{
private:
    char name[50];
    char description[200];

public:
    Monsters();//����������� �� ���������
    Monsters(char* n, char* d);//����������� � �����������
    Monsters(const Monsters& copy);//����������� �����������
    ~Monsters();//����������

    //�������
    void setName(char* n);
    void setDescription(char* d);

    //�������
    const char* getName() const;
    const char* getDescription() const;
};

