#pragma once
#include "Heroes.h"
#include "LinkedList.h"
#include <iostream>
#include <string>
using namespace std;

//класс положительные герои
class Positive_Heroes : public Heroes{
private:
    string wearponType;//тип оружия
    string skills;//навыки

public:
    Positive_Heroes();//конструктор по умолчанию
    Positive_Heroes(const string& n, const string& w, const string& s);//конструктор с параметрами
    Positive_Heroes(const Positive_Heroes& copy);//конструктор копирования
    ~Positive_Heroes();//деструктор

    //Сеттеры
    //void setName(string& n);
    void setWearponType(string& w);
    void setSkills(string& s);

    //геттеры
    //string getName() const;
    string getWearponType() const;
    string getSkills() const;

    //функции
    void inputData();//ввод данных пользователем
    void print();//вывод данных на экран
    void printInfo() const;
    void saveToFile(ofstream& file) const;
    void loadFromFile(ifstream& file);
    void changeSpec();
};

