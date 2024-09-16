#pragma once
#include <iostream>
#include "Heroes.h"
#include "Positive_Heroes.h"
#include "Monsters.h"
#include "Villains.h"
#include "LinkedList.h"

class Keeper
{
private:
	//создаем контейнер для хренения героев
	List heroesList;

public:
	Keeper() {};//конструктор
	~Keeper() {};//деструктор

	void addHero(Heroes* hero);//добавление героя
	void removeHero();//удаление героя
	Heroes* searchName(string& n);
	void printHeroes() const; // Печать информации о всех героях
	void clearHeroes();//очистка контейнера
	void removeByName(string& n);//удаление по имени

	void saveToFile(const char* filename);//загрузка в файл
	void loadFromFile(const char* filename);//выгрузка из файла

	void printlist();
	size_t getCount() const;//получение текущего количества объектов
	Heroes* getHero(size_t index) const;//получение объекта по индексу
};

