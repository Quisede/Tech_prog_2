#pragma once
#include "Heroes.h"
class Villains :
    public Heroes
{
private:
    char name[50]; //имя
    char wearponType[50]; //тип оружия
    char crime[100]; //преступление
    char location[50]; //место обитания
    char skills[100]; //навыки
public:
    Villains();//конструктор по умолчанию
    Villains(char* n, char* w, char* c, char* l, char* s);//конструктор с параметрами
    Villains(const Villains& copy);//конструктор копирования
    ~Villains();//деструктор

    //сеттеры
    void setName(char* n);
    void setWearponType(char* w);
    void setCrime(char* c);
    void setLocation(char* l);
    void setSkills(char* s);

    //геттеры
    const char* getName() const;
    const char* getWearponType() const;
    const char* getCrime() const;
    const char* getLocation() const;
    const char* getSkills() const;
};

