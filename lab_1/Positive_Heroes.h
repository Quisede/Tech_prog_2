#pragma once
#include "Heroes.h"
class Positive_Heroes :
    public Heroes
{
private:
    char name[50];//имя
    char wearponType[50];//тип оружия
    char skills[100];//навыки

public:
    Positive_Heroes();//конструктор по умолчанию
    Positive_Heroes(char* n, char* w, char* s);//конструктор с параметрами
    Positive_Heroes(const Positive_Heroes& copy);//конструктор копирования
    ~Positive_Heroes();//деструктор

    //
    void setName(char* n);
    void setWearponType(char* w);
    void setSkills(char* s);

    //геттеры
    const char* getName() const;
    const char* getWearponType() const;
    const char* getSkills() const;
};

