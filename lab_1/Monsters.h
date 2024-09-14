#pragma once
#include "Heroes.h"
#include "LinkedList.h"
#include <iostream>
#include <string>
using namespace std;

//класс монстры
class Monsters : public Heroes
{
private:
    string description;//описание

public:
    Monsters();//конструктор по умолчанию
    Monsters(const string& n, const string& d); // конструктор с параметрами
    Monsters(const Monsters& copy);//конструктор копирования
    ~Monsters();//деструктор

    //сеттеры
    //void setName(string& n);
    void setDescription(string& d);

    //геттеры
    //string getName() const;
    string getDescription() const;

    //функции
    void inputData();//ввод данных пользователем
    void printInfo() const; //вывод данных на экран
};

