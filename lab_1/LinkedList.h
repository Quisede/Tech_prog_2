#pragma once
#include <string>
#include "Heroes.h"
using namespace std;

struct Node{
	Heroes* hero;//��������� �� ������ �����
	Node* next;//��������� �� ��������� ����

	Node(Heroes* h) : hero(h), next(nullptr) {} // ����������� ����
};

class List {
private:
	Node* head;
	size_t size;
public:
	List() : head(nullptr), size(0) {};

	void add(Heroes* hero);//���������� ������� � ������
	void print() const;
	void printTypeHero(int type) const;
	//Node& operator[](int id);
	Node* getHead() { return head; }
	void setHead(Node* newHead) { head = newHead; }
};
