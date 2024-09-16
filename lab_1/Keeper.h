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
	void removeHero();//�������� �����
	Heroes* searchName(string& n);
	void printHeroes() const; // ������ ���������� � ���� ������
	void clearHeroes();//������� ����������
	void removeByName(string& n);//�������� �� �����

	void saveToFile(const char* filename);//�������� � ����
	void loadFromFile(const char* filename);//�������� �� �����

	void printlist();
	size_t getCount() const;//��������� �������� ���������� ��������
	Heroes* getHero(size_t index) const;//��������� ������� �� �������
};

