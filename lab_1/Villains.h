#pragma once
#include "Heroes.h"
#include "LinkedList.h"
#include <iostream>
#include <string>
using namespace std;

//класс злодеи
class Villains : public Heroes
{
private:
    string wearponType; //тип оружия
    string crime; //преступление
    string location; //место обитания
    string skills; //навыки
public:
    Villains();//конструктор по умолчанию
    Villains(string& n, string& w, string& c, string& l, string& s);//конструктор с параметрами
    Villains(const Villains& copy);//конструктор копирования
    ~Villains();//деструктор

    //сеттеры
    void setWearponType(string& w);
    void setCrime(string& c);
    void setLocation(string& l);
    void setSkills(string& s);

    //геттеры 
    string getWearponType() const;
    string getCrime() const;
    string getLocation() const;
    string getSkills() const;

    //функции
    void inputData();//ввод данных пользователем
    void print();//вывод данных на экран
    void printInfo() const; //вывод данных на экран
};