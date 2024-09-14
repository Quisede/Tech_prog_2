#pragma once
#include <string>
using namespace std;

class Heroes
{
protected:
    string name;//имя персонажа

public:
    Heroes() : name(""){}
    Heroes(const string& name) : name(name){}
    virtual ~Heroes() {}
    
    virtual void printInfo() const = 0; // Виртуальный метод для вывода информации
    /*
    virtual void saveToFile(ofstream& file) const = 0; // Виртуальный метод для сохранения данных в файл
    virtual void loadFromFile(ifstream& file) = 0; // Виртуальный метод для загрузки данных из файла
    */

    // Сеттеры
    void setName(const string& n) { name = n; }

    // Геттеры
    string getName() const { return name; }
};

