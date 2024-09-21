#pragma once
#include <string>
#include "Heroes.h"
using namespace std;

struct Node{
	Heroes* hero;//указатель на объект героя
	Node* next;//указатель на следующий узел

	Node(Heroes* h) : hero(h), next(nullptr) {} // Конструктор узла
};

class List {
private:
	Node* head;
	size_t size;
public:
	List() : head(nullptr), size(0) {};

	void add(Heroes* hero);//добавление объекта в список
	void print() const;
	void printTypeHero(int type) const;
	//Node& operator[](int id);
	Node* getHead() { return head; }
	void setHead(Node* newHead) { head = newHead; }
};
