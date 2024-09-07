#pragma once
#include "Heroes.h"
class Villains :
    public Heroes
{
private:
    char name[50]; //���
    char wearponType[50]; //��� ������
    char crime[100]; //������������
    char location[50]; //����� ��������
    char skills[100]; //������
public:
    Villains();//����������� �� ���������
    Villains(char* n, char* w, char* c, char* l, char* s);//����������� � �����������
    Villains(const Villains& copy);//����������� �����������
    ~Villains();//����������

    //�������
    void setName(char* n);
    void setWearponType(char* w);
    void setCrime(char* c);
    void setLocation(char* l);
    void setSkills(char* s);

    //�������
    const char* getName() const;
    const char* getWearponType() const;
    const char* getCrime() const;
    const char* getLocation() const;
    const char* getSkills() const;
};

