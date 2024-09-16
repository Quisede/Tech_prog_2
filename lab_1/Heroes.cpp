#include "Heroes.h"
#include <iostream>
#include <fstream>

using namespace std;

void Heroes::saveToFile(ofstream& file) const {
	file << getName() << endl;
}

void Heroes::loadFromFile(ifstream& file) {
	//getline(file, name);
	//file >> name;
}

void Heroes::changeSpec() {

}