#pragma once
#include "Heroes.h"
class Positive_Heroes :
    public Heroes
{
private:
    char name[50];//���
    char wearponType[50];//��� ������
    char skills[100];//������

public:
    Positive_Heroes();//����������� �� ���������
    Positive_Heroes(char* n, char* w, char* s);//����������� � �����������
    Positive_Heroes(const Positive_Heroes& copy);//����������� �����������
    ~Positive_Heroes();//����������

    //
    void setName(char* n);
    void setWearponType(char* w);
    void setSkills(char* s);

    //�������
    const char* getName() const;
    const char* getWearponType() const;
    const char* getSkills() const;
};

