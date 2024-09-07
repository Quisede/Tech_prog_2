#pragma once
#include "Heroes.h"
class Monsters :
    public Heroes
{
private:
    char name[50];
    char description[200];

public:
    Monsters();//конструктор по умолчанию
    Monsters(char* n, char* d);//конструктор с параметрами
    Monsters(const Monsters& copy);//конструктор копирования
    ~Monsters();//деструктор

    //сеттеры
    void setName(char* n);
    void setDescription(char* d);

    //геттеры
    const char* getName() const;
    const char* getDescription() const;
};

