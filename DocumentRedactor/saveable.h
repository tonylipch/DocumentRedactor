#pragma once
#include <iostream>

using namespace std;

class Saveable {

protected:
	virtual void saveToStream(ostream& out) = NULL;
	virtual void loadFromStream(istream& in) = NULL;

public:
	void saveToDisk(string fileName);
	void readFromDisk(string fileName);

};