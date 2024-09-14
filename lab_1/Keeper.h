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
	//������� ��������� ��� �������� ������
	List heroesList;

public:
	Keeper() {};//�����������
	~Keeper() {};//����������

	void addHero(Heroes* hero);//���������� �����
	void removeHero(size_t index);//�������� �����
	void saveToFile(const char* filename) const;//�������� � ����
	void loadFromFile(const char* filename);//�������� �� �����
	void printlist();
	size_t getCount() const;//��������� �������� ���������� ��������
	Heroes* getHero(size_t index) const;//��������� ������� �� �������
	void printHeroes() const; // ������ ���������� � ���� ������
	void clearHeroes();
};

